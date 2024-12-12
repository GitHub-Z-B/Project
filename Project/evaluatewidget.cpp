#include "evaluatewidget.h"
#include "ui_evaluatewidget.h"
#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include <QCheckBox>

#include <QSqlError>
EvaluateWidget::EvaluateWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EvaluateWidget)
{
    ui->setupUi(this);
    ui->rightStackedWidget->setCurrentIndex(1);
    ui->tabWidget_2->setCurrentIndex(0);
    ui->stackedWidget_3->setCurrentIndex(0);

    connect(ui->analysis_btn, &QPushButton::clicked, this, &EvaluateWidget::analysisButtonClicked);

    m_VerticalBarChart = new VerticalBarChart();
    ui->BarChart_layout->addWidget(m_VerticalBarChart);

    m_EvaluationAlgorithms = new EvaluationAlgorithms();
    ui->algorithms_layout->addWidget(m_EvaluationAlgorithms);


    SetcurrentperformanceTable();
}

EvaluateWidget::~EvaluateWidget()
{
    delete ui;
}

void EvaluateWidget::on_pushButton_1_clicked()
{
    ui->rightStackedWidget->setCurrentIndex(0);
}

void EvaluateWidget::on_pushButton_2_clicked()
{
    ui->rightStackedWidget->setCurrentIndex(1);
}

void EvaluateWidget::on_pushButton_3_clicked()
{
    ui->rightStackedWidget->setCurrentIndex(2);
}

void EvaluateWidget::on_detail_clicked()
{
    ui->stackedWidget_3->setCurrentIndex(1);
}

void EvaluateWidget::on_export_word_clicked()
{
    QString filePath = QFileDialog::getSaveFileName(nullptr, "Save as Word", "", "Doc Files (*.doc)");
    if (!filePath.isEmpty())
    {
        QWidget* contentWidget = ui->scrollAreaContent;

        // 创建一个 QPixmap 大小为内容部件的大小
        QPixmap pixmap(contentWidget->size());
        pixmap.fill(Qt::white); // 填充背景为白色（可选）
        // 渲染内容部件到 QPixmap
        contentWidget->render(&pixmap);
        // 保存 QPixmap 为 PNG 文件
        pixmap.save("pixmap.png");

        QString imgPath("pixmap.png");

        QString html;
        //文字部分
        QDateTime current_date_time = QDateTime::currentDateTime();
        QString current_date = current_date_time.toString("yyyy-MM-dd hh:mm:ss ddd");
        html += "<h2 align=\"center\">任务综合评估报告</h2>";
        html += "<h4 align=\"center\">" + current_date + "</h2><br>";
        //图片部分
        html += "<img align=\"middle\" src = \"" + imgPath + "\"  width=\"600\" height=\""+ QString::number(pixmap.height()) + "\"/><br>" ;

        QFile outFile(filePath);
        outFile.open(QIODevice::WriteOnly | QIODevice::Append );
        QTextStream ts(&outFile);
        ts << html;
        outFile.close();
    }
}

void EvaluateWidget::on_export_pdf_clicked()
{
    QString filePath = QFileDialog::getSaveFileName(nullptr, "Save as PDF", "", "PDF Files (*.pdf)");
    if (!filePath.isEmpty())
    {
        QWidget* contentWidget = ui->scrollAreaContent;

        // 设置 PDF 文件写入器
        QPdfWriter pdfWriter(filePath);
        pdfWriter.setPageSize(QPageSize(QPageSize::A4)); // 设置为 A4 纸张大小
        pdfWriter.setResolution(300); // 设置分辨率
        QPainter painter(&pdfWriter);

        // 获取内容的总大小和页面的绘制区域大小
        QSize contentSize = contentWidget->size();
        QRect pdfPageRect = pdfWriter.pageLayout().paintRectPixels(pdfWriter.resolution());

        // 计算缩放比例（等比缩放）
        qreal scaleFactor = qMin(
            pdfPageRect.width() / static_cast<qreal>(contentSize.width()),
            pdfPageRect.height() / static_cast<qreal>(contentSize.height())
            );

        // 渲染内容到 PDF，保持等比缩放并靠上对齐
        int yOffset = 0;
        while (yOffset < contentSize.height())
        {
            QRect partRect(0, yOffset, contentSize.width(), pdfPageRect.height() / scaleFactor);

            // 截取当前页的内容
            QPixmap pagePixmap(contentSize);
            contentWidget->render(&pagePixmap, QPoint(0, -yOffset)); // 渲染内容到 Pixmap
            QPixmap currentPage = pagePixmap.copy(partRect);

            // 计算靠上对齐的目标矩形
            QSize scaledSize = QSize(
                static_cast<int>(contentSize.width() * scaleFactor),
                static_cast<int>(contentSize.height() * scaleFactor)
                );
            QRectF targetRect(
                0, // 左对齐
                0, // 上对齐，留白在下方
                scaledSize.width(),
                scaledSize.height()
                );

            // 缩放并绘制到 PDF 页面
            painter.drawPixmap(targetRect, currentPage, QRectF(0, 0, currentPage.width(), currentPage.height()));

            yOffset += partRect.height();
            if (yOffset < contentSize.height()) {
                pdfWriter.newPage(); // 创建新页面
            }
        }

        painter.end();
    }
}

