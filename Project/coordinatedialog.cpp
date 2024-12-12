#include "coordinatedialog.h"
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QDebug>
#include <QUdpSocket>
#include <QByteArray>
#include <QApplication>
#include <QScreen>
#include <QSettings>
CoordinateDialog::CoordinateDialog(QString name,QWidget *parent) : QDialog(parent)
{


    // 创建 QSettings 对象，指定配置文件的格式和文件名
    QSettings settings("config.ini", QSettings::IniFormat);

    // 读取 IP 地址
    QString ipAddress = settings.value("Network/IP_Address").toString();

    // 检查 IP 地址是否成功读取
    if (ipAddress.isEmpty()) {
        qWarning() << "未找到 IP 地址配置项。";
    } else {
        qDebug() << "读取到的 IP 地址是：" << ipAddress;
    }
    ip=ipAddress;















    this->exeName=name;
    // 设置无边框
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    // 设置窗口大小
    this->resize(260, 130); // 使用resize而不是setGeometry来设置大小

    // 如果父窗口存在，则相对于父窗口居中
    if (parent) {
        QPoint parentCenter = parent->geometry().center();
        QPoint thisCenter = this->rect().center();
        QPoint newCenter = parentCenter - thisCenter;
        this->move(newCenter);
    }
    // 设置背景颜色和边框样式
    this->setStyleSheet(R"(
        QDialog {
            background-color: #f5f5f5; /* 浅灰色背景 */
            border: 1px solid #d3d3d3; /* 边框浅灰色 */
            border-radius: 10px;       /* 圆角半径 */
        }
        QLineEdit {
            border: 1px solid #cccccc; /* 输入框的边框 */
            border-radius: 5px;        /* 输入框的圆角 */
            padding: 5px;
            background-color: #ffffff; /* 输入框背景为白色 */
            color: #333333;            /* 输入框字体颜色 */
        }
        QPushButton {
            background-color: #a6dcef; /* 浅蓝色按钮背景 */
            color: #ffffff;            /* 按钮文字颜色白色 */
            border: none;
            border-radius: 5px;        /* 按钮圆角 */
            padding: 10px 20px;
        }
        QPushButton:hover {
            background-color: #7fcde9; /* 鼠标悬停时加深按钮颜色 */
        }
        QPushButton:pressed {
            background-color: #4ab8e6; /* 按钮按下时的颜色 */
        }
    )");

    // 创建输入框和按钮
    xEdit = new QLineEdit(this);
    yEdit = new QLineEdit(this);
    sendButton = new QPushButton("确定", this);
    closeButton = new QPushButton("关闭", this);

    // 布局
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    QHBoxLayout *xLayout = new QHBoxLayout();
    QHBoxLayout *yLayout = new QHBoxLayout();
    QHBoxLayout *buttonLayout = new QHBoxLayout();

    xLayout->addWidget(new QLabel("X 坐标:", this));
    xLayout->addWidget(xEdit);
    yLayout->addWidget(new QLabel("Y 坐标:", this));
    yLayout->addWidget(yEdit);

    buttonLayout->addWidget(sendButton);
    buttonLayout->addWidget(closeButton);

    mainLayout->addLayout(xLayout);
    mainLayout->addLayout(yLayout);
    mainLayout->addLayout(buttonLayout);

    // 连接按钮点击事件
    connect(sendButton, &QPushButton::clicked, this, &CoordinateDialog::onSendCoordinates);
    connect(closeButton, &QPushButton::clicked, this, &CoordinateDialog::onCloseDialog);
}

int CoordinateDialog::getX() const {
    return xEdit->text().toInt();
}

int CoordinateDialog::getY() const {
    return yEdit->text().toInt();
}

void CoordinateDialog::setX(int x)
{
    xEdit->setText(QString::number(x));
}

void CoordinateDialog::setY(int y)
{
    yEdit->setText(QString::number(y));
}

void CoordinateDialog::setName(QString name)
{
    this->exeName=name;
}

void CoordinateDialog::closeExe()
{
    QUdpSocket udpSocket;

    // 动态设置结构体字段
    ExeInfo info;

    // 动态赋值字段
    QString exeName = this->exeName; // 这里可以从用户输入或其他动态来源获取
  //  int posX = x;
  //  int posY = y;

    // 使用 toLocal8Bit() 转换为字节数组并复制到 exeName 字段
    QByteArray byteArray = exeName.toLocal8Bit();

    // 显式将 byteArray.size() 转换为 size_t 类型，并手动获取最小值
    size_t len = (byteArray.size() < sizeof(info.exeName) - 1) ? byteArray.size() : sizeof(info.exeName) - 1;
    memcpy(info.exeName, byteArray.constData(), len);

    // 确保 exeName 字符串以 null 结尾
    info.exeName[len] = '\0';

    // 设置 posX 和 posY
  //  info.posX = posX;
   // info.posY = posY;
    info.flag=2;
    // 发送结构体数据到目标地址和端口

    quint16 port = 11223; // 目标端口

    // 发送数据包
    udpSocket.writeDatagram(reinterpret_cast<const char*>(&info), sizeof(info), QHostAddress(ip), port);
}

void CoordinateDialog::onSendCoordinates() {
    int x = getX();
    int y = getY();
    qDebug() << "Sending coordinates: X =" << x << ", Y =" << y<<"name:"<<this->exeName;
    // 创建 QUdpSocket 实例
    QUdpSocket udpSocket;

        // 动态设置结构体字段
        ExeInfo info;

        // 动态赋值字段
        QString exeName = this->exeName; // 这里可以从用户输入或其他动态来源获取
        int posX = x;
        int posY = y;

        // 使用 toLocal8Bit() 转换为字节数组并复制到 exeName 字段
        QByteArray byteArray = exeName.toLocal8Bit();

        // 显式将 byteArray.size() 转换为 size_t 类型，并手动获取最小值
        size_t len = (byteArray.size() < sizeof(info.exeName) - 1) ? byteArray.size() : sizeof(info.exeName) - 1;
        memcpy(info.exeName, byteArray.constData(), len);

        // 确保 exeName 字符串以 null 结尾
        info.exeName[len] = '\0';

        // 设置 posX 和 posY
        info.posX = posX;
        info.posY = posY;
        info.flag=1;
        // 发送结构体数据到目标地址和端口

        quint16 port = 11223; // 目标端口

        // 发送数据包
        udpSocket.writeDatagram(reinterpret_cast<const char*>(&info), sizeof(info), QHostAddress(ip), port);

        qDebug() << "Sent ExeInfo with exeName:" << info.exeName << ", posX:" << info.posX << ", posY:" << info.posY;
         emit flagopen();
        sendPoint(posX,posY);
}

void CoordinateDialog::onCloseDialog() {
    this->close();
}
