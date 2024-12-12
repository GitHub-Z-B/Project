#pragma once
#include <QSqlQuery>
#include <QWidget>
#include <Analyzeresults/verticalbarchart.h>
#include "EvaluationAlgorithms/evaluationalgorithms.h"
namespace Ui {
class EvaluateWidget;
}

class EvaluateWidget : public QWidget
{
    Q_OBJECT
public:
    explicit EvaluateWidget(QWidget *parent = nullptr);
    ~EvaluateWidget();
    //设置绩效总体数据表格
    void SetPerformanceTable();
    //设置当前数据表格
    void SetcurrentperformanceTable();
    //开始数据分析按钮点击事件
    void analysisButtonClicked() ;
    //将数据插入到combobox中
    void InsertCombobox(QSqlQuery query);
private:
    Ui::EvaluateWidget *ui;

    VerticalBarChart *m_VerticalBarChart=nullptr;//柱状图


    QList<QString> UserIddata;
    QList<QString> UserNamedata;
    QList<QString> TaskSubdata;

    QList<QString> ConstTime;
    QList<QString> TaskConstTime;
    QList<QString> Errorrate;
    QList<QString> TaskCompletiontime;
    QList<QString> Sucessrate;

    EvaluationAlgorithms *m_EvaluationAlgorithms=nullptr;

private slots:
    void on_pushButton_1_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_detail_clicked();
    void on_export_word_clicked();
    void on_export_pdf_clicked();
    void on_analyze_clicked();
    void on_subjective_return_clicked();
    void on_performance_btn_clicked();
    void on_currentperformance_btn_clicked();

};
