#include "replaylistitem.h"
#include "ui_replaylistitem.h"

ReplayListItem::ReplayListItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ReplayListItem)
{
    ui->setupUi(this);
}

ReplayListItem::~ReplayListItem()
{
    delete ui;
}

void ReplayListItem::on_delete_2_clicked()
{

}

