#pragma once

#include <QWidget>
#include <adduserwidget.h>
#include <QApplication>
#include <QTableWidget>
#include <QPushButton>
#include <QTableWidgetItem>
#include <QSqlQuery>
#include <QSqlError>
namespace Ui {
class UserManagementWidget;
}

class UserManagementWidget : public QWidget
{
    Q_OBJECT

public:
    explicit UserManagementWidget(QWidget *parent = nullptr);
    ~UserManagementWidget();
    void initUserList(bool userflag);

private slots:
    void on_NewUser_btn_clicked();

    void init();
    //设置表格数据
    void SetUsertable(QString  name,QString  sex,QString  high,QString  weight,QString  workplace);
    //删除用户
    void DeleteUser();
    //编辑用户
    void EditUser();

    void RecvEditUser(int row,QList<QString>data);
    void on_pushButton_clicked();


signals:

private:
    Ui::UserManagementWidget *ui;
    AddUserWidget *m_AddUserWidget = nullptr;
    //表格中的删除按钮
    QPushButton *Delete_btn;
    QPushButton *Edit_btn;
    //用户插入行数
    int tablerow=0;
    //用户序号
    int User_Id=0;
};
