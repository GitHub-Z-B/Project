#pragma once

#include <QWidget>

namespace Ui { 
class ConfigListItem;
}

class ConfigListItem : public QWidget
{
    Q_OBJECT

public:
    explicit ConfigListItem(QWidget *parent = nullptr);
    ~ConfigListItem();
    void setJLName(QString name);

private slots:
    void on_Edit_btn_clicked();

    void on_Delete_btn_clicked();

private:
    Ui::ConfigListItem *ui;
signals:
    void Send_JL_Json_Name(QString name);
    void Send_JL_Del(QString name);
};
