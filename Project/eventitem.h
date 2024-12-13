#pragma once

#include <QWidget>

namespace Ui {
class EventItem;
}

class EventItem : public QWidget
{
    Q_OBJECT
public:
    explicit EventItem(QWidget *parent = nullptr);
    ~EventItem();
    void set_task_event(QString task_event);
    QString task_event();
    void set_trigger_event(QString trigger_event);
    QString trigger_event();
    QString getTimeList();
    void setTimeString(QString str);

signals:
    void delete_event();
private:
    Ui::EventItem *ui;
    QString TimeString;
    QString TimeList;

private slots:
    void on_add_child_clicked();
    void on_delete_child_clicked();
signals:
    void requestDeletion();
    void getTriggerTime();
};
