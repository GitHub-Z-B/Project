#include "adduserwidget.h"
#include "ui_adduserwidget.h"

AddUserWidget::AddUserWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AddUserWidget)
{
    ui->setupUi(this);
    init();
}

AddUserWidget::~AddUserWidget()
{
    delete ui;
}

void AddUserWidget::init()
{


    ui->Sex_comboBox->addItem("男");
    ui->Sex_comboBox->addItem("女");
    addUser=true;
}

void AddUserWidget::on_Save_btn_clicked()
{
    QList<QString> data;
    QMessageBox *tips_box= new QMessageBox();
    QString  name=ui->Name_Edit->text();
    data.append(name);
    QString  sex=ui->Sex_comboBox->currentText();
    data.append(sex);
    QString heightText = ui->High_Edit->text();
    bool ok;
    double height = heightText.toDouble(&ok); // 尝试将文本转换为double
    data.append(heightText);
    // 检查是否成功转换为数字
    if (!ok) {
        QMessageBox::warning(this, "输入错误", "请输入有效的数字作为身高。");
        return;
    }

    // 检查身高是否在合理范围内
    if (height < 1.0 || height > 300.0) {
        QMessageBox::warning(this, "输入错误", "请输入一个在1cm到300cm之间的身高值。");
        return;
    }

    QString weightText = ui->Widght_Edit->text();
    bool ok1;
    double weight = weightText.toDouble(&ok1); // 尝试将文本转换为double

    data.append(weightText);
    // 检查是否成功转换为数字
    if (!ok1) {
        QMessageBox::warning(this, "输入错误", "请输入有效的数字作为体重。");
        return;
    }

    // 检查体重是否在合理范围内，例如1kg到500kg
    if (weight < 1.0 || weight > 500.0) {
        QMessageBox::warning(this, "输入错误", "请输入一个在1kg到500kg之间的体重值。");
        return;
    }


    QString  workplace=ui->workplace_Edit->text();
    data.append(workplace);
    if(addUser==true)
    {
        emit SendUserData(name,sex,heightText,QString::number(weight),workplace);
    }else if(addUser==false)
    {
        emit SendEditUserData(Editrow,data);

    }


    tips_box->setText("添加成功");
    tips_box->exec();
    this->close();
}



void AddUserWidget::SetUserFlag(int row ,bool Userflag,QString  name,QString  sex,QString  high,QString  weight,QString  workplace)
{
    ui->Name_Edit->setText(name);
    ui->Sex_comboBox->setEditText(sex);
    ui->High_Edit->setText(high);
    ui->Widght_Edit->setText(weight);
    ui->workplace_Edit->setText(workplace);

    Editrow=row;
    addUser=Userflag;
}