void EvaluateWidget::on_analyze_clicked()
{
    ui->stackedWidget_3->setCurrentIndex(2);
}

void EvaluateWidget::on_subjective_return_clicked()
{
    ui->stackedWidget_3->setCurrentIndex(1);
}
//设置客观评估表格
void EvaluateWidget::SetPerformanceTable()
{
    int row = 0;
    int tsaksucessrow=0;
    int timerow=0;
    float taskcount = 0;
    float tasksucesscount = 0;
    float taskerror = 0;
    float tasksucess = 0;

    QSqlQuery query;
    query.prepare("SELECT * FROM result");
    InsertCombobox(query);
    if(!query.exec())
    {
        qDebug()<<"error:"<<query.lastError().text();
    }

    QDateTime starttime;
    QDateTime endtime;
    QDateTime taskstarttime;
    while(query.next())
    {

        foreach (const QString &item,query.value("UserId").toString())
        {
            // 用户id
            if (!UserIddata.contains(query.value("UserId").toString()))
            {
                UserIddata.append(query.value("UserId").toString());
            }
        }
        foreach (const QString &item,query.value("TaskSub").toString()) {
            // 任务类型
            if (!TaskSubdata.contains(query.value("TaskSub").toString()))
            {
                TaskSubdata.append(query.value("TaskSub").toString());
            }
        }
        foreach (const QString &item,query.value("Id").toString()) {
            // 任务名称
            if (!UserNamedata.contains(query.value("Id").toString()))
            {
                UserNamedata.append(query.value("Id").toString());
            }
        }

        taskcount++;
        if(query.value("Flag").toUInt()==1)
        {
            tasksucesscount++;
        }

        if(query.value("Start_End").toString()=="1")
        {
            tasksucess=tasksucesscount/taskcount;
            taskerror=(taskcount-tasksucesscount)/taskcount;

            QTableWidgetItem *errorRateItem = new QTableWidgetItem(QString::number(taskerror)+"%");
            ui->performance_Table->setItem(tsaksucessrow, 5, errorRateItem);
            Errorrate.append(QString::number(taskerror)+"%");

            QTableWidgetItem *ErrorrateData = new QTableWidgetItem(Errorrate.last());;
            ui->currentperformance_table->setItem(1,1,ErrorrateData);

            tsaksucessrow++;
            tasksucess=0;
            tasksucesscount=0;
            taskcount=0;
        }

        //只取第一行
        if(query.value("Start_End").toString()=="0")
        {
            ui->performance_Table->insertRow(row);

            QTableWidgetItem *idItem = new QTableWidgetItem(query.value("Id").toString());

            ui->performance_Table->setItem(row, 1, idItem);
            ui->performance_Table->setColumnWidth(0,20);

            QTableWidgetItem *UserItem = new QTableWidgetItem(query.value("NumFlag").toString());
            ui->performance_Table->setItem(row, 2, UserItem);

            ui->User_label->setText(query.value("NumFlag").toString());

            QTableWidgetItem *taskNameItem = new QTableWidgetItem(query.value("TaskType").toString());
            ui->performance_Table->setItem(row, 3, taskNameItem);

            ui->Task_label->setText(query.value("TaskType").toString());
            QTableWidgetItem *taskTypeItem = new QTableWidgetItem(query.value("TaskSub").toString());
            ui->performance_Table->setItem(row, 4, taskTypeItem);

            QTableWidgetItem *completionTimeItem = new QTableWidgetItem(query.value("Time").toString());
            ui->performance_Table->setItem(row, 6, completionTimeItem);

            // time=QTime::fromString(query.value("Time").toString(), "HH:mm:ss.zzz");

            TaskCompletiontime.append(query.value("Time").toString());
            ui->dateTimeEdit_2->setTime(QTime::fromString(query.value("Time").toString(), "HH:mm:ss.zzz"));

            QTableWidgetItem *TaskCompletiontimeData = new QTableWidgetItem(TaskCompletiontime.last());;
            ui->currentperformance_table->setItem(2,1,TaskCompletiontimeData);

            row++;
            starttime=QDateTime::fromString(query.value("Time").toString(), "HH:mm:ss.zzz");

            //  QTableWidgetItem *SucessrateData = new QTableWidgetItem(Sucessrate.last());;
            //  ui->currentperformance_table->setItem(3,1,SucessrateData);
        }

        if(query.value("ControlName").toString()=="开始实验")
        {
            taskstarttime = endtime=QDateTime::fromString(query.value("Time").toString(), "HH:mm:ss.zzz");

        }
        if(query.value("Start_End").toString()=="1")
        {


            endtime=QDateTime::fromString(query.value("Time").toString(), "HH:mm:ss.zzz");
            int secsTo= starttime.secsTo(endtime);

            int secsTotaskstarttime=taskstarttime.secsTo(endtime);
            QTableWidgetItem *totalTimeItem = new QTableWidgetItem(QString::number(secsTo)+"(s)");
            ui->performance_Table->setItem(timerow, 8, totalTimeItem);


            TaskConstTime.append(QString::number(secsTotaskstarttime)+"(s)");

            ConstTime.append(QString::number(secsTo)+"(s)");
            timerow++;

            QTableWidgetItem *ConstTimeData = new QTableWidgetItem(ConstTime.last());;
            ui->currentperformance_table->setItem(0,1,ConstTimeData);

        }
    }

    //QList<QString> Sucessrate;
    for (int row = 0; row <  ui->performance_Table->rowCount(); ++row) {
        // 创建一个新的复选框
        QCheckBox *checkBox = new QCheckBox();
        // 将复选框设置为第一列的单元格小部件
        checkBox->setObjectName("checkBox" + QString::number(row));
        ui->performance_Table->setCellWidget(row, 0, checkBox);
    }
    for(int i=0;i<UserIddata.size();i++)
    {
        ui->userid_comboBox->addItem(UserIddata.at(i));

    }
    for(int i=0;i<UserNamedata.size();i++)
    {
        ui->username_comboBox->addItem(UserNamedata.at(i));
    }
    for(int i=0;i<TaskSubdata.size();i++)
    {
        ui->tasksub_comboBox->addItem(TaskSubdata.at(i));
    }
}

