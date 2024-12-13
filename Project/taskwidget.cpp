#include "taskwidget.h"
#include "ui_taskwidget.h"


#include "coordinatedialog.h"
#include "confirmdialog.h"
#include <QDir>
#include <QFileInfo>
#include <QJsonDocument>
#include <QFile>
#include <QDebug>
#include <QDirIterator>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>

TaskWidget::TaskWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TaskWidget)
{
    ui->setupUi(this);
    ui->task_finish->setEnabled(false);
    ui->task_return->setVisible(false);
    ui->return_btn->setVisible(false);
    ui->port_Edit->setText("54321");
    ui->ip_Edit->setText("239.0.0.1");
    receivingEnabled=true;
    m_recvFZ = new QUdpSocket(this);
    connect(m_recvFZ, &QUdpSocket::readyRead, this, &TaskWidget::handleReadyRead);
    m_udp = new QUdpSocket(this);
    m_udp->bind(QHostAddress::AnyIPv4, 6500, QUdpSocket::ShareAddress);
    m_udp->joinMulticastGroup(QHostAddress("224.0.0.0"));
    connect(m_udp, &QUdpSocket::readyRead, this, &TaskWidget::readyRead);
    ui->taskListLayout->addStretch();

    ui->configListLayout->addStretch();

    ui->widget_type_right->hide();
    ui->widget_26->hide();
    ui->widget_type_left->hide();
    m_task_timer = new QTimer(this);
    connect(m_task_timer, &QTimer::timeout, [=](){
        ui->timeEdit->setTime(ui->timeEdit->time().addSecs(1));
    });
    m_DynamicDataWidget=new DynamicDataWidget(ui->widget_10);
    QVBoxLayout *layout = new QVBoxLayout(ui->widget_10);
    layout->addWidget(m_DynamicDataWidget);
    init_JL_List(); 
    ui->finish_edit->hide();
    ui->JLFlag->setText("未开启激励数据驱动");
    ui->JL_Combox->setVisible(false);

    connect(ui->checkBox_1, &QCheckBox::toggled, this, &TaskWidget::onCheckBoxToggled);
    connect(ui->checkBox_2, &QCheckBox::toggled, this, &TaskWidget::onCheckBoxToggled);
    connect(ui->checkBox_3, &QCheckBox::toggled, this, &TaskWidget::onCheckBoxToggled);
    ui->stack_widget->setCurrentIndex(4);


}

TaskWidget::~TaskWidget()
{
    if (process.state() == QProcess::Running)
    {
        process.terminate();
        process.waitForFinished(3000);
    }
    delete ui;
}

void TaskWidget::init()
{
    QSqlQuery query(QString("SELECT * FROM task"));
    while (query.next()) {
        TaskListItem *taskListItem = new TaskListItem(this);
        connect(taskListItem, &TaskListItem::task_start, this, &TaskWidget::task_start);
        connect(this,&TaskWidget::SendStartFlag, taskListItem, &TaskListItem::RecvStartFlag);
        connect(taskListItem, &TaskListItem::task_edit, this, &TaskWidget::task_edit);
        connect(taskListItem, &TaskListItem::task_delete, this, &TaskWidget::task_delete);
        connect(taskListItem, &TaskListItem::TaskSelect, this, [=](QString name)
                {
                    QSqlQuery query;
                    query.prepare("SELECT task_path FROM task where task_name=:taskname");
                    query.bindValue(":taskname",name);
                    query.exec();
                    query.next();

                    QStringList exePath=query.value(0).toString().split(",");
                    ui->exePath_comboBox->clear();
                    ui->exePath_comboBox->addItems(exePath);
                    ui->task_Combox->setCurrentText(name);
                    ui->stack_widget->setCurrentIndex(4);

                });
        taskListItem->set_task_name(query.value(0).toString());
        taskListItem->set_create_name(query.value(1).toString());
        taskListItem->set_create_time(query.value(2).toDateTime());
        taskListItem->set_task_description(query.value(3).toString());
        taskListItem->set_task_type(query.value(4).toString());
        taskListItem->set_task_path(query.value(5).toString());
        taskListItem->set_task_questionnaire(query.value(6).toString());
        taskListItem->set_trigger_questionnaire(query.value(7).toString());
        taskListItem->set_task_event(query.value(8).toString());
        taskListItem->set_trigger_event(query.value(9).toString());
        ui->taskListLayout->insertWidget(0, taskListItem);
        initUserComboxAndTaskCombox();
    }
}

QString TaskWidget::TriggerTime()
{
    Trigger_TimeList.clear();
    for(int i=0; i<ui->layout_event->count(); i++)
    {
        QLayoutItem* item = ui->layout_event->itemAt(i);
        if (!item) continue;

        QWidget* widget = item->widget();
        if (widget)
        {
            EventItem* eventItem = qobject_cast<EventItem*>(widget);
            if (eventItem)
            {
                Trigger_TimeList.append(eventItem->getTimeList());//eventitem类已经判断好了
            }
        }
    }
    qDebug()<<"Trigger_TimeList--:"<<Trigger_TimeList;
    QStringList timeStrList; // 用于存储处理后的时间字符串

    for (int i = 0; i < Trigger_TimeList.size(); i++) {
        QStringList timeStr = Trigger_TimeList[i].split(","); // 拆分每个元素中的时间
        QString formattedTime;
        for (int j = 0; j < timeStr.size(); j++) {
            formattedTime += timeStr[j].trimmed(); // 移除可能存在的空白字符
            // 在时间之间添加分隔符，除了最后一个时间
            if (j < timeStr.size() - 1) {
                formattedTime += "-";
            }
        }
        timeStrList << formattedTime; // 将格式化后的时间字符串添加到列表中
    }

    return timeStrList.join(","); // 将 timeStrList 中的所有元素连接成一个单一的字符串
}

