/********************************************************************************
** Form generated from reading UI file 'eventitem.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EVENTITEM_H
#define UI_EVENTITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EventItem
{
public:
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_item;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_17;
    QLineEdit *task_event;
    QSpacerItem *horizontalSpacer;
    QPushButton *add_child;
    QPushButton *delete_child;
    QWidget *widget_2;
    QVBoxLayout *eventItemLayout;

    void setupUi(QWidget *EventItem)
    {
        if (EventItem->objectName().isEmpty())
            EventItem->setObjectName("EventItem");
        EventItem->resize(733, 347);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(EventItem->sizePolicy().hasHeightForWidth());
        EventItem->setSizePolicy(sizePolicy);
        verticalLayout_2 = new QVBoxLayout(EventItem);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        widget_item = new QWidget(EventItem);
        widget_item->setObjectName("widget_item");
        widget_item->setStyleSheet(QString::fromUtf8("QWidget#widget_item{\n"
"background-color: rgb(255, 255, 255);\n"
"border:1px solid rgb(95, 95, 95);\n"
"border-radius:6px;\n"
"}"));
        verticalLayout = new QVBoxLayout(widget_item);
        verticalLayout->setObjectName("verticalLayout");
        widget = new QWidget(widget_item);
        widget->setObjectName("widget");
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        label_17 = new QLabel(widget);
        label_17->setObjectName("label_17");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_17->sizePolicy().hasHeightForWidth());
        label_17->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(label_17);

        task_event = new QLineEdit(widget);
        task_event->setObjectName("task_event");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(task_event->sizePolicy().hasHeightForWidth());
        task_event->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(task_event);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        add_child = new QPushButton(widget);
        add_child->setObjectName("add_child");
        sizePolicy2.setHeightForWidth(add_child->sizePolicy().hasHeightForWidth());
        add_child->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(add_child);

        delete_child = new QPushButton(widget);
        delete_child->setObjectName("delete_child");
        sizePolicy2.setHeightForWidth(delete_child->sizePolicy().hasHeightForWidth());
        delete_child->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(delete_child);


        verticalLayout->addWidget(widget);

        widget_2 = new QWidget(widget_item);
        widget_2->setObjectName("widget_2");
        eventItemLayout = new QVBoxLayout(widget_2);
        eventItemLayout->setObjectName("eventItemLayout");

        verticalLayout->addWidget(widget_2);


        verticalLayout_2->addWidget(widget_item);


        retranslateUi(EventItem);

        QMetaObject::connectSlotsByName(EventItem);
    } // setupUi

    void retranslateUi(QWidget *EventItem)
    {
        EventItem->setWindowTitle(QCoreApplication::translate("EventItem", "Form", nullptr));
        label_17->setText(QCoreApplication::translate("EventItem", "\345\256\236\351\252\214\345\220\215\347\247\260", nullptr));
        task_event->setPlaceholderText(QCoreApplication::translate("EventItem", "\350\257\267\350\276\223\345\205\245\344\272\213\344\273\266\345\220\215\347\247\260", nullptr));
        add_child->setText(QCoreApplication::translate("EventItem", "\345\242\236\345\212\240", nullptr));
        delete_child->setText(QCoreApplication::translate("EventItem", "\345\210\240\351\231\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EventItem: public Ui_EventItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EVENTITEM_H
