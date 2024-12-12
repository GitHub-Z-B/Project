#include "eventchilditem.h"
#include "ui_eventchilditem.h"

#include <QMessageBox>

EventChildItem::EventChildItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::eventChildItem)
{
    ui->setupUi(this);
    dialog.hide();
}

EventChildItem::~EventChildItem()
{
    delete ui;
}

void EventChildItem::set_trigger_event(int id)
{
    ui->trigger_event->setText(dialog.name_from_id(id));
    dialog.selectItemByButtonId(id);
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

