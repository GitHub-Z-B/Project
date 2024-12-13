#include "eventchilditem.h"
#include "ui_eventchilditem.h"

#include <QMessageBox>

EventChildItem::EventChildItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::eventChildItem)
{
    ui->setupUi(this);
    connect(ui->hour_spinBox, QOverload<int>::of(&QSpinBox::valueChanged), this, &EventChildItem::onHourChanged);
    connect(ui->minute_spinBox, QOverload<int>::of(&QSpinBox::valueChanged), this, &EventChildItem::onMinuteChanged);
    connect(ui->second_spinBox, QOverload<int>::of(&QSpinBox::valueChanged), this, &EventChildItem::onSecondChanged);

    // 设置最大值
    ui->hour_spinBox->setMaximum(23);  // 设置小时最大值为23
    ui->minute_spinBox->setMaximum(59); // 设置分钟最大值为59
    ui->second_spinBox->setMaximum(59); // 设置秒钟最大值为59
    dialog.hide();

    QTime time(hour, minute, second);
    timeString = time.toString("hh:mm:ss");
}

EventChildItem::~EventChildItem()
{
    delete ui;
}
// 秒钟变化时的处理
void EventChildItem::onSecondChanged(int value)
{
    if (value >= 60) {
        // 秒数超过60，进位到分钟
        ui->second_spinBox->setValue(0);
        ui->minute_spinBox->setValue(ui->minute_spinBox->value() + 1);
    }
}

// 分钟变化时的处理
void EventChildItem::onMinuteChanged(int value)
{
    if (value >= 60) {
        // 分钟超过60，进位到小时
        ui->minute_spinBox->setValue(0);
        ui->hour_spinBox->setValue(ui->hour_spinBox->value() + 1);
    }
}

// 小时变化时的处理
void EventChildItem::onHourChanged(int value)
{
    // 如果小时大于23，重置为0（24小时制）
    if (value >= 24) {
        ui->hour_spinBox->setValue(0);
    }
}
void EventChildItem::set_trigger_event(int id)
{
    ui->trigger_event->setText(dialog.name_from_id(id));
    dialog.selectItemByButtonId(id);
}

void EventChildItem::setTriggerTime(QString time)//接收传过来的时间
{


    QStringList parts = time.split(":"); // 使用 ':' 作为分隔符拆分字符串
    ui->hour_spinBox->setValue(parts[0].toInt()); // 将小时部分转换为 int
    ui->minute_spinBox->setValue(parts[1].toInt()); // 将分钟部分转换为 int
    ui->second_spinBox->setValue(parts[2].toInt()); // 将秒部分转换为 int
}

int EventChildItem::trigger_event()
{
    return dialog.result_id();
}

void EventChildItem::setItemReadonly()
{
    //  ui->hour_spinBox->setVisible(false);
    //  ui->minute_spinBox->setVisible(false);
    //  ui->second_spinBox->setVisible(false);
    //  ui->trigger_lab->setVisible(false);
    //  ui->hour_lab->setVisible(false);
    //  ui->minute_lab->setVisible(false);
    //  ui->second_lab->setVisible(false);
}

QString EventChildItem::getTime()
{
    return timeString;
}

void EventChildItem::on_pushButton_clicked()
{
    if(dialog.exec() == QDialog::Accepted)
    {
        ui->trigger_event->setText(dialog.result_name());
    }
}

void EventChildItem::on_delete_btn_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(nullptr, "确认删除", "您确定要删除这个目标吗？",
                                  QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        // 用户选择了“是”，在这里执行删除操作
        // ...
        delete this;
    } else {
        // 用户选择了“否”，取消删除操作
    }

}


void EventChildItem::on_hour_spinBox_valueChanged(int arg1)
{
    this->hour=arg1;
    QTime time(hour, minute, second);
    timeString = time.toString("hh:mm:ss");
}


void EventChildItem::on_minute_spinBox_valueChanged(int arg1)
{
    this->minute=arg1;
    QTime time(hour, minute, second);
    timeString = time.toString("hh:mm:ss");
}


void EventChildItem::on_second_spinBox_valueChanged(int arg1)
{
    this->second=arg1;
    QTime time(hour, minute, second);
    timeString = time.toString("hh:mm:ss");
}

