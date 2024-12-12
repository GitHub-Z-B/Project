#include "screenimportitem.h"
#include "ui_screenimportitem.h"

#include <QFileInfo>
#include <QMessageBox>

ScreenImportItem::ScreenImportItem(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ScreenImportItem)
{
    ui->setupUi(this);
    QString filePath = ui->ScreenPath_Edit->text();

    // 使用 QFileInfo 提取文件名
    QFileInfo fileInfo(filePath);
    QString fileName = fileInfo.fileName(); // 仅提取文件名
    m_CoordinateDialog =new CoordinateDialog(fileName);
}

ScreenImportItem::~ScreenImportItem()
{
    delete ui;
}

void ScreenImportItem::setScreenPath(QString name)
{
    ui->ScreenPath_Edit->setText(name);
}

QString ScreenImportItem::ScreenPath()
{
    return ui->ScreenPath_Edit->text();
}

int ScreenImportItem::GetX()
{
    return this->pos_X;
}

int ScreenImportItem::GetY()
{
    return this->pos_Y;
}

void ScreenImportItem::setX(int x)
{
    this->pos_X=x;
}

void ScreenImportItem::setY(int y)
{
    this->pos_Y=y;
}

void ScreenImportItem::setCoordinate_X_Y(int x, int y)
{
    this->pos_X=x;
    this->pos_Y=y;
    m_CoordinateDialog->setX(x);
    m_CoordinateDialog->setY(y);
}
void ScreenImportItem::on_SetPosition_btn_clicked()
{

    connect(this,&ScreenImportItem::closeExe,m_CoordinateDialog,&CoordinateDialog::closeExe);
    connect(m_CoordinateDialog,&CoordinateDialog::sendPoint,this,[=](int x,int y)
            {
                this->pos_X=x;
                this->pos_Y=y;

            });
    m_CoordinateDialog->show();
}


void ScreenImportItem::on_CloseExe_btn__clicked()
{
    emit closeExe();
}


void ScreenImportItem::on_delete_btn_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(nullptr, "确认删除", "您确定要删除这个画面吗？",
                                  QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        // 用户选择了“是”，在这里执行删除操作
        // ...
     this->deleteLater();
    } else {
        // 用户选择了“否”，取消删除操作
    }

}

