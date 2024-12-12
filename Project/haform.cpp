#include "haform.h"
#include "ui_haform.h"

#include <QFileDialog>
#include <QMainWindow>
#include <QThread>

#include <confirmdialog.h>

ButtonClickEvent receivedData;

HaForm::HaForm(QList<QStringList> list,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HaForm),isRunning(false)
{
    ui->setupUi(this);
    qDebug()<<"targettarget:"<<list;
    Target_List=list;
    startTask=false;
    this->id=id;
    leftValue=true;
    RightValue=true;
    flagfirst=true;
    ui->label_3->setText("任务未进行");
    ui->label_2->setVisible(false);
    ui->lineEdit_6->setVisible(false);

    surveyflag=true;
    flagbtnbtn=false;
    shortnum=0;
    longnum =0;
    doublenum=0;
    flag123=true;
    CurrentTask="";
    CurrentSmallTask="";
    currentTaskNum=0;//定义-存
    currentTaskErrorNum=0;
    hour=0;
    minute=0;
    second=0;
    millisecond=0;
    hour2=0;
    minute2=0;
    second2=0;
    millisecond2=0;
    totalMilliseconds1=0;
    totalMilliseconds2=0;
    totalMilliseconds3=0;
    smallTaskFlag=true;//标志小任务
    flaghud=false;
    m_qudpSockety =new QUdpSocket(this);

    num=0;
    numnum=0;
    this->showMaximized();
    TimeFlag=false;
    ui->lineEdit->setReadOnly(true);
    ui->lineEdit_2->setReadOnly(true);
    m_qudpSocket=new QUdpSocket();
    m_qudpSocket->bind(QHostAddress::AnyIPv4,6500,QUdpSocket::ShareAddress);
    m_qudpSocket->joinMulticastGroup(QHostAddress("224.0.0.0"));
    connect(m_qudpSocket,SIGNAL(readyRead()),this,SLOT(RecvData()));
    flag=false;
    o=false;
    QString fileName = "buttons.json"; // 文件名为 "buttons.json"
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)) {
        //  qDebug() << "无法打开文件:" << file.errorString();
    }
    else
    {
        //   qDebug()<<"成功打开";
    }
    QByteArray jsonData = file.readAll();
    file.close();
    QJsonDocument   doc = QJsonDocument::fromJson(jsonData);
    if (doc.isNull()) {
        //  qDebug() << "解析 JSON 失败";

    }
    buttonsArray = doc.object()["buttons"].toArray();
    QJsonObject jsonObject;
    // 获取当前项目的路径
    QString projectDir = QCoreApplication::applicationDirPath();  // 获取应用程序目录
    QString jsonFilePath = projectDir + "/controls.json";  // 构造 JSO N 文件的完整路径
    qDebug()<<jsonFilePath;
    // 读取 JSON 文件
    jsonObject = loadJsonFromFile(jsonFilePath);
    if (!jsonObject.isEmpty()) {
        qDebug() << "JSON Content:" << jsonObject;
    }

    QJsonArray jsonArray = jsonObject["controls"].toArray();
    for (const QJsonValue& value : jsonArray) {
        QJsonObject obj = value.toObject();
        int buttonId = obj["buttonId"].toInt();
        QString controlName = obj["ControlName"].toString();
        buttonMap.insert(buttonId, controlName);  // 插入到 map 中
    }

    // 打印测试
    for (auto it = buttonMap.cbegin(); it != buttonMap.cend(); ++it) {
        //   qDebug() << "ButtonId:" << it.key() << ", ControlName:" << it.value();
    }


    // foreach (auto item, Left_Right) {
    //     btnIdLeft_Right.append(QString::number(findIdByName(buttonsArray,item)));
    // }


     ab.append(Target_List[0][0]);
     ab.append(Target_List[0][Target_List[0].size()-1]);
     aaaaaa.append(findNameById(buttonsArray,Target_List[0][0].toInt()));
     aaaaaa.append(findNameById(buttonsArray,Target_List[0][1].toInt()));
   //  qDebug()<<"left_right"<<Left_Right<<" "<<btnIdLeft_Right;



     QStringList listlist= Target_List[0];
     QStringList nameList;

     for (auto item : listlist) {
         nameList.append(findNameById(buttonsArray,item.toInt()));


     }
     QString name=nameList.join(",");

     m_qudpSockety->writeDatagram(QString("请点击 ：").toUtf8(),QHostAddress("127.0.0.1"),22345);
     m_qudpSockety->writeDatagram(name.toUtf8(),QHostAddress("127.0.0.1"),22345);




}
void HaForm::RecvData()//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
{
    if(startTask)
    {

        QByteArray array;
        array.resize(m_qudpSocket->bytesAvailable());
        m_qudpSocket->readDatagram(array.data(),array.size());
        memcpy(&receivedData,array.data(),sizeof(ButtonClickEvent));


        // QByteArray byteArray;
        //  while(m_qudpSocket->hasPendingDatagrams())
        //  {
        //      byteArray.resize(m_qudpSocket->pendingDatagramSize());
        //      m_qudpSocket->readDatagram(byteArray.data(), byteArray.size());
        //      memcpy(&receivedData, byteArray.data(), sizeof(ButtonClickEvent));

        //  Time=receivedData.hour;

        //   }

        hour=receivedData.hour;
        minute=receivedData.minute;
        second=receivedData.second;
        millisecond=receivedData.millisecond;
        totalMilliseconds1 = hour * 3600000 + minute * 60000 + second * 1000 + millisecond;
        int timeDifference =  totalMilliseconds1;
        int diffHour = timeDifference / 3600000;
        int diffMinute = (timeDifference % 3600000) / 60000;
        int diffSecond = (timeDifference % 60000) / 1000;
        int diffMillisecond = timeDifference % 1000;
        QTime time(diffHour, diffMinute, diffSecond, diffMillisecond);
        CurrformattedTime = time.toString("HH:mm:ss.zzz");  // 格式化为 HH:mm:ss.zzz
        logTask(ui->textEdit,CurrentTask,CurrentSmallTask,username,buttonMap[receivedData.buttonId]);
        qDebug()<<"totalnum:"<<TotalNum;

        qDebug()<<"receivedData.button:"<<receivedData.buttonId;
        qDebug()<<"name:"<<findNameById(buttonsArray,receivedData.buttonId)<<"name2:"<<buttonMap[receivedData.buttonId]<<"ad[1]:"<<ab[1]<<"status"<<receivedData.status;

        QStringList jxList=jx1.split(",");

        if(jxList[0]!=""&&jxList[0]!="-1" && jxList[1]!="-1")
        {

            if(receivedData.buttonId==jxList[0].toInt())
            {
                lefttime=CurrformattedTime;
            }


            if(receivedData.buttonId==jxList[1].toInt())
            {
                righttime=CurrformattedTime;
            }

        }


        if(Target_List[0].contains("104001")||Target_List[0].contains("106001")) //检测喜好检测
        {
            aaaaaa.clear();
            aaaaaa.append(findNameById(buttonsArray,Target_List[0][0].toInt()));
            aaaaaa.append(findNameById(buttonsArray,Target_List[0][1].toInt()));
            aaaaaa.append(findNameById(buttonsArray,Target_List[0][2].toInt()));


            if(receivedData.buttonId==104006||receivedData.buttonId==106006)
            {

            }
            else
            {
                if(like.size()==4)
                {
                    like.removeFirst();
                }
                else if(receivedData.buttonId==204005||receivedData.buttonId==205005)
                {
                    like.clear();
                }
                like.append(QString::number(receivedData.buttonId));
            }

            qDebug()<<"like:::::"<<like;
            if(receivedData.buttonId==104006||receivedData.buttonId==106006)//完成了，存入数据库
            {
                QSqlQuery query;
                if(flag123)
                {
                    maxNumFlag = getMaxNumFlag3(UserId,aaaaaa[0],aaaaaa[1],aaaaaa[2]);
                    flag123=false;
                }
                query.prepare("INSERT INTO likeorder (UserId, TaskRoot,TaskType,TypeSub,OrderLike,NumFlag) VALUES (:userid, :taskroot,:tasktype,:tasksub,:orderlike,:numflag)");
                query.bindValue(":userid",UserId );
                query.bindValue(":taskroot", aaaaaa[0]);
                query.bindValue(":tasktype", aaaaaa[1]);
                query.bindValue(":tasksub", aaaaaa[2]);
                QString order=like.join(",");
                query.bindValue(":orderlike",order);
                if(maxNumFlag!=-1)
                {
                    query.bindValue(":numflag",QString::number(UserId)+"_"+QString::number(maxNumFlag+1));
                }
                else
                {
                    query.bindValue(":numflag",QString::number(UserId)+"_1");
                }

                if(!query.exec())
                {
                    qDebug()<<"控件操作结果表插入失败1"<<query.lastError().text();
                }
                else
                {
                    qDebug()<<"成功！！！！！！！！！！！！！！！！！！";
                }
            }


        }else
        {
            //============================================================================================================================================================================================================result2

            if(receivedData.buttonId==107001||receivedData.buttonId==108001 ||flagbtnbtn) //检测按键时间和好双击按键逻辑
            {

                flagbtnbtn=true;//向数据库插入按键操作时间实验和 双击按键逻辑的任务

                QSqlQuery query;
                qDebug()<<"abababababab:"<<ab;
                if(receivedData.buttonId==ab[0].toInt())//记录第一个
                {
                    if(flag123)
                    {
                        maxNumFlag = getMaxNumFlag2(UserId, CurrentTask);
                        maxflag=maxNumFlag;
                        flag123=false;
                    }
                    query.prepare("INSERT INTO result2 (UserId, TaskType,ControlName,Time,Flag,NumFlag,Start_End) VALUES (:userid, :tasktype,:controlname,:time,:flag,:numflag,:start_end)");
                    query.bindValue(":userid",UserId );
                    query.bindValue(":tasktype", CurrentTask);
                    query.bindValue(":tasksub",CurrentSmallTask );
                    query.bindValue(":controlname",buttonMap[receivedData.buttonId]);
                    query.bindValue(":time",CurrformattedTime);
                    query.bindValue(":flag","");
                    if(maxNumFlag!=-1)
                    {
                        query.bindValue(":numflag",QString::number(UserId)+"_"+QString::number(maxNumFlag+1));
                    }
                    else
                    {

                        query.bindValue(":numflag",QString::number(UserId)+"_1");
                    }
                    query.bindValue(":start_end","0");
                    if(!query.exec())
                    {
                        qDebug()<<"控件操作结果表插入失败1"<<query.lastError().text();
                    }
                    else
                    {
                        qDebug()<<"成功！！！！！！！！！！！！！！！！！！";
                    }
                }
                else if(receivedData.buttonId==ab[1].toInt())//记录最后一个
                {
                    if(flag123)
                    {
                        maxNumFlag = getMaxNumFlag2(UserId, CurrentTask);
                        maxflag=maxNumFlag;
                        flag123=false;
                    }
                    query.prepare("INSERT INTO result2 (UserId, TaskType,ControlName,Time,Flag,NumFlag,Start_End) VALUES (:userid, :tasktype,:controlname,:time,:flag,:numflag,:start_end)");
                    query.bindValue(":userid",UserId );
                    query.bindValue(":tasktype", CurrentTask);
                    query.bindValue(":tasksub",CurrentSmallTask );
                    query.bindValue(":controlname",buttonMap[receivedData.buttonId]);
                    query.bindValue(":time",CurrformattedTime);
                    query.bindValue(":flag","");
                    if(maxNumFlag!=-1)
                    {
                        query.bindValue(":numflag",QString::number(UserId)+"_"+QString::number(maxNumFlag+1));
                    }
                    else
                    {
                        query.bindValue(":numflag",QString::number(UserId)+"_1");
                    }
                    query.bindValue(":start_end","");
                    if(!query.exec())
                    {
                        qDebug()<<"控件操作结果表插入失败1"<<query.lastError().text();
                    }
                    else
                    {
                        qDebug()<<"成功！！！！！！！！！！！！！！！！！！";
                    }
                }

                else
                {
                    QSqlQuery query;
                    if(flag123)
                    {
                        maxNumFlag = getMaxNumFlag2(UserId, CurrentTask);
                        maxflag=maxNumFlag;
                        flag123=false;
                    }
                    if(receivedData.buttonId==107005 || receivedData.buttonId==107006 || receivedData.buttonId==107007 || receivedData.buttonId==108005 || receivedData.buttonId==108006 || receivedData.buttonId==108007 || receivedData.buttonId==108008 || receivedData.buttonId==108009 || receivedData.buttonId==108010 || receivedData.buttonId==108011 || receivedData.buttonId==108012 || receivedData.buttonId==108013 || receivedData.buttonId==108014)
                    {
                        if(receivedData.status==1)
                        {
                            query.prepare("INSERT INTO result2 (UserId, TaskType,ControlName,Time,Flag,NumFlag,Start_End) VALUES (:userid, :tasktype,:controlname,:time,:flag,:numflag,start_end)");
                            query.bindValue(":userid",UserId );
                            query.bindValue(":tasktype", CurrentTask);
                            previousName = currentName;  // 更新前一个数
                            currentName = buttonMap[receivedData.buttonId];  // 假设 buttonId 是接收数据中要存储的值
                            if(currentName!="短按按键" && currentName!="长按按键" && currentName!="双击按键" && currentName!="按键1" && currentName!="按键2"&&
                                    currentName!="按键3" && currentName!="按键4" && currentName!="按键5" && currentName!="按键6" && currentName!="按键7" && currentName!="按键8" && currentName!="按键9" && currentName!="按键10")
                            {
                                query.bindValue(":controlname",previousName);
                            }
                            else
                            {
                                query.bindValue(":controlname",buttonMap[receivedData.buttonId]);
                            }

                            query.bindValue(":time",CurrformattedTime);
                            query.bindValue(":flag",1);

                            if(maxNumFlag!=-1)
                            {
                                query.bindValue(":numflag",QString::number(UserId)+"_"+QString::number(maxNumFlag+1));
                            }
                            else
                            {
                                query.bindValue(":numflag",QString::number(UserId)+"_1");
                            }
                            query.bindValue(":start_end","");
                            if(!query.exec())
                            {
                                qDebug()<<"控件操作结果表插入失败1"<<query.lastError().text();
                            }
                            else
                            {
                                qDebug()<<"成功！！！！！！！！！！！！！！！！！！";
                            }
                        }
                        else
                        {
                            query.prepare("INSERT INTO result2 (UserId, TaskType,ControlName,Time,Flag,NumFlag,Start_End) VALUES (:userid, :tasktype,:controlname,:time,:flag,:numflag,start_end)");
                            query.bindValue(":userid",UserId );
                            query.bindValue(":tasktype", CurrentTask);
                            previousName = currentName;  // 更新前一个数
                            currentName = buttonMap[receivedData.buttonId];  // 假设 buttonId 是接收数据中要存储的值
                            if(currentName!="短按按键" && currentName!="长按按键" && currentName!="双击按键" && currentName!="按键1" && currentName!="按键2"&&
                                    currentName!="按键3" && currentName!="按键4" && currentName!="按键5" && currentName!="按键6" && currentName!="按键7" && currentName!="按键8" && currentName!="按键9" && currentName!="按键10")
                            {
                                query.bindValue(":controlname",previousName);
                            }
                            else
                            {
                                query.bindValue(":controlname",buttonMap[receivedData.buttonId]);
                            }

                            query.bindValue(":time",CurrformattedTime);
                            query.bindValue(":flag","");

                            if(maxNumFlag!=-1)
                            {
                                query.bindValue(":numflag",QString::number(UserId)+"_"+QString::number(maxNumFlag+1));
                            }
                            else
                            {
                                query.bindValue(":numflag",QString::number(UserId)+"_1");
                            }
                            query.bindValue(":start_end","");
                            if(!query.exec())
                            {
                                qDebug()<<"控件操作结果表插入失败1"<<query.lastError().text();
                            }
                            else
                            {
                                qDebug()<<"成功！！！！！！！！！！！！！！！！！！";
                            }
                        }
                    }
                    else
                    {
                        query.prepare("INSERT INTO result2 (UserId, TaskType,ControlName,Time,Flag,NumFlag,Start_End) VALUES (:userid, :tasktype,:controlname,:time,:flag,:numflag,start_end)");
                        query.bindValue(":userid",UserId );
                        query.bindValue(":tasktype", CurrentTask);
                        previousName = currentName;  // 更新前一个数
                        currentName = buttonMap[receivedData.buttonId];  // 假设 buttonId 是接收数据中要存储的值
                        if(currentName!="短按按键" && currentName!="长按按键" && currentName!="双击按键" && currentName!="按键1" && currentName!="按键2"&&
                                currentName!="按键3" && currentName!="按键4" && currentName!="按键5" && currentName!="按键6" && currentName!="按键7" && currentName!="按键8" && currentName!="按键9" && currentName!="按键10")
                        {
                            query.bindValue(":controlname",previousName);
                        }
                        else
                        {
                            query.bindValue(":controlname",buttonMap[receivedData.buttonId]);
                        }

                        query.bindValue(":time",CurrformattedTime);
                        query.bindValue(":flag","");

                        if(maxNumFlag!=-1)
                        {
                            query.bindValue(":numflag",QString::number(UserId)+"_"+QString::number(maxNumFlag+1));
                        }
                        else
                        {
                            query.bindValue(":numflag",QString::number(UserId)+"_1");
                        }
                        query.bindValue(":start_end","");
                        if(!query.exec())
                        {
                            qDebug()<<"控件操作结果表插入失败1"<<query.lastError().text();
                        }
                        else
                        {
                            qDebug()<<"成功！！！！！！！！！！！！！！！！！！";
                        }
                    }



                }



            }else
            {
                QSqlQuery query;
                qDebug()<<"==--=-=-=--==================================================================进到result11";
                //第一个点击按钮====================================================================================================================================================================================================================================================================== result



                //无论对错，直接插入，当作开始任务标志
                if(flagfirst)
                {
                    if(flag123)
                    {
                        maxNumFlag = getMaxNumFlag(UserId, CurrentTask, CurrentSmallTask);
                        flag123=false;
                    }
                    query.prepare("INSERT INTO result (UserId, TaskType, TaskSub,ControlName,Time,Flag,NumFlag,Start_End) VALUES (:userid, :tasktype, :tasksub,:controlname,:time,:flag,:numflag,:start_end)");
                    query.bindValue(":userid",UserId );
                    query.bindValue(":tasktype", CurrentTask);
                    query.bindValue(":tasksub",CurrentSmallTask );
                    query.bindValue(":controlname",buttonMap[receivedData.buttonId]);
                    query.bindValue(":time",CurrformattedTime);
                    query.bindValue(":flag",1);
                    if(maxNumFlag!=-1)
                    {
                        query.bindValue(":numflag",QString::number(UserId)+"_"+QString::number(maxNumFlag+1));
                    }
                    else
                    {
                        query.bindValue(":numflag",QString::number(UserId)+"_1");
                    }
                    query.bindValue(":start_end","0");
                    if(!query.exec())
                    {
                        qDebug()<<"控件操作结果表插入失败112345678"<<query.lastError().text();
                    }
                    else
                    {
                        qDebug()<<"成功！！！！！！！！！！！！！！！！！！";
                    }
                    flagfirst=false;
                }


                if(receivedData.buttonId==ab[0].toInt())//第一个按钮
                {
                    if(flagfirst)
                    {
                        if(flag123)
                        {
                            maxNumFlag = getMaxNumFlag(UserId, CurrentTask, CurrentSmallTask);
                            flag123=false;
                        }
                        query.prepare("INSERT INTO result (UserId, TaskType, TaskSub,ControlName,Time,Flag,NumFlag,Start_End) VALUES (:userid, :tasktype, :tasksub,:controlname,:time,:flag,:numflag,:start_end)");
                        query.bindValue(":userid",UserId );
                        query.bindValue(":tasktype", CurrentTask);
                        query.bindValue(":tasksub",CurrentSmallTask );
                        query.bindValue(":controlname",buttonMap[ab[0].toInt()]);
                        query.bindValue(":time",CurrformattedTime);
                        query.bindValue(":flag",1);
                        if(maxNumFlag!=-1)
                        {
                            query.bindValue(":numflag",QString::number(UserId)+"_"+QString::number(maxNumFlag+1));
                        }
                        else
                        {
                            query.bindValue(":numflag",QString::number(UserId)+"_1");
                        }
                        query.bindValue(":start_end","0");
                        if(!query.exec())
                        {
                            qDebug()<<"控件操作结果表插入失败1"<<query.lastError().text();
                        }
                        else
                        {
                            qDebug()<<"成功！！！！！！！！！！！！！！！！！！";
                        }
                    }

                }
                else if(receivedData.buttonId==ab[1].toInt()) //最后一个按钮

                {

                    if(flag123)
                    {
                        maxNumFlag = getMaxNumFlag(UserId, CurrentTask, CurrentSmallTask);
                        flag123=false;
                    }
                    query.prepare("INSERT INTO result (UserId, TaskType, TaskSub,ControlName,Time,Flag,NumFlag,Start_End) VALUES (:userid, :tasktype, :tasksub,:controlname,:time,:flag,:numflag,:start_end)");
                    query.bindValue(":userid",UserId );
                    query.bindValue(":tasktype", CurrentTask);
                    query.bindValue(":tasksub",CurrentSmallTask );
                    query.bindValue(":controlname",buttonMap[receivedData.buttonId]);
                    query.bindValue(":time",CurrformattedTime);
                    query.bindValue(":flag",1);
                    if(maxNumFlag!=-1)
                    {
                        query.bindValue(":numflag",QString::number(UserId)+"_"+QString::number(maxNumFlag+1));
                    }
                    else
                    {
                        query.bindValue(":numflag",QString::number(UserId)+"_1");
                    }
                    query.bindValue(":start_end","1");
                    if(!query.exec())
                    {
                        qDebug()<<"控件操作结果表插入失败1"<<query.lastError().text();
                    }
                    else
                    {
                        qDebug()<<"成功！！！！！！！！！！！！！！！！！！";
                    }
                }
                else
                {

                    if(index>=TotalNum)
                    {

                    }
                    else
                    {
                        qDebug()<<"进到result11:"<<flagnum<<index;
                        qDebug()<<"flagnum[index].toInt()"<<flagnum[index].toInt();
                        qDebug()<<"receivedData.buttonId"<<receivedData.buttonId<<index;

                        qDebug()<<"receivedData.buttonId11"<<receivedData.buttonId<<index<<btnIdLeft_Right<<flagnum;
                        //  好

                        if(flagnum[index].toInt()==receivedData.buttonId) //相等的情况
                        {





                            //判断是否是左值  L
                            if(receivedData.buttonId==btnIdLeft_Right[0].toInt())
                            {


                                if(flag123)
                                {
                                    maxNumFlag = getMaxNumFlag(UserId, CurrentTask, CurrentSmallTask);
                                    flag123=false;
                                }
                                query.prepare("INSERT INTO result (UserId, TaskType, TaskSub,ControlName,Time,Flag,NumFlag,Start_End) VALUES (:userid, :tasktype, :tasksub,:controlname,:time,:flag,:numflag,:start_end)");
                                query.bindValue(":userid",UserId );
                                query.bindValue(":tasktype", CurrentTask);
                                query.bindValue(":tasksub",CurrentSmallTask );
                                query.bindValue(":controlname",buttonMap[receivedData.buttonId]);
                                query.bindValue(":time",CurrformattedTime);
                                query.bindValue(":flag",1);
                                if(maxNumFlag!=-1)
                                {
                                    query.bindValue(":numflag",QString::number(UserId)+"_"+QString::number(maxNumFlag+1));
                                }
                                else
                                {
                                    query.bindValue(":numflag",QString::number(UserId)+"_1");
                                }
                                if(leftValue)
                                {
                                    leftValue=false;
                                    query.bindValue(":start_end","L");
                                }
                                else
                                {
                                    query.bindValue(":start_end","");
                                }
                                if(!query.exec())
                                {
                                    qDebug()<<"控件操作结果表插入失败1"<<query.lastError().text();
                                }
                                else
                                {
                                    qDebug()<<"成功！！！！！！！！！！！！！！！！！！";
                                }








                            }else if(receivedData.buttonId==btnIdLeft_Right[1].toInt())
                            {








                                if(flag123)
                                {
                                    maxNumFlag = getMaxNumFlag(UserId, CurrentTask, CurrentSmallTask);
                                    flag123=false;
                                }
                                query.prepare("INSERT INTO result (UserId, TaskType, TaskSub,ControlName,Time,Flag,NumFlag,Start_End) VALUES (:userid, :tasktype, :tasksub,:controlname,:time,:flag,:numflag,:start_end)");
                                query.bindValue(":userid",UserId );
                                query.bindValue(":tasktype", CurrentTask);
                                query.bindValue(":tasksub",CurrentSmallTask );
                                query.bindValue(":controlname",buttonMap[receivedData.buttonId]);
                                query.bindValue(":time",CurrformattedTime);
                                query.bindValue(":flag",1);
                                if(maxNumFlag!=-1)
                                {
                                    query.bindValue(":numflag",QString::number(UserId)+"_"+QString::number(maxNumFlag+1));
                                }
                                else
                                {
                                    query.bindValue(":numflag",QString::number(UserId)+"_1");
                                }
                                if(RightValue)
                                {
                                    RightValue=false;
                                    query.bindValue(":start_end","R");
                                }
                                else
                                {
                                    query.bindValue("start_end","");
                                }
                                if(!query.exec())
                                {
                                    qDebug()<<"控件操作结果表插入失败1"<<query.lastError().text();
                                }
                                else
                                {
                                    qDebug()<<"成功！！！！！！！！！！！！！！！！！！";
                                }










                            }
                            else
                            {

                                if(flag123)
                                {
                                    maxNumFlag = getMaxNumFlag(UserId, CurrentTask, CurrentSmallTask);
                                    flag123=false;
                                }
                                query.prepare("INSERT INTO result (UserId, TaskType, TaskSub,ControlName,Time,Flag,NumFlag,Start_End) VALUES (:userid, :tasktype, :tasksub,:controlname,:time,:flag,:numflag,:start_end)");
                                query.bindValue(":userid",UserId );
                                query.bindValue(":tasktype", CurrentTask);
                                query.bindValue(":tasksub",CurrentSmallTask );
                                query.bindValue(":controlname",buttonMap[receivedData.buttonId]);
                                query.bindValue(":time",CurrformattedTime);
                                query.bindValue(":flag",1);
                                if(maxNumFlag!=-1)
                                {
                                    query.bindValue(":numflag",QString::number(UserId)+"_"+QString::number(maxNumFlag+1));
                                }
                                else
                                {
                                    query.bindValue(":numflag",QString::number(UserId)+"_1");
                                }
                                query.bindValue(":start_end","");
                                if(!query.exec())
                                {
                                    qDebug()<<"控件操作结果表插入失败1"<<query.lastError().text();
                                }
                                else
                                {
                                    qDebug()<<"成功！！！！！！！！！！！！！！！！！！";
                                }
                            }
                        }
                        else
                        {
                            //判断是否是左值  L
                            if(receivedData.buttonId==btnIdLeft_Right[0].toInt())
                            {








                                if(flag123)
                                {
                                    maxNumFlag = getMaxNumFlag(UserId, CurrentTask, CurrentSmallTask);
                                    flag123=false;
                                }
                                query.prepare("INSERT INTO result (UserId, TaskType, TaskSub,ControlName,Time,Flag,NumFlag,Start_End) VALUES (:userid, :tasktype, :tasksub,:controlname,:time,:flag,:numflag,:start_end)");
                                query.bindValue(":userid",UserId );
                                query.bindValue(":tasktype", CurrentTask);
                                query.bindValue(":tasksub",CurrentSmallTask );
                                query.bindValue(":controlname",buttonMap[receivedData.buttonId]);
                                query.bindValue(":time",CurrformattedTime);
                                query.bindValue(":flag",1);
                                if(maxNumFlag!=-1)
                                {
                                    query.bindValue(":numflag",QString::number(UserId)+"_"+QString::number(maxNumFlag+1));
                                }
                                else
                                {
                                    query.bindValue(":numflag",QString::number(UserId)+"_1");
                                }
                                if(leftValue)
                                {
                                    leftValue=false;
                                    query.bindValue(":start_end","L");
                                }
                                else
                                {
                                    query.bindValue(":start_end","");
                                }

                                if(!query.exec())
                                {
                                    qDebug()<<"控件操作结果表插入失败1"<<query.lastError().text();
                                }
                                else
                                {
                                    qDebug()<<"成功！！！！！！！！！！！！！！！！！！";
                                }
                            }else if(receivedData.buttonId==btnIdLeft_Right[1].toInt())
                            {
                                if(flag123)
                                {
                                    maxNumFlag = getMaxNumFlag(UserId, CurrentTask, CurrentSmallTask);
                                    flag123=false;
                                }
                                query.prepare("INSERT INTO result (UserId, TaskType, TaskSub,ControlName,Time,Flag,NumFlag,Start_End) VALUES (:userid, :tasktype, :tasksub,:controlname,:time,:flag,:numflag,:start_end)");
                                query.bindValue(":userid",UserId );
                                query.bindValue(":tasktype", CurrentTask);
                                query.bindValue(":tasksub",CurrentSmallTask );
                                query.bindValue(":controlname",buttonMap[receivedData.buttonId]);
                                query.bindValue(":time",CurrformattedTime);
                                query.bindValue(":flag",1);
                                if(maxNumFlag!=-1)
                                {
                                    query.bindValue(":numflag",QString::number(UserId)+"_"+QString::number(maxNumFlag+1));
                                }
                                else
                                {
                                    query.bindValue(":numflag",QString::number(UserId)+"_1");
                                }
                                if(RightValue)
                                {
                                    RightValue=false;
                                    query.bindValue(":start_end","R");
                                }
                                else
                                {
                                    query.bindValue("start_end","");
                                }
                                if(!query.exec())
                                {
                                    qDebug()<<"控件操作结果表插入失败1"<<query.lastError().text();
                                }
                                else
                                {
                                    qDebug()<<"成功！！！！！！！！！！！！！！！！！！";
                                }
                            }else
                            {
                                //判断是否是右值 R
                                QSqlQuery query;
                                //判断当地一个按钮对了再插入数据
                                if(flag123)
                                {
                                    maxNumFlag = getMaxNumFlag(UserId, CurrentTask, CurrentSmallTask);
                                    flag123=false;
                                }


                                query.prepare("INSERT INTO result (UserId, TaskType, TaskSub,ControlName,Time,Flag,NumFlag,Start_End) VALUES (:userid, :tasktype, :tasksub,:controlname,:time,:flag,:numflag,:start_end)");
                                query.bindValue(":userid",UserId );
                                query.bindValue(":tasktype", CurrentTask);
                                query.bindValue(":tasksub",CurrentSmallTask );
                                query.bindValue(":controlname",buttonMap[receivedData.buttonId]);
                                query.bindValue(":time",CurrformattedTime);
                                query.bindValue(":flag",0);
                                if(maxNumFlag!=-1)
                                {
                                    query.bindValue(":numflag",QString::number(UserId)+"_"+QString::number(maxNumFlag+1));
                                }
                                else
                                {
                                    query.bindValue(":numflag",QString::number(UserId)+"_1");
                                }
                                query.bindValue(":start_end","");
                                if(!query.exec())
                                {
                                    qDebug()<<"控件操作结果表插入失败1"<<query.lastError().text();
                                }
                                else
                                {
                                    qDebug()<<"成功！！！！！！！！！！！！！！";
                                }
                            }

                        }

                    }
                }
                if(receivedData.buttonId==202012)
                {
                    TotalNum--;
                    index--;
                }
                else
                {
                    if(index<TotalNum)
                        index++;
                }
            }

        }
    }
}

