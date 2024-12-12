#ifndef HAFORM_H
#define HAFORM_H

#include <QWidget>
#include "icd.h"
#include <QUdpSocket>
#include <windows.h>
#include <QTime>
#include <tuple>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>
#include <QApplication>
#include <QFileDialog>
#include <QString>
#include <QDebug>
#include <QFileDialog>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QMap>
#include <QDebug>
#include <QUdpSocket>
#include <QTextEdit>
namespace Ui {
class HaForm;
}

class HaForm : public QWidget
{
    Q_OBJECT

public:
    explicit HaForm(QList<QStringList> list,QWidget *parent = nullptr);
    ~HaForm();

    //  通知仪表和触控打开
    struct ExeInfo {
        char exeName[100];
        int posX;
        int posY;
        int flag;
    };
     bool startTask;

    //读取json文件
    QJsonArray buttonsArray;
    //标志点击第一个按钮记为0
    bool flagfirst;
    int TotalNum;//需要点击的次数
    QStringList flagnum;//存储当前目标
    int index;//记录下标对比
    bool flag123;//标志只获取一次当前记录最大值
    int maxNumFlag;//记录最大值
    int maxflag;
    QString findNameById(const QJsonArray &buttons, int id);
    int findIdByName(const QJsonArray &buttons, QString &name);
    QString SurveyTime;
    bool surveyflag;
    bool leftValue;
    bool RightValue;
    QStringList btnIdLeft_Right;

        int getMaxNumFlag(int userId, const QString& taskType, const QString& taskSub);
        int getMaxNumFlag2(int userId, const QString &taskType);

        int getMaxNumFlag3(int userId, QString a1,QString a2,QString a3);
        int getMaxNumFlag4(QString userId, QString a1,QString a2);
        QStringList ab;//存任务开始到结束的标志按钮
        QString previousName;  // 存储前一个数
        QString currentName;   // 存储当前数
        QStringList aaaaaa; //记录任务和任务类型


public slots:
        void startTask1();
signals:
    void windowClosed();

    void ComeToNotificationWidget(int ,QString );
    void boolflag(bool flag); //控制自激励
    void boolflag2(bool flag);//控制仿真激励


protected:
    void closeEvent(QCloseEvent *event) override;
private:
    Ui::HaForm *ui;
    QStringList like;
    QList<QStringList> Target_List;
    QList<QString> Left_Right;
    int UserId;
    QString EventTarget;
    QStringList list;

    bool flaghud;//标志hud是否打开

    int EventNum;//判断 当前事件数量
    QMap<int, QString> buttonMap;  // 存储buttonId和ControlName的映射
    QUdpSocket* m_qudpSocket;
    QUdpSocket* m_qudpSockety;
    QUdpSocket* m_qudpSocket2;


    bool Compare;
    bool o;
    HaForm* h;
    QString username ;
    int id;
    int num;
    int numnum;


    bool flag;

    QString Time;
    int time;  // 记录时间（毫秒）
    QString CurrformattedTime;
    QTimer *timer;
    bool isRunning;
    QTime startTime;
    int elapsedTime;  // 用于保存已过去的时间，单位为毫秒
    bool TimeFlag;
    QString jx1; //用于区间记录
   QString jx2;
    QString jx3;

    bool task1;//处于当前任务循环中
    bool task2;
    bool task3;

    int aa;
    int retryCount;       // 记录重新输入的次数
    int currentIndex;     // 记录当前需要比较的位置
    bool task4;
    bool task5;
    // 用于存储喜好顺序
    QVector<int> likeButtonIds;
    QString CurrentTask;
    bool flagbtnbtn;
    int shortnum;
    int longnum;
    int doublenum;
    QString CurrentSmallTask;
    int currentTaskNum;//定义-存储本次任务操作的次数
    int currentTaskErrorNum;//定义-存储本次任务失败的次数
    int timeFlag;//先定义一个变量，使得只执行一次代码，目的是记录初始时间//定义-计算任务初始时间
    int hour;
    int minute;
    int second;
    int millisecond;
    int hour2;
    int minute2;
    int second2;
    int millisecond2;
    int totalMilliseconds1;
    int totalMilliseconds2;
    int totalMilliseconds3;
    bool smallTaskFlag;//标志小任务

    QString surveyName;
     QString lefttime;
     QString righttime;

private slots:
    void RecvData();
    int findKeyByValue(const QMap<int, int>& map, int value);
    QJsonObject loadJsonFromFile(const QString &filePath);
    void initTime();
    void init();
    QString getCurrentTime();
    void logTask(QTextEdit* logTextEdit, const QString& taskSize, const QString& subTask, const QString& user, const QString& action);
    void logTask2(QTextEdit* logTextEdit, const QString& user, const QString& action);





    void on_pushButton_clicked();


    void on_pushButton1_clicked();
    void updateTime();                // 更新计时器显示


    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

public slots:
    void on_btn_StartTask_clicked();
signals:
    void jieshu();
};

#endif // HAFORM_H
