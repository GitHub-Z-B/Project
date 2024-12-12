/********************************************************************************
** Form generated from reading UI file 'questionnairelistitem.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUESTIONNAIRELISTITEM_H
#define UI_QUESTIONNAIRELISTITEM_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QuestionnaireListItem
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget_task;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout;
    QLabel *questionnaire_name;
    QSpacerItem *horizontalSpacer;
    QLabel *label_6;
    QLabel *average_score;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_8;
    QLabel *question_number;
    QLabel *label;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_9;
    QLabel *answer_number;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_5;
    QDateTimeEdit *create_time;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QFrame *line;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *preview;
    QPushButton *export_pdf;
    QPushButton *export_word;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *questionnaire_edit;
    QPushButton *questionnaire_delete;

    void setupUi(QWidget *QuestionnaireListItem)
    {
        if (QuestionnaireListItem->objectName().isEmpty())
            QuestionnaireListItem->setObjectName("QuestionnaireListItem");
        QuestionnaireListItem->resize(830, 150);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(QuestionnaireListItem->sizePolicy().hasHeightForWidth());
        QuestionnaireListItem->setSizePolicy(sizePolicy);
        QuestionnaireListItem->setMinimumSize(QSize(0, 150));
        QuestionnaireListItem->setMaximumSize(QSize(16777215, 150));
        verticalLayout = new QVBoxLayout(QuestionnaireListItem);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget_task = new QWidget(QuestionnaireListItem);
        widget_task->setObjectName("widget_task");
        widget_task->setStyleSheet(QString::fromUtf8("QWidget#widget_task{\n"
"background-color: rgb(255, 255, 255);\n"
"border:1px solid rgb(95, 95, 95);\n"
"border-radius:6px;\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(widget_task);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, -1, 0, -1);
        widget_4 = new QWidget(widget_task);
        widget_4->setObjectName("widget_4");
        horizontalLayout = new QHBoxLayout(widget_4);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(-1, 0, -1, 0);
        questionnaire_name = new QLabel(widget_4);
        questionnaire_name->setObjectName("questionnaire_name");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(questionnaire_name->sizePolicy().hasHeightForWidth());
        questionnaire_name->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(questionnaire_name);

        horizontalSpacer = new QSpacerItem(200, 20, QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_6 = new QLabel(widget_4);
        label_6->setObjectName("label_6");
        sizePolicy1.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(label_6);

        average_score = new QLabel(widget_4);
        average_score->setObjectName("average_score");
        sizePolicy1.setHeightForWidth(average_score->sizePolicy().hasHeightForWidth());
        average_score->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(average_score);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        label_8 = new QLabel(widget_4);
        label_8->setObjectName("label_8");
        sizePolicy1.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(label_8);

        question_number = new QLabel(widget_4);
        question_number->setObjectName("question_number");
        sizePolicy1.setHeightForWidth(question_number->sizePolicy().hasHeightForWidth());
        question_number->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(question_number);

        label = new QLabel(widget_4);
        label->setObjectName("label");
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(label);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        label_9 = new QLabel(widget_4);
        label_9->setObjectName("label_9");
        sizePolicy1.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(label_9);

        answer_number = new QLabel(widget_4);
        answer_number->setObjectName("answer_number");
        sizePolicy1.setHeightForWidth(answer_number->sizePolicy().hasHeightForWidth());
        answer_number->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(answer_number);

        label_2 = new QLabel(widget_4);
        label_2->setObjectName("label_2");
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(label_2);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        label_5 = new QLabel(widget_4);
        label_5->setObjectName("label_5");
        sizePolicy1.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(label_5);

        create_time = new QDateTimeEdit(widget_4);
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


        verticalLayout_2->addWidget(widget_4);

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
        horizontalLayout_2->setContentsMargins(-1, 0, -1, 0);
        preview = new QPushButton(widget);
        preview->setObjectName("preview");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(preview->sizePolicy().hasHeightForWidth());
        preview->setSizePolicy(sizePolicy3);
        preview->setFlat(true);

        horizontalLayout_2->addWidget(preview);

        export_pdf = new QPushButton(widget);
        export_pdf->setObjectName("export_pdf");
        sizePolicy3.setHeightForWidth(export_pdf->sizePolicy().hasHeightForWidth());
        export_pdf->setSizePolicy(sizePolicy3);
        export_pdf->setFlat(true);

        horizontalLayout_2->addWidget(export_pdf);

        export_word = new QPushButton(widget);
        export_word->setObjectName("export_word");
        sizePolicy3.setHeightForWidth(export_word->sizePolicy().hasHeightForWidth());
        export_word->setSizePolicy(sizePolicy3);
        export_word->setFlat(true);

        horizontalLayout_2->addWidget(export_word);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        questionnaire_edit = new QPushButton(widget);
        questionnaire_edit->setObjectName("questionnaire_edit");
        sizePolicy3.setHeightForWidth(questionnaire_edit->sizePolicy().hasHeightForWidth());
        questionnaire_edit->setSizePolicy(sizePolicy3);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/mainwindow/edit.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        questionnaire_edit->setIcon(icon);
        questionnaire_edit->setFlat(true);

        horizontalLayout_2->addWidget(questionnaire_edit);

        questionnaire_delete = new QPushButton(widget);
        questionnaire_delete->setObjectName("questionnaire_delete");
        sizePolicy3.setHeightForWidth(questionnaire_delete->sizePolicy().hasHeightForWidth());
        questionnaire_delete->setSizePolicy(sizePolicy3);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/mainwindow/delete.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        questionnaire_delete->setIcon(icon1);
        questionnaire_delete->setFlat(true);

        horizontalLayout_2->addWidget(questionnaire_delete);


        verticalLayout_2->addWidget(widget);


        verticalLayout->addWidget(widget_task);


        retranslateUi(QuestionnaireListItem);

        QMetaObject::connectSlotsByName(QuestionnaireListItem);
    } // setupUi

    void retranslateUi(QWidget *QuestionnaireListItem)
    {
        QuestionnaireListItem->setWindowTitle(QCoreApplication::translate("QuestionnaireListItem", "Form", nullptr));
        questionnaire_name->setText(QCoreApplication::translate("QuestionnaireListItem", "\351\227\256\345\215\267\345\220\215\347\247\260\351\227\256\345\215\267\345\220\215\347\247\260", nullptr));
        label_6->setText(QCoreApplication::translate("QuestionnaireListItem", "\351\227\256\345\215\267\345\271\263\345\235\207\345\210\206\357\274\232", nullptr));
        average_score->setText(QCoreApplication::translate("QuestionnaireListItem", "\342\200\224\342\200\224", nullptr));
        label_8->setText(QCoreApplication::translate("QuestionnaireListItem", "\351\242\230\347\233\256\346\225\260\351\207\217\357\274\232", nullptr));
        question_number->setText(QCoreApplication::translate("QuestionnaireListItem", "20", nullptr));
        label->setText(QCoreApplication::translate("QuestionnaireListItem", "\351\242\230", nullptr));
        label_9->setText(QCoreApplication::translate("QuestionnaireListItem", "\344\275\234\347\255\224\346\254\241\346\225\260\357\274\232", nullptr));
        answer_number->setText(QCoreApplication::translate("QuestionnaireListItem", "4", nullptr));
        label_2->setText(QCoreApplication::translate("QuestionnaireListItem", "\346\254\241", nullptr));
        label_5->setText(QCoreApplication::translate("QuestionnaireListItem", "\345\210\233\345\273\272\346\227\266\351\227\264\357\274\232", nullptr));
        create_time->setDisplayFormat(QCoreApplication::translate("QuestionnaireListItem", "yyyy-M-d H:mm:ss", nullptr));
        preview->setText(QCoreApplication::translate("QuestionnaireListItem", "\351\227\256\345\215\267\351\242\204\350\247\210", nullptr));
        export_pdf->setText(QCoreApplication::translate("QuestionnaireListItem", "\350\276\223\345\207\272PDF", nullptr));
        export_word->setText(QCoreApplication::translate("QuestionnaireListItem", "\350\276\223\345\207\272word", nullptr));
        questionnaire_edit->setText(QCoreApplication::translate("QuestionnaireListItem", "\347\274\226\350\276\221", nullptr));
        questionnaire_delete->setText(QCoreApplication::translate("QuestionnaireListItem", "\345\210\240\351\231\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QuestionnaireListItem: public Ui_QuestionnaireListItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUESTIONNAIRELISTITEM_H
