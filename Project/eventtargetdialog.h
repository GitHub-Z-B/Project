#ifndef EVENTTARGETDIALOG_H
#define EVENTTARGETDIALOG_H

#include <QObject>
#include <QTreeWidget>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QTreeWidgetItem>
#include <QDialog>
#include <QVBoxLayout>
#include <QFile>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QDebug>
namespace Ui {
class EventTargetDialog;
}

class EventTargetDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EventTargetDialog(int num,QWidget *parent = nullptr);
    ~EventTargetDialog();
    QString CurrentButtonName;

    QTreeWidget *treeWidget;
    // 用于存储选中的按钮名称和对应的 ID
    struct SelectedButton {
        QString name;
        int buttonId;
    };

    QList<SelectedButton> selectedButtons;
    int ids;
    void loadJsonFile(const QString &filePath);
    void populateTree(const QJsonArray &buttons);
    void addChildren(QTreeWidgetItem *parentItem, const QJsonArray &children);
    QStringList All;

        void saveSelectedItems();  // 新增保存选项的方法
        QPushButton *saveButton;  // 保存按钮
        void collectSelectedItems(QTreeWidgetItem *item, QList<QString> &selectedList);  // 收集选中项
public slots:

private slots:


    void on_pushButton_Cancel_clicked();

    void handleItemChanged(QTreeWidgetItem *item, int column);

private:
    Ui::EventTargetDialog *ui;
    int num;
    QTreeWidget* m_treeWidget;
    QStringList names; // 用于存储按钮名称



signals:
    void EventName(QString);
    void EventName1(int,QString);
    void SendSelected();
    void OrderName(QString list,int ids);
    void sendAll(QStringList data);

};

#endif // EVENTTARGETDIALOG_H
