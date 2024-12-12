/********************************************************************************
** Form generated from reading UI file 'questiontypedialog.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUESTIONTYPEDIALOG_H
#define UI_QUESTIONTYPEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QuestionTypeDialog
{
public:
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidget;
    QWidget *page1;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QTextEdit *textEdit;
    QWidget *page2;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QTextEdit *textEdit_2;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_5;
    QWidget *widget_7;
    QGridLayout *gridLayout;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_1;
    QWidget *widget_10;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_8;
    QLineEdit *lineEdit_3;
    QCheckBox *checkBox_4;
    QWidget *widget_9;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_7;
    QLineEdit *lineEdit_2;
    QWidget *widget_8;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_6;
    QLineEdit *lineEdit_1;
    QCheckBox *checkBox_2;
    QWidget *widget_11;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_9;
    QLineEdit *lineEdit_4;
    QWidget *page3;
    QVBoxLayout *verticalLayout_4;
    QWidget *widget_12;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_10;
    QSpacerItem *horizontalSpacer_3;
    QWidget *widget_13;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_11;
    QTextEdit *textEdit_3;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *QuestionTypeDialog)
    {
        if (QuestionTypeDialog->objectName().isEmpty())
            QuestionTypeDialog->setObjectName("QuestionTypeDialog");
        QuestionTypeDialog->resize(405, 372);
        verticalLayout = new QVBoxLayout(QuestionTypeDialog);
        verticalLayout->setObjectName("verticalLayout");
        stackedWidget = new QStackedWidget(QuestionTypeDialog);
        stackedWidget->setObjectName("stackedWidget");
        page1 = new QWidget();
        page1->setObjectName("page1");
        verticalLayout_2 = new QVBoxLayout(page1);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(page1);
        widget->setObjectName("widget");
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(widget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(295, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_2->addWidget(widget);

        widget_2 = new QWidget(page1);
        widget_2->setObjectName("widget_2");
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_2 = new QLabel(widget_2);
        label_2->setObjectName("label_2");

        horizontalLayout_2->addWidget(label_2);

        textEdit = new QTextEdit(widget_2);
        textEdit->setObjectName("textEdit");

        horizontalLayout_2->addWidget(textEdit);


        verticalLayout_2->addWidget(widget_2);

        stackedWidget->addWidget(page1);
        page2 = new QWidget();
        page2->setObjectName("page2");
        verticalLayout_3 = new QVBoxLayout(page2);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        widget_4 = new QWidget(page2);
        widget_4->setObjectName("widget_4");
        horizontalLayout_4 = new QHBoxLayout(widget_4);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_3 = new QLabel(widget_4);
        label_3->setObjectName("label_3");

        horizontalLayout_4->addWidget(label_3);

        horizontalSpacer_2 = new QSpacerItem(295, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        verticalLayout_3->addWidget(widget_4);

        widget_5 = new QWidget(page2);
        widget_5->setObjectName("widget_5");
        horizontalLayout_5 = new QHBoxLayout(widget_5);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_4 = new QLabel(widget_5);
        label_4->setObjectName("label_4");

        horizontalLayout_5->addWidget(label_4);

        textEdit_2 = new QTextEdit(widget_5);
        textEdit_2->setObjectName("textEdit_2");

        horizontalLayout_5->addWidget(textEdit_2);


        verticalLayout_3->addWidget(widget_5);

        widget_6 = new QWidget(page2);
        widget_6->setObjectName("widget_6");
        horizontalLayout_6 = new QHBoxLayout(widget_6);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        label_5 = new QLabel(widget_6);
        label_5->setObjectName("label_5");

        horizontalLayout_6->addWidget(label_5);

        widget_7 = new QWidget(widget_6);
        widget_7->setObjectName("widget_7");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget_7->sizePolicy().hasHeightForWidth());
        widget_7->setSizePolicy(sizePolicy);
        widget_7->setMinimumSize(QSize(0, 150));
        gridLayout = new QGridLayout(widget_7);
        gridLayout->setSpacing(6);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        checkBox_3 = new QCheckBox(widget_7);
        checkBox_3->setObjectName("checkBox_3");

        gridLayout->addWidget(checkBox_3, 2, 0, 1, 1);

        checkBox_1 = new QCheckBox(widget_7);
        checkBox_1->setObjectName("checkBox_1");

        gridLayout->addWidget(checkBox_1, 0, 0, 1, 1);

        widget_10 = new QWidget(widget_7);
        widget_10->setObjectName("widget_10");
        horizontalLayout_9 = new QHBoxLayout(widget_10);
        horizontalLayout_9->setSpacing(0);
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(widget_10);
        label_8->setObjectName("label_8");

        horizontalLayout_9->addWidget(label_8);

        lineEdit_3 = new QLineEdit(widget_10);
        lineEdit_3->setObjectName("lineEdit_3");

        horizontalLayout_9->addWidget(lineEdit_3);


        gridLayout->addWidget(widget_10, 2, 1, 1, 1);

        checkBox_4 = new QCheckBox(widget_7);
        checkBox_4->setObjectName("checkBox_4");

        gridLayout->addWidget(checkBox_4, 3, 0, 1, 1);

        widget_9 = new QWidget(widget_7);
        widget_9->setObjectName("widget_9");
        horizontalLayout_8 = new QHBoxLayout(widget_9);
        horizontalLayout_8->setSpacing(0);
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(widget_9);
        label_7->setObjectName("label_7");

        horizontalLayout_8->addWidget(label_7);

        lineEdit_2 = new QLineEdit(widget_9);
        lineEdit_2->setObjectName("lineEdit_2");

        horizontalLayout_8->addWidget(lineEdit_2);


        gridLayout->addWidget(widget_9, 1, 1, 1, 1);

        widget_8 = new QWidget(widget_7);
        widget_8->setObjectName("widget_8");
        horizontalLayout_7 = new QHBoxLayout(widget_8);
        horizontalLayout_7->setSpacing(0);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(widget_8);
        label_6->setObjectName("label_6");

        horizontalLayout_7->addWidget(label_6);

        lineEdit_1 = new QLineEdit(widget_8);
        lineEdit_1->setObjectName("lineEdit_1");

        horizontalLayout_7->addWidget(lineEdit_1);


        gridLayout->addWidget(widget_8, 0, 1, 1, 1);

        checkBox_2 = new QCheckBox(widget_7);
        checkBox_2->setObjectName("checkBox_2");

        gridLayout->addWidget(checkBox_2, 1, 0, 1, 1);

        widget_11 = new QWidget(widget_7);
        widget_11->setObjectName("widget_11");
        horizontalLayout_10 = new QHBoxLayout(widget_11);
        horizontalLayout_10->setSpacing(0);
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(widget_11);
        label_9->setObjectName("label_9");

        horizontalLayout_10->addWidget(label_9);

        lineEdit_4 = new QLineEdit(widget_11);
        lineEdit_4->setObjectName("lineEdit_4");

        horizontalLayout_10->addWidget(lineEdit_4);


        gridLayout->addWidget(widget_11, 3, 1, 1, 1);


        horizontalLayout_6->addWidget(widget_7);


        verticalLayout_3->addWidget(widget_6);

        stackedWidget->addWidget(page2);
        page3 = new QWidget();
        page3->setObjectName("page3");
        verticalLayout_4 = new QVBoxLayout(page3);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        widget_12 = new QWidget(page3);
        widget_12->setObjectName("widget_12");
        horizontalLayout_11 = new QHBoxLayout(widget_12);
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        label_10 = new QLabel(widget_12);
        label_10->setObjectName("label_10");

        horizontalLayout_11->addWidget(label_10);

        horizontalSpacer_3 = new QSpacerItem(295, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_3);


        verticalLayout_4->addWidget(widget_12);

        widget_13 = new QWidget(page3);
        widget_13->setObjectName("widget_13");
        horizontalLayout_12 = new QHBoxLayout(widget_13);
        horizontalLayout_12->setObjectName("horizontalLayout_12");
        label_11 = new QLabel(widget_13);
        label_11->setObjectName("label_11");

        horizontalLayout_12->addWidget(label_11);

        textEdit_3 = new QTextEdit(widget_13);
        textEdit_3->setObjectName("textEdit_3");

        horizontalLayout_12->addWidget(textEdit_3);


        verticalLayout_4->addWidget(widget_13);

        stackedWidget->addWidget(page3);

        verticalLayout->addWidget(stackedWidget);

        widget_3 = new QWidget(QuestionTypeDialog);
        widget_3->setObjectName("widget_3");
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        buttonBox = new QDialogButtonBox(widget_3);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);

        horizontalLayout_3->addWidget(buttonBox);


        verticalLayout->addWidget(widget_3);


        retranslateUi(QuestionTypeDialog);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(QuestionTypeDialog);
    } // setupUi

    void retranslateUi(QDialog *QuestionTypeDialog)
    {
        QuestionTypeDialog->setWindowTitle(QCoreApplication::translate("QuestionTypeDialog", "\346\267\273\345\212\240\351\242\230\347\233\256", nullptr));
        label->setText(QCoreApplication::translate("QuestionTypeDialog", "\346\267\273\345\212\240\346\211\223\345\210\206\351\242\230", nullptr));
        label_2->setText(QCoreApplication::translate("QuestionTypeDialog", "\351\242\230\345\271\262\357\274\232", nullptr));
        textEdit->setPlaceholderText(QCoreApplication::translate("QuestionTypeDialog", "\350\257\267\350\276\223\345\205\245\351\242\230\345\271\262\345\206\205\345\256\271", nullptr));
        label_3->setText(QCoreApplication::translate("QuestionTypeDialog", "\346\267\273\345\212\240\351\200\211\346\213\251\351\242\230", nullptr));
        label_4->setText(QCoreApplication::translate("QuestionTypeDialog", "\351\242\230\345\271\262\357\274\232", nullptr));
        textEdit_2->setPlaceholderText(QCoreApplication::translate("QuestionTypeDialog", "\350\257\267\350\276\223\345\205\245\351\242\230\345\271\262\345\206\205\345\256\271", nullptr));
        label_5->setText(QCoreApplication::translate("QuestionTypeDialog", "\351\200\211\351\241\271\357\274\232", nullptr));
        checkBox_3->setText(QString());
        checkBox_1->setText(QString());
        label_8->setText(QCoreApplication::translate("QuestionTypeDialog", "\351\200\211\351\241\271\344\270\211\357\274\232", nullptr));
        lineEdit_3->setPlaceholderText(QCoreApplication::translate("QuestionTypeDialog", "\350\257\267\350\276\223\345\205\245\351\200\211\351\241\271\345\206\205\345\256\271", nullptr));
        checkBox_4->setText(QString());
        label_7->setText(QCoreApplication::translate("QuestionTypeDialog", "\351\200\211\351\241\271\344\272\214\357\274\232", nullptr));
        lineEdit_2->setPlaceholderText(QCoreApplication::translate("QuestionTypeDialog", "\350\257\267\350\276\223\345\205\245\351\200\211\351\241\271\345\206\205\345\256\271", nullptr));
        label_6->setText(QCoreApplication::translate("QuestionTypeDialog", "\351\200\211\351\241\271\344\270\200\357\274\232", nullptr));
        lineEdit_1->setPlaceholderText(QCoreApplication::translate("QuestionTypeDialog", "\350\257\267\350\276\223\345\205\245\351\200\211\351\241\271\345\206\205\345\256\271", nullptr));
        checkBox_2->setText(QString());
        label_9->setText(QCoreApplication::translate("QuestionTypeDialog", "\351\200\211\351\241\271\345\233\233\357\274\232", nullptr));
        lineEdit_4->setPlaceholderText(QCoreApplication::translate("QuestionTypeDialog", "\350\257\267\350\276\223\345\205\245\351\200\211\351\241\271\345\206\205\345\256\271", nullptr));
        label_10->setText(QCoreApplication::translate("QuestionTypeDialog", "\346\267\273\345\212\240\344\270\273\350\247\202\351\242\230", nullptr));
        label_11->setText(QCoreApplication::translate("QuestionTypeDialog", "\351\242\230\345\271\262\357\274\232", nullptr));
        textEdit_3->setPlaceholderText(QCoreApplication::translate("QuestionTypeDialog", "\350\257\267\350\276\223\345\205\245\351\242\230\345\271\262\345\206\205\345\256\271", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QuestionTypeDialog: public Ui_QuestionTypeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUESTIONTYPEDIALOG_H
