/********************************************************************************
** Form generated from reading UI file 'replaywidget.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPLAYWIDGET_H
#define UI_REPLAYWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ReplayWidget
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_3;
    QHBoxLayout *_1;
    QLabel *label;
    QLineEdit *lineEdit;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_5;
    QComboBox *comboBox_3;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_3;
    QDateEdit *dateEdit;
    QLabel *label_4;
    QDateEdit *dateEdit_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QWidget *widget_4;
    QHBoxLayout *_2;
    QPushButton *pushButton_3;
    QComboBox *comboBox;
    QComboBox *comboBox_2;
    QSpacerItem *horizontalSpacer_2;
    QScrollArea *scrollArea;
    QWidget *replayListWidget;
    QVBoxLayout *replayListLayout;

    void setupUi(QWidget *ReplayWidget)
    {
        if (ReplayWidget->objectName().isEmpty())
            ReplayWidget->setObjectName("ReplayWidget");
        ReplayWidget->resize(1092, 561);
        verticalLayout = new QVBoxLayout(ReplayWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        page_2 = new QWidget(ReplayWidget);
        page_2->setObjectName("page_2");
        page_2->setStyleSheet(QString::fromUtf8("QWidget#page_2{\n"
"background-color: #FFFFFF;\n"
"}\n"
""));
        verticalLayout_3 = new QVBoxLayout(page_2);
        verticalLayout_3->setObjectName("verticalLayout_3");
        widget_2 = new QWidget(page_2);
        widget_2->setObjectName("widget_2");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy);
        widget_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #007BFF;  /* \350\223\235\350\211\262\350\203\214\346\231\257 */\n"
"    color: white;  /* \347\231\275\350\211\262\346\226\207\345\255\227 */\n"
"    border-radius: 4px;  /* \345\234\206\350\247\222 */\n"
"    padding: 5px 10px;  /* \345\206\205\350\276\271\350\267\235 */\n"
"    border: none;  /* \346\227\240\350\276\271\346\241\206 */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #0056b3;  /* \346\202\254\345\201\234\346\227\266\346\233\264\346\267\261\347\232\204\350\223\235\350\211\262 */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #003d80;  /* \346\214\211\344\270\213\346\227\266\346\233\264\346\267\261\347\232\204\350\223\235\350\211\262 */\n"
"}\n"
"QComboBox {\n"
"    background-color: white;             /* \350\203\214\346\231\257\351\242\234\350\211\262\344\270\272\347\231\275\350\211\262 */\n"
"    color: #1E90FF;                      /* \345\255\227\344\275\223\351\242\234\350\211\262\344\270\272\350\223\235\350\211\262 */\n"
""
                        "    border: 1px solid #1E90FF;           /* \350\276\271\346\241\206\344\270\272\350\223\235\350\211\262\357\274\214\345\256\275\345\272\246\344\270\2722px */\n"
"    border-radius: 4px;                  /* \345\234\206\350\247\222\345\215\212\345\276\204 */\n"
"    padding: 5px 10px;  /* \345\206\205\350\276\271\350\267\235 */\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"    background-color: white;             /* \344\270\213\346\213\211\345\210\227\350\241\250\347\232\204\350\203\214\346\231\257\344\270\272\347\231\275\350\211\262 */\n"
"    color: #1E90FF;                      /* \344\270\213\346\213\211\345\210\227\350\241\250\345\255\227\344\275\223\351\242\234\350\211\262\344\270\272\350\223\235\350\211\262 */\n"
"    selection-background-color: #D0E8FF; /* \351\200\211\344\270\255\351\241\271\347\232\204\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"    selection-color: #1E90FF;            /* \351\200\211\344\270\255\351\241\271\347\232\204\345\255\227\344\275\223\351\242\234\350\211\262 *"
                        "/\n"
