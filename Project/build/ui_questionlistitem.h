/********************************************************************************
** Form generated from reading UI file 'questionlistitem.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUESTIONLISTITEM_H
#define UI_QUESTIONLISTITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QuestionListItem
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidget;
    QWidget *page1;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *scoring_question;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_4;
    QRadioButton *radioButton_1;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;
    QRadioButton *radioButton_5;
    QRadioButton *radioButton_6;
    QRadioButton *radioButton_7;
    QRadioButton *radioButton_8;
    QRadioButton *radioButton_9;
    QRadioButton *radioButton_10;
    QSpacerItem *horizontalSpacer_4;
    QWidget *page2;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_6;
    QLabel *choice_question;
    QWidget *widget_7;
    QHBoxLayout *horizontalLayout_7;
    QRadioButton *choice_optional_1;
    QRadioButton *choice_optional_2;
    QRadioButton *choice_optional_3;
    QRadioButton *choice_optional_4;
    QSpacerItem *horizontalSpacer_3;
    QWidget *page3;
    QVBoxLayout *verticalLayout_4;
    QWidget *widget_9;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer_5;
    QWidget *widget_8;
    QVBoxLayout *verticalLayout_5;
    QLabel *subjective_question;
    QTextEdit *subjective_answer;

    void setupUi(QWidget *QuestionListItem)
    {
        if (QuestionListItem->objectName().isEmpty())
            QuestionListItem->setObjectName("QuestionListItem");
        QuestionListItem->resize(838, 150);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(QuestionListItem->sizePolicy().hasHeightForWidth());
        QuestionListItem->setSizePolicy(sizePolicy);
        QuestionListItem->setMinimumSize(QSize(0, 150));
        QuestionListItem->setMaximumSize(QSize(16777215, 150));
        horizontalLayout = new QHBoxLayout(QuestionListItem);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(QuestionListItem);
        widget->setObjectName("widget");
        widget->setStyleSheet(QString::fromUtf8("QWidget#widget{\n"
"background-color: rgb(255, 255, 255);\n"
"}"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        stackedWidget = new QStackedWidget(widget);
        stackedWidget->setObjectName("stackedWidget");
        page1 = new QWidget();
        page1->setObjectName("page1");
        verticalLayout_2 = new QVBoxLayout(page1);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        widget_2 = new QWidget(page1);
        widget_2->setObjectName("widget_2");
        sizePolicy.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy);
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label = new QLabel(widget_2);
        label->setObjectName("label");

        horizontalLayout_2->addWidget(label);

        horizontalSpacer = new QSpacerItem(715, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout_2->addWidget(widget_2);

        widget_3 = new QWidget(page1);
        widget_3->setObjectName("widget_3");
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        scoring_question = new QLabel(widget_3);
        scoring_question->setObjectName("scoring_question");

        horizontalLayout_3->addWidget(scoring_question);


        verticalLayout_2->addWidget(widget_3);

        widget_4 = new QWidget(page1);
        widget_4->setObjectName("widget_4");
        horizontalLayout_4 = new QHBoxLayout(widget_4);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        radioButton_1 = new QRadioButton(widget_4);
        radioButton_1->setObjectName("radioButton_1");

        horizontalLayout_4->addWidget(radioButton_1);

        radioButton_2 = new QRadioButton(widget_4);
        radioButton_2->setObjectName("radioButton_2");

        horizontalLayout_4->addWidget(radioButton_2);

        radioButton_3 = new QRadioButton(widget_4);
        radioButton_3->setObjectName("radioButton_3");

        horizontalLayout_4->addWidget(radioButton_3);

        radioButton_4 = new QRadioButton(widget_4);
        radioButton_4->setObjectName("radioButton_4");

        horizontalLayout_4->addWidget(radioButton_4);

        radioButton_5 = new QRadioButton(widget_4);
        radioButton_5->setObjectName("radioButton_5");

        horizontalLayout_4->addWidget(radioButton_5);

        radioButton_6 = new QRadioButton(widget_4);
        radioButton_6->setObjectName("radioButton_6");

        horizontalLayout_4->addWidget(radioButton_6);

        radioButton_7 = new QRadioButton(widget_4);
        radioButton_7->setObjectName("radioButton_7");

        horizontalLayout_4->addWidget(radioButton_7);

        radioButton_8 = new QRadioButton(widget_4);
        radioButton_8->setObjectName("radioButton_8");

        horizontalLayout_4->addWidget(radioButton_8);

        radioButton_9 = new QRadioButton(widget_4);
        radioButton_9->setObjectName("radioButton_9");

        horizontalLayout_4->addWidget(radioButton_9);

        radioButton_10 = new QRadioButton(widget_4);
        radioButton_10->setObjectName("radioButton_10");

        horizontalLayout_4->addWidget(radioButton_10);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);


        verticalLayout_2->addWidget(widget_4);

        stackedWidget->addWidget(page1);
        page2 = new QWidget();
        page2->setObjectName("page2");
        verticalLayout_3 = new QVBoxLayout(page2);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        widget_5 = new QWidget(page2);
        widget_5->setObjectName("widget_5");
        sizePolicy.setHeightForWidth(widget_5->sizePolicy().hasHeightForWidth());
        widget_5->setSizePolicy(sizePolicy);
        horizontalLayout_5 = new QHBoxLayout(widget_5);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_3 = new QLabel(widget_5);
        label_3->setObjectName("label_3");

        horizontalLayout_5->addWidget(label_3);

        horizontalSpacer_2 = new QSpacerItem(715, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);


        verticalLayout_3->addWidget(widget_5);

        widget_6 = new QWidget(page2);
        widget_6->setObjectName("widget_6");
        horizontalLayout_6 = new QHBoxLayout(widget_6);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        choice_question = new QLabel(widget_6);
        choice_question->setObjectName("choice_question");

        horizontalLayout_6->addWidget(choice_question);


        verticalLayout_3->addWidget(widget_6);

        widget_7 = new QWidget(page2);
        widget_7->setObjectName("widget_7");
        horizontalLayout_7 = new QHBoxLayout(widget_7);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        choice_optional_1 = new QRadioButton(widget_7);
        choice_optional_1->setObjectName("choice_optional_1");

        horizontalLayout_7->addWidget(choice_optional_1);

        choice_optional_2 = new QRadioButton(widget_7);
        choice_optional_2->setObjectName("choice_optional_2");

        horizontalLayout_7->addWidget(choice_optional_2);

        choice_optional_3 = new QRadioButton(widget_7);
        choice_optional_3->setObjectName("choice_optional_3");

        horizontalLayout_7->addWidget(choice_optional_3);

        choice_optional_4 = new QRadioButton(widget_7);
        choice_optional_4->setObjectName("choice_optional_4");

        horizontalLayout_7->addWidget(choice_optional_4);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_3);


        verticalLayout_3->addWidget(widget_7);

        stackedWidget->addWidget(page2);
        page3 = new QWidget();
        page3->setObjectName("page3");
        verticalLayout_4 = new QVBoxLayout(page3);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        widget_9 = new QWidget(page3);
        widget_9->setObjectName("widget_9");
        sizePolicy.setHeightForWidth(widget_9->sizePolicy().hasHeightForWidth());
        widget_9->setSizePolicy(sizePolicy);
        horizontalLayout_9 = new QHBoxLayout(widget_9);
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        label_6 = new QLabel(widget_9);
        label_6->setObjectName("label_6");

        horizontalLayout_9->addWidget(label_6);

        horizontalSpacer_5 = new QSpacerItem(715, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_5);


        verticalLayout_4->addWidget(widget_9);

        widget_8 = new QWidget(page3);
        widget_8->setObjectName("widget_8");
        verticalLayout_5 = new QVBoxLayout(widget_8);
        verticalLayout_5->setObjectName("verticalLayout_5");
        subjective_question = new QLabel(widget_8);
        subjective_question->setObjectName("subjective_question");

        verticalLayout_5->addWidget(subjective_question);

        subjective_answer = new QTextEdit(widget_8);
        subjective_answer->setObjectName("subjective_answer");

        verticalLayout_5->addWidget(subjective_answer);


        verticalLayout_4->addWidget(widget_8);

        stackedWidget->addWidget(page3);

        verticalLayout->addWidget(stackedWidget);


        horizontalLayout->addWidget(widget);


        retranslateUi(QuestionListItem);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(QuestionListItem);
    } // setupUi

    void retranslateUi(QWidget *QuestionListItem)
    {
        QuestionListItem->setWindowTitle(QCoreApplication::translate("QuestionListItem", "Form", nullptr));
        label->setText(QCoreApplication::translate("QuestionListItem", "\346\211\223\345\210\206\351\242\230\357\274\210\346\227\240\346\214\207\346\240\207\357\274\211", nullptr));
        scoring_question->setText(QCoreApplication::translate("QuestionListItem", "\346\210\221\345\234\250\344\275\277\347\224\250\346\234\254\347\263\273\347\273\237\347\232\204\346\227\266\345\200\231\351\235\236\345\270\270\350\207\252\344\277\241", nullptr));
        radioButton_1->setText(QCoreApplication::translate("QuestionListItem", "1\345\210\206", nullptr));
        radioButton_2->setText(QCoreApplication::translate("QuestionListItem", "2\345\210\206", nullptr));
        radioButton_3->setText(QCoreApplication::translate("QuestionListItem", "3\345\210\206", nullptr));
        radioButton_4->setText(QCoreApplication::translate("QuestionListItem", "4\345\210\206", nullptr));
        radioButton_5->setText(QCoreApplication::translate("QuestionListItem", "5\345\210\206", nullptr));
        radioButton_6->setText(QCoreApplication::translate("QuestionListItem", "6\345\210\206", nullptr));
        radioButton_7->setText(QCoreApplication::translate("QuestionListItem", "7\345\210\206", nullptr));
        radioButton_8->setText(QCoreApplication::translate("QuestionListItem", "8\345\210\206", nullptr));
        radioButton_9->setText(QCoreApplication::translate("QuestionListItem", "9\345\210\206", nullptr));
        radioButton_10->setText(QCoreApplication::translate("QuestionListItem", "10\345\210\206", nullptr));
        label_3->setText(QCoreApplication::translate("QuestionListItem", "\351\200\211\346\213\251\351\242\230\357\274\210\346\227\240\346\214\207\346\240\207\357\274\211", nullptr));
        choice_question->setText(QCoreApplication::translate("QuestionListItem", "\346\210\221\345\234\250\344\275\277\347\224\250\346\234\254\347\263\273\347\273\237\347\232\204\346\227\266\345\200\231\351\235\236\345\270\270\350\207\252\344\277\241", nullptr));
        choice_optional_1->setText(QCoreApplication::translate("QuestionListItem", "\351\200\211\351\241\271\344\270\200", nullptr));
        choice_optional_2->setText(QCoreApplication::translate("QuestionListItem", "\351\200\211\351\241\271\344\272\214", nullptr));
        choice_optional_3->setText(QCoreApplication::translate("QuestionListItem", "\351\200\211\351\241\271\344\270\211", nullptr));
        choice_optional_4->setText(QCoreApplication::translate("QuestionListItem", "\351\200\211\351\241\271\345\233\233", nullptr));
        label_6->setText(QCoreApplication::translate("QuestionListItem", "\344\270\273\350\247\202\351\242\230\357\274\210\346\227\240\346\214\207\346\240\207\357\274\211", nullptr));
        subjective_question->setText(QCoreApplication::translate("QuestionListItem", "\346\210\221\345\234\250\344\275\277\347\224\250\346\234\254\347\263\273\347\273\237\347\232\204\346\227\266\345\200\231\351\235\236\345\270\270\350\207\252\344\277\241", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QuestionListItem: public Ui_QuestionListItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUESTIONLISTITEM_H
