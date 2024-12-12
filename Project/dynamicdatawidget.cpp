#include "dynamicdatawidget.h"
#include <QFileDialog>
#include <QRandomGenerator>
#include <QVBoxLayout>
#include <QSpinBox>
#include <QComboBox>
#include <QPushButton>
#include <QTimer>
#include <QDateTime>
#include <QDebug>
#include <QHeaderView>
#include <QJsonArray>
#include <QJsonObject>
#include <QFile>
#include <QJsonDocument>
#include <QCoreApplication>
DynamicDataWidget::DynamicDataWidget(QWidget *parent)
    : QWidget(parent),
      currentAirSpeed(0),               // 初始值
            currentAirSpeedLabel(0),          // 对应的标签
            currentAiritude(0),              // 初始值
            currentHeading(0),               // 初始值
            currentHeadingDesign(0),         // 对应的字段
            currentHeadingLabel(0),          // 对应的标签
            currentPitch(0),                 // 初始值
            currentRoll(0),                  // 初始值
            currentN1(0),                    // 初始值
            currentN2(0),                    // 初始值
            currentMath(0),                  // 初始值
            currentAlpha(0),                 // 初始值
            currentBelta(0),                 // 初始值
            currentOverLoading(0),           // 初始值
            currentMaxOverLoading(0),        // 初始值
            currentWirelessAlt(0),           // 初始值
            currentMinOilQuantity(0),        // 初始值
            currentLandingGearHandleValid(false),  // 初始值
            currentGAxisUpsideSpeed(0),      // 初始值
            currentYuyou(0),                 // 初始值
            currentLzg(false),               // 初始值
            changeFrequency(1),              // 初始值
            changeType(0),                   // 初始值
            timer(new QTimer(this))          // 初始化定时器
{

    startflag=false;
    QVBoxLayout *layout = new QVBoxLayout(this);

    this->setGeometry(0,0,1000,700);
    tableWidget = new QTableWidget(0, 8, this);
    tableWidget->setHorizontalHeaderLabels({"数据", "最小值", "最大值", "当前值", "激励类型", "激励频率", "说明", "数据类型"});

    layout->addWidget(tableWidget);
    // 设置布局自适应大小
       setLayout(layout);

       // 设置 QTableWidget 自适应大小策略
       tableWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
       for (int i = 0; i < tableWidget->columnCount(); ++i) {
               tableWidget->horizontalHeader()->setSectionResizeMode(i, QHeaderView::Stretch);  // 自动调整列宽
           }
    // 向表格中添加行
       addRow("AirSpeed", 0.0f, 1000.0f, 100.0f, "Linear", 3.0f, "空速", "float");
       addRow("AirSpeedLabel", 0.0f, 1000.0f, 100.0f, "Linear", 3.0f, "空速标签", "int");
       addRow("Airitude", 0.0f, 1000.0f, 50.0f, "Linear", 2.0f, "空高", "float");
       addRow("Heading", 0.0f, 360.0f, 180.0f, "Linear", 1.0f, "航向角", "float");
       addRow("HeadingDesign", 0.0f, 360.0f, 180.0f, "Linear", 1.0f, "航向设计角", "float");
       addRow("HeadingLabel", 0.0f, 360.0f, 180.0f, "Linear", 1.0f, "航向标签", "int");
       addRow("Pitch", -90.0f, 90.0f, 0.0f, "Linear", 1.0f, "俯仰角", "float");
       addRow("Roll", -90.0f, 90.0f, 0.0f, "Linear", 1.0f, "横滚角", "float");
       addRow("N1", 0.0f, 100.0f, 50.0f, "Linear", 3.0f, "N1 转速", "float");
       addRow("N2", 0.0f, 100.0f, 50.0f, "Linear", 3.0f, "N2 转速", "float");
       addRow("Math", -100.0f, 100.0f, 0.0f, "Increment", 2.0f, "数学计算", "float");
       addRow("Alpha", -180.0f, 180.0f, 0.0f, "Fixed", 1.0f, "攻角", "float");
       addRow("Belta", -180.0f, 180.0f, 0.0f, "Fixed", 1.0f, "横向角度", "float");
       addRow("OverLoading", 0.0f, 10.0f, 1.0f, "Fixed", 3.0f, "过载", "float");
       addRow("MaxOverLoading", 0.0f, 20.0f, 1.0f, "Fixed", 3.0f, "最大过载", "float");
       addRow("WirelessAlt", 0.0f, 1000.0f, 500.0f, "Fixed", 1.0f, "无线高度", "float");
       addRow("MinOilQuantity", 0.0f, 100.0f, 10.0f, "Fixed", 3.0f, "最小油量", "float");
       addRow("LandingGearHandleValid", 0.0f, 1.0f, 0.0f, "Fixed", 1.0f, "着陆架有效性", "bool");
       addRow("GAxis_upside_Speed", 0.0f, 500.0f, 100.0f, "Linear", 3.0f, "G轴向速度", "float");
       addRow("yuyou", 0.0f, 100.0f, 0.0f, "Increment", 1.0f, "余油", "float");
       addRow("lzg", 0.0f, 1.0f, 0.0f, "Fixed", 1.0f, "拦阻钩", "bool");




       QHBoxLayout *buttonLayout = new QHBoxLayout();

       // 创建 QPushButton 按钮
       startButton = new QPushButton("开始激励");
       pauseButton = new QPushButton("暂停激励");
       saveButton = new QPushButton("保存激励配置");
       loadButton = new QPushButton("加载激励配置");




       // 将按钮添加到水平布局
       buttonLayout->addWidget(startButton);
       buttonLayout->addWidget(pauseButton);
       buttonLayout->addWidget(saveButton);
       buttonLayout->addWidget(loadButton);

       // 将水平布局添加到垂直布局
       layout->addLayout(buttonLayout);
       buttonLayout->setAlignment(Qt::AlignCenter);
    // 创建暂停按钮

        connect(pauseButton, &QPushButton::clicked, this, &DynamicDataWidget::onPauseButtonClicked);
        connect(saveButton, &QPushButton::clicked, this, &DynamicDataWidget::onSaveButtonClicked);
        connect(loadButton, &QPushButton::clicked, this, &DynamicDataWidget::loadDataFromFile);

    // 设置定时器
    connect(timer, &QTimer::timeout, this, &DynamicDataWidget::updateData);
    connect(startButton, &QPushButton::clicked, this, &DynamicDataWidget::startSendingData);

    setLayout(layout);
}

