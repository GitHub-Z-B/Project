#ifndef CONFIRMDIALOG_H
#define CONFIRMDIALOG_H

#include <QDialog>
#include <QString>

class ConfirmDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ConfirmDialog(const QString &message,
                           const QString &yesText = "Yes",
                           const QString &noText = "No",
                           QWidget *parent = nullptr);

    ~ConfirmDialog();

signals:
    void confirmed();
    void cancelled();

private slots:
    void on_buttonYes_clicked();
    void on_buttonNo_clicked();

private:
    QString message;
    QString yesText;
    QString noText;
};

#endif // CONFIRMDIALOG_H
