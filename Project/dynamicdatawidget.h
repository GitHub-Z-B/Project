#ifndef DYNAMICDATAWIDGET_H
#define DYNAMICDATAWIDGET_H

#include <QWidget>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QSpinBox>
#include <QComboBox>
#include <QPushButton>
#include <QMap>
#include <QTimer>
#include <QUdpSocket>
#include <QHostAddress>

struct HeadICD
{
    uint16_t msgType;
    uint16_t length;
    uint32_t sn;
    uint32_t timestamp;
    uint32_t reserved = 0;
};

struct HUDDataStruct4pop
{
    float AirSpeed;
    int AirSpeedLabel;
    float Airitude;
    float Heading;
    float HeadingDesign;
    int HeadingLabel;
    float Pitch;
    float Roll;
    float N1;
    float N2;
    float Math;
    float Alpha;
    float Belta;
    float OverLoading;
    float MaxOverLoading;
    float WirelessAlt;
    float MinOilQuantity;
    bool LandingGearHandleValid;
    float GAxis_upside_Speed;
    float yuyou;
    bool lzg;
};

struct Mystruct4Pop
{
    HeadICD headicd;
    HUDDataStruct4pop hudDataStruct;
};

class DynamicDataWidget : public QWidget
{
    Q_OBJECT

public:
    explicit DynamicDataWidget(QWidget *parent = nullptr);
    ~DynamicDataWidget();
    bool startflag;
public slots:
    void loadDataFromFile2(QString jili);
    void recvjili123(bool flag);
    void startSendingData();
    void onPauseButtonClicked();
private slots:


    void onSaveButtonClicked();
    void updateData();
    void sendData();
    void loadDataFromFile();

private:
    void addRow(const QString &field, float minValue, float maxValue, float currentValue, const QString &changeType, float changeTime, const QString &translation, const QString &dataType);

    void updateField(const QString &fieldName);

    QTableWidget *tableWidget;
    QPushButton *startButton;
    QPushButton *pauseButton;
    QPushButton* saveButton;
    QPushButton* loadButton;

    QTimer *timer;

    struct FieldControls {
        QSpinBox *minSpinBox;
        QSpinBox *maxSpinBox;
        QSpinBox *currentSpinBox;
        QComboBox *changeTypeComboBox;
        QSpinBox *changeTimeSpinBox;
    };

    QMap<QString, FieldControls> fieldControls;//用于存储对应数据的最大值和最小值

        float currentAirSpeed;
        int currentAirSpeedLabel;
        float currentAiritude;
        float currentHeading;
        float currentHeadingDesign;
        int currentHeadingLabel;
        float currentPitch;
        float currentRoll;
        float currentN1;
        float currentN2;
        float currentMath;
        float currentAlpha;
        float currentBelta;
        float currentOverLoading;
        float currentMaxOverLoading;
        float currentWirelessAlt;
        float currentMinOilQuantity;
        bool currentLandingGearHandleValid;
        float currentGAxisUpsideSpeed;
        float currentYuyou;
        bool currentLzg;

        // 控制频率和类型
        int changeFrequency;
        int changeType;

};

#endif // DYNAMICDATAWIDGET_H