DynamicDataWidget::~DynamicDataWidget() {}

void DynamicDataWidget::startSendingData()
{
    qDebug() << "Start button clicked, starting timer...";

    changeFrequency = fieldControls["AirSpeed"].changeTimeSpinBox->value();
    qDebug() << "Change frequency:" << changeFrequency;

    if (changeFrequency > 0) {
        timer->start(100);  // 设置为100毫秒间隔，确保更新足够频繁
        qDebug() << "Timer started with interval: 100 ms";
    } else {
        qDebug() << "Invalid change frequency, timer not started.";
    }
}

void DynamicDataWidget::onPauseButtonClicked()
{
    timer->stop();
}

void DynamicDataWidget::onSaveButtonClicked()
{
    int rowCount = tableWidget->rowCount();
   // qDebug() << "Row count: " << rowCount;
    int colCount = tableWidget->columnCount();

    // 创建一个 QJsonArray 用于保存所有行的数据
    QJsonArray dataArray;

    // 获取表格的列标题
    QStringList headers = {"数据", "最小值", "最大值", "当前值", "激励类型", "激励频率", "说明", "数据类型"};

    // 遍历所有行
    for (int row = 0; row < rowCount; ++row) {
        QJsonObject rowObject;

        // 遍历每一列并获取数据
        for (int col = 0; col < colCount; ++col) {
            // 获取当前列对应的控件
            QWidget *widget = tableWidget->cellWidget(row, col);

            QString header = headers[col];  // 获取对应列的标题

            if (QSpinBox *spinBox = qobject_cast<QSpinBox*>(widget)) {
                // 处理 QSpinBox 控件
                rowObject[header] = spinBox->value();
            }
            else if (QComboBox *comboBox = qobject_cast<QComboBox*>(widget)) {
                // 处理 QComboBox 控件
                rowObject[header] = comboBox->currentText();
            }
            else if (QDoubleSpinBox *doubleSpinBox = qobject_cast<QDoubleSpinBox*>(widget)) {
                // 处理 QDoubleSpinBox 控件
                rowObject[header] = doubleSpinBox->value();
            }
            else {
                // 对于其他类型的控件（例如标签或普通文本），可以直接保存文本
                rowObject[header] = tableWidget->item(row, col)->text();
            }
        }

        // 将每一行的数据添加到 JSON 数组中
        dataArray.append(rowObject);
    }

    // 创建根 JSON 对象，并将数据添加到其中
    QJsonObject rootObject;
    rootObject["data"] = dataArray;

    // 使用 QFileDialog 选择保存路径
    QString filePath = QFileDialog::getSaveFileName(this, "保存文件", QString(), "JSON 文件 (*.json);;所有文件 (*)");

    // 如果选择了路径，则保存文件
    if (!filePath.isEmpty()) {
        QFile saveFile(filePath);
        if (saveFile.open(QIODevice::WriteOnly)) {
            QJsonDocument saveDoc(rootObject);
            saveFile.write(saveDoc.toJson());  // 将 JSON 写入文件
            saveFile.close();
            qDebug() << "Data saved successfully to " << filePath;
        } else {
            qWarning() << "Failed to open file for writing.";
        }
    } else {
        qWarning() << "No file selected for saving.";
    }
}

void DynamicDataWidget::loadDataFromFile()
{
    // 使用 QFileDialog 弹出文件选择对话框
    QString filePath = QFileDialog::getOpenFileName(this, "打开文件", QString(), "JSON 文件 (*.json);;所有文件 (*)");

    // 如果用户没有选择文件，直接返回
    if (filePath.isEmpty()) {
        qWarning() << "No file selected for loading.";
        return;
    }

    // 打开选中的 JSON 文件进行读取
    QFile loadFile(filePath);
    if (!loadFile.open(QIODevice::ReadOnly)) {
        qWarning() << "Failed to open file for reading.";
        return;
    }

    // 解析 JSON 文件
    QByteArray data = loadFile.readAll();
    QJsonDocument loadDoc(QJsonDocument::fromJson(data));
    QJsonObject rootObject = loadDoc.object();

    // 获取 "data" 数组
    QJsonArray dataArray = rootObject["data"].toArray();

    // 清空表格中的所有数据
    tableWidget->setRowCount(0);  // 清空现有的行
    tableWidget->setColumnCount(8);  // 设置列数，如果你需要固定列数，确保列数与数据匹配

    // 遍历每一行数据并添加到表格
    for (const QJsonValue &value : dataArray) {
        QJsonObject rowObject = value.toObject();

        // 读取每一列的值
        QString dataName = rowObject["数据"].toString();
        float minValue = rowObject["最小值"].toDouble();
        float maxValue = rowObject["最大值"].toDouble();
        float currentValue = rowObject["当前值"].toDouble();
        QString incentiveType = rowObject["激励类型"].toString();
        float incentiveFrequency = rowObject["激励频率"].toDouble();
        QString description = rowObject["说明"].toString();
        QString dataType = rowObject["数据类型"].toString();

        // 调用 addRow 函数添加一行
        addRow(dataName, minValue, maxValue, currentValue, incentiveType, incentiveFrequency, description, dataType);
    }

  //  qDebug() << "Data loaded and rows added.";
}

void DynamicDataWidget::updateData()
{
    qDebug() << "Updating data...";
    qDebug() << "Updating data1...";
    for (const QString &fieldName : fieldControls.keys()) {
        qDebug() << "Updating data2...";
            updateField(fieldName);
        }
qDebug() << "Updating data3...";
    // 发送数据
    sendData();
}