void EvaluateWidget::SetcurrentperformanceTable()
{

    QSqlQuery query;
    query.prepare("SELECT * FROM result");

    if(!query.exec())
    {
        qDebug()<<"error:"<<query.lastError().text();
    }

    // ui->currentperformance_table->insertRow(4);

    QStringList Headerdata;
    Headerdata.append("总操作事件(s)");
    Headerdata.append("操作失误率(%)");
    Headerdata.append("任务完成时间");
    Headerdata.append("任务成功率");

    QStringList Interpretationdata;
    Interpretationdata.append("在本次任务中所有操作时间总和");
    Interpretationdata.append("操作失误的次数占总操作次数百分比");
    Interpretationdata.append("整个任务从开始到结束所用时间");
    Interpretationdata.append("本次任务中成功完成任务占全部任务的百分比");

    for(int row=0;row<4;row++)
    {

        QTableWidgetItem *Header = new QTableWidgetItem(Headerdata.at(row));;
        ui->currentperformance_table->setItem(row,0,Header);

        QTableWidgetItem *Interpretation = new QTableWidgetItem(Interpretationdata.at(row));;
        ui->currentperformance_table->setItem(row,2,Interpretation);
    }

}

void EvaluateWidget::analysisButtonClicked()
{
    int checkedIndex = -1; // 默认索引为-1，表示没有勾选任何checkbox
    QStringList id;
    QList<QString> completionTime;
    QList<QString>  sucess;
    QList<QString>  error;
    // 检查第一列的checkbox是否被勾选

    if(ui->performance_Table->rowCount()!=0)
    {
        for (int row = 0; row < ui->performance_Table->rowCount(); ++row)
        {
            QCheckBox *checkBox = static_cast<QCheckBox*>(ui->performance_Table->cellWidget(row, 0));
            if (checkBox->isChecked())
            {
                checkedIndex = row;
                ui->stackedWidget->setCurrentIndex(2);
                qDebug() << "勾选的索引是：" << checkedIndex;
                //error.append(ui->performance_Table->item(row,5)->text());
                //id.append(ui->performance_Table->item(row,2)->text());
                //sucess.append(ui->performance_Table->item(row,)->text());
                // completionTime.append(ui->performance_Table->item(row,8)->text());


                TaskConstTime.append(QString::number(row));


                id.append(QString::number(row));
                //sucess.append(ui->performance_Table->item(row,)->text());


            }
        }
    }
    // error.append(QString::number(3));
    // error.append(QString::number(3));
    // error.append(QString::number(3));
    // error.append(QString::number(3));
    // error.append(QString::number(3));

    // completionTime.append(QString::number(4));
    // completionTime.append(QString::number(4));
    // completionTime.append(QString::number(4));
    // completionTime.append(QString::number(4));
    // completionTime.append(QString::number(4));
    // completionTime.append(QString::number(4));


    // m_VerticalBarChart->SetcompletionTimeBarChart(id,completionTime,sucess,error);
    // m_VerticalBarChart->initChart(id,completionTime,sucess,error);
    //m_VerticalBarChart->SetResultTable(id,completionTime,sucess,error,TaskConstTime);
    // ui->stackedWidget_2->setCurrentIndex(2);
    ui->stackedWidget_2->setCurrentIndex(3);
    m_EvaluationAlgorithms->setAlgorithms_table(completionTime,sucess,error,TaskConstTime);
}

void EvaluateWidget::InsertCombobox(QSqlQuery query)
{
    while(query.next())
    {

    }
}

void EvaluateWidget::on_performance_btn_clicked()
{
    SetPerformanceTable();

    ui->stackedWidget_2->setCurrentIndex(1);
}


void EvaluateWidget::on_currentperformance_btn_clicked()
{


    ui->stackedWidget_2->setCurrentIndex(0);
}