HaForm::~HaForm()
{

    delete ui;
}
void HaForm::updateTime()
{
    // 每次定时器触发时，更新时间
    time++;

    // 将毫秒数转换为小时、分钟、秒、毫秒
    int hours = time / 3600000;
    int minutes = (time % 3600000) / 60000;
    int seconds = (time % 60000) / 1000;
    int milliseconds = time % 1000;

    // 格式化输出为 "00:00:00:00" 的格式
    QString timeString = QString::asprintf("%02d:%02d:%02d:%03d", hours, minutes, seconds, milliseconds);
    ui->lineEdit_6->setText(timeString);  // 显示在lineEdit中
}

void HaForm::on_btn_StartTask_clicked()
{
    startTask=true;
    ui->label_3->setText("任务进行中");
    QStringList list= EventTarget.split(",");
    QStringList nameList;

    for (auto item : list) {
        nameList.append(findNameById(buttonsArray,item.toInt()));


    }
    QString name=nameList.join(",");

    m_qudpSockety->writeDatagram(QString("请点击 ：").toUtf8(),QHostAddress("127.0.0.1"),22345);
    m_qudpSockety->writeDatagram(name.toUtf8(),QHostAddress("127.0.0.1"),22345);
    if(flagbtnbtn)
    {
        m_qudpSockety->writeDatagram("请点击 ："+name.toUtf8()+"：每个按键操作五次",QHostAddress("127.0.0.1"),22345);
    }



}

