#pragma once

#include <QWidget>
#include <QMessageBox>
namespace Ui {
class TaskListItem;
}

class TaskListItem : public QWidget
{
    Q_OBJECT
public:
    explicit TaskListItem(QWidget *parent = nullptr);
    ~TaskListItem();
    void set_task_name(QString text);
    void set_create_name(QString text);
    void set_create_time(QDateTime dateTime);
    void set_task_description(QString text);
    QString task_name();
    QString create_name();
    QDateTime create_time();
    QString task_description();
    void set_task_type(QString task_type);
    QString task_type();
    void set_task_path(QString task_path);
    QString task_path();
    void set_task_questionnaire(QString task_questionnaire);
    void set_task_event(QString task_event);
    void set_trigger_questionnaire(QString trigger_questionnaire);
    void set_trigger_event(QString trigger_event);
    QString task_questionnaire() const;
    QString task_event() const;
    QString trigger_questionnaire() const;
    QString trigger_event() const;
    void setPos_X_Y(QString x_y);
    void setTrigger_Time(QString time);
    QString getTrigger_Time();
    QString getPos_X_Y();
    void setJL(QString name);
    QString JL();
    void setLabel(QString name);
public slots:
    void RecvStartFlag(bool flag);
private:
    Ui::TaskListItem *ui;
    QString m_task_type;
    QString m_task_path;
    QString m_task_questionnaire;
    QString m_task_event;
    QString m_trigger_questionnaire;
    QString m_trigger_event;
    QString pos_X_Y;
    QString JLName;
    QString trigger_time;
    bool TaskStartFlag=false;
private slots:
    void on_task_start_clicked();
    void on_task_edit_clicked();
    void on_task_delete_clicked();
    void on_TaskSelect_clicked();

signals:
    void task_start();
    void task_edit();
    void task_delete();
    void TaskSelect(QString name);
    void requestDeletion();
};
