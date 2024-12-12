/********************************************************************************
** Form generated from reading UI file 'answerlistitem.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ANSWERLISTITEM_H
#define UI_ANSWERLISTITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AnswerListItem
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *questionnaire_name;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QLabel *answer_number;

    void setupUi(QWidget *AnswerListItem)
    {
        if (AnswerListItem->objectName().isEmpty())
            AnswerListItem->setObjectName("AnswerListItem");
        AnswerListItem->resize(776, 50);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AnswerListItem->sizePolicy().hasHeightForWidth());
        AnswerListItem->setSizePolicy(sizePolicy);
        AnswerListItem->setMinimumSize(QSize(0, 50));
        AnswerListItem->setMaximumSize(QSize(16777215, 59));
        horizontalLayout = new QHBoxLayout(AnswerListItem);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(AnswerListItem);
        widget->setObjectName("widget");
        widget->setStyleSheet(QString::fromUtf8("QWidget#widget{\n"
"background-color: rgb(255, 255, 255);\n"
"border:1px solid rgb(95, 95, 95);\n"
"border-radius:6px;\n"
"}"));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        questionnaire_name = new QLabel(widget);
        questionnaire_name->setObjectName("questionnaire_name");

        horizontalLayout_2->addWidget(questionnaire_name);

        horizontalSpacer = new QSpacerItem(623, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");

        horizontalLayout_2->addWidget(label_2);

        answer_number = new QLabel(widget);
        answer_number->setObjectName("answer_number");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(answer_number->sizePolicy().hasHeightForWidth());
        answer_number->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(answer_number);


        horizontalLayout->addWidget(widget);


        retranslateUi(AnswerListItem);

        QMetaObject::connectSlotsByName(AnswerListItem);
    } // setupUi

    void retranslateUi(QWidget *AnswerListItem)
    {
        AnswerListItem->setWindowTitle(QString());
        questionnaire_name->setText(QCoreApplication::translate("AnswerListItem", "\351\227\256\345\215\267\345\220\215\347\247\260", nullptr));
        label_2->setText(QCoreApplication::translate("AnswerListItem", "\347\255\224\345\215\267\346\225\260\351\207\217\357\274\232", nullptr));
        answer_number->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AnswerListItem: public Ui_AnswerListItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANSWERLISTITEM_H
