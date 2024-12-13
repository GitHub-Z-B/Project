#pragma once

#include <QWidget>
#include "triggeractiondialog.h"
#include <QTime>

namespace Ui {
class eventChildItem;
}

class EventChildItem : public QWidget
{
    Q_OBJECT
public:
    explicit EventChildItem(QWidget *parent = nullptr);
    ~EventChildItem();
    void set_trigger_event(int id);
    void setTriggerTime(QString time);
    int trigger_event();
    void setItemReadonly();
    QString getTime();
private:
    Ui::eventChildItem *ui;
    TriggerActionDialog dialog;
    int hour=0;
    int minute=0;
    int second=0;
    QString timeString;
    void onSecondChanged(int value);
    void onMinuteChanged(int value);
    void onHourChanged(int value);
private slots:
    void on_pushButton_clicked();
    void on_delete_btn_clicked();
    void on_hour_spinBox_valueChanged(int arg1);

    void on_minute_spinBox_valueChanged(int arg1);

    void on_second_spinBox_valueChanged(int arg1);

signals:
    void  requestDeletion();
};