QString HaForm::findNameById(const QJsonArray &buttons, int id)
{
    for (const QJsonValue &buttonValue : buttons) {
        QJsonObject buttonObject = buttonValue.toObject();
        int buttonId = buttonObject["buttonId"].toInt();

        if (buttonId == id) {
            return buttonObject["name"].toString();
        }

        if (buttonObject.contains("children")) {
            QString name = findNameById(buttonObject["children"].toArray(), id);
            if (!name.isEmpty()) {
                return name;
            }
        }
    }
    return QString();
}

int HaForm::findIdByName(const QJsonArray &buttons, QString &name)
{
    // 遍历按钮数组中的每个按钮
    for (const QJsonValue &buttonValue : buttons) {
        // 将 QJsonValue 转换为 QJsonObject
        QJsonObject buttonObject = buttonValue.toObject();

        // 获取按钮名称
        QString buttonName = buttonObject["name"].toString();

        // 如果按钮名称匹配，返回该按钮的 ID
        if (buttonName == name) {
            return buttonObject["buttonId"].toInt();
        }

        // 如果按钮有 "children" 字段，递归查找子按钮
        if (buttonObject.contains("children")) {
            int id = findIdByName(buttonObject["children"].toArray(), name);
            // 如果在子按钮中找到了匹配的 ID，返回它
            if (id != -1) {
                return id;
            }
        }
    }

    // 如果没有找到匹配的按钮，返回 -1
    return -1;
}