void TaskWidget::task_start()
{
    //TODO: 提示先关闭上一个任务 然后才能开启新任务
    ui->label_task_name->setText(ui->task_name->text());
    ui->label_task_type->setText(type_string());
    ui->stack_widget->setCurrentIndex(4);

    if (!m_exePath.isEmpty())
    {
        process.start(m_exePath);
    }

    m_task_timer->start(1000);

    ui->ffmpeg_widget->start_preview("rtmp://192.168.129.154/live/livestream");
}

void TaskWidget::task_edit()
{
    // 假设 layout_Screen 是一个已经存在的布局

    // 遍历布局中的所有子项，并删除它们
    QLayoutItem* child;
    while ((child = ui->layout_Screen->takeAt(0)) != nullptr) {
        if (child->widget()) {
            delete child->widget();
        }
        delete child;
    }
    ui->JLList_Combox->setCurrentIndex(-1);

    ui->buttonSave->hide();
    ui->finish_edit->show();
    TaskListItem *taskListItem = qobject_cast<TaskListItem*>(sender());

    QSqlQuery query(QString("SELECT * FROM task WHERE task_name = '%1';").arg(taskListItem->task_name()));
    if(query.next())
    {
        taskListItem->set_create_name(query.value(1).toString());
        taskListItem->set_create_time(query.value(2).toDateTime());
        taskListItem->set_task_description(query.value(3).toString());
        taskListItem->set_task_type(query.value(4).toString());
        taskListItem->set_task_path(query.value(5).toString());
        taskListItem->set_task_questionnaire(query.value(6).toString());
        taskListItem->set_trigger_questionnaire(query.value(7).toString());
        taskListItem->set_task_event(query.value(8).toString());
        taskListItem->set_trigger_event(query.value(9).toString());
        taskListItem->setPos_X_Y(query.value(10).toString());
        taskListItem->setJL(query.value(11).toString());
        qDebug()<<"Trigger_Time"<<query.value(12).toString();
        taskListItem->setTrigger_Time(query.value(12).toString());

    }

    ui->task_name->setText(taskListItem->task_name());
    ui->task_description->setText(taskListItem->task_description());
    QStringList task_type_list = taskListItem->task_type().split('-');
    if(task_type_list.size() == 2)
    {
        if(ui->checkBox_type_left->text() == task_type_list.at(0))
        {
            ui->checkBox_type_left->setChecked(true);
            if(ui->checkBox_left_sub1->text() == task_type_list.at(1))
            {
                ui->checkBox_left_sub1->setChecked(true);
            }
            else if(ui->checkBox_left_sub2->text() == task_type_list.at(1))
            {
                ui->checkBox_left_sub2->setChecked(true);
            }
            else if(ui->checkBox_left_sub3->text() == task_type_list.at(1))
            {
                ui->checkBox_left_sub3->setChecked(true);
            }
            else if(ui->checkBox_left_sub4->text() == task_type_list.at(1))
            {
                ui->checkBox_left_sub4->setChecked(true);
            }
        }
        else
        {
            ui->checkBox_type_right->setChecked(true);
            if(ui->checkBox_right_sub1->text() == task_type_list.at(1))
            {
                ui->checkBox_right_sub1->setChecked(true);
            }
            else if(ui->checkBox_right_sub2->text() == task_type_list.at(1))
            {
                ui->checkBox_right_sub2->setChecked(true);
            }
            else if(ui->checkBox_right_sub3->text() == task_type_list.at(1))
            {
                ui->checkBox_right_sub3->setChecked(true);
            }
            else if(ui->checkBox_right_sub4->text() == task_type_list.at(1))
            {
                ui->checkBox_right_sub4->setChecked(true);
            }
        }
    }

    //TODO: m_exePath 放入 TaskListItem 类

    m_exePath = taskListItem->task_path();
    m_pos=taskListItem->getPos_X_Y();
    ui->JLList_Combox->setCurrentText(taskListItem->JL());
 //   qDebug()<<"exepath:"<<m_exePath<<"pos:"<<m_pos;
    QStringList exeList = m_exePath.split(',');
    QStringList posList = m_pos.split(',');
    if(exeList.at(0)!="")
    {
        for (int i = 0; i < exeList.size(); ++i) {
            ScreenImportItem* item =new ScreenImportItem(this);

            ui->layout_Screen->addWidget(item);
            item->setScreenPath(exeList[i]);
            item->setCoordinate_X_Y(posList[i].split("-")[0].toInt(),posList[i].split("-")[1].toInt());
        }
    }

    m_question_item_count = 0;
    while (QLayoutItem* item = ui->layout_question->takeAt(0)) {
        if (QWidget* widget = item->widget()) {
            widget->deleteLater();
        }
        delete item;
    }
    ui->layout_question->addStretch();

    m_event_item_count = 0;
    while (QLayoutItem* item = ui->layout_event->takeAt(0)) {
        if (QWidget* widget = item->widget()) {
            widget->deleteLater();
        }
        delete item;
    }
    ui->layout_event->addStretch();

    QStringList task_questionnaire_list = taskListItem->task_questionnaire().split(',');
    QStringList trigger_questionnaire_list = taskListItem->trigger_questionnaire().split(',');
    for(int i=0; i<task_questionnaire_list.size(); i++)
    {
        QuestionItem *questionItem = new QuestionItem;
        questionItem->setNameIndex(1 + m_question_item_count);
        questionItem->set_task_questionnaire(task_questionnaire_list.at(i));
        questionItem->set_trigger_questionnaire(trigger_questionnaire_list.at(i).toInt());
        ui->layout_question->insertWidget(1 + m_question_item_count, questionItem);
        m_question_item_count++;
    }

    QStringList task_event_list = taskListItem->task_event().split(',');
    QStringList trigger_event_list = taskListItem->trigger_event().split(',');
    QString triggerTime= taskListItem->getTrigger_Time();//一整条的时间00:00:00-00:06:00-00:00:0000:00:00-00:07:00-00:00:00
    QStringList triggerTimeList=triggerTime.split(",");

    for(int i=0; i<task_event_list.size(); i++)
    {
        EventItem *eventItem = new EventItem;
        connect(this,&TaskWidget::getTriggerTime,eventItem,&EventItem::getTriggerTime);
        eventItem->set_task_event(task_event_list.at(i));
        eventItem->setTimeString(triggerTimeList[i]);
        eventItem->set_trigger_event(trigger_event_list[i]);
        ui->layout_event->insertWidget(1 + m_event_item_count, eventItem);
        m_event_item_count++;
    }

    ui->stack_widget->setCurrentIndex(1);
}