void DynamicDataWidget::loadDataFromFile2(QString jili)
{

    QFile loadFile(jili);
    if (!loadFile.open(QIODevice::ReadOnly)) {
        qWarning() << "Failed to open file for reading.";
        return;
    }

    // 解析 JSON 文件
    QByteArray data = loadFile.readAll();
    QJsonDocument loadDoc(QJsonDocument::fromJson(data));
    QJsonObject rootObject = loadDoc.object();

    // 获取 "data" 数组
    QJsonArray dataArray = rootObject["data"].toArray();

    // 清空表格中的所有数据
    tableWidget->setRowCount(0);  // 清空现有的行
    tableWidget->setColumnCount(8);  // 设置列数，如果你需要固定列数，确保列数与数据匹配

    // 遍历每一行数据并添加到表格
    for (const QJsonValue &value : dataArray) {
        QJsonObject rowObject = value.toObject();

        // 读取每一列的值
        QString dataName = rowObject["数据"].toString();
        float minValue = rowObject["最小值"].toDouble();
        float maxValue = rowObject["最大值"].toDouble();
        float currentValue = rowObject["当前值"].toDouble();
        QString incentiveType = rowObject["激励类型"].toString();
        float incentiveFrequency = rowObject["激励频率"].toDouble();
        QString description = rowObject["说明"].toString();
        QString dataType = rowObject["数据类型"].toString();

        // 调用 addRow 函数添加一行
        addRow(dataName, minValue, maxValue, currentValue, incentiveType, incentiveFrequency, description, dataType);
    }

    qDebug() << "Data loaded and rows added.";
}


 void DynamicDataWidget::recvjili123(bool flag)
 {
     if(flag)
     {
         startSendingData();
     }
     else
     {
         onPauseButtonClicked();
     }
     qDebug()<<"自激励"<<flag;
 }
void DynamicDataWidget::sendData()
{
    Mystruct4Pop dataToSend;
    dataToSend.headicd.msgType = 1;
    dataToSend.headicd.length = sizeof(Mystruct4Pop);
    dataToSend.headicd.sn = 12345;
    dataToSend.headicd.timestamp = QDateTime::currentSecsSinceEpoch();
    dataToSend.hudDataStruct.AirSpeed = currentAirSpeed;        // Set current airspeed
    dataToSend.hudDataStruct.AirSpeedLabel = currentAirSpeedLabel; // Set airspeed label
    dataToSend.hudDataStruct.Airitude = currentAiritude;        // Set current air altitude
    dataToSend.hudDataStruct.Heading = currentHeading;          // Set current heading angle
    dataToSend.hudDataStruct.HeadingDesign = currentHeadingDesign;  // Set heading design value
    dataToSend.hudDataStruct.HeadingLabel = currentHeadingLabel;    // Set heading label
    dataToSend.hudDataStruct.Pitch = currentPitch;              // Set current pitch angle
    dataToSend.hudDataStruct.Roll = currentRoll;                // Set current roll angle
    dataToSend.hudDataStruct.N1 = currentN1;                    // Set N1 speed
    dataToSend.hudDataStruct.N2 = currentN2;                    // Set N2 speed
    dataToSend.hudDataStruct.Math = currentMath;                // Set current math result
    dataToSend.hudDataStruct.Alpha = currentAlpha;              // Set current alpha (angle of attack)
    dataToSend.hudDataStruct.Belta = currentBelta;              // Set current beta (side slip angle)
    dataToSend.hudDataStruct.OverLoading = currentOverLoading;  // Set current overload value
    dataToSend.hudDataStruct.MaxOverLoading = currentMaxOverLoading; // Set max overload value
    dataToSend.hudDataStruct.WirelessAlt = currentWirelessAlt;  // Set wireless altitude
    dataToSend.hudDataStruct.MinOilQuantity = currentMinOilQuantity; // Set minimum oil quantity
    dataToSend.hudDataStruct.LandingGearHandleValid = currentLandingGearHandleValid; // Set landing gear validity
    dataToSend.hudDataStruct.GAxis_upside_Speed = currentGAxisUpsideSpeed; // Set G-axis speed
    dataToSend.hudDataStruct.yuyou = currentYuyou;              // Set current fuel level
    dataToSend.hudDataStruct.lzg = currentLzg;                  // Set arrestor hook status

    QUdpSocket udpSocket;
    udpSocket.writeDatagram(reinterpret_cast<char*>(&dataToSend), sizeof(dataToSend),
                            QHostAddress("239.0.0.1"), 11111);  // 组播地址和端口

    qDebug() << "Data sent via UDP.";
}