int HaForm::getMaxNumFlag(int userId, const QString &taskType, const QString &taskSub)
{
    QString queryStr = "SELECT NumFlag FROM result WHERE UserId = :userId AND TaskType = :taskType AND TaskSub = :taskSub";
    int max=-1;
    QSqlQuery query;
    query.prepare(queryStr);
    query.bindValue(":userId", userId);
    query.bindValue(":taskType", taskType);
    query.bindValue(":taskSub", taskSub);

    if (query.exec()) {
        while(query.next())
        {
            QString numflag = query.value(0).toString(); // 获取 MAX(NumFlag) 的值
            if(!numflag.isEmpty())
            {
                QStringList a = numflag.split("_");
                if(a[1].toInt()>max)
                {
                    max=a[1].toInt();
                }

            }
        }
        if(max!=-1)
        {
            return max;
        }
        else {
            qDebug() << "No result found";
            return -1; // 如果没有找到数据，返回一个标志值
        }
    } else {
        qDebug() << "SQL error:" << query.lastError();
        return -1; // 查询失败，返回一个标志值
    }
}
int HaForm::getMaxNumFlag2(int userId, const QString &taskType)
{
    QString queryStr = "SELECT NumFlag FROM  result2 WHERE UserId = :userId AND TaskType = :taskType";
    int max=-1;
    QSqlQuery query;
    query.prepare(queryStr);
    query.bindValue(":userId", userId);
    query.bindValue(":taskType", taskType);

    if (query.exec()) {
        while(query.next())
        {
            QString numflag = query.value(0).toString(); // 获取 MAX(NumFlag) 的值
            if(!numflag.isEmpty())
            {
                QStringList a = numflag.split("_");
                if(a[1].toInt()>max)
                {
                    max=a[1].toInt();
                }

            }
        }
        if(max!=-1)
        {
            return max;
        }
        else {
            qDebug() << "No result found";
            return -1; // 如果没有找到数据，返回一个标志值
        }
    } else {
        qDebug() << "SQL error:" << query.lastError();
        return -1; // 查询失败，返回一个标志值
    }
}
int HaForm::getMaxNumFlag3(int userId, QString a1,QString a2,QString a3)
{


    QString queryStr = "SELECT NumFlag FROM  likeorder WHERE UserId = :userId";
    int max=-1;
    QSqlQuery query;
    query.prepare(queryStr);
    query.bindValue(":userId", userId);

    qDebug()<<"qwerty:"<<userId<<a1<<a2<<a3;
    if (query.exec()) {
        while(query.next())
        {
            QString numflag = query.value(0).toString(); // 获取 MAX(NumFlag) 的值
            if(!numflag.isEmpty())
            {
                QStringList a = numflag.split("_");
                qDebug()<<"aaaaaaaaa:"<<a;
                if(a[1].toInt()>max)
                {
                    max=a[1].toInt();
                }
            }
        }
        if(max!=-1)
        {
            return max;
        }
        else {
            qDebug() << "No result found";
            return -1; // 如果没有找到数据，返回一个标志值
        }
    } else {
        qDebug() << "SQL error:" << query.lastError();
        return -1; // 查询失败，返回一个标志值
    }








}

