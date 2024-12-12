#pragma once

#include <QWidget>
#include <QSqlQuery>
#include "triggeractiondialog.h"

namespace Ui {
class QuestionItem;
}

class QuestionItem : public QWidget
{
    Q_OBJECT
public:
    explicit QuestionItem(QWidget *parent = nullptr);
    ~QuestionItem();
    void setNameIndex(int nameIndex);
    void set_task_questionnaire(QString text);
    QString task_questionnaire();
    void set_trigger_questionnaire(int id);
    int trigger_questionnaire();
signals:
    void delete_question();

private:
    Ui::QuestionItem *ui;
    TriggerActionDialog dialog;
private slots:
    void on_trigger_questionnaire_clicked();
    void on_preview_clicked();
    void on_delete_btn_clicked();
signals:
    void requestDeletion();
};
