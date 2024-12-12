#ifndef EVALUATIONALGORITHMS_H
#define EVALUATIONALGORITHMS_H

#include <QWidget>

namespace Ui {
class EvaluationAlgorithms;
}

enum sifttype
{
    completionTimetype,
    sucesstype,
    errortype,
    TaskConstTimetype,
};

class EvaluationAlgorithms : public QWidget
{
    Q_OBJECT

public:
    explicit EvaluationAlgorithms(QWidget *parent = nullptr);
    ~EvaluationAlgorithms();


    void onIndexChanged(int index);
    void setAlgorithms_table(QList<QString>  completionTime, QList<QString>  sucess, QList<QString>  error,QList<QString>TaskConstTime);
private slots:
    void on_start_btn_clicked();

private:
    Ui::EvaluationAlgorithms *ui;
};

#endif // EVALUATIONALGORITHMS_H
