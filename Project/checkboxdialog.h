#ifndef CHECKBOXLISTDIALOG_H
#define CHECKBOXLISTDIALOG_H

#include <QDialog>
#include <QCheckBox>
#include <QPushButton>
#include <QVector>
#include <QPair>

class CheckboxDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CheckboxDialog(const QStringList &btnList, QWidget *parent = nullptr);

signals:
    // 发射信号，返回选中的项（下标和文本）
    void selectionConfirmed(const QVector<QPair<int, QString>> &selectedItems);

private slots:
    // 处理复选框选中状态变化
    void onCheckboxToggled(bool checked);

    // 确认按钮点击事件
    void onConfirmClicked();

private:
    QStringList m_btnList;            // 按钮文本列表
    QVector<QCheckBox*> m_checkBoxes;  // 存储所有的复选框
};

#endif // CHECKBOXLISTDIALOG_H
