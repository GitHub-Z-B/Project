/********************************************************************************
** Form generated from reading UI file 'eventchilditem.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EVENTCHILDITEM_H
#define UI_EVENTCHILDITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_eventChildItem
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget_item;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *trigger_event;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QLabel *trigger_lab;
    QSpinBox *hour_spinBox;
    QLabel *hour_lab;
    QSpinBox *minute_spinBox;
    QLabel *minute_lab;
    QSpinBox *second_spinBox;
    QLabel *second_lab;
    QPushButton *delete_btn;

    void setupUi(QWidget *eventChildItem)
    {
        if (eventChildItem->objectName().isEmpty())
            eventChildItem->setObjectName("eventChildItem");
        eventChildItem->resize(798, 50);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(eventChildItem->sizePolicy().hasHeightForWidth());
        eventChildItem->setSizePolicy(sizePolicy);
        eventChildItem->setMinimumSize(QSize(0, 50));
        eventChildItem->setMaximumSize(QSize(16777215, 50));
        verticalLayout = new QVBoxLayout(eventChildItem);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget_item = new QWidget(eventChildItem);
        widget_item->setObjectName("widget_item");
        widget_item->setStyleSheet(QString::fromUtf8("QWidget#widget_item{\n"
"background-color: rgb(255, 255, 255);\n"
"border:1px solid rgb(95, 95, 95);\n"
"border-radius:6px;\n"
"}"));
        horizontalLayout = new QHBoxLayout(widget_item);
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(widget_item);
        label->setObjectName("label");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(label);

        trigger_event = new QLineEdit(widget_item);
        trigger_event->setObjectName("trigger_event");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(trigger_event->sizePolicy().hasHeightForWidth());
        trigger_event->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(trigger_event);

        pushButton = new QPushButton(widget_item);
        pushButton->setObjectName("pushButton");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy3);

        horizontalLayout->addWidget(pushButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        trigger_lab = new QLabel(widget_item);
        trigger_lab->setObjectName("trigger_lab");
        sizePolicy1.setHeightForWidth(trigger_lab->sizePolicy().hasHeightForWidth());
        trigger_lab->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(trigger_lab);

        hour_spinBox = new QSpinBox(widget_item);
        hour_spinBox->setObjectName("hour_spinBox");
        sizePolicy3.setHeightForWidth(hour_spinBox->sizePolicy().hasHeightForWidth());
        hour_spinBox->setSizePolicy(sizePolicy3);
        hour_spinBox->setMinimumSize(QSize(65, 0));

        horizontalLayout->addWidget(hour_spinBox);

        hour_lab = new QLabel(widget_item);
        hour_lab->setObjectName("hour_lab");
        sizePolicy1.setHeightForWidth(hour_lab->sizePolicy().hasHeightForWidth());
        hour_lab->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(hour_lab);

        minute_spinBox = new QSpinBox(widget_item);
        minute_spinBox->setObjectName("minute_spinBox");
        sizePolicy3.setHeightForWidth(minute_spinBox->sizePolicy().hasHeightForWidth());
        minute_spinBox->setSizePolicy(sizePolicy3);
        minute_spinBox->setMinimumSize(QSize(65, 0));

        horizontalLayout->addWidget(minute_spinBox);

        minute_lab = new QLabel(widget_item);
        minute_lab->setObjectName("minute_lab");
        sizePolicy1.setHeightForWidth(minute_lab->sizePolicy().hasHeightForWidth());
        minute_lab->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(minute_lab);

        second_spinBox = new QSpinBox(widget_item);
        second_spinBox->setObjectName("second_spinBox");
        sizePolicy3.setHeightForWidth(second_spinBox->sizePolicy().hasHeightForWidth());
        second_spinBox->setSizePolicy(sizePolicy3);
        second_spinBox->setMinimumSize(QSize(65, 0));

        horizontalLayout->addWidget(second_spinBox);

        second_lab = new QLabel(widget_item);
        second_lab->setObjectName("second_lab");
        sizePolicy1.setHeightForWidth(second_lab->sizePolicy().hasHeightForWidth());
        second_lab->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(second_lab);

        delete_btn = new QPushButton(widget_item);
        delete_btn->setObjectName("delete_btn");

        horizontalLayout->addWidget(delete_btn);


        verticalLayout->addWidget(widget_item);


        retranslateUi(eventChildItem);

        QMetaObject::connectSlotsByName(eventChildItem);
    } // setupUi

    void retranslateUi(QWidget *eventChildItem)
    {
        eventChildItem->setWindowTitle(QCoreApplication::translate("eventChildItem", "Form", nullptr));
        label->setText(QCoreApplication::translate("eventChildItem", "\345\256\236\351\252\214\347\233\256\346\240\207", nullptr));
        pushButton->setText(QCoreApplication::translate("eventChildItem", "\351\200\211\346\213\251", nullptr));
        trigger_lab->setText(QCoreApplication::translate("eventChildItem", "\350\247\246\345\217\221\346\227\266\351\227\264\357\274\210\345\256\236\351\252\214\345\274\200\345\247\213\345\220\216\357\274\211", nullptr));
        hour_lab->setText(QCoreApplication::translate("eventChildItem", "\345\260\217\346\227\266", nullptr));
        minute_lab->setText(QCoreApplication::translate("eventChildItem", "\345\210\206\351\222\237", nullptr));
        second_lab->setText(QCoreApplication::translate("eventChildItem", "\347\247\222", nullptr));
        delete_btn->setText(QCoreApplication::translate("eventChildItem", "\345\210\240\351\231\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class eventChildItem: public Ui_eventChildItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EVENTCHILDITEM_H
