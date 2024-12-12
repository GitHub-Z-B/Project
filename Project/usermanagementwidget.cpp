#include "usermanagementwidget.h"
#include "ui_usermanagementwidget.h"

UserManagementWidget::UserManagementWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserManagementWidget)
{
    ui->setupUi(this);
    init();

}

UserManagementWidget::~UserManagementWidget()
{
    delete ui;
}

void UserManagementWidget::init()
{
    m_AddUserWidget = new AddUserWidget();
    connect(m_AddUserWidget,&AddUserWidget::SendUserData,this,&UserManagementWidget::SetUsertable);   //新建用户

    connect(m_AddUserWidget,&AddUserWidget::SendEditUserData,this,&UserManagementWidget::RecvEditUser);
}

void UserManagementWidget::on_NewUser_btn_clicked()
{
    m_AddUserWidget->show();

}

void UserManagementWidget::SetUsertable(QString  name,QString  sex,QString  high,QString  weight,QString  workplace)
{
    QSqlQuery query;
    query.prepare("insert into user(username,sex,height,weight,section) values(:username,:sex,:height,:weight,:section)");
    query.bindValue(":username",name);
    query.bindValue(":sex",sex);
    query.bindValue(":height",high);
    query.bindValue(":weight",weight);
    query.bindValue(":section",workplace);
    if(!query.exec())
    {
        qDebug()<<"错误："<<query.lastError().text();
    }

    ui->User_Widget->insertRow(tablerow);

    for(int row=0;row<ui->User_Widget->rowCount();row++)
    {
        QTableWidgetItem *id_item =new QTableWidgetItem(QString::number(row+1));
        ui->User_Widget->setItem(row,0,id_item);
        User_Id=row+1;
    }

    QTableWidgetItem *id_item =new QTableWidgetItem(QString::number(User_Id));
    ui->User_Widget->setItem(tablerow,0,id_item);

    QTableWidgetItem *name_item=new QTableWidgetItem(name);
    ui->User_Widget->setItem(tablerow,1,name_item);

    QTableWidgetItem *sex_item=new QTableWidgetItem(sex);
    ui->User_Widget->setItem(tablerow,2,sex_item);

    QTableWidgetItem *high_item=new QTableWidgetItem(high);
    ui->User_Widget->setItem(tablerow,3,high_item);

    QTableWidgetItem *weight_item=new QTableWidgetItem(weight);
    ui->User_Widget->setItem(tablerow,4,weight_item);


    QTableWidgetItem *workplace_item=new QTableWidgetItem(workplace);
    ui->User_Widget->setItem(tablerow,5,workplace_item);

    Delete_btn = new QPushButton;
    Delete_btn->setText("删除");

    //表格中删除按钮
    connect(Delete_btn, &QPushButton::clicked, this, &UserManagementWidget::DeleteUser);

    Delete_btn->setObjectName("Delete_btn" + QString::number(tablerow));
    ui->User_Widget->setCellWidget(tablerow, 6, Delete_btn);
    Delete_btn->setProperty("row", tablerow);
    Delete_btn->setProperty("col", 6);

    Edit_btn = new QPushButton;
    Edit_btn->setText("编辑");
    //表格中编辑按钮
    connect(Edit_btn, &QPushButton::clicked, this, &UserManagementWidget::EditUser);

    Edit_btn->setObjectName("Edit_btn" + QString::number(tablerow));
    ui->User_Widget->setCellWidget(tablerow, 7, Edit_btn);
    Edit_btn->setProperty("row", tablerow);
    Edit_btn->setProperty("col", 7);

    tablerow++;


}

//删除用户
void UserManagementWidget::DeleteUser()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    uint EndId;
    if (button)
    {
        // 获取按钮的行和列信息
        int row =ui->User_Widget->currentRow();
        int col = button->property("col").toInt();

        ui->User_Widget->removeRow(row);
        tablerow--;

        // 动态计算序号
        for(int row=0;row<ui->User_Widget->rowCount();row++)
        {
            QTableWidgetItem *id_item =new QTableWidgetItem(QString::number(row+1));
            ui->User_Widget->setItem(row,0,id_item);
            User_Id=row+1;
        }
    }
}
//编辑用户
void UserManagementWidget::EditUser()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    uint EndId;
    if (button)
    {
        // 获取按钮的行和列信息
        int row =ui->User_Widget->currentRow();

        int col = button->property("col").toInt();
        bool flag=false;

        QString name= ui->User_Widget->item(row,1)->text();
        QString sex= ui->User_Widget->item(row,2)->text();
        QString high= ui->User_Widget->item(row,3)->text();
        QString weight= ui->User_Widget->item(row,4)->text();
        QString workplace= ui->User_Widget->item(row,5)->text();
        m_AddUserWidget->SetUserFlag(row,flag,name,sex,high,weight,workplace);
        m_AddUserWidget->show();


    }

}
//编辑用户信息
void UserManagementWidget::RecvEditUser(int row,QList<QString>data)
{

    QTableWidgetItem *name_item=new QTableWidgetItem(data.at(0));
    ui->User_Widget->setItem(row,1,name_item);

    QTableWidgetItem *sex_item=new QTableWidgetItem(data.at(1));
    ui->User_Widget->setItem(row,2,sex_item);

    QTableWidgetItem *high_item=new QTableWidgetItem(data.at(2));
    ui->User_Widget->setItem(row,3,high_item);

    QTableWidgetItem *weight_item=new QTableWidgetItem(data.at(3));
    ui->User_Widget->setItem(row,4,weight_item);

    QTableWidgetItem *workplace_item=new QTableWidgetItem(data.at(4));
    ui->User_Widget->setItem(row,5,workplace_item);

    QSqlQuery query;
    query.exec("UPDATE user SET username = 'data.at(0)', sex = 'data.at(1)' , height='data.at(2)' weight='data.at(3)',section ='data.at(4)' WHERE username id = data.at(0)");

    if(!query.exec())
    {
        qDebug()<<"错误："<<query.lastError().text();
    }

}

