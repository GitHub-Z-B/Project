#include "confirmdialog.h"
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGraphicsDropShadowEffect>
ConfirmDialog::ConfirmDialog(const QString &message,
                             const QString &yesText,
                             const QString &noText,
                             QWidget *parent) :
    QDialog(parent),
    message(message),
    yesText(yesText),
    noText(noText)
{
    // 设置无标题栏窗口
    setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);

    // 添加阴影效果
    QGraphicsDropShadowEffect *shadowEffect = new QGraphicsDropShadowEffect(this);
    shadowEffect->setBlurRadius(15);  // 阴影模糊半径
    shadowEffect->setOffset(0, 5);    // 阴影偏移
    shadowEffect->setColor(QColor(0, 0, 0, 120)); // 阴影颜色

    // 创建一个 QWidget 容器作为背景
    QWidget *backgroundWidget = new QWidget(this);
    backgroundWidget->setObjectName("backgroundWidget");
    backgroundWidget->setGraphicsEffect(shadowEffect);

    // 设置背景样式，使用 rgba(59, 153, 252, 1) 作为边框颜色
    backgroundWidget->setStyleSheet(
        "#backgroundWidget {"
        "    background-color: #FFFFFF;"   // 白色背景
        "    border-radius: 10px;"         // 圆角
        "    border: 2px solid rgba(59, 153, 252, 1);"  // 蓝色边框，宽度为 2px
        "}"
    );

    // 设置窗口布局和大小
    QVBoxLayout *mainLayout = new QVBoxLayout(backgroundWidget);
    mainLayout->setContentsMargins(20, 20, 20, 20); // 控制边距

    QLabel *label = new QLabel(message, backgroundWidget);
    label->setAlignment(Qt::AlignCenter);
    // 增加标题字体大小，使其更加突出
    label->setStyleSheet("color: #333333; font-size: 18px; font-weight: bold;");

    // 按钮样式
    QPushButton *buttonYes = new QPushButton(yesText, backgroundWidget);
    QPushButton *buttonNo = new QPushButton(noText, backgroundWidget);

    buttonYes->setStyleSheet(
        "QPushButton {"
        "    color: white;"  // 白色文字
        "    background-color: #3B99FC;"  // 蓝色按钮背景
        "    border-radius: 5px;"
        "    padding: 6px 12px;"          // 减少内边距，使按钮看起来不那么大
        "    font-size: 14px;"            // 减少字体大小
        "    border: none;"               // 去掉边框
        "}"
        "QPushButton:hover {"
        "    background-color: #337ACC;"  // 悬停时的按钮颜色
        "}"
        "QPushButton:pressed {"
        "    background-color: #2A6EBF;"  // 按下时的按钮颜色
        "}"
    );

    buttonNo->setStyleSheet(
        "QPushButton {"
        "    color: #333333;"             // 灰色文字
        "    background-color: #EEEEEE;"  // 灰色按钮背景
        "    border-radius: 5px;"
        "    padding: 6px 12px;"          // 减少内边距
        "    font-size: 14px;"            // 减少字体大小
        "    border: 1px solid #CCCCCC;"  // 灰色边框
        "}"
        "QPushButton:hover {"
        "    background-color: #DDDDDD;"  // 悬停时的按钮颜色
        "}"
        "QPushButton:pressed {"
        "    background-color: #CCCCCC;"  // 按下时的按钮颜色
        "}"
    );

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->setSpacing(20); // 按钮间距
    buttonLayout->addWidget(buttonYes);
    buttonLayout->addWidget(buttonNo);

    mainLayout->addWidget(label);
    mainLayout->addLayout(buttonLayout);

    // 设置背景窗口的布局为对话框的主布局
    QVBoxLayout *outerLayout = new QVBoxLayout(this);
    outerLayout->addWidget(backgroundWidget);
    outerLayout->setContentsMargins(0, 0, 0, 0);  // 外部布局无边距

    setLayout(outerLayout);

    // 连接按钮信号
    connect(buttonYes, &QPushButton::clicked, this, &ConfirmDialog::on_buttonYes_clicked);
    connect(buttonNo, &QPushButton::clicked, this, &ConfirmDialog::on_buttonNo_clicked);
}

ConfirmDialog::~ConfirmDialog()
{
}

void ConfirmDialog::on_buttonYes_clicked()
{
    emit confirmed();
    accept(); // 关闭对话框
}

void ConfirmDialog::on_buttonNo_clicked()
{
    emit cancelled();
    reject(); // 关闭对话框
}
