#include "tasklistitem.h"
#include "ui_tasklistitem.h"
extern int TaskStartFlag;
TaskListItem::TaskListItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TaskListItem)
{
    ui->setupUi(this);
    ui->label_2->setVisible(false);
    ui->comboBox->setVisible(false);
    ui->task_start->setVisible(false);
}

TaskListItem::~TaskListItem()
{
    delete ui;
}

void TaskListItem::on_task_start_clicked()
{

    qDebug() << __func__ << __FILE__ << __LINE__;
    emit task_start();
}

void TaskListItem::on_task_edit_clicked()
{
    qDebug() << __func__ << __FILE__ << __LINE__;
    emit task_edit();
}

void TaskListItem::on_task_delete_clicked()
{
    qDebug() << __func__ << __FILE__ << __LINE__;
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(nullptr, "确认删除", "您确定要删除这个任务吗？",
                                  QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        // 用户选择了“是”，在这里执行删除操作
        emit task_delete(); // 发出信号，通知其他组件任务已被删除
    } else {
        // 用户选择了“否”，取消删除操作
    }
}

void TaskListItem::set_task_name(QString text)
{
    ui->task_name->setText(text);
}

void TaskListItem::set_create_name(QString text)
{
    ui->create_name->setText(text);
}

void TaskListItem::set_create_time(QDateTime dateTime)
{
    ui->create_time->setDateTime(dateTime);
}

void TaskListItem::set_task_description(QString text)
{
    ui->task_description->setPlainText(text);
}

void TaskListItem::set_task_type(QString task_type)
{
    m_task_type = task_type;
}

void TaskListItem::set_task_path(QString task_path)
{
    m_task_path = task_path;
}

void TaskListItem::set_task_questionnaire(QString task_questionnaire)
{
    m_task_questionnaire = task_questionnaire;
}

void TaskListItem::set_task_event(QString task_event)
{
    m_task_event = task_event;
}

void TaskListItem::set_trigger_questionnaire(QString trigger_questionnaire)
{
    m_trigger_questionnaire = trigger_questionnaire;
}

void TaskListItem::set_trigger_event(QString trigger_event)
{
    m_trigger_event = trigger_event;
}

QString TaskListItem::task_questionnaire() const
{
    return m_task_questionnaire;
}

QString TaskListItem::task_event() const
{
    return m_task_event;
}

QString TaskListItem::trigger_questionnaire() const
{
    return m_trigger_questionnaire;
}

QString TaskListItem::trigger_event() const
{
    return m_trigger_event;
}

void TaskListItem::setPos_X_Y(QString x_y)
{
    this->pos_X_Y=x_y;
}

QString TaskListItem::getPos_X_Y()
{
    return this->pos_X_Y;
}

void TaskListItem::setJL(QString name)
{
    this->JLName=name;
}

QString TaskListItem::JL()
{
    return this->JLName;
}

void TaskListItem::setLabel(QString name)
{
    ui->TaskSelect->setText(name);
}

void TaskListItem::RecvStartFlag(bool flag)
{
    TaskStartFlag=flag;
}



QString TaskListItem::task_name()
{
    return ui->task_name->text();
}

QString TaskListItem::create_name()
{
    return ui->create_name->text();
}

QDateTime TaskListItem::create_time()
{
    return ui->create_time->dateTime();
}

QString TaskListItem::task_description()
{
    return ui->task_description->toPlainText();
}

QString TaskListItem::task_type()
{
    return m_task_type;
}

QString TaskListItem::task_path()
{
    return m_task_path;
}

void TaskListItem::on_TaskSelect_clicked()
{

    if(TaskStartFlag)
    {
        QMessageBox::information(this,"提示","请先结束当前正在运行的任务");
        return ;
    }
    emit TaskSelect(ui->task_name->text());
}