void TaskWidget::task_delete()
{
    TaskListItem *taskListItem = qobject_cast<TaskListItem*>(sender());

    while (QLayoutItem* item = ui->layout_question->takeAt(0))
    {
        if (QWidget* widget = item->widget())
        {
            widget->deleteLater();
        }
        delete item;
    }


    while (QLayoutItem* item = ui->layout_event->takeAt(0))
    {
        if (QWidget* widget = item->widget())
        {
            widget->deleteLater();
        }
        delete item;
    }

    taskListItem->deleteLater();
    QSqlQuery query;
    query.prepare("delete from task where task_name=:taskname");
    query.bindValue(":taskname",taskListItem->task_name());
    query.exec();

}

void TaskWidget::initUserComboxAndTaskCombox()
{
    ui->user_Combox->clear();
    ui->task_Combox->clear();
    QSqlQuery query;
    if(!query.exec("select * from user"))
    {
        qDebug()<<"error:"<<query.lastError().text();
    }
    while(query.next())
    {
        ui->user_Combox->addItem(query.value(1).toString());
    }
    query.clear();
    query.exec("select * from task");
    while(query.next())
    {
        ui->task_Combox->addItem(query.value(0).toString());
    }

    query.prepare("SELECT task_path FROM task where task_name=:taskname");
    query.bindValue(":taskname",ui->task_Combox->currentText());
    if(!query.exec())
    {
        qDebug()<<"错误："<<query.lastError().text();
    }
    query.next();

    exePath=query.value(0).toString().split(",");
    // ExePathList=exePath;
    //  qDebug()<<"exePath"<<exePath;
    ui->exePath_comboBox->clear();
    ui->exePath_comboBox->addItems(exePath);

    //
    query.prepare("SELECT  screen_x_y FROM task where task_name=:taskname");
    query.bindValue(":taskname",ui->task_Combox->currentText());
    if(!query.exec())
    {
        qDebug()<<"错误："<<query.lastError().text();
    }
    query.next();
    ExePos=query.value(0).toString().split(",");
  //  qDebug()<<"exePath"<<exePath;
  //  qDebug()<<"exepos"<<ExePos;




}

void TaskWidget::readyRead()
{
    while(m_udp->hasPendingDatagrams())
    {
        QByteArray buffer;
        buffer.resize(m_udp->pendingDatagramSize());
        m_udp->readDatagram(buffer.data(), buffer.size());
        memcpy(&receivedData, buffer.data(), sizeof(ButtonClickEvent));
        qDebug() << receivedData.buttonId << receivedData.hour << receivedData.minute << receivedData.second << receivedData.millisecond;
    }
}

void TaskWidget::on_add_task_clicked()
{
    ui->task_name->clear();
    ui->task_description->clear();
    ui->checkBox_type_left->setChecked(false);

    while (QLayoutItem* item = ui->layout_question->takeAt(0)) {
        if (QWidget* widget = item->widget()) {
            widget->deleteLater();
        }
        delete item;
    }
    ui->layout_question->addStretch();
    while (QLayoutItem* item = ui->layout_Screen->takeAt(0)) {
        if (QWidget* widget = item->widget()) {
            widget->deleteLater();
        }
        delete item;
    }
    ui->layout_Screen->addStretch();

    while (QLayoutItem* item = ui->layout_event->takeAt(0)) {
        if (QWidget* widget = item->widget()) {
            widget->deleteLater();
        }
        delete item;
    }
    ui->layout_event->addStretch();

    ui->buttonSave->show();
    ui->finish_edit->hide();

    ui->stack_widget->setCurrentIndex(1);
}

void TaskWidget::on_buttonReturn_clicked()
{
    if(return_page_flag==MainWindow_CreateTask)
    {
        ui->stack_widget->setCurrentIndex(4);
    }
    else
    {
        ui->stack_widget->setCurrentIndex(0);
    }

}

QString TaskWidget::type_string()
{
    QString string1;
    QString string2;
    if(ui->checkBox_type_left->isChecked())
    {
        string1 = ui->checkBox_type_left->text();
        if(ui->checkBox_left_sub1->isChecked())
        {
            string2 = ui->checkBox_left_sub1->text();
        }
        else if(ui->checkBox_left_sub2->isChecked())
        {
            string2 = ui->checkBox_left_sub2->text();
        }
        else if(ui->checkBox_left_sub3->isChecked())
        {
            string2 = ui->checkBox_left_sub3->text();
        }
        else if(ui->checkBox_left_sub4->isChecked())
        {
            string2 = ui->checkBox_left_sub4->text();
        }
    }
    else
    {
        string1 = ui->checkBox_type_right->text();
        if(ui->checkBox_right_sub1->isChecked())
        {
            string2 = ui->checkBox_right_sub1->text();
        }
        else if(ui->checkBox_right_sub2->isChecked())
        {
            string2 = ui->checkBox_right_sub2->text();
        }
        else if(ui->checkBox_right_sub3->isChecked())
        {
            string2 = ui->checkBox_right_sub3->text();
        }
        else if(ui->checkBox_right_sub4->isChecked())
        {
            string2 = ui->checkBox_right_sub4->text();
        }
    }

    return string1 + "-" + string2;
}