void DynamicDataWidget::addRow(const QString &fieldName, float minValue, float maxValue, float currentValue, const QString &changeType, float changeTime, const QString &translation, const QString &dataType)
{
    int row = tableWidget->rowCount();
    tableWidget->insertRow(row);

    // 添加字段名称列
    QTableWidgetItem *fieldItem = new QTableWidgetItem(fieldName);
    fieldItem->setFlags(fieldItem->flags() & ~Qt::ItemIsEditable);  // 禁用编辑
    tableWidget->setItem(row, 0, fieldItem);

    // 添加最小值列
    QSpinBox *minSpinBox = new QSpinBox();
    minSpinBox->setRange(0, 1000);
    minSpinBox->setValue(minValue);
    tableWidget->setCellWidget(row, 1, minSpinBox);

    // 添加最大值列
    QSpinBox *maxSpinBox = new QSpinBox();
    maxSpinBox->setRange(0, 1000);
    maxSpinBox->setValue(maxValue);
    tableWidget->setCellWidget(row, 2, maxSpinBox);

    // 添加当前值列
    QSpinBox *currentSpinBox = new QSpinBox();
    currentSpinBox->setRange(0, 1000);
    currentSpinBox->setValue(currentValue);
    tableWidget->setCellWidget(row, 3, currentSpinBox);

    // 添加变化类型列
    QComboBox *changeTypeComboBox = new QComboBox();
    changeTypeComboBox->addItem("Linear");
    changeTypeComboBox->addItem("Increment");
    changeTypeComboBox->addItem("Decrement");
    changeTypeComboBox->addItem("Fixed");
    changeTypeComboBox->addItem("Random");
    changeTypeComboBox->setCurrentText(changeType);  // 设置初始值为传入的changeType
    tableWidget->setCellWidget(row, 4, changeTypeComboBox);

    // 添加变化时间列
    QSpinBox *changeTimeSpinBox = new QSpinBox();
    changeTimeSpinBox->setRange(0, 10000);
    changeTimeSpinBox->setValue(changeTime);
    tableWidget->setCellWidget(row, 5, changeTimeSpinBox);

    // 添加中文翻译列
    QTableWidgetItem *translationItem = new QTableWidgetItem(translation);
    translationItem->setFlags(translationItem->flags() & ~Qt::ItemIsEditable);  // 禁用编辑
    tableWidget->setItem(row, 6, translationItem);

    // 添加数据类型列（传入的 dataType 参数）
    QTableWidgetItem *dataTypeItem = new QTableWidgetItem(dataType);
    dataTypeItem->setFlags(dataTypeItem->flags() & ~Qt::ItemIsEditable);  // 禁用编辑
    tableWidget->setItem(row, 7, dataTypeItem);  // 将数据类型列添加到最后一个位置

    // 根据变化类型初始化控件的行为
    if (changeType == "Linear") {
        minSpinBox->setRange(0, 1000);
        maxSpinBox->setRange(0, 1000);
        currentSpinBox->setRange(0, 1000);
    } else if (changeType == "Increment") {
        minSpinBox->setRange(0, 500);
        maxSpinBox->setRange(0, 500);
        currentSpinBox->setRange(0, 500);
    } else if (changeType == "Decrement") {  // 新增递减类型
        minSpinBox->setRange(0, 1000);
        maxSpinBox->setRange(0, 1000);
        currentSpinBox->setRange(0, 1000);
    }else if (changeType == "Fixed") {
        minSpinBox->setRange(0, 100);
        maxSpinBox->setRange(0, 100);
        currentSpinBox->setRange(0, 100);
    }   else if (changeType == "Random") {
        // 随机激励的设置
        int minValue = 0;
        int maxValue = 1000;

        minSpinBox->setRange(minValue, maxValue);
        maxSpinBox->setRange(minValue, maxValue);
        currentSpinBox->setRange(minValue, maxValue);

        // 生成一个随机数并设置
        int randomValue = QRandomGenerator::global()->bounded(minValue, maxValue + 1);
        currentSpinBox->setValue(randomValue);
    }

    // 将控件存储到 fieldControls 中
    fieldControls[fieldName] = {minSpinBox, maxSpinBox, currentSpinBox, changeTypeComboBox, changeTimeSpinBox};
}

