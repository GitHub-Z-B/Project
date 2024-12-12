/********************************************************************************
** Form generated from reading UI file 'replaylistitem.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPLAYLISTITEM_H
#define UI_REPLAYLISTITEM_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
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

class Ui_ReplayListItem
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget_replay;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QLabel *label_3;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_5;
    QLabel *label_9;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_6;
    QLabel *label_7;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_8;
    QDateTimeEdit *dateTimeEdit;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *delete_2;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QFrame *line;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QPlainTextEdit *plainTextEdit;
    QPushButton *start;

    void setupUi(QWidget *ReplayListItem)
    {
        if (ReplayListItem->objectName().isEmpty())
            ReplayListItem->setObjectName("ReplayListItem");
        ReplayListItem->resize(681, 150);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ReplayListItem->sizePolicy().hasHeightForWidth());
        ReplayListItem->setSizePolicy(sizePolicy);
        ReplayListItem->setMinimumSize(QSize(0, 150));
        ReplayListItem->setMaximumSize(QSize(16777215, 267));
        verticalLayout = new QVBoxLayout(ReplayListItem);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget_replay = new QWidget(ReplayListItem);
        widget_replay->setObjectName("widget_replay");
        widget_replay->setStyleSheet(QString::fromUtf8("QWidget#widget_replay{\n"
"background-color: rgb(255, 255, 255);\n"
"border:1px solid rgb(95, 95, 95);\n"
"border-radius:6px;\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(widget_replay);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, -1, 0, -1);
        widget_2 = new QWidget(widget_replay);
        widget_2->setObjectName("widget_2");
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(-1, 0, -1, 0);
        label = new QLabel(widget_2);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(706, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_3 = new QLabel(widget_2);
        label_3->setObjectName("label_3");

        horizontalLayout->addWidget(label_3);

        label_4 = new QLabel(widget_2);
        label_4->setObjectName("label_4");

        horizontalLayout->addWidget(label_4);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        label_5 = new QLabel(widget_2);
        label_5->setObjectName("label_5");

        horizontalLayout->addWidget(label_5);

        label_9 = new QLabel(widget_2);
        label_9->setObjectName("label_9");

        horizontalLayout->addWidget(label_9);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        label_6 = new QLabel(widget_2);
        label_6->setObjectName("label_6");

        horizontalLayout->addWidget(label_6);

        label_7 = new QLabel(widget_2);
        label_7->setObjectName("label_7");

        horizontalLayout->addWidget(label_7);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        label_8 = new QLabel(widget_2);
        label_8->setObjectName("label_8");

        horizontalLayout->addWidget(label_8);

        dateTimeEdit = new QDateTimeEdit(widget_2);
        dateTimeEdit->setObjectName("dateTimeEdit");
        dateTimeEdit->setFocusPolicy(Qt::FocusPolicy::ClickFocus);
        dateTimeEdit->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        dateTimeEdit->setDateTime(QDateTime(QDate(2024, 10, 10), QTime(11, 6, 34)));
        dateTimeEdit->setDate(QDate(2024, 10, 10));

        horizontalLayout->addWidget(dateTimeEdit);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        delete_2 = new QPushButton(widget_2);
        delete_2->setObjectName("delete_2");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(delete_2->sizePolicy().hasHeightForWidth());
        delete_2->setSizePolicy(sizePolicy1);
        delete_2->setMinimumSize(QSize(50, 0));
        delete_2->setMaximumSize(QSize(50, 16777215));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/mainwindow/delete.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        delete_2->setIcon(icon);
        delete_2->setFlat(true);

        horizontalLayout->addWidget(delete_2);


        verticalLayout_2->addWidget(widget_2);

        widget_3 = new QWidget(widget_replay);
        widget_3->setObjectName("widget_3");
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        line = new QFrame(widget_3);
        line->setObjectName("line");
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);

        horizontalLayout_3->addWidget(line);


        verticalLayout_2->addWidget(widget_3);

        widget = new QWidget(widget_replay);
        widget->setObjectName("widget");
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(-1, 0, -1, 0);
        plainTextEdit = new QPlainTextEdit(widget);
        plainTextEdit->setObjectName("plainTextEdit");
        plainTextEdit->setFocusPolicy(Qt::FocusPolicy::ClickFocus);
        plainTextEdit->setFrameShape(QFrame::Shape::NoFrame);

        horizontalLayout_2->addWidget(plainTextEdit);

        start = new QPushButton(widget);
        start->setObjectName("start");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(start->sizePolicy().hasHeightForWidth());
        start->setSizePolicy(sizePolicy2);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/mainwindow/start.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        start->setIcon(icon1);
        start->setFlat(true);

        horizontalLayout_2->addWidget(start);


        verticalLayout_2->addWidget(widget);


        verticalLayout->addWidget(widget_replay);


        retranslateUi(ReplayListItem);

        QMetaObject::connectSlotsByName(ReplayListItem);
    } // setupUi

    void retranslateUi(QWidget *ReplayListItem)
    {
        ReplayListItem->setWindowTitle(QCoreApplication::translate("ReplayListItem", "Form", nullptr));
        label->setText(QCoreApplication::translate("ReplayListItem", "\344\273\273\345\212\241\345\220\215\347\247\260\344\273\273\345\212\241\345\220\215\347\247\260", nullptr));
        label_3->setText(QCoreApplication::translate("ReplayListItem", "\345\233\236\346\224\276\346\254\241\346\225\260\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("ReplayListItem", "4\346\254\241", nullptr));
        label_5->setText(QCoreApplication::translate("ReplayListItem", "\350\257\225\351\243\236\344\272\272\345\221\230\357\274\232", nullptr));
        label_9->setText(QCoreApplication::translate("ReplayListItem", "\344\272\214\347\211\233", nullptr));
        label_6->setText(QCoreApplication::translate("ReplayListItem", "\345\210\233\345\273\272\344\272\272\357\274\232", nullptr));
        label_7->setText(QCoreApplication::translate("ReplayListItem", "\345\260\217\350\217\234\346\227\240\346\225\214", nullptr));
        label_8->setText(QCoreApplication::translate("ReplayListItem", "\345\233\236\346\224\276\346\227\266\351\227\264", nullptr));
        dateTimeEdit->setDisplayFormat(QCoreApplication::translate("ReplayListItem", "yyyy-M-d H:mm:ss", nullptr));
        delete_2->setText(QCoreApplication::translate("ReplayListItem", "\345\210\240\351\231\244", nullptr));
        plainTextEdit->setPlainText(QCoreApplication::translate("ReplayListItem", "\351\227\256\345\215\267\346\217\217\350\277\260\351\227\256\345\215\267\346\217\217\350\277\260\351\227\256\345\215\267\346\217\217\350\277\260\351\227\256\345\215\267\346\217\217\350\277\260", nullptr));
        start->setText(QCoreApplication::translate("ReplayListItem", "\345\274\200\345\247\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ReplayListItem: public Ui_ReplayListItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPLAYLISTITEM_H
