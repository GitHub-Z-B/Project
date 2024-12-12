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
    QLabel *label_19;
    QSpinBox *spinBox;
    QLabel *label_20;
    QSpinBox *spinBox_2;
    QLabel *label_21;
    QSpinBox *spinBox_3;
    QLabel *label_22;
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

        label_19 = new QLabel(widget_item);
        label_19->setObjectName("label_19");
        sizePolicy1.setHeightForWidth(label_19->sizePolicy().hasHeightForWidth());
        label_19->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(label_19);

        spinBox = new QSpinBox(widget_item);
        spinBox->setObjectName("spinBox");
        sizePolicy3.setHeightForWidth(spinBox->sizePolicy().hasHeightForWidth());
        spinBox->setSizePolicy(sizePolicy3);

        horizontalLayout->addWidget(spinBox);

        label_20 = new QLabel(widget_item);
        label_20->setObjectName("label_20");
        sizePolicy1.setHeightForWidth(label_20->sizePolicy().hasHeightForWidth());
        label_20->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(label_20);

        spinBox_2 = new QSpinBox(widget_item);
        spinBox_2->setObjectName("spinBox_2");
        sizePolicy3.setHeightForWidth(spinBox_2->sizePolicy().hasHeightForWidth());
        spinBox_2->setSizePolicy(sizePolicy3);

        horizontalLayout->addWidget(spinBox_2);

        label_21 = new QLabel(widget_item);
        label_21->setObjectName("label_21");
        sizePolicy1.setHeightForWidth(label_21->sizePolicy().hasHeightForWidth());
        label_21->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(label_21);

        spinBox_3 = new QSpinBox(widget_item);
        spinBox_3->setObjectName("spinBox_3");
        sizePolicy3.setHeightForWidth(spinBox_3->sizePolicy().hasHeightForWidth());
        spinBox_3->setSizePolicy(sizePolicy3);

        horizontalLayout->addWidget(spinBox_3);

        label_22 = new QLabel(widget_item);
        label_22->setObjectName("label_22");
        sizePolicy1.setHeightForWidth(label_22->sizePolicy().hasHeightForWidth());
        label_22->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(label_22);

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
        label->setText(QCoreApplication::translate("eventChildItem", "\344\272\213\344\273\266\347\233\256\346\240\207", nullptr));
        pushButton->setText(QCoreApplication::translate("eventChildItem", "\351\200\211\346\213\251", nullptr));
        label_19->setText(QCoreApplication::translate("eventChildItem", "\344\272\213\344\273\266\350\247\246\345\217\221\346\227\266\351\227\264\357\274\210\344\273\273\345\212\241\345\274\200\345\247\213\345\220\216\357\274\211", nullptr));
        label_20->setText(QCoreApplication::translate("eventChildItem", "\345\260\217\346\227\266", nullptr));
        label_21->setText(QCoreApplication::translate("eventChildItem", "\345\210\206\351\222\237", nullptr));
        label_22->setText(QCoreApplication::translate("eventChildItem", "\347\247\222", nullptr));
        delete_btn->setText(QCoreApplication::translate("eventChildItem", "\345\210\240\351\231\244\344\273\273\345\212\241", nullptr));
    } // retranslateUi

};

namespace Ui {
    class eventChildItem: public Ui_eventChildItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EVENTCHILDITEM_H