void DynamicDataWidget::updateField(const QString &fieldName)
{
    auto &controls = fieldControls[fieldName];
    QSpinBox *minSpinBox = controls.minSpinBox;
    QSpinBox *maxSpinBox = controls.maxSpinBox;
    QSpinBox *currentSpinBox = controls.currentSpinBox;
    QComboBox *changeTypeComboBox = controls.changeTypeComboBox;
    QSpinBox *changeTimeSpinBox = controls.changeTimeSpinBox;

    float minValue = minSpinBox->value();
    float maxValue = maxSpinBox->value();
    float currentValue = currentSpinBox->value();
    float step = (maxValue - minValue) / (changeTimeSpinBox->value() * 10);  // 每次更新步长

    QString changeType = changeTypeComboBox->currentText();

    // 根据选择的变化类型执行不同逻辑
    if (changeType == "Linear") {
        currentValue += step;
        if (currentValue >= maxValue) {
            currentValue = minValue;  // 达到最大值后重置为最小值
        }
    } else if (changeType == "Increment") {
        currentValue += step;  // 每次简单递增 step
        if (currentValue > maxValue) {
            currentValue = maxValue;  // 到达最大值后保持最大值
        }
    } else if (changeType == "Decrement") {
        currentValue -= step;  // 递减
        if (currentValue < minValue) {
            currentValue = maxValue;  // 到达最小值后重置为最大值
        }
    } else if (changeType == "Fixed") {
        // "Fixed" 类型，不改变 currentValue，保持固定值
    } else if (changeType == "Random") {
        // "Random" 类型，在[minValue, maxValue]范围内生成一个随机值
        currentValue = minValue + QRandomGenerator::global()->bounded(static_cast<quint32>(maxValue - minValue + 1));
    }

    currentSpinBox->setValue(static_cast<int>(currentValue));  // 更新 UI 上的值

    // 更新内部变量值
    // 更新内部变量值
    if (fieldName == "AirSpeed") {
        currentAirSpeed = currentValue;
    } else if (fieldName == "AirSpeedLabel") {  // 更新对应的变量名
        currentAirSpeedLabel = currentValue;
    } else if (fieldName == "Airitude") {
        currentAiritude = currentValue;
    } else if (fieldName == "Heading") {
        currentHeading = currentValue;
    } else if (fieldName == "HeadingDesign") {  // 更新对应的变量名
        currentHeadingDesign = currentValue;
    } else if (fieldName == "HeadingLabel") {  // 更新对应的变量名
        currentHeadingLabel = currentValue;
    } else if (fieldName == "Pitch") {
        currentPitch = currentValue;
    } else if (fieldName == "Roll") {
        currentRoll = currentValue;
    } else if (fieldName == "N1") {
        currentN1 = currentValue;
    } else if (fieldName == "N2") {
        currentN2 = currentValue;
    } else if (fieldName == "Math") {
        currentMath = currentValue;
    } else if (fieldName == "Alpha") {
        currentAlpha = currentValue;
    } else if (fieldName == "Belta") {
        currentBelta = currentValue;
    } else if (fieldName == "OverLoading") {
        currentOverLoading = currentValue;
    } else if (fieldName == "MaxOverLoading") {
        currentMaxOverLoading = currentValue;
    } else if (fieldName == "WirelessAlt") {
        currentWirelessAlt = currentValue;
    } else if (fieldName == "MinOilQuantity") {
        currentMinOilQuantity = currentValue;
    } else if (fieldName == "LandingGearHandleValid") {
        currentLandingGearHandleValid = currentValue;
    } else if (fieldName == "GAxis_upside_Speed") {
        currentGAxisUpsideSpeed = currentValue;
    } else if (fieldName == "yuyou") {
        currentYuyou = currentValue;
    } else if (fieldName == "lzg") {
        currentLzg = currentValue;
    }
}