int HaForm::getMaxNumFlag4(QString userId, QString a1, QString a2)
{
    QString queryStr = "SELECT NumFlag FROM  target WHERE UserId = :userId AND TaskType = :taskType AND TaskSub = :taskSub";
    int max=-1;
    QSqlQuery query;
    query.prepare(queryStr);
    query.bindValue(":userId", userId);
    query.bindValue(":taskType", a1);
    query.bindValue(":taskSub", a2);

    if (query.exec()) {
        while(query.next())
        {
            QString numflag = query.value(0).toString(); // 获取 MAX(NumFlag) 的值
            if(!numflag.isEmpty())
            {
                QStringList a = numflag.split("_");
                if(a[1].toInt()>max)
                {
                    max=a[1].toInt();
                }

            }
        }
        if(max!=-1)
        {
            return max;
        }
        else {
            qDebug() << "No result found";
            return -1; // 如果没有找到数据，返回一个标志值
        }
    } else {
        qDebug() << "SQL error:" << query.lastError();
        return -1; // 查询失败，返回一个标志值
    }
}

void HaForm::startTask1()
{
    QStringList listlist= Target_List[0];
    QStringList nameList;

    for (auto item : listlist) {
        nameList.append(findNameById(buttonsArray,item.toInt()));


    }
    QString name=nameList.join(",");

    m_qudpSockety->writeDatagram(QString("请点击 ：").toUtf8(),QHostAddress("127.0.0.1"),22345);
    m_qudpSockety->writeDatagram(name.toUtf8(),QHostAddress("127.0.0.1"),22345);
}
void HaForm::closeEvent(QCloseEvent *event)
{



}