void TaskWidget::on_buttonSave_clicked()
{
    Trigger_TimeList.clear();
    ScreenImportItemInfo *s_ScreenImportItemInfo =new ScreenImportItemInfo;
    // 假设 layout_Screen 是一个 QLayout 指针，指向你想要打印内容的布局

    // 遍历布局中的所有子项
    for (int i = 0; i < ui->layout_Screen->count(); ++i) {
        // 获取布局项
        QLayoutItem* item = ui->layout_Screen->itemAt(i);

        // 检查布局项是否存在
        if (item) {
            // 检查布局项是否包含一个 widget
            if (QWidget* widget = item->widget()) {
                // 如果 widget 是一个自定义类型，比如 ScreenImportItem，
                // 你可以将其转换为正确的类型并调用自定义的方法来获取信息
                if (ScreenImportItem* screenItem = qobject_cast<ScreenImportItem*>(widget)) {
                    // 假设 ScreenImportItem 有一个方法叫做 getScreenPath() 来获取路径
                    s_ScreenImportItemInfo->path.append(screenItem->ScreenPath());
                    s_ScreenImportItemInfo->x.append(screenItem->GetX());
                    s_ScreenImportItemInfo->y.append(screenItem->GetY());

                }
            }
        } else {
            // 如果 item 为 nullptr，则说明该位置的内容已被删除
            qDebug() << "Index" << i << "is empty.";
        }
    }
    QStringList ScreenPathList;
    QStringList ScreenPosX_PosY;
    QString PosX_PosY;
    QStringList PosX_PosYList;
    QString PathListString;
    for (int i = 0; i <s_ScreenImportItemInfo->x.size() ; ++i) {
        ScreenPosX_PosY.clear();
        ScreenPathList.append(s_ScreenImportItemInfo->path[i]);
        PosX_PosY=QString::number(s_ScreenImportItemInfo->x[i])+"-"+QString::number(s_ScreenImportItemInfo->y[i]);
        PosX_PosYList.append(PosX_PosY);


    }

    PosX_PosY=PosX_PosYList.join(",");
    PathListString= ScreenPathList.join(",");
    qDebug()<<PosX_PosY<<PathListString;







    QStringList task_questionnaire_list;
    QStringList trigger_questionnaire_list;
    for(int i=0; i<ui->layout_question->count(); i++)
    {
        QLayoutItem* item = ui->layout_question->itemAt(i);
        if (!item) continue;

        QWidget* widget = item->widget();
        if (widget)
        {
            QuestionItem* questionItem = qobject_cast<QuestionItem*>(widget);
            if (questionItem)
            {
                task_questionnaire_list << questionItem->task_questionnaire();
                trigger_questionnaire_list << QString::number(questionItem->trigger_questionnaire());
            }
        }
    }

    QStringList task_event_list;
    QStringList trigger_event_list;
    for(int i=0; i<ui->layout_event->count(); i++)
    {
        QLayoutItem* item = ui->layout_event->itemAt(i);
        if (!item) continue;

        QWidget* widget = item->widget();
        if (widget)
        {
            EventItem* eventItem = qobject_cast<EventItem*>(widget);
            if (eventItem)
            {
                task_event_list << eventItem->task_event();
                trigger_event_list << eventItem->trigger_event();
            }
        }
    }
    emit getTriggerTime();


    QSqlQuery query;
    QString str = QString("INSERT INTO task (task_name, create_name, create_time, task_description, task_type, task_path, task_questionnaire, task_event, trigger_questionnaire, trigger_event ,screen_x_y ,incentive,trigger_time) "
                          "VALUES ('%1', '%2', '%3', '%4', '%5', '%6', '%7', '%8', '%9', '%10', '%11' ,'%12','%13');")
                      .arg(ui->task_name->text())
                      .arg("小菜无敌")
                      .arg(QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss")) // 确保这个值被单引号括起来
                      .arg(ui->task_description->toPlainText())
                      .arg(type_string())
                      .arg(PathListString)
                      .arg(task_questionnaire_list.join(','))
                      .arg(task_event_list.join(','))
                      .arg(trigger_questionnaire_list.join(','))
                      .arg(trigger_event_list.join(','))
                      .arg(PosX_PosY)
                      .arg(ui->JLList_Combox->currentText())
                      .arg(TriggerTime());

    if(!query.exec(str))
    {
        qDebug()<<"error:"<<query.lastError().text();
    }


    TaskListItem *taskListItem = new TaskListItem(this);
    connect(taskListItem, &TaskListItem::task_start, this, &TaskWidget::task_start);
    connect(this,&TaskWidget::SendStartFlag, taskListItem, &TaskListItem::RecvStartFlag);
    connect(taskListItem, &TaskListItem::task_edit, this, &TaskWidget::task_edit);
    connect(taskListItem, &TaskListItem::task_delete, this, &TaskWidget::task_delete);
    connect(taskListItem, &TaskListItem::TaskSelect, this, [=](QString name)
            {

                ui->task_Combox->setCurrentText(name);
                ui->stack_widget->setCurrentIndex(4);
            });
    taskListItem->set_task_name(ui->task_name->text());
    taskListItem->set_create_name("小菜无敌");
    taskListItem->set_create_time(QDateTime::currentDateTime());
    taskListItem->set_task_description(ui->task_description->toPlainText());
    ui->taskListLayout->insertWidget(0, taskListItem);
    //  taskListItem->setTrigger_Time(timeStr);
    ui->stack_widget->setCurrentIndex(0);
    initUserComboxAndTaskCombox();


}

void TaskWidget::on_config_clicked()
{
    return_page_flag=TaskWidget_Edit;
    ui->stack_widget->setCurrentIndex(2);
}

void TaskWidget::on_addConfig_clicked()
{
    ui->stack_widget->setCurrentIndex(3);
}

void TaskWidget::on_configSave_clicked()
{
    ui->stack_widget->setCurrentIndex(2);
}

void TaskWidget::on_buttonBack_clicked()
{
    if(return_page_flag==TaskWidget_Edit)
    {
        ui->stack_widget->setCurrentIndex(1);
    }
    else if(return_page_flag==MainWindow_Title)
    {
        ui->stack_widget->setCurrentIndex(0);
    }
}

void TaskWidget::on_buttonOpen_clicked()
{
    m_exePath = QFileDialog::getOpenFileName(this, "选择可执行文件", "./", "可执行文件 (*.exe);;所有文件 (*)");
}

void TaskWidget::on_add_question_clicked()
{
    QuestionItem *item = new QuestionItem;
    item->setNameIndex(1 + m_question_item_count);
    ui->layout_question->insertWidget(1 + m_question_item_count, item);
    m_question_item_count++;
}

void TaskWidget::on_add_event_clicked()
{
    EventItem *item = new EventItem;
    connect(this,&TaskWidget::getTriggerTime,item,&EventItem::getTriggerTime);
    connect(item, &EventItem::requestDeletion, this, [item](){
        item->deleteLater();
    });
    ui->layout_event->addWidget(item);
    //  m_event_item_count++;
}

void TaskWidget::on_task_return_clicked()
{
    ui->stack_widget->setCurrentIndex(0);

    ui->ffmpeg_widget->stop_preview();
}

void TaskWidget::on_task_finish_clicked()
{
    QMessageBox::StandardButton reply;
    QString startMessage="确定结束任务："+ui->task_Combox->currentText();
    reply = QMessageBox::question(nullptr, "确认删除", startMessage,
                                  QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        ui->task_finish->setEnabled(false);
        ui->user_Combox->setEnabled(true);
        ui->task_Combox->setEnabled(true);
        ui->TaskConfig->setEnabled(true);
        for (int i = 0; i < ui->taskListLayout->count(); ++i) {
            // 获取布局中的子项
            QLayoutItem* layoutItem = ui->taskListLayout->itemAt(i);
            if (layoutItem) {
                QWidget* widget = layoutItem->widget();
                if (widget) {
                    // 检查这个子项是否是 TaskListItem 的实例
                    TaskListItem* taskListItem = qobject_cast<TaskListItem*>(widget);
                    if (taskListItem) {
                        taskListItem->setLabel("选择任务");
                        taskListItem->RecvStartFlag(false);
                    }
                }
            }
        }


        ui->StartTask_btn->setText("开始任务");

        m_task_timer->stop();
        ui->timeEdit->setTime(QTime(0,0,0,0));

        if (process.state() == QProcess::Running)
        {
            process.terminate();
            process.waitForFinished(3000);
        }

        ui->ffmpeg_widget->stop_preview();

    } else {
        // 用户选择了“否”，取消删除操作
    }


}

void TaskWidget::on_checkBox_type_left_clicked()
{
    ui->widget_type_left->show();
    ui->widget_type_right->hide();
}

void TaskWidget::on_checkBox_type_right_clicked()
{
    ui->widget_type_left->hide();
    ui->widget_type_right->show();
}


void TaskWidget::on_return_JL_btn_clicked()
{

    ui->stack_widget->setCurrentIndex(2);
    // 假设layout是QVBoxLayout或其他类型的布局
    QLayout* layout = ui->configListLayout;

    // 从布局中移除所有项
    while (layout->count()) {
        QLayoutItem* item = layout->takeAt(0);
        if (item->widget()) {
            delete item->widget(); // 删除控件
        }
        delete item; // 删除布局项
    }

    init_JL_List();
}


void TaskWidget::on_bind_btn_clicked()
{
    if(ui->port_Edit->text().isEmpty())
    {
        QMessageBox::information(this,"提示","ip和端口号不能为空");
        return ;
    }

    // 检查是否已经绑定
    if(FZFlag)
    {
        return ;
    }
    if (m_recvFZ->state() == QAbstractSocket::BoundState) {
        QMessageBox::information(this, "提示", "端口已经绑定，无需重复绑定");
        return;
    }

    // 尝试绑定端口
    if (!m_recvFZ->bind(QHostAddress::AnyIPv4,ui->port_Edit->text().toInt(), QUdpSocket::ShareAddress) || !m_recvFZ->joinMulticastGroup(QHostAddress(ui->ip_Edit->text()))) {
        QMessageBox::information(this,"提示","绑定端口号失败,加入组播失败");
        return ;
    } else {
        QMessageBox::information(this,"提示","成功绑定端口号,加入组播成功");
        FZFlag=true;
    }

}

void TaskWidget::handleReadyRead()
{
    if (receivingEnabled) {
        while (m_recvFZ->hasPendingDatagrams())
        {
            QNetworkDatagram datagram = m_recvFZ->receiveDatagram();
            QByteArray receivedData = datagram.data();

            m_recvFZ->writeDatagram(receivedData, QHostAddress("239.0.0.1"), 11111);
        } }
}

QStringList TaskWidget::getJsonFilenames(const QDir &directory)
{
    QStringList jsonFilenames;
    QStringList filters;
    filters << "*.json"; // 过滤器，只选取json文件

    // 获取目录下所有.json文件的文件名
    QFileInfoList fileInfoList = directory.entryInfoList(filters, QDir::Files | QDir::NoDotAndDotDot | QDir::Readable);
    for (const QFileInfo &fileInfo : fileInfoList) {
        jsonFilenames.append(fileInfo.fileName());
    }

    return jsonFilenames;
}

void TaskWidget::init_JL_List()
{
    // 获取当前可执行文件的位置
    QString appFilePath = QCoreApplication::applicationFilePath();
    QFileInfo appFileInfo(appFilePath);

    // 获取可执行文件的目录
    QString appDirPath = appFileInfo.absoluteDir().absolutePath();

    // 使用QDir来获取项目根目录（假设可执行文件位于项目目录下的某个子目录中）
    QDir projectDir1(appDirPath);
    projectDir1.cdUp(); // 跳转到项目目录

    // 构建激励配置文件夹的路径
    QString configFolderPath = projectDir1.absolutePath() + QDir::separator() + "激励配置";

    // 输出配置文件夹路径
    qDebug() << "Configuration folder path:" << configFolderPath;




    QDir projectDir(configFolderPath);
    // 移动到上一层目录
    QStringList jsonFilenames = getJsonFilenames(projectDir);

    // 输出JSON文件名列表
    for (const QString &filename : jsonFilenames) {
        ConfigListItem *item = new ConfigListItem(this);
        connect(item,&ConfigListItem::Send_JL_Json_Name,this,[=](QString name)
                {
                    m_DynamicDataWidget->loadDataFromFile2(name);
                    ui->stack_widget->setCurrentIndex(3);
                });
        connect(item,&ConfigListItem::Send_JL_Del,this,[=](QString name)
                {
                    QStringList jsonFiles = findJsonFiles(projectDir);

                    // 假设您要删除的JSON文件名为1.json
                    QString fileNameToDelete = name;

                    // 检查JSON文件列表中是否包含1.json
                    for (const QString &filePath : jsonFiles) {
                        QString fileName = filePath.split('/').last(); // 获取最后一个文件名
                        if (fileName == fileNameToDelete) {
                            // 删除1.json文件
                            deleteJsonFile(fileNameToDelete, projectDir);
                            break; // 找到并删除后，退出循环
                        }
                    }
                    on_return_JL_btn_clicked();
                });
        item->setJLName(filename);
        ui->JLList_Combox->addItem(filename);
        ui->configListLayout->addWidget(item);
    }
    ui->configListLayout->addStretch();
}

QStringList TaskWidget::findJsonFiles(const QDir &directory)
{
    QStringList jsonFiles;

    // 获取目录下的所有文件和文件夹
    QFileInfoList entries = directory.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot);

    // 遍历目录树，查找所有JSON文件
    for (const QFileInfo &entry : entries) {
        if (entry.isFile() && entry.suffix() == "json") {
            // qDebug()<<entry.filePath();
            jsonFiles.append(entry.filePath());
        }
    }

    return jsonFiles;
}

