#include "verticalbarchart.h"
#include "ui_verticalbarchart.h"

VerticalBarChart::VerticalBarChart(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VerticalBarChart)
{
    ui->setupUi(this);

    initBarChart();

}

VerticalBarChart::~VerticalBarChart()
{
    delete ui;
}

void VerticalBarChart::initBarChart()
{
    m_completionTime_chart = new QChart;


}

void VerticalBarChart::SetcompletionTimeBarChart(QStringList id,  QList<QString>  completionTime, QList<QString>  sucess, QList<QString>  error)
{

    bool ok;
    m_completionTime_chart = new QChart;
    m_completionTime_chart->legend()->setVisible(false);
    m_completionTime_chart->setTitle("完成时间柱状图");

    QChartView* chartView = new QChartView(this);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setChart(m_completionTime_chart);

    //加入到主界面中
    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(chartView);
    layout->setSizeConstraint(QLayout::SetNoConstraint);
    ui->VerticalBar_widget->setLayout(layout);

    //设置X轴
    QBarCategoryAxis* category_axis_x = new QBarCategoryAxis(m_completionTime_chart);
    m_completionTime_chart->addAxis(category_axis_x, Qt::AlignBottom);

    //设置X轴标签
    QStringList categories;
    categories<< "操作失误率（%）" << "任务完成时间（S）"<<"任务成功率（%）"<<"总操作时间（S）";

    category_axis_x->setCategories(categories);

    //设置Y轴
    QValueAxis* axis_y = new QValueAxis(m_completionTime_chart);
    m_completionTime_chart->addAxis(axis_y, Qt::AlignLeft);

    //创建柱状图
    QBarSeries* bar_series = new QBarSeries(m_completionTime_chart);
    m_completionTime_chart->addSeries(bar_series);

    //加入坐标轴
    bar_series->attachAxis(category_axis_x);
    bar_series->attachAxis(axis_y);

    //创建1组柱状图

    QVector<QBarSet*>*item;

    item= new QVector<QBarSet*>;

    for(int i=0;i<id.size();i++)
    {
        QBarSet* set = new QBarSet("0", m_completionTime_chart);
        item->append(set);
    }

    for(int x=0;x<item->size();x++)
    {
        bar_series->append(item->at(x));
        //设置数据
        item->at(x)->append(error.at(x).toDouble(&ok));
        item->at(x)->append(completionTime.at(x).toDouble(&ok));
        item->at(x)->append(completionTime.at(x).toDouble(&ok));
        item->at(x)->append(completionTime.at(x).toDouble(&ok));
    }


    //设置显示范围
    axis_y->setRange(0, 5);

    //设置Y轴刻度数
    axis_y->setTickCount(11);
}

void VerticalBarChart::SetResultTable(QStringList id,  QList<QString>  completionTime, QList<QString>  sucess, QList<QString>  error,QList<QString>TaskConstTime)
{

    QStringList headers;
    headers << "" << "操作失误率（%）" << "任务完成时间（S）"<<"任务成功率（%）"<<"总操作时间（S）";
    ui->Result_Widget->setHorizontalHeaderLabels(headers);

    //  QVBoxLayout* layout = new QVBoxLayout;
    //  layout->addWidget(ui->Result_Widget);
    //  layout->setSizeConstraint(QLayout::SetNoConstraint);
    //  ui->completionTime_widget->setLayout(layout);

    ui->Result_Widget->verticalHeader()->hide();


    for(int i=0;i<id.size();i++)
    {
        ui->Result_Widget->insertRow(i);


        QTableWidgetItem *idItem = new QTableWidgetItem(id.at(i));
        ui->Result_Widget->setItem(i, 0, idItem);

        idItem->setTextAlignment(Qt::AlignCenter);

        QTableWidgetItem *errorItem = new QTableWidgetItem(error.at(i));
        ui->Result_Widget->setItem(i, 1, errorItem);

        errorItem->setTextAlignment(Qt::AlignCenter);

        QTableWidgetItem *completionTimeItem = new QTableWidgetItem(completionTime.at(i));
        ui->Result_Widget->setItem(i, 2, completionTimeItem);

        completionTimeItem->setTextAlignment(Qt::AlignCenter);

        QTableWidgetItem *TaskConstTimeItem = new QTableWidgetItem(TaskConstTime.at(i));
        ui->Result_Widget->setItem(i, 4, TaskConstTimeItem);

        TaskConstTimeItem->setTextAlignment(Qt::AlignCenter);
    }
}