int HaForm::findKeyByValue(const QMap<int, int> &map, int value)
{
    for (auto it = map.constBegin(); it != map.constEnd(); ++it) {
        if (it.value() == value) {
            return it.key(); // 找到匹配的值，返回对应的键
        }
    }
    return -1; // 如果未找到，返回一个标识值（如 -1）
}

QJsonObject HaForm::loadJsonFromFile(const QString &filePath)
{
    QFile file(filePath);
    QJsonObject jsonObject;
    if (!file.open(QIODevice::ReadOnly)) {
        qWarning() << "Cannot open file for reading:" << file.errorString();
        return jsonObject;
    }
    QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
    if (doc.isObject()) {
        jsonObject = doc.object();
    }
    file.close();
    return jsonObject;
}

void HaForm::initTime()
{
    timeFlag=1;
    hour=0;//定义-计算任务完成时间
    minute=0;
    second=0;
    millisecond=0;
    hour2=0;
    minute2=0;
    second2=0;
    millisecond2=0;
    totalMilliseconds1=0;
    totalMilliseconds2=0;
    totalMilliseconds3=0;
}

void HaForm::init()
{
    task1=false;//处于当前任务循环中
    task2=false;
    task3=false;
    task4=false;
    task5=false;
    //  CurrentTask="";
    //  CurrentSmallTask="";
    currentTaskNum=0;//定义-存储本次任务操作的次数
    currentTaskErrorNum=0;//定义-存储本次任务失败的次数
    timeFlag=1;
    hour=0;//定义-计算任务完成时间
    minute=0;
    second=0;
    millisecond=0;
    hour2=0;
    minute2=0;
    second2=0;
    millisecond2=0;
    totalMilliseconds1=0;
    totalMilliseconds2=0;
    totalMilliseconds3=0;
    smallTaskFlag=true;


    o=false;
    // temptask32.clear();
    retryCount = -1;       // 记录重新输入的次数
    currentIndex = 0;     // 记录当前需要比较的位置
    likeButtonIds.clear();
    aa=0;
}