void TaskWidget::deleteJsonFile(const QString &fileName, const QDir &directory)
{
    QString filePath = directory.filePath(fileName);
    // qDebug()<<filePath;
    QFile file(filePath);
    if (file.remove()) {
        qDebug() << "JSON文件已删除：" << filePath;
    } else {
        qDebug() << "删除JSON文件失败：" << filePath;
    }
}

void TaskWidget::setReceivingEnabled(bool enabled)
{
    qDebug()<<"仿真激励"<<enabled;
    receivingEnabled = enabled;
}

void TaskWidget::ToJLConfig()
{
    return_page_flag=MainWindow_Title;
    ui->stack_widget->setCurrentIndex(3);
}



QStringList task_event_list;
QStringList trigger_event_list;
void TaskWidget::on_OpenExe_btn_clicked()
{
    QString relativePath;
    // 弹出对话框让用户选择 .exe 文件
    QString baseDirectory = QDir::currentPath(); // 设置基目录
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Select .exe File"),
                                                    baseDirectory,
                                                    tr("Executable (*.exe)"));

    if (!fileName.isEmpty()) {
        // 将绝对路径转换为相对路径
        relativePath = QFileInfo(fileName).canonicalFilePath().remove(0, baseDirectory.length() + 1);

        // 打印相对路径
        qDebug() << "Relative path: " << relativePath;
    }





    ScreenImportItem* item =new ScreenImportItem(this);

    ui->layout_Screen->addWidget(item);
    item->setScreenPath(relativePath);
}