"}\n"
"\n"
"QComboBox:hover {\n"
"    border: 1px solid #4682B4;           /* \346\202\254\345\201\234\346\227\266\350\276\271\346\241\206\345\217\230\346\210\220\350\276\203\346\267\261\347\232\204\350\223\235\350\211\262 */\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"    border: none;                        /* \345\216\273\351\231\244\344\270\213\346\213\211\346\214\211\351\222\256\347\232\204\350\276\271\346\241\206 */\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: url(:/mainwindow/arrow_down.png);  /* \350\207\252\345\256\232\344\271\211\344\270\213\346\213\211\347\256\255\345\244\264\345\233\276\346\240\207 */\n"
"    width: 12px;                         /* \345\233\276\346\240\207\345\256\275\345\272\246 */\n"
"    height: 12px;                        /* \345\233\276\346\240\207\351\253\230\345\272\246 */\n"
"}\n"
"\n"
"QLineEdit,QDateEdit{\n"
"    background-color: white;          /* \350\203\214\346\231\257\351\242\234\350\211\262\344\270\272\347\231\275\350\211\262 */\n"
"    border: 1px sol"
                        "id #A9A9A9;        /* \350\276\271\346\241\206\351\242\234\350\211\262\344\270\272\347\201\260\350\211\262\357\274\210#A9A9A9\357\274\211\357\274\214\345\256\275\345\272\246\344\270\272 1px */\n"
