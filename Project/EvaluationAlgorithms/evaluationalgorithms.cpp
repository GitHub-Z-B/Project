#include "evaluationalgorithms.h"
#include "ui_evaluationalgorithms.h"

#include <QCheckBox>
EvaluationAlgorithms::EvaluationAlgorithms(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::EvaluationAlgorithms)
{
    ui->setupUi(this);

    connect(ui->comboBox, &QComboBox::currentIndexChanged, this,&EvaluationAlgorithms::onIndexChanged);

}

EvaluationAlgorithms::~EvaluationAlgorithms()
{
    delete ui;
}

void EvaluationAlgorithms::onIndexChanged(int index)
{
    switch (index){
    case 0:
        ui->textEdit->setText("频数分析是对一组数据的不同数值的频数，或者数据落入指定区域内的频数进行统计，了解其数据分布状况的方式。通过频数分析，能在一定程度上反映出样本是否具有总体代表性，抽样是否存在系统偏差，并以此证明以后相关问题分析的代表性和可信性。"
                              "(1)频数：对每个类，统计数据中出现的次数。"
                              "(2)频率：对每个类，计算其频率或百分比。"
                              "(3)生成柱状图，横坐标为分级，纵坐标为频率。");
        break;

    case 1:
        ui->textEdit->setText("交叉分析用于分析定类数据与定类数据之间的关系情况.例如研究人员想知道两组学生对于手机品牌的偏好差异情况。首先判断是否呈现出显著性,如果呈现出显著性,则说明两组数据具有显著性差异,具体差异可通过选择百分比进行对比判断。"
                              "(1)交叉制表：根据选定的变量，制作一个交叉表，其中行表示一个变量的级别，列表示另一个变量的级别。交叉表中的每个单元格将显示两个变量的交叉频数或频率。"
                              "(2)计算比例：以计算每个交叉单元格中的比例或百分比，以便更直观地理解变量之间的关系。"
                              "(3)统计检验：对交叉分析的结果进行统计检验，以确定变量之间的关联是否显著。"
                              "(4)可视化结果:据交叉分析的结果，可以绘制图表或图形，如堆积柱状图、热图等，以便更好地展示变量之间的关系。");
        break;
    case 2:
        ui->textEdit->setText("描述性统计分析是对调查总体所有变量的有关数据进行统计性描述，包括数据的集中趋势与离散趋势。");

        break;
    case 3:
        ui->textEdit->setText("根据定类变量分类进行汇总（按照某一标准进行分类，然后在分完类的基础上对各类别相关数据分别进行求和、求平均数、求个数、求最大值、求最小值等方法的汇总。又名列联表分析）。");
        break;
    case 4:
        ui->textEdit->setText("正态性检验用于检验数据是否满足正态分布，一些算法需要数据满足正态分布（如单样本 t 检验，独立样本 t 检验等）。");
        break;
    case 5:
        ui->textEdit->setText("该方法直接通过绘制数据的直方图，与标准正态分布曲线进行比较。但该方法在数据量少的时候比较难看出两者之间的差异，因此更多地会通过对数据直方图曲线与对应μ、σ的标准正态分布曲线之间进行回归，计算出拟合优度来说明两条曲线之间的拟合程度。这种用于评估数据正态性的图形工具有很多，其中“分位数-分位数图”，即QQ图是正态检验中最常见的图示方法。这种图正是样本数据直方图和正态分布图之间一种拟合优度的直观度量方式，当QQ图上的点都大致落在一条直线上时，表示高度正相关，即这些数据是正态分布的。");
        break;
    case 6:
        ui->textEdit->setText("");
        break;
    case 7:
        ui->textEdit->setText("");
        break;
    case 8:
        ui->textEdit->setText("");
        break;
    case 9:
        ui->textEdit->setText("");
        break;
    case 10:
        ui->textEdit->setText("");
        break;
    case 11:
        ui->textEdit->setText("");
        break;
    case 12:
        ui->textEdit->setText("");
        break;
    case 13:
        ui->textEdit->setText("");
        break;
    case 14:
        ui->textEdit->setText("");
        break;
    case 15:
        ui->textEdit->setText("");
        break;
    case 16:
        ui->textEdit->setText("");
        break;
    case 17:
        ui->textEdit->setText("");
        break;
    case 18:
        ui->textEdit->setText("");
        break;
    case 19:
        ui->textEdit->setText("");
        break;

    }
}

void EvaluationAlgorithms::setAlgorithms_table(QList<QString> completionTime, QList<QString> sucess, QList<QString> error, QList<QString> TaskConstTime)
{
    ui->Algorithms_table->insertRow(0);
    QTableWidgetItem *completionTimeItem = new QTableWidgetItem("完成时间");
    ui->Algorithms_table->setItem(0, 1, completionTimeItem);

    ui->Algorithms_table->insertRow(1);
    QTableWidgetItem *sucessItem = new QTableWidgetItem("成功率");
    ui->Algorithms_table->setItem(1, 1, sucessItem);

    ui->Algorithms_table->insertRow(2);
    QTableWidgetItem *errorItem = new QTableWidgetItem("错误率");
    ui->Algorithms_table->setItem(2, 1, errorItem);

    ui->Algorithms_table->insertRow(3);
    QTableWidgetItem *TaskConstTimeItem = new QTableWidgetItem("总操作时间");
    ui->Algorithms_table->setItem(3, 1, TaskConstTimeItem);

    for (int row = 0; row <  ui->Algorithms_table->rowCount(); ++row) {
        // 创建一个新的复选框
        QCheckBox *checkBox = new QCheckBox();
        // 将复选框设置为第一列的单元格小部件
        checkBox->setObjectName("checkBox" + QString::number(row));
        ui->Algorithms_table->setCellWidget(row, 0, checkBox);
        ui->Algorithms_table->setColumnWidth(0,20);
    }
    ui->Algorithms_table->horizontalHeader()->setVisible(false);
}


void EvaluationAlgorithms::on_start_btn_clicked()
{
    if(ui->Algorithms_table->rowCount()!=0)
    {
        for (int row = 0; row < ui->Algorithms_table->rowCount(); ++row)
        {
            QCheckBox *checkBox = static_cast<QCheckBox*>(ui->Algorithms_table->cellWidget(row, 0));
            if (checkBox->isChecked())
            {

                if(row==completionTimetype)
                {

                }
                if(row==sucesstype)
                {

                }
                if(row==errortype)
                {

                }
                if(row==TaskConstTimetype)
                {

                }
            }
        }
    }
}