void TaskWidget::on_SetPosition_btn_clicked()
{

}

void TaskWidget::on_SetPosition_btn_clicked2()
{

}


void TaskWidget::on_CloseExe_btn__clicked()
{
    emit closeExe();
}

void TaskWidget::on_finish_edit_clicked()
{
    Trigger_TimeList.clear();
    ScreenImportItemInfo *s_ScreenImportItemInfo =new ScreenImportItemInfo;
    // 假设 layout_Screen 是一个 QLayout 指针，指向你想要打印内容的布局

    // 遍历布局中的所有子项
    for (int i = 0; i < ui->layout_Screen->count(); ++i) {
        // 获取布局项
        QLayoutItem* item = ui->layout_Screen->itemAt(i);

        // 检查布局项是否存在
        if (item) {
            // 检查布局项是否包含一个 widget
            if (QWidget* widget = item->widget()) {
                // 如果 widget 是一个自定义类型，比如 ScreenImportItem，
                // 你可以将其转换为正确的类型并调用自定义的方法来获取信息
                if (ScreenImportItem* screenItem = qobject_cast<ScreenImportItem*>(widget)) {
                    // 假设 ScreenImportItem 有一个方法叫做 getScreenPath() 来获取路径
                    s_ScreenImportItemInfo->path.append(screenItem->ScreenPath());
                    s_ScreenImportItemInfo->x.append(screenItem->GetX());
                    s_ScreenImportItemInfo->y.append(screenItem->GetY());

                }
            }
        } else {
            // 如果 item 为 nullptr，则说明该位置的内容已被删除
            qDebug() << "Index" << i << "is empty.";
        }
    }
    QStringList ScreenPathList;
    QString PosX_PosY;
    QStringList PosX_PosYList;
    QString PathListString;
    for (int i = 0; i <s_ScreenImportItemInfo->x.size() ; ++i)
    {
        ScreenPathList.append(s_ScreenImportItemInfo->path[i]);
        PosX_PosY=QString::number(s_ScreenImportItemInfo->x[i])+"-"+QString::number(s_ScreenImportItemInfo->y[i]);
        PosX_PosYList.append(PosX_PosY);


    }

    PosX_PosY=PosX_PosYList.join(",");
    PathListString= ScreenPathList.join(",");
    qDebug()<<PosX_PosY<<PathListString;

    QStringList task_questionnaire_list;
    QStringList trigger_questionnaire_list;
    for(int i=0; i<ui->layout_question->count(); i++)
    {
        QLayoutItem* item = ui->layout_question->itemAt(i);
        if (!item) continue;

        QWidget* widget = item->widget();
        if (widget)
        {
            QuestionItem* questionItem = qobject_cast<QuestionItem*>(widget);
            if (questionItem)
            {
                task_questionnaire_list << questionItem->task_questionnaire();
                trigger_questionnaire_list << QString::number(questionItem->trigger_questionnaire());
            }
        }
    }

    QStringList task_event_list;
    QStringList trigger_event_list;
    for(int i=0; i<ui->layout_event->count(); i++)
    {
        QLayoutItem* item = ui->layout_event->itemAt(i);
        if (!item) continue;

        QWidget* widget = item->widget();
        if (widget)
        {
            EventItem* eventItem = qobject_cast<EventItem*>(widget);
            if (eventItem)
            {
                task_event_list << eventItem->task_event();
                trigger_event_list << eventItem->trigger_event();
            }
        }
    }
    emit getTriggerTime();

    QSqlQuery query;
    QString task_name = ui->task_name->text();
    QString str = QString("UPDATE task "
                          "SET create_name = '%1', create_time = '%2', "
                          "task_description = '%3', task_type = '%4', task_path = '%5', "
                          "task_questionnaire = '%6', task_event = '%7', "
                          "trigger_questionnaire = '%8', trigger_event = '%9' , screen_x_y = '%10' , incentive = '%11', trigger_time= '%12'"
                          "WHERE task_name = '%13';")
                      .arg("小菜无敌")
                      .arg(QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss"))  // 更新时间
                      .arg(ui->task_description->toPlainText())                           // 更新任务描述
                      .arg(type_string())                                                 // 更新任务类型
                      .arg(PathListString)                                                     // 更新任务路径
                      .arg(task_questionnaire_list.join(','))                             // 更新问卷列表
                      .arg(task_event_list.join(','))                                     // 更新事件列表
                      .arg(trigger_questionnaire_list.join(','))                          // 更新触发问卷列表
                      .arg(trigger_event_list.join(','))                                  // 更新触发事件列表
                      .arg(PosX_PosY)
                      .arg(ui->JLList_Combox->currentText())
                      .arg(TriggerTime())
                      .arg(task_name);                                                    // 指定更新的任务名
    if (!query.exec(str)) {
        qDebug() << "Update failed: " << query.lastError();
    } else {
        int rowsAffected = query.numRowsAffected();
        if (rowsAffected > 0) {
            qDebug() << "Update successful, rows affected: " << rowsAffected;
        } else {
            qDebug() << "No rows updated, check your WHERE clause.";
        }
    }

    for(int i=0; i<ui->taskListLayout->count(); i++)
    {
        QLayoutItem* item = ui->taskListLayout->itemAt(i);
        if (!item) continue;

        QWidget* widget = item->widget();
        if (widget)
        {
            TaskListItem* taskListItem = qobject_cast<TaskListItem*>(widget);
            if (taskListItem)
            {
                if(taskListItem->task_name() == ui->task_name->text())
                {
                    taskListItem->set_create_name("小菜无敌");
                    taskListItem->set_create_time(QDateTime::currentDateTime());
                    taskListItem->set_task_description(ui->task_description->toPlainText());
                    break;
                }
            }
        }
    }

    ui->stack_widget->setCurrentIndex(0);

}
void TaskWidget::on_StartJL_btn_clicked()
{
    if(JLFlag==1)
    {
        m_DynamicDataWidget->startSendingData();
        ui->JLFlag->setText("已开启激励数据驱动");
        FZFlag=false;
    }
    else if(JLFlag==2)
    {
        m_DynamicDataWidget->onPauseButtonClicked();
        on_bind_btn_clicked();
        setReceivingEnabled(true);
        ui->JLFlag->setText("已开启激励数据驱动");

    }
    else
    {

    }
}


void TaskWidget::on_StopJL_btn_clicked()
{
    if(JLFlag==1)
    {
        m_DynamicDataWidget->onPauseButtonClicked();
        ui->JLFlag->setText("未开启激励数据驱动");

    }
    else if(JLFlag==2)
    {
        ui->JLFlag->setText("未开启激励数据驱动");
        setReceivingEnabled(false);


    }
    else
    {

    }


}


void TaskWidget::on_JL_Combox_activated(int index)
{
    JLFlag=index;
}


void TaskWidget::on_StartTask_btn_clicked()
{
    QMessageBox::StandardButton reply;
    QString startMessage="确定开始任务："+ui->task_Combox->currentText();
    reply = QMessageBox::question(nullptr, "开始任务", startMessage,
                                  QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        ui->task_finish->setEnabled(true);
        ui->user_Combox->setEnabled(false);
        ui->task_Combox->setEnabled(false);
        emit SendStartFlag(true);
        for (int i = 0; i < ui->taskListLayout->count(); ++i) {
            // 获取布局中的子项
            QWidget* widget = ui->taskListLayout->itemAt(i)->widget();

            // 检查这个子项是否是 TaskListItem 的实例
            if (TaskListItem* taskListItem = qobject_cast<TaskListItem*>(widget)) {
                // 调用 task_name() 方法获取任务名
                QString currentTaskName = taskListItem->task_name();

                // 比较任务名
                if (currentTaskName == ui->task_Combox->currentText()) {

                    taskListItem->setLabel("任务进行中");
                    taskListItem->RecvStartFlag(false);
                    break;
                }
            }
        }



        if(ui->StartTask_btn->text()=="开始任务")
        {
            m_task_timer->start(1000);
        }
        else if(ui->StartTask_btn->text()=="暂停任务")
        {
            m_task_timer->stop();
        }
        else
        {
            m_task_timer->start(1000);
        }
        ui->StartTask_btn->setText(ui->StartTask_btn->text()=="暂停任务" ? "继续任务" : "暂停任务");


        emit startTask(); //还没用上
    } else {
        // 用户选择了“否”，取消删除操作
    }




}

void TaskWidget::onCheckBoxToggled(bool checked)
{
    QCheckBox *senderCheckBox = qobject_cast<QCheckBox *>(sender());
    if (!senderCheckBox) return;

    // 如果当前复选框被选中
    if (checked) {
        if (senderCheckBox == ui->checkBox_1) {
            JLFlag = 1;
        } else if (senderCheckBox == ui->checkBox_2) {
            JLFlag = 2;
        } else if (senderCheckBox == ui->checkBox_3) {
            JLFlag = 3;
        }

        // 取消其他复选框的选中状态
        if (senderCheckBox != ui->checkBox_1)
            ui->checkBox_1->setChecked(false);
        if (senderCheckBox != ui->checkBox_2)
            ui->checkBox_2->setChecked(false);
        if (senderCheckBox != ui->checkBox_3)
            ui->checkBox_3->setChecked(false);

        qDebug() << "Selected JLFlag:" << JLFlag; // 输出调试信息
    }
}



void TaskWidget::on_SetPosition_btn_2_clicked()
{




    QString filePath = ui->exePath_comboBox->currentText();

    // 使用 QFileInfo 提取文件名
    QFileInfo fileInfo(filePath);
    QString fileName = fileInfo.fileName(); // 仅提取文件名

    // 打印或处理文件名
    qDebug() << "文件路径:" << filePath;
    qDebug() << "文件名:" << fileName;

    dialog =new CoordinateDialog(fileName,this);
    connect(this,&TaskWidget::closeExe,dialog,&CoordinateDialog::closeExe);

    int index = exePath.indexOf(ui->exePath_comboBox->currentText());
    qDebug()<<index;
    QString exePos=ExePos[index];
    QStringList list=exePos.split("-");
    dialog->setX(list[0].toInt());
    dialog->setY(list[1].toInt());



    dialog->show();


}


void TaskWidget::on_CloseExe_btn_1_clicked()
{
    emit closeExe();
}


void TaskWidget::on_TaskConfig_clicked()
{
    ui->return_btn->setVisible(true);
    ui->stack_widget->setCurrentIndex(0);
}


void TaskWidget::on_return_Task_btn_clicked()
{
    if(return_page_flag==TaskWidget_Edit)
    {
        ui->stack_widget->setCurrentIndex(1);
    }
    else if(return_page_flag==MainWindow_Title)
    {
        ui->stack_widget->setCurrentIndex(0);
    }
    else if(return_page_flag==MainWindow_CreateTask)
    {
        ui->stack_widget->setCurrentIndex(4);
    }

}





void TaskWidget::on_task_Combox_currentTextChanged(const QString &arg1)
{
    QSqlQuery query;
    query.prepare("SELECT task_path FROM task where task_name=:taskname");
    query.bindValue(":taskname",arg1);
    if(!query.exec())
    {
        qDebug()<<"错误："<<query.lastError().text();
    }
    query.next();

    QStringList exePath=query.value(0).toString().split(",");
  //  qDebug()<<"eexepath:"<<exePath;
    ui->exePath_comboBox->clear();
    if (!exePath.isEmpty()) {
        ui->exePath_comboBox->addItems(exePath);
    } else {
        qDebug() << "exePath is empty. Cannot add items to comboBox.";
    }

    //

    query.prepare("SELECT  screen_x_y FROM task where task_name=:taskname");
    query.bindValue(":taskname",ui->task_Combox->currentText());
    if(!query.exec())
    {
        qDebug()<<"错误："<<query.lastError().text();
    }
    query.next();
    ExePos=query.value(0).toString().split(",");
  //  qDebug()<<"exePath"<<exePath;
  //  qDebug()<<"exepos"<<ExePos;
}



void TaskWidget::on_create_task_clicked()
{
    return_page_flag=MainWindow_CreateTask;
    ui->task_name->clear();
    ui->task_description->clear();
    ui->checkBox_type_left->setChecked(false);

    while (QLayoutItem* item = ui->layout_question->takeAt(0)) {
        if (QWidget* widget = item->widget()) {
            widget->deleteLater();
        }
        delete item;
    }
    ui->layout_question->addStretch();
    while (QLayoutItem* item = ui->layout_Screen->takeAt(0)) {
        if (QWidget* widget = item->widget()) {
            widget->deleteLater();
        }
        delete item;
    }
    ui->layout_Screen->addStretch();

    while (QLayoutItem* item = ui->layout_event->takeAt(0)) {
        if (QWidget* widget = item->widget()) {
            widget->deleteLater();
        }
        delete item;
    }
    ui->layout_event->addStretch();

    ui->buttonSave->show();
    ui->finish_edit->hide();

    ui->stack_widget->setCurrentIndex(1);
}


void TaskWidget::on_return_btn_clicked()
{
    ui->stack_widget->setCurrentIndex(4);
    ui->return_btn->setVisible(true);
}

