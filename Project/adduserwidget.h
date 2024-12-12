#ifndef ADDUSERWIDGET_H
#define ADDUSERWIDGET_H

#include <QWidget>

#include <QMessageBox>
namespace Ui {
class AddUserWidget;
}

class AddUserWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AddUserWidget(QWidget *parent = nullptr);
    ~AddUserWidget();

    void init();


   //设置添加用户标志位
    void SetUserFlag(int row,bool Userflag,QString  name,QString  sex,QString  high,QString  weight,QString  workplace);
signals:
    //新建任务数据发送至表格
    void SendUserData(QString  name,QString  sex,QString  high,QString  weight,QString  workplace);
    void SendEditUserData(int row,QList<QString>data);
private slots:
    void on_Save_btn_clicked();

private:
    Ui::AddUserWidget *ui;
    bool addUser;
    int Editrow;
};

#endif // ADDUSERWIDGET_H
