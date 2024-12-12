#ifndef VERTICALBARCHART_H
#define VERTICALBARCHART_H

#include <QWidget>
#include <QtCharts>
#include <QBarSeries>
#include <QBarCategoryAxis>
#include <QVBoxLayout>

namespace Ui {
class VerticalBarChart;
}

class VerticalBarChart : public QWidget
{
    Q_OBJECT

public:
    explicit VerticalBarChart(QWidget *parent = nullptr);
    ~VerticalBarChart();
    void initBarChart();

    void SetcompletionTimeBarChart(QStringList id,  QList<QString>  completionTime, QList<QString>  sucess, QList<QString>  error);

    void SetResultTable(QStringList id,  QList<QString>  completionTime, QList<QString>  sucess, QList<QString>  error,QList<QString>TaskConstTime);
private:
    Ui::VerticalBarChart *ui;

    QChart* m_completionTime_chart ;
    QChart* m_sucess_chart;
    QChart* m_error_chart;
};

#endif // VERTICALBARCHART_H