QString HaForm::getCurrentTime()
{
    QTime currentTime = QTime::currentTime();  // 获取当前时间
    QString formattedTime = currentTime.toString("hh:mm:ss:zzz");  // 格式化时间为 12:10:11:123
    return formattedTime;
}

void HaForm::logTask(QTextEdit *logTextEdit, const QString &taskSize, const QString &subTask, const QString &user, const QString &action)
{


    QString logContent = QString(
                "<p style='font-size:14px; font-family:Arial;'>"
                "<b>任务：</b><span style='color:blue;'>%1</span><br>"
                "<b>子任务：</b><span style='color:green;'>%2</span><br>"
                "<b>用户：</b><span style='color:purple;'>%3</span><br>"
                "<b>时间：</b><span style='color:orange;'>%4</span><br>"
                "<b>用户执行的操作：</b><span style='color:red;'>%5</span><br>"
                "</p><hr>"
                ).arg(taskSize, subTask, user, CurrformattedTime
                      , action);
    qDebug()<<"time:"<<CurrformattedTime;
    logTextEdit->append(logContent);
}

void HaForm::logTask2(QTextEdit *logTextEdit,  const QString &user, const QString &action)
{


    QString logContent = QString(
                "<p style='font-size:14px; font-family:Arial;'>"
                "<b>用户：</b><span style='color:purple;'>%1</span><br>"
                "<b>时间：</b><span style='color:orange;'>%2</span><br>"
                "<b>用户执行的操作：</b><span style='color:red;'>%3</span><br>"
                "</p><hr>"
                ).arg( user, CurrformattedTime, action);

    logTextEdit->append(logContent);
}
void HaForm::on_pushButton_clicked()
{


}


void HaForm::on_pushButton1_clicked()
{
    if(ui->lineEdit->text()=="自激励")
    {
        emit boolflag2(flag=!flag);
    }
    else if(ui->lineEdit->text()=="仿真激励")
    {
        emit boolflag(flag=!flag);
    }
    else
    {

    }

    if(flag) ui->pushButton1->setText("关闭激励数据");
    else ui->pushButton1->setText("开启激励数据");
}



void HaForm::on_pushButton_3_clicked()
{




}


void HaForm::on_pushButton_4_clicked()
{




}


void HaForm::on_pushButton_5_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(
            nullptr,          // 父窗口指针，这里设置为nullptr
            "选择可执行文件", // 对话框标题
            "",               // 起始目录，这里为空表示当前目录
            "可执行文件 (*.exe)" // 文件过滤器，这里设置为只显示.exe文件
        );
    ui->comboBox->addItem(filePath);


}

