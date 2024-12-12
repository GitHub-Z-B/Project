#include "eventtargetdialog.h"
#include "ui_eventtargetdialog.h"
#include <QDebug>
#include <QFile>
#include <QDebug>
#include<QHeaderView>
EventTargetDialog::EventTargetDialog(int num,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EventTargetDialog)
{

    this->num=num;

    ui->setupUi(this);
    ui->pushButton_Cancel->setVisible(false);
    ui->pushButton_OK->setVisible(false);
    setWindowFlags(Qt::Dialog | Qt::WindowTitleHint | Qt::WindowCloseButtonHint);
    CurrentButtonName="";
    treeWidget = new QTreeWidget(this);
    treeWidget->setHeaderLabel("Buttons");
    treeWidget->setColumnCount(1);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(treeWidget);

    connect(treeWidget, &QTreeWidget::itemChanged, this, &EventTargetDialog::handleItemChanged);

    // 加载 JSON 文件
    loadJsonFile("buttons.json");
    saveButton = new QPushButton("确定", this);
    saveButton->setFixedSize(200, 40); // 设置按钮固定大小为 200x40

    // 将按钮添加到布局
    layout->addWidget(saveButton, 0, Qt::AlignCenter); // 使用 Qt::AlignCenter 实现居中显示

    connect(saveButton, &QPushButton::clicked, this, &EventTargetDialog::saveSelectedItems);

    setLayout(layout);


    this->resize(300,700);








}

EventTargetDialog::~EventTargetDialog()
{
    delete ui;
}

void EventTargetDialog::loadJsonFile(const QString &filePath)
{
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Couldn't open file:" << filePath;
        return;
    }

    QByteArray jsonData = file.readAll();
    file.close();

    QJsonParseError jsonError;
    QJsonDocument document = QJsonDocument::fromJson(jsonData, &jsonError);

    if (jsonError.error != QJsonParseError::NoError) {
        qWarning() << "JSON parse error:" << jsonError.errorString();
        return;
    }

    QJsonObject rootObj = document.object();
    QJsonArray buttons = rootObj["buttons"].toArray();
    populateTree(buttons);
}

void EventTargetDialog::populateTree(const QJsonArray &buttons)
{
    for (const auto &button : buttons) {
        QJsonObject buttonObj = button.toObject();
        QTreeWidgetItem *parentItem = new QTreeWidgetItem(treeWidget);
        parentItem->setText(0, buttonObj["name"].toString());
        parentItem->setCheckState(0, Qt::Unchecked);
        parentItem->setData(0, Qt::UserRole, buttonObj["buttonId"].toInt()); // 存储按钮 ID

        // 递归添加子按钮
        addChildren(parentItem, buttonObj["children"].toArray());

        // 将父节点展开
        //  parentItem->setExpanded(true);
    }
}


void EventTargetDialog::addChildren(QTreeWidgetItem *parentItem, const QJsonArray &children)
{
    for (const auto &child : children) {
        QJsonObject childObj = child.toObject();
        QTreeWidgetItem *childItem = new QTreeWidgetItem(parentItem);
        childItem->setText(0, childObj["name"].toString());
        childItem->setData(0, Qt::UserRole, childObj["buttonId"].toInt()); // 存储按钮 ID
        childItem->setCheckState(0, Qt::Unchecked);
        childItem->setFlags(childItem->flags() | Qt::ItemIsUserCheckable);  // 允许选中

        // 将子节点展开
        //     childItem->setExpanded(true);

        // 递归添加子节点
        addChildren(childItem, childObj["children"].toArray());
    }
}




void EventTargetDialog::saveSelectedItems()
{


    names.clear();
    QList<QString> selectedList;
    for (int i = 0; i < treeWidget->topLevelItemCount(); ++i) {
        QTreeWidgetItem *topItem = treeWidget->topLevelItem(i);
        collectSelectedItems(topItem, selectedList);
    }


    for (const SelectedButton &button : selectedButtons) {

        qDebug() << "Name:" << button.name << ", ID:" << button.buttonId;  // 打印名称和 ID
        ids=button.buttonId;
        All.append(QString::number(button.buttonId));

        names.append(button.name);

    }


    // 将名称用 "-" 分割
    QString concatenatedNames = names.join(",");

    // 输出结果
    qDebug() << "Concatenated Names:" << concatenatedNames;



    qDebug()<<"ids:"<<ids;
    selectedButtons.clear();
    emit OrderName(concatenatedNames , ids);
    emit sendAll(All);
    this->close();

}

void EventTargetDialog::collectSelectedItems(QTreeWidgetItem *item, QList<QString> &selectedList)
{
    if (item->checkState(0) == Qt::Checked) {
        selectedList.append(item->text(0));  // 添加到列表中
        SelectedButton selectedButton;
        selectedButton.name = item->text(0);
        selectedButton.buttonId = item->data(0, Qt::UserRole).toInt();  // 获取按钮 ID
        selectedButtons.append(selectedButton);  // 添加到选中列表
    }
    for (int i = 0; i < item->childCount(); ++i) {
        collectSelectedItems(item->child(i), selectedList);  // 递归收集子节点
    }
}






void EventTargetDialog::on_pushButton_Cancel_clicked()
{
    this->close();
}

void EventTargetDialog::handleItemChanged(QTreeWidgetItem *item, int column)
{
    if (column != 0) return;

    treeWidget->blockSignals(true);  // 暂时阻止信号以避免递归调用

    if (!item->parent()) {
        // 处理顶级父节点
        bool isChecked = item->checkState(0) == Qt::Checked;

        // 启用或禁用所有子节点及其子节点
        //   setChildrenEnabled(item, isChecked);

        if (!isChecked) {
            // 递归取消所有子节点及其子节点的选中状态
            //  uncheckAllChildren(item);
        } else {
            // 如果当前顶级父节点被选中，取消其他顶级父节点的选中状态
            //         for (int i = 0; i < treeWidget->topLevelItemCount(); ++i) {
            //           QTreeWidgetItem *sibling = treeWidget->topLevelItem(i);
            //         if (sibling != item) {
            //           sibling->setCheckState(0, Qt::Unchecked);
            //         setChildrenEnabled(sibling, false);  // 禁用该顶级父节点的所有子节点
            //       uncheckAllChildren(sibling);  // 取消所有子节点的选中状态
            //  }
            // }
        }
    } else {
        // 处理子节点的选中逻辑
        //  if (item->checkState(0) == Qt::Checked) {
        //    QTreeWidgetItem *parentItem = item->parent();

        // 确保父节点已选中
        //   if (parentItem->checkState(0) != Qt::Checked) {
        //     parentItem->setCheckState(0, Qt::Checked);
        // }

        // 取消同级别其他子节点的选中状态
        //  for (int i = 0; i < parentItem->childCount(); ++i) {
        //     QTreeWidgetItem *sibling = parentItem->child(i);
        //    if (sibling != item) {
        //       sibling->setCheckState(0, Qt::Unchecked);
        // 确保其他子节点的子节点也取消选中状态
        //     uncheckAllChildren(sibling);
        //   }
        //  }
        // 启用选中的子节点的子级
        //     setChildrenEnabled(item, true);
        //  } else {
        // 如果子节点被取消选中，递归取消其所有子节点的选中状态并禁用
        //      uncheckAllChildren(item);
        //    setChildrenEnabled(item, false);
        // }
    }

    treeWidget->blockSignals(false);  // 恢复信号
}

