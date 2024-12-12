/********************************************************************************
** Form generated from reading UI file 'questionitem.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUESTIONITEM_H
#define UI_QUESTIONITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QuestionItem
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget_question_item;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *name;
    QSpacerItem *horizontalSpacer;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_28;
    QComboBox *task_questionnaire;
    QPushButton *preview;
    QSpacerItem *horizontalSpacer_28;
    QLabel *label_29;
    QPushButton *trigger_questionnaire;
    QLabel *label_30;
    QSpinBox *trigger_hour;
    QLabel *label_31;
    QSpinBox *trigger_minute;
    QLabel *label_32;
    QSpinBox *trigger_second;
    QLabel *label_33;
    QPushButton *delete_btn;

    void setupUi(QWidget *QuestionItem)
    {
        if (QuestionItem->objectName().isEmpty())
            QuestionItem->setObjectName("QuestionItem");
        QuestionItem->resize(798, 80);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(QuestionItem->sizePolicy().hasHeightForWidth());
        QuestionItem->setSizePolicy(sizePolicy);
        QuestionItem->setMinimumSize(QSize(0, 80));
        QuestionItem->setMaximumSize(QSize(16777215, 80));
        verticalLayout = new QVBoxLayout(QuestionItem);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget_question_item = new QWidget(QuestionItem);
        widget_question_item->setObjectName("widget_question_item");
        widget_question_item->setStyleSheet(QString::fromUtf8("QWidget#widget_question_item{\n"
"background-color: rgb(255, 255, 255);\n"
"border:1px solid rgb(95, 95, 95);\n"
"border-radius:6px;\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(widget_question_item);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        widget_2 = new QWidget(widget_question_item);
        widget_2->setObjectName("widget_2");
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        name = new QLabel(widget_2);
        name->setObjectName("name");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(name->sizePolicy().hasHeightForWidth());
        name->setSizePolicy(sizePolicy1);
        name->setMinimumSize(QSize(80, 0));
        name->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_2->addWidget(name);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout_2->addWidget(widget_2);

        widget = new QWidget(widget_question_item);
        widget->setObjectName("widget");
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        label_28 = new QLabel(widget);
        label_28->setObjectName("label_28");
        sizePolicy1.setHeightForWidth(label_28->sizePolicy().hasHeightForWidth());
        label_28->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(label_28);

        task_questionnaire = new QComboBox(widget);
        task_questionnaire->setObjectName("task_questionnaire");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(task_questionnaire->sizePolicy().hasHeightForWidth());
        task_questionnaire->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(task_questionnaire);

        preview = new QPushButton(widget);
        preview->setObjectName("preview");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(preview->sizePolicy().hasHeightForWidth());
        preview->setSizePolicy(sizePolicy3);

        horizontalLayout->addWidget(preview);

        horizontalSpacer_28 = new QSpacerItem(0, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_28);

        label_29 = new QLabel(widget);
        label_29->setObjectName("label_29");
        sizePolicy1.setHeightForWidth(label_29->sizePolicy().hasHeightForWidth());
        label_29->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(label_29);

        trigger_questionnaire = new QPushButton(widget);
        trigger_questionnaire->setObjectName("trigger_questionnaire");
        sizePolicy3.setHeightForWidth(trigger_questionnaire->sizePolicy().hasHeightForWidth());
        trigger_questionnaire->setSizePolicy(sizePolicy3);

        horizontalLayout->addWidget(trigger_questionnaire);

        label_30 = new QLabel(widget);
        label_30->setObjectName("label_30");
        sizePolicy1.setHeightForWidth(label_30->sizePolicy().hasHeightForWidth());
        label_30->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(label_30);

        trigger_hour = new QSpinBox(widget);
        trigger_hour->setObjectName("trigger_hour");
        sizePolicy3.setHeightForWidth(trigger_hour->sizePolicy().hasHeightForWidth());
        trigger_hour->setSizePolicy(sizePolicy3);

        horizontalLayout->addWidget(trigger_hour);

        label_31 = new QLabel(widget);
        label_31->setObjectName("label_31");
        sizePolicy1.setHeightForWidth(label_31->sizePolicy().hasHeightForWidth());
        label_31->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(label_31);

        trigger_minute = new QSpinBox(widget);
        trigger_minute->setObjectName("trigger_minute");
        sizePolicy3.setHeightForWidth(trigger_minute->sizePolicy().hasHeightForWidth());
        trigger_minute->setSizePolicy(sizePolicy3);

        horizontalLayout->addWidget(trigger_minute);

        label_32 = new QLabel(widget);
        label_32->setObjectName("label_32");
        sizePolicy1.setHeightForWidth(label_32->sizePolicy().hasHeightForWidth());
        label_32->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(label_32);

        trigger_second = new QSpinBox(widget);
        trigger_second->setObjectName("trigger_second");
        sizePolicy3.setHeightForWidth(trigger_second->sizePolicy().hasHeightForWidth());
        trigger_second->setSizePolicy(sizePolicy3);

        horizontalLayout->addWidget(trigger_second);

        label_33 = new QLabel(widget);
        label_33->setObjectName("label_33");
        sizePolicy1.setHeightForWidth(label_33->sizePolicy().hasHeightForWidth());
        label_33->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(label_33);

        delete_btn = new QPushButton(widget);
        delete_btn->setObjectName("delete_btn");

        horizontalLayout->addWidget(delete_btn);


        verticalLayout_2->addWidget(widget);


        verticalLayout->addWidget(widget_question_item);


        retranslateUi(QuestionItem);

        QMetaObject::connectSlotsByName(QuestionItem);
    } // setupUi

    void retranslateUi(QWidget *QuestionItem)
    {
        QuestionItem->setWindowTitle(QCoreApplication::translate("QuestionItem", "Form", nullptr));
        name->setText(QCoreApplication::translate("QuestionItem", "\351\227\256\345\215\267\344\270\200", nullptr));
        label_28->setText(QCoreApplication::translate("QuestionItem", "\351\200\211\346\213\251\351\227\256\345\215\267\357\274\232", nullptr));
        task_questionnaire->setPlaceholderText(QCoreApplication::translate("QuestionItem", "\350\257\267\351\200\211\346\213\251\351\227\256\345\215\267", nullptr));
        preview->setText(QCoreApplication::translate("QuestionItem", "\351\242\204\350\247\210", nullptr));
        label_29->setText(QCoreApplication::translate("QuestionItem", "\350\247\246\345\217\221\345\212\250\344\275\234\357\274\232", nullptr));
        trigger_questionnaire->setText(QCoreApplication::translate("QuestionItem", "\350\257\267\351\200\211\346\213\251\350\247\246\345\217\221\347\233\256\346\240\207", nullptr));
        label_30->setText(QCoreApplication::translate("QuestionItem", "\350\247\246\345\217\221\346\227\266\351\227\264\357\274\232", nullptr));
        label_31->setText(QCoreApplication::translate("QuestionItem", "\345\260\217\346\227\266", nullptr));
        label_32->setText(QCoreApplication::translate("QuestionItem", "\345\210\206\351\222\237", nullptr));
        label_33->setText(QCoreApplication::translate("QuestionItem", "\347\247\222", nullptr));
        delete_btn->setText(QCoreApplication::translate("QuestionItem", "\345\210\240\351\231\244\351\227\256\345\215\267", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QuestionItem: public Ui_QuestionItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUESTIONITEM_H
