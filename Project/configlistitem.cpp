#include "configlistitem.h"
#include "ui_configlistitem.h"
#include <QMessageBox> 
ConfigListItem::ConfigListItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ConfigListItem)
{
    ui->setupUi(this);
}

ConfigListItem::~ConfigListItem()
{
    delete ui;
}

void ConfigListItem::setJLName(QString name)
{
    ui->JI_Name_label->setText(name);
}

void ConfigListItem::on_Edit_btn_clicked()
{
    emit Send_JL_Json_Name(ui->JI_Name_label->text());
}


void ConfigListItem::on_Delete_btn_clicked()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("删除操作");
    msgBox.setText("您确定删除此项激励数据吗");
    msgBox.setIcon(QMessageBox::Warning);
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);
    int ret = msgBox.exec();
    if(ret==QMessageBox::Yes)
    {
        emit Send_JL_Del(ui->JI_Name_label->text());
    }
    else
    {
        return ;
    }

}

