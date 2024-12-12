#include "checkboxdialog.h"
#include <QVBoxLayout>
#include <QMessageBox>
#include <QDebug>
#include <QFont>

CheckboxDialog::CheckboxDialog(const QStringList &btnList, QWidget *parent)
    : QDialog(parent), m_btnList(btnList) {
    // 移除标题栏和叉号
 //   setWindowFlags(windowFlags() & ~Qt::WindowTitleHint & ~Qt::WindowCloseButtonHint);

    // 设置字体为微软雅黑 15
    QFont font("Microsoft YaHei", 15);
    setFont(font);

    // 设置窗体初始大小
    resize(400, 300);  // 可根据需要调整宽高

    setWindowTitle("请选择两项");

    // 创建布局
    QVBoxLayout *layout = new QVBoxLayout(this);

    // 动态创建复选框并将其添加到布局中
    for (int i = 0; i < m_btnList.size(); ++i) {
        QCheckBox *checkBox = new QCheckBox(m_btnList[i], this);
        layout->addWidget(checkBox);

        // 连接复选框的状态变化信号
        connect(checkBox, &QCheckBox::toggled, this, &CheckboxDialog::onCheckboxToggled);

        // 将复选框添加到复选框列表中
        m_checkBoxes.append(checkBox);
    }

    // 创建确认按钮
    QPushButton *confirmButton = new QPushButton("确认", this);
    layout->addWidget(confirmButton);

    // 连接确认按钮点击信号
    connect(confirmButton, &QPushButton::clicked, this, &CheckboxDialog::onConfirmClicked);
}

void CheckboxDialog::onCheckboxToggled(bool checked) {
    // 统计已选中的复选框数量
    int selectedCount = 0;
    for (QCheckBox *checkBox : m_checkBoxes) {
        if (checkBox->isChecked()) {
            selectedCount++;
        }
    }

    // 如果选中超过两个复选框，禁用其他未选中的复选框
    for (QCheckBox *checkBox : m_checkBoxes) {
        if (selectedCount >= 2 && !checkBox->isChecked()) {
            checkBox->setEnabled(false);
        } else {
            checkBox->setEnabled(true);
        }
    }
}

void CheckboxDialog::onConfirmClicked() {
    // 获取已选择的两个项的下标和文本
    QVector<QPair<int, QString>> selectedItems;
    for (int i = 0; i < m_checkBoxes.size(); ++i) {
        if (m_checkBoxes[i]->isChecked()) {
            selectedItems.append(qMakePair(i, m_checkBoxes[i]->text()));
        }
    }

    // 如果选中了两个项，设置返回值并关闭对话框
    if (selectedItems.size() == 2) {
        qDebug() << "选中的项：" << selectedItems;
        emit selectionConfirmed(selectedItems);  // 发射信号
        accept();  // 关闭对话框
    } else {
        // 如果未选中两个项，弹出提示
        QMessageBox::warning(this, "错误", "请选择两项");
    }
}