"    border-radius: 4px;               /* \345\234\206\350\247\222\345\215\212\345\276\204 */\n"
"    padding: 4px;                     /* \345\206\205\350\276\271\350\267\235\357\274\214\347\241\256\344\277\235\346\226\207\345\255\227\345\222\214\350\276\271\346\241\206\344\271\213\351\227\264\346\234\211\350\267\235\347\246\273 */\n"
"}\n"
"\n"
"QLineEdit:focus,QDateEdit:focus {\n"
"    border: 1px solid #808080;        /* \345\275\223 QLineEdit \350\216\267\345\217\226\347\204\246\347\202\271\346\227\266\357\274\214\350\276\271\346\241\206\351\242\234\350\211\262\345\217\230\346\210\220\346\267\261\347\201\260\350\211\262 */\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(widget_2);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        widget_3 = new QWidget(widget_2);
        widget_3->setObjectName("widget_3");
        _1 = new QHBoxLayout(widget_3);
        _1->setObjectName("_1");
        _1->setContentsMargins(0, 9, 0, 9);
        label = new QLabel(widget_3);
        label->setObjectName("label");

        _1->addWidget(label);

        lineEdit = new QLineEdit(widget_3);
        lineEdit->setObjectName("lineEdit");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy1);

        _1->addWidget(lineEdit);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        _1->addItem(horizontalSpacer_5);

        label_2 = new QLabel(widget_3);
        label_2->setObjectName("label_2");

        _1->addWidget(label_2);

        lineEdit_2 = new QLineEdit(widget_3);
        lineEdit_2->setObjectName("lineEdit_2");
        sizePolicy1.setHeightForWidth(lineEdit_2->sizePolicy().hasHeightForWidth());
        lineEdit_2->setSizePolicy(sizePolicy1);
        lineEdit_2->setMinimumSize(QSize(150, 0));
        lineEdit_2->setMaximumSize(QSize(150, 16777215));

        _1->addWidget(lineEdit_2);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        _1->addItem(horizontalSpacer_4);

        label_5 = new QLabel(widget_3);
        label_5->setObjectName("label_5");

        _1->addWidget(label_5);

        comboBox_3 = new QComboBox(widget_3);
        comboBox_3->addItem(QString());
        comboBox_3->setObjectName("comboBox_3");
        sizePolicy1.setHeightForWidth(comboBox_3->sizePolicy().hasHeightForWidth());
        comboBox_3->setSizePolicy(sizePolicy1);
        comboBox_3->setMinimumSize(QSize(150, 0));
        comboBox_3->setMaximumSize(QSize(150, 16777215));

        _1->addWidget(comboBox_3);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        _1->addItem(horizontalSpacer_3);

        label_3 = new QLabel(widget_3);
        label_3->setObjectName("label_3");

        _1->addWidget(label_3);

        dateEdit = new QDateEdit(widget_3);
        dateEdit->setObjectName("dateEdit");
        sizePolicy1.setHeightForWidth(dateEdit->sizePolicy().hasHeightForWidth());
        dateEdit->setSizePolicy(sizePolicy1);
        dateEdit->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);

        _1->addWidget(dateEdit);

        label_4 = new QLabel(widget_3);
        label_4->setObjectName("label_4");

        _1->addWidget(label_4);

        dateEdit_2 = new QDateEdit(widget_3);
        dateEdit_2->setObjectName("dateEdit_2");
        sizePolicy1.setHeightForWidth(dateEdit_2->sizePolicy().hasHeightForWidth());
        dateEdit_2->setSizePolicy(sizePolicy1);
        dateEdit_2->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);

        _1->addWidget(dateEdit_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        _1->addItem(horizontalSpacer);

        pushButton = new QPushButton(widget_3);
        pushButton->setObjectName("pushButton");
        pushButton->setMinimumSize(QSize(0, 29));

        _1->addWidget(pushButton);


        verticalLayout_2->addWidget(widget_3);

        widget_4 = new QWidget(widget_2);
        widget_4->setObjectName("widget_4");
        _2 = new QHBoxLayout(widget_4);
        _2->setObjectName("_2");
        _2->setContentsMargins(0, 9, 0, 9);
        pushButton_3 = new QPushButton(widget_4);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setMinimumSize(QSize(0, 29));

        _2->addWidget(pushButton_3);

        comboBox = new QComboBox(widget_4);
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");

        _2->addWidget(comboBox);

        comboBox_2 = new QComboBox(widget_4);
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName("comboBox_2");

        _2->addWidget(comboBox_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        _2->addItem(horizontalSpacer_2);


        verticalLayout_2->addWidget(widget_4);


        verticalLayout_3->addWidget(widget_2);

        scrollArea = new QScrollArea(page_2);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setFrameShape(QFrame::Shape::NoFrame);
        scrollArea->setFrameShadow(QFrame::Shadow::Plain);
        scrollArea->setWidgetResizable(true);
        replayListWidget = new QWidget();
        replayListWidget->setObjectName("replayListWidget");
        replayListWidget->setGeometry(QRect(0, 0, 1074, 443));
        replayListWidget->setStyleSheet(QString::fromUtf8("QWidget#replayListWidget{\n"
"background-color: rgb(255, 255, 255);\n"
"}"));
        replayListLayout = new QVBoxLayout(replayListWidget);
        replayListLayout->setSpacing(20);
        replayListLayout->setObjectName("replayListLayout");
        scrollArea->setWidget(replayListWidget);

        verticalLayout_3->addWidget(scrollArea);


        verticalLayout->addWidget(page_2);


        retranslateUi(ReplayWidget);

        QMetaObject::connectSlotsByName(ReplayWidget);
    } // setupUi

    void retranslateUi(QWidget *ReplayWidget)
    {
        ReplayWidget->setWindowTitle(QCoreApplication::translate("ReplayWidget", "Form", nullptr));
        label->setText(QCoreApplication::translate("ReplayWidget", "\344\273\273\345\212\241\345\220\215\347\247\260\357\274\232", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("ReplayWidget", "\350\257\267\350\276\223\345\205\245\344\273\273\345\212\241\345\220\215\347\247\260", nullptr));
        label_2->setText(QCoreApplication::translate("ReplayWidget", "\350\257\225\351\243\236\344\272\272\345\221\230\345\220\215\347\247\260\357\274\232", nullptr));
        lineEdit_2->setPlaceholderText(QCoreApplication::translate("ReplayWidget", "\350\257\267\350\276\223\345\205\245\350\257\225\351\243\236\344\272\272\345\221\230\345\220\215\347\247\260", nullptr));
        label_5->setText(QCoreApplication::translate("ReplayWidget", "\345\233\236\346\224\276\346\254\241\346\225\260\346\216\222\345\272\217\357\274\232", nullptr));
        comboBox_3->setItemText(0, QCoreApplication::translate("ReplayWidget", "\344\273\216\345\244\247\345\210\260\345\260\217", nullptr));

        label_3->setText(QCoreApplication::translate("ReplayWidget", "\345\210\233\345\273\272\346\227\266\351\227\264\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("ReplayWidget", "\350\207\263", nullptr));
        pushButton->setText(QCoreApplication::translate("ReplayWidget", "\346\220\234\347\264\242", nullptr));
        pushButton_3->setText(QCoreApplication::translate("ReplayWidget", "\345\205\250\351\203\250", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("ReplayWidget", "\345\216\237\345\236\213\350\257\204\344\274\260", nullptr));

        comboBox_2->setItemText(0, QCoreApplication::translate("ReplayWidget", "\346\234\272\345\236\213\350\257\204\344\274\260", nullptr));

    } // retranslateUi

};

namespace Ui {
    class ReplayWidget: public Ui_ReplayWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPLAYWIDGET_H
