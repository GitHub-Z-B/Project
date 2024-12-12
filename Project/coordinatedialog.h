#ifndef COORDINATEDIALOG_H
#define COORDINATEDIALOG_H

#include <QDialog>
struct ExeInfo {
    char exeName[100];
    int posX;
    int posY;
    int flag;
};

class QPushButton;
class QLineEdit;

class CoordinateDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CoordinateDialog(QString name,QWidget *parent = nullptr);

    int getX() const;
    int getY() const;
    void setX(int x);
    void setY(int y);
public slots:
    void setName(QString name);
    void closeExe();
private slots:
    void onSendCoordinates();  // 点击“确定”按钮后发送坐标
    void onCloseDialog();      // 点击“关闭”按钮后关闭弹窗

private:
    QLineEdit *xEdit;  // 输入 X 坐标的文本框
    QLineEdit *yEdit;  // 输入 Y 坐标的文本框
    QPushButton *sendButton;  // “确定”按钮
    QPushButton *closeButton; // “关闭”按钮
    QString exeName;
    QString ip;
signals:
    void flagopen();
    void sendPoint(int x,int y);
};

#endif // COORDINATEDIALOG_H
