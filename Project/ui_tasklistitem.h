/********************************************************************************
** Form generated from reading UI file 'tasklistitem.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASKLISTITEM_H
#define UI_TASKLISTITEM_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TaskListItem
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget_task;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QLabel *task_name;
    QSpacerItem *horizontalSpacer;
    QLabel *label_6;
    QLabel *create_name;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_8;
    QDateTimeEdit *create_time;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *task_edit;
    QPushButton *task_delete;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QFrame *line;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QPlainTextEdit *task_description;
    QLabel *label_2;
    QComboBox *comboBox;
    QPushButton *task_start;
    QPushButton *TaskSelect;

    void setupUi(QWidget *TaskListItem)
    {
        if (TaskListItem->objectName().isEmpty())
            TaskListItem->setObjectName("TaskListItem");
        TaskListItem->resize(953, 150);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(TaskListItem->sizePolicy().hasHeightForWidth());
        TaskListItem->setSizePolicy(sizePolicy);
        TaskListItem->setMinimumSize(QSize(0, 150));
        TaskListItem->setMaximumSize(QSize(16777215, 150));
        TaskListItem->setStyleSheet(QString::fromUtf8(""));
        verticalLayout = new QVBoxLayout(TaskListItem);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget_task = new QWidget(TaskListItem);
        widget_task->setObjectName("widget_task");
        widget_task->setStyleSheet(QString::fromUtf8("QWidget#widget_task{\n"
"background-color: rgb(255, 255, 255);\n"
"border:1px solid rgb(95, 95, 95);\n"
"border-radius:6px;\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(widget_task);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, -1, 0, -1);
        widget_2 = new QWidget(widget_task);
        widget_2->setObjectName("widget_2");
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(-1, 0, -1, 0);
        task_name = new QLabel(widget_2);
        task_name->setObjectName("task_name");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(task_name->sizePolicy().hasHeightForWidth());
        task_name->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(task_name);

        horizontalSpacer = new QSpacerItem(706, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_6 = new QLabel(widget_2);
        label_6->setObjectName("label_6");
        sizePolicy1.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(label_6);

        create_name = new QLabel(widget_2);
        create_name->setObjectName("create_name");
        sizePolicy1.setHeightForWidth(create_name->sizePolicy().hasHeightForWidth());
        create_name->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(create_name);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        horizontalSpacer_4 = new QSpacerItem(50, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        label_8 = new QLabel(widget_2);
        label_8->setObjectName("label_8");
        sizePolicy1.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(label_8);

        create_time = new QDateTimeEdit(widget_2);
        create_time->setObjectName("create_time");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(create_time->sizePolicy().hasHeightForWidth());
        create_time->setSizePolicy(sizePolicy2);
        create_time->setFocusPolicy(Qt::FocusPolicy::ClickFocus);
        create_time->setFrame(false);
        create_time->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        create_time->setDateTime(QDateTime(QDate(2024, 10, 10), QTime(11, 6, 34)));
        create_time->setDate(QDate(2024, 10, 10));

        horizontalLayout->addWidget(create_time);

        horizontalSpacer_5 = new QSpacerItem(50, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        task_edit = new QPushButton(widget_2);
        task_edit->setObjectName("task_edit");
        sizePolicy2.setHeightForWidth(task_edit->sizePolicy().hasHeightForWidth());
        task_edit->setSizePolicy(sizePolicy2);
        task_edit->setMinimumSize(QSize(50, 0));
        task_edit->setMaximumSize(QSize(50, 16777215));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/mainwindow/edit.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        task_edit->setIcon(icon);
        task_edit->setFlat(true);

        horizontalLayout->addWidget(task_edit);

        task_delete = new QPushButton(widget_2);
        task_delete->setObjectName("task_delete");
        sizePolicy2.setHeightForWidth(task_delete->sizePolicy().hasHeightForWidth());
        task_delete->setSizePolicy(sizePolicy2);
        task_delete->setMinimumSize(QSize(50, 0));
        task_delete->setMaximumSize(QSize(50, 16777215));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/mainwindow/delete.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        task_delete->setIcon(icon1);
        task_delete->setFlat(true);

        horizontalLayout->addWidget(task_delete);


        verticalLayout_2->addWidget(widget_2);

        widget_3 = new QWidget(widget_task);
        widget_3->setObjectName("widget_3");
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        line = new QFrame(widget_3);
        line->setObjectName("line");
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);

        horizontalLayout_3->addWidget(line);


        verticalLayout_2->addWidget(widget_3);

        widget = new QWidget(widget_task);
        widget->setObjectName("widget");
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        task_description = new QPlainTextEdit(widget);
        task_description->setObjectName("task_description");
        task_description->setFocusPolicy(Qt::FocusPolicy::ClickFocus);
        task_description->setFrameShape(QFrame::Shape::NoFrame);

        horizontalLayout_2->addWidget(task_description);

        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(label_2);

        comboBox = new QComboBox(widget);
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        sizePolicy2.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy2);
        comboBox->setMinimumSize(QSize(158, 0));
        comboBox->setMaximumSize(QSize(150, 16777215));

        horizontalLayout_2->addWidget(comboBox);

        task_start = new QPushButton(widget);
        task_start->setObjectName("task_start");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(task_start->sizePolicy().hasHeightForWidth());
        task_start->setSizePolicy(sizePolicy3);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/mainwindow/start.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        task_start->setIcon(icon2);
        task_start->setFlat(true);

        horizontalLayout_2->addWidget(task_start);

        TaskSelect = new QPushButton(widget);
        TaskSelect->setObjectName("TaskSelect");
        sizePolicy3.setHeightForWidth(TaskSelect->sizePolicy().hasHeightForWidth());
        TaskSelect->setSizePolicy(sizePolicy3);
        QFont font;
        font.setPointSize(11);
        TaskSelect->setFont(font);
        TaskSelect->setStyleSheet(QString::fromUtf8("color: rgb(85, 170, 255);"));
        TaskSelect->setFlat(true);

        horizontalLayout_2->addWidget(TaskSelect);


        verticalLayout_2->addWidget(widget);


        verticalLayout->addWidget(widget_task);

        QWidget::setTabOrder(create_time, task_delete);
        QWidget::setTabOrder(task_delete, task_description);

        retranslateUi(TaskListItem);

        QMetaObject::connectSlotsByName(TaskListItem);
    } // setupUi

    void retranslateUi(QWidget *TaskListItem)
    {
        TaskListItem->setWindowTitle(QCoreApplication::translate("TaskListItem", "Form", nullptr));
        task_name->setText(QCoreApplication::translate("TaskListItem", "\344\273\273\345\212\241\345\220\215\347\247\260\344\273\273\345\212\241\345\220\215\347\247\260", nullptr));
        label_6->setText(QCoreApplication::translate("TaskListItem", "\345\210\233\345\273\272\344\272\272\357\274\232", nullptr));
        create_name->setText(QCoreApplication::translate("TaskListItem", "\345\260\217\350\217\234\346\227\240\346\225\214", nullptr));
        label_8->setText(QCoreApplication::translate("TaskListItem", "\345\210\233\345\273\272\346\227\266\351\227\264", nullptr));
        create_time->setDisplayFormat(QCoreApplication::translate("TaskListItem", "yyyy-M-d H:mm:ss", nullptr));
        task_edit->setText(QCoreApplication::translate("TaskListItem", "\347\274\226\350\276\221", nullptr));
        task_delete->setText(QCoreApplication::translate("TaskListItem", "\345\210\240\351\231\244", nullptr));
        task_description->setPlainText(QCoreApplication::translate("TaskListItem", "\351\227\256\345\215\267\346\217\217\350\277\260\351\227\256\345\215\267\346\217\217\350\277\260\351\227\256\345\215\267\346\217\217\350\277\260\351\227\256\345\215\267\346\217\217\350\277\260", nullptr));
        label_2->setText(QCoreApplication::translate("TaskListItem", "\351\200\211\346\213\251\350\257\225\351\243\236\344\272\272\345\221\230\357\274\232", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("TaskListItem", "\346\232\202\346\234\252\351\200\211\346\213\251", nullptr));

        task_start->setText(QCoreApplication::translate("TaskListItem", "\345\274\200\345\247\213", nullptr));
        TaskSelect->setText(QCoreApplication::translate("TaskListItem", "\351\200\211\346\213\251\344\273\273\345\212\241", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TaskListItem: public Ui_TaskListItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASKLISTITEM_H