//搜索按钮
void UserManagementWidget::on_pushButton_clicked()
{

    int rowCount = ui->User_Widget->rowCount();
    int columnCount = ui->User_Widget->columnCount();

    for (int row = 0; row < rowCount; ++row)
    {
        for (int column = 0; column < 5 ;++column)
        {
            QTableWidgetItem *Resetitem = ui->User_Widget->item(row, column);
            Resetitem->setBackground(QBrush(QColor(255, 255, 255)));
        }
    }

    QString User=ui->User_Edit->text();
    QString workplace=ui->WorkPlace_Edit->text();
    QString Sex=ui->Sex_comboBox->currentText();

    for (int row = 0; row < rowCount; ++row)
    {

        QTableWidgetItem *user_item = ui->User_Widget->item(row, 1);
        QTableWidgetItem *workplace_item = ui->User_Widget->item(row, 5);
        if(User!=nullptr&&workplace!=nullptr)
        {

        }
        if (user_item && user_item->text() == User)
        {
            QModelIndex index = ui->User_Widget->model()->index(row, 0);
            ui->User_Widget->scrollTo(index);
            user_item->setBackground(QBrush(QColor(255, 0, 0)));
        }
        if (workplace_item && workplace_item->text() == workplace)
        {
            QModelIndex index = ui->User_Widget->model()->index(row, 0);
            ui->User_Widget->scrollTo(index);
            workplace_item->setBackground(QBrush(QColor(255, 0, 0)));
        }
    }
}

void UserManagementWidget::initUserList(bool userflag)
{
    QSqlQuery query;

    if(userflag==false)
    {
         query.exec("select* from user");
        while(query.next())
        {
            ui->User_Widget->insertRow(tablerow);
            QTableWidgetItem *name_item=new QTableWidgetItem(query.value(1).toString());
            ui->User_Widget->setItem(tablerow,1,name_item);

            QTableWidgetItem *sex_item=new QTableWidgetItem(query.value(2).toString());
            ui->User_Widget->setItem(tablerow,2,sex_item);

            QTableWidgetItem *high_item=new QTableWidgetItem(query.value(3).toString());
            ui->User_Widget->setItem(tablerow,3,high_item);

            QTableWidgetItem *weight_item=new QTableWidgetItem(query.value(4).toString());
            ui->User_Widget->setItem(tablerow,4,weight_item);


            QTableWidgetItem *workplace_item=new QTableWidgetItem(query.value(5).toString());
            ui->User_Widget->setItem(tablerow,5,workplace_item);
            Delete_btn = new QPushButton;
            Delete_btn->setText("删除");
            //表格中删除按钮
            connect(Delete_btn, &QPushButton::clicked, this, &UserManagementWidget::DeleteUser);

            Delete_btn->setObjectName("Delete_btn" + QString::number(tablerow));
            ui->User_Widget->setCellWidget(tablerow, 6, Delete_btn);
            Delete_btn->setProperty("row", tablerow);
            Delete_btn->setProperty("col", 6);

            Edit_btn = new QPushButton;
            Edit_btn->setText("编辑");
            //表格中编辑按钮
            connect(Edit_btn, &QPushButton::clicked, this, &UserManagementWidget::EditUser);

            Edit_btn->setObjectName("Edit_btn" + QString::number(tablerow));
            ui->User_Widget->setCellWidget(tablerow, 7, Edit_btn);
            Edit_btn->setProperty("row", tablerow);
            Edit_btn->setProperty("col", 7);

            tablerow++;
        }
        // 动态计算序号
        for(int row=0;row<ui->User_Widget->rowCount();row++)
        {
            QTableWidgetItem *id_item =new QTableWidgetItem(QString::number(row+1));
            ui->User_Widget->setItem(row,0,id_item);
            User_Id=row+1;
        }
    }

}
