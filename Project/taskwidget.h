#pragma once

#include <QWidget>
#include <QUdpSocket>
#include <QProcess>
#include <QSqlError>
#include "tasklistitem.h"
#include "configlistitem.h"
#include "coordinatedialog.h"
#include <QDebug>
#include <QFileDialog>
#include "questionitem.h"
#include "eventitem.h"
#include <QTimer>
#include "dynamicdatawidget.h"
#include <QNetworkDatagram>
#include <QSqlQuery>
#include <QMessageBox>
#include <QDir>
#include "icd.h"
#include "screenimportitem.h"
namespace Ui {
class TaskWidget;
}
struct ScreenImportItemInfo {
    QStringList path;
    QList<int> x;
    QList<int> y;
};
class TaskWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TaskWidget(QWidget *parent = nullptr);
    ~TaskWidget();
    QString type_string();
    void init();
    QString findExecutableInDirectory(const QString &directory, const QString &fileName); //根据exe名字查询整个exe路径
    enum page
    {
        MainWindow_Title,
        TaskWidget_Edit,
        MainWindow_CreateTask

    };

private:
    Ui::TaskWidget *ui;
    QUdpSocket *m_udp;
    ButtonClickEvent receivedData;
    QProcess process;
    int m_question_item_count{0};
    int m_event_item_count{0};
    QTimer *m_task_timer;
    QString m_exePath;
    QString m_pos;
    int return_page_flag=0;
    DynamicDataWidget* m_DynamicDataWidget;
    QUdpSocket *m_recvFZ;
    bool receivingEnabled;
    CoordinateDialog* dialog;
    int JLFlag;
    bool TaskStartFlag=false;
    QStringList exePath;
    QStringList ExePathList;
    QStringList ExePos;
    bool FZFlag=false;
    QList<QString> Trigger_TimeList;
    QString TriggerTime();

public slots:
    void readyRead();
    void task_start();
    void task_edit();
    void task_delete();
    void on_bind_btn_clicked();
    void initUserComboxAndTaskCombox();
    void setReceivingEnabled(bool enabled);
    void ToJLConfig();

private slots:
    void on_add_task_clicked();
    void on_buttonReturn_clicked();
    void on_buttonSave_clicked();
    void on_config_clicked();
    void on_addConfig_clicked();
    void on_configSave_clicked();
    void on_buttonBack_clicked();
    void on_buttonOpen_clicked();
    void on_add_question_clicked();
    void on_add_event_clicked();
    void on_task_return_clicked();
    void on_task_finish_clicked();
    void on_checkBox_type_left_clicked();
    void on_checkBox_type_right_clicked();
    void on_finish_edit_clicked();
    void on_return_JL_btn_clicked();
    void handleReadyRead();
    QStringList getJsonFilenames(const QDir &directory);
    void init_JL_List();
    QStringList findJsonFiles(const QDir &directory);
    void deleteJsonFile(const QString &fileName, const QDir &directory);
    void on_OpenExe_btn_clicked();
    void on_SetPosition_btn_clicked();
    void on_SetPosition_btn_clicked2();
    void on_CloseExe_btn__clicked();
    void on_StartJL_btn_clicked();
    void on_StopJL_btn_clicked();
    void on_JL_Combox_activated(int index);
    void on_StartTask_btn_clicked();
    void on_TaskConfig_clicked();
    void onCheckBoxToggled(bool checked);
    void on_SetPosition_btn_2_clicked();
    void on_CloseExe_btn_1_clicked();
    void on_return_Task_btn_clicked();



    void on_task_Combox_currentTextChanged(const QString &arg1);




    void on_create_task_clicked();

    void on_return_btn_clicked();

signals:
    void closeExe();
    void startTask();
    void SendStartFlag(bool flag);
    void getTriggerTime();
};
