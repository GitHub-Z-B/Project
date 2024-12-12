/********************************************************************************
** Form generated from reading UI file 'questionnairemanagementwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUESTIONNAIREMANAGEMENTWIDGET_H
#define UI_QUESTIONNAIREMANAGEMENTWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QuestionnaireManagementWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_1;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QSpacerItem *verticalSpacer;
    QStackedWidget *stackedWidget;
    QWidget *subPage1;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QDateTimeEdit *dateTimeEdit;
    QLabel *label_3;
    QDateTimeEdit *dateTimeEdit_2;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *add_questionnaire;
    QSpacerItem *horizontalSpacer_2;
    QScrollArea *scrollArea;
    QWidget *questionnaireListWidget;
    QVBoxLayout *questionnaireListLayout;
    QWidget *subPage2;
    QVBoxLayout *verticalLayout_5;
    QWidget *widget_8;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_7;
    QLineEdit *lineEdit_2;
    QSpacerItem *horizontalSpacer_6;
    QLabel *label_8;
    QComboBox *comboBox_2;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *pushButton_6;
    QSpacerItem *horizontalSpacer_7;
    QWidget *answerListWidget;
    QVBoxLayout *answerListLayout;
    QWidget *subPage3;
    QVBoxLayout *verticalLayout_6;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButton_5;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_6;
    QComboBox *comboBox;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_6;
    QTreeWidget *treeWidget;
    QTableView *tableView_bank;
    QWidget *subPage4;
    QVBoxLayout *verticalLayout_7;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_9;
    QWidget *widget_9;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_9;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton_7;
    QSpacerItem *horizontalSpacer_9;
    QScrollArea *scrollArea_3;
    QWidget *scoringCenterListWidget;
    QVBoxLayout *scoringCenterListLayout;
    QWidget *tab_2;
    QWidget *subPage5;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label_4;
    QLabel *label_5;
    QTextEdit *questionnaire_description;
    QLineEdit *questionnaire_name;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *add_question_type2;
    QPushButton *add_question_type1;
    QPushButton *add_question_type3;
    QPushButton *add_question_type4;
    QSpacerItem *horizontalSpacer_3;
    QScrollArea *scrollArea_2;
    QWidget *questionListWidget;
    QVBoxLayout *questionListLayout;
    QSpacerItem *verticalSpacer_2;
    QWidget *widget_7;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *finish_questionnaire;
    QPushButton *finish_edit;

    void setupUi(QWidget *QuestionnaireManagementWidget)
    {
        if (QuestionnaireManagementWidget->objectName().isEmpty())
            QuestionnaireManagementWidget->setObjectName("QuestionnaireManagementWidget");
        QuestionnaireManagementWidget->resize(1375, 854);
        horizontalLayout = new QHBoxLayout(QuestionnaireManagementWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(QuestionnaireManagementWidget);
        widget->setObjectName("widget");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        widget->setMinimumSize(QSize(120, 0));
        widget->setMaximumSize(QSize(120, 16777215));
        widget->setStyleSheet(QString::fromUtf8("QWidget{\n"
"background-color: rgb(255, 255, 255);\n"
"}\n"
"QPushButton {\n"
"border:none;\n"
"color: black;\n"
"padding:10px;\n"
"}\n"
"\n"
"QPushButton:checked {\n"
"color: blue;\n"
"}"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        pushButton_1 = new QPushButton(widget);
        pushButton_1->setObjectName("pushButton_1");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/mainwindow/2.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_1->setIcon(icon);
        pushButton_1->setIconSize(QSize(24, 24));
        pushButton_1->setCheckable(true);
        pushButton_1->setChecked(true);
        pushButton_1->setAutoExclusive(true);
        pushButton_1->setAutoDefault(true);
        pushButton_1->setFlat(true);

        verticalLayout->addWidget(pushButton_1);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setIcon(icon);
        pushButton_2->setIconSize(QSize(24, 24));
        pushButton_2->setCheckable(true);
        pushButton_2->setAutoExclusive(true);
        pushButton_2->setFlat(true);

        verticalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setIcon(icon);
        pushButton_3->setIconSize(QSize(24, 24));
        pushButton_3->setCheckable(true);
        pushButton_3->setAutoExclusive(true);
        pushButton_3->setFlat(true);

        verticalLayout->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(widget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setIcon(icon);
        pushButton_4->setIconSize(QSize(24, 24));
        pushButton_4->setCheckable(true);
        pushButton_4->setAutoExclusive(true);
        pushButton_4->setFlat(true);

        verticalLayout->addWidget(pushButton_4);

        verticalSpacer = new QSpacerItem(20, 808, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addWidget(widget);

        stackedWidget = new QStackedWidget(QuestionnaireManagementWidget);
        stackedWidget->setObjectName("stackedWidget");
        subPage1 = new QWidget();
        subPage1->setObjectName("subPage1");
        subPage1->setStyleSheet(QString::fromUtf8("QWidget#subPage1{\n"
"background-color: rgb(255, 255, 255);\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(subPage1);
        verticalLayout_2->setObjectName("verticalLayout_2");
        widget_3 = new QWidget(subPage1);
        widget_3->setObjectName("widget_3");
        horizontalLayout_2 = new QHBoxLayout(widget_3);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label = new QLabel(widget_3);
        label->setObjectName("label");

        horizontalLayout_2->addWidget(label);

        lineEdit = new QLineEdit(widget_3);
        lineEdit->setObjectName("lineEdit");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(lineEdit);

        label_2 = new QLabel(widget_3);
        label_2->setObjectName("label_2");

        horizontalLayout_2->addWidget(label_2);

        dateTimeEdit = new QDateTimeEdit(widget_3);
        dateTimeEdit->setObjectName("dateTimeEdit");
        dateTimeEdit->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);

        horizontalLayout_2->addWidget(dateTimeEdit);

        label_3 = new QLabel(widget_3);
        label_3->setObjectName("label_3");

        horizontalLayout_2->addWidget(label_3);

        dateTimeEdit_2 = new QDateTimeEdit(widget_3);
        dateTimeEdit_2->setObjectName("dateTimeEdit_2");
        dateTimeEdit_2->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);

        horizontalLayout_2->addWidget(dateTimeEdit_2);

        pushButton = new QPushButton(widget_3);
        pushButton->setObjectName("pushButton");

        horizontalLayout_2->addWidget(pushButton);

        horizontalSpacer = new QSpacerItem(618, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout_2->addWidget(widget_3);

        widget_4 = new QWidget(subPage1);
        widget_4->setObjectName("widget_4");
        horizontalLayout_3 = new QHBoxLayout(widget_4);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        add_questionnaire = new QPushButton(widget_4);
        add_questionnaire->setObjectName("add_questionnaire");

        horizontalLayout_3->addWidget(add_questionnaire);

        horizontalSpacer_2 = new QSpacerItem(1109, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout_2->addWidget(widget_4);

        scrollArea = new QScrollArea(subPage1);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setFrameShape(QFrame::Shape::NoFrame);
        scrollArea->setFrameShadow(QFrame::Shadow::Plain);
        scrollArea->setWidgetResizable(true);
        questionnaireListWidget = new QWidget();
        questionnaireListWidget->setObjectName("questionnaireListWidget");
        questionnaireListWidget->setGeometry(QRect(0, 0, 1231, 742));
        questionnaireListWidget->setStyleSheet(QString::fromUtf8("QWidget#questionnaireListWidget{\n"
"background-color: rgb(255, 255, 255);\n"
"}"));
        questionnaireListLayout = new QVBoxLayout(questionnaireListWidget);
        questionnaireListLayout->setSpacing(20);
        questionnaireListLayout->setObjectName("questionnaireListLayout");
        scrollArea->setWidget(questionnaireListWidget);

        verticalLayout_2->addWidget(scrollArea);

        stackedWidget->addWidget(subPage1);
        subPage2 = new QWidget();
        subPage2->setObjectName("subPage2");
        subPage2->setStyleSheet(QString::fromUtf8("QWidget#subPage2{\n"
"background-color: rgb(255, 255, 255);\n"
"}"));
        verticalLayout_5 = new QVBoxLayout(subPage2);
        verticalLayout_5->setObjectName("verticalLayout_5");
        widget_8 = new QWidget(subPage2);
        widget_8->setObjectName("widget_8");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(widget_8->sizePolicy().hasHeightForWidth());
        widget_8->setSizePolicy(sizePolicy2);
        horizontalLayout_8 = new QHBoxLayout(widget_8);
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        label_7 = new QLabel(widget_8);
        label_7->setObjectName("label_7");

        horizontalLayout_8->addWidget(label_7);

        lineEdit_2 = new QLineEdit(widget_8);
        lineEdit_2->setObjectName("lineEdit_2");
        sizePolicy1.setHeightForWidth(lineEdit_2->sizePolicy().hasHeightForWidth());
        lineEdit_2->setSizePolicy(sizePolicy1);

        horizontalLayout_8->addWidget(lineEdit_2);

        horizontalSpacer_6 = new QSpacerItem(50, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_6);

        label_8 = new QLabel(widget_8);
        label_8->setObjectName("label_8");

        horizontalLayout_8->addWidget(label_8);

        comboBox_2 = new QComboBox(widget_8);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName("comboBox_2");

        horizontalLayout_8->addWidget(comboBox_2);

        horizontalSpacer_8 = new QSpacerItem(50, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_8);

        pushButton_6 = new QPushButton(widget_8);
        pushButton_6->setObjectName("pushButton_6");

        horizontalLayout_8->addWidget(pushButton_6);

        horizontalSpacer_7 = new QSpacerItem(294, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_7);


        verticalLayout_5->addWidget(widget_8);

        answerListWidget = new QWidget(subPage2);
        answerListWidget->setObjectName("answerListWidget");
        answerListLayout = new QVBoxLayout(answerListWidget);
        answerListLayout->setObjectName("answerListLayout");

        verticalLayout_5->addWidget(answerListWidget);

        stackedWidget->addWidget(subPage2);
        subPage3 = new QWidget();
        subPage3->setObjectName("subPage3");
        verticalLayout_6 = new QVBoxLayout(subPage3);
        verticalLayout_6->setObjectName("verticalLayout_6");
        widget_5 = new QWidget(subPage3);
        widget_5->setObjectName("widget_5");
        horizontalLayout_5 = new QHBoxLayout(widget_5);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        pushButton_5 = new QPushButton(widget_5);
        pushButton_5->setObjectName("pushButton_5");

        horizontalLayout_5->addWidget(pushButton_5);

        horizontalSpacer_4 = new QSpacerItem(975, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);

        label_6 = new QLabel(widget_5);
        label_6->setObjectName("label_6");

        horizontalLayout_5->addWidget(label_6);

        comboBox = new QComboBox(widget_5);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");

        horizontalLayout_5->addWidget(comboBox);


        verticalLayout_6->addWidget(widget_5);

        widget_6 = new QWidget(subPage3);
        widget_6->setObjectName("widget_6");
        horizontalLayout_6 = new QHBoxLayout(widget_6);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        treeWidget = new QTreeWidget(widget_6);
        new QTreeWidgetItem(treeWidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem(treeWidget);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem(treeWidget);
        new QTreeWidgetItem(__qtreewidgetitem1);
        new QTreeWidgetItem(__qtreewidgetitem1);
        new QTreeWidgetItem(__qtreewidgetitem1);
        new QTreeWidgetItem(__qtreewidgetitem1);
        new QTreeWidgetItem(__qtreewidgetitem1);
        new QTreeWidgetItem(treeWidget);
        new QTreeWidgetItem(treeWidget);
        new QTreeWidgetItem(treeWidget);
        treeWidget->setObjectName("treeWidget");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(treeWidget->sizePolicy().hasHeightForWidth());
        treeWidget->setSizePolicy(sizePolicy3);

        horizontalLayout_6->addWidget(treeWidget);

        tableView_bank = new QTableView(widget_6);
        tableView_bank->setObjectName("tableView_bank");
        tableView_bank->verticalHeader()->setVisible(false);

        horizontalLayout_6->addWidget(tableView_bank);


        verticalLayout_6->addWidget(widget_6);

        stackedWidget->addWidget(subPage3);
        subPage4 = new QWidget();
        subPage4->setObjectName("subPage4");
        subPage4->setStyleSheet(QString::fromUtf8("QTabBar::tab {\n"
"	color: black;\n"
"	padding: 3px;\n"
"	margin-left:3px;\n"
"	background-color: transparent;\n"
"	width: 80px;\n"
"    height:40px;\n"
"}\n"
"QTabBar::tab:selected, QTabBar::tab:last:selected, QTabBar::tab:hover {\n"
"	color: blue;\n"
"	padding-left: 3px;\n"
"	padding-bottom: 2px;\n"
"}"));
        verticalLayout_7 = new QVBoxLayout(subPage4);
        verticalLayout_7->setObjectName("verticalLayout_7");
        tabWidget = new QTabWidget(subPage4);
        tabWidget->setObjectName("tabWidget");
        tab = new QWidget();
        tab->setObjectName("tab");
        verticalLayout_9 = new QVBoxLayout(tab);
        verticalLayout_9->setObjectName("verticalLayout_9");
        widget_9 = new QWidget(tab);
        widget_9->setObjectName("widget_9");
        horizontalLayout_9 = new QHBoxLayout(widget_9);
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        label_9 = new QLabel(widget_9);
        label_9->setObjectName("label_9");
        sizePolicy.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy);

        horizontalLayout_9->addWidget(label_9);

        lineEdit_3 = new QLineEdit(widget_9);
        lineEdit_3->setObjectName("lineEdit_3");
        sizePolicy1.setHeightForWidth(lineEdit_3->sizePolicy().hasHeightForWidth());
        lineEdit_3->setSizePolicy(sizePolicy1);

        horizontalLayout_9->addWidget(lineEdit_3);

        pushButton_7 = new QPushButton(widget_9);
        pushButton_7->setObjectName("pushButton_7");
        sizePolicy1.setHeightForWidth(pushButton_7->sizePolicy().hasHeightForWidth());
        pushButton_7->setSizePolicy(sizePolicy1);

        horizontalLayout_9->addWidget(pushButton_7);

        horizontalSpacer_9 = new QSpacerItem(882, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_9);


        verticalLayout_9->addWidget(widget_9);

        scrollArea_3 = new QScrollArea(tab);
        scrollArea_3->setObjectName("scrollArea_3");
        scrollArea_3->setWidgetResizable(true);
        scoringCenterListWidget = new QWidget();
        scoringCenterListWidget->setObjectName("scoringCenterListWidget");
        scoringCenterListWidget->setGeometry(QRect(0, 0, 1205, 718));
        scoringCenterListLayout = new QVBoxLayout(scoringCenterListWidget);
        scoringCenterListLayout->setObjectName("scoringCenterListLayout");
        scrollArea_3->setWidget(scoringCenterListWidget);

        verticalLayout_9->addWidget(scrollArea_3);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        tabWidget->addTab(tab_2, QString());

        verticalLayout_7->addWidget(tabWidget);

        stackedWidget->addWidget(subPage4);
        subPage5 = new QWidget();
        subPage5->setObjectName("subPage5");
        verticalLayout_4 = new QVBoxLayout(subPage5);
        verticalLayout_4->setObjectName("verticalLayout_4");
        groupBox = new QGroupBox(subPage5);
        groupBox->setObjectName("groupBox");
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName("gridLayout");
        label_4 = new QLabel(groupBox);
        label_4->setObjectName("label_4");

        gridLayout->addWidget(label_4, 0, 0, 1, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName("label_5");

        gridLayout->addWidget(label_5, 0, 2, 1, 1);

        questionnaire_description = new QTextEdit(groupBox);
        questionnaire_description->setObjectName("questionnaire_description");

        gridLayout->addWidget(questionnaire_description, 0, 3, 2, 1);

        questionnaire_name = new QLineEdit(groupBox);
        questionnaire_name->setObjectName("questionnaire_name");

        gridLayout->addWidget(questionnaire_name, 0, 1, 1, 1);


        verticalLayout_4->addWidget(groupBox);

        groupBox_2 = new QGroupBox(subPage5);
        groupBox_2->setObjectName("groupBox_2");
        verticalLayout_3 = new QVBoxLayout(groupBox_2);
        verticalLayout_3->setObjectName("verticalLayout_3");
        widget_2 = new QWidget(groupBox_2);
        widget_2->setObjectName("widget_2");
        horizontalLayout_4 = new QHBoxLayout(widget_2);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        add_question_type2 = new QPushButton(widget_2);
        add_question_type2->setObjectName("add_question_type2");

        horizontalLayout_4->addWidget(add_question_type2);

        add_question_type1 = new QPushButton(widget_2);
        add_question_type1->setObjectName("add_question_type1");

        horizontalLayout_4->addWidget(add_question_type1);

        add_question_type3 = new QPushButton(widget_2);
        add_question_type3->setObjectName("add_question_type3");

        horizontalLayout_4->addWidget(add_question_type3);

        add_question_type4 = new QPushButton(widget_2);
        add_question_type4->setObjectName("add_question_type4");

        horizontalLayout_4->addWidget(add_question_type4);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);


        verticalLayout_3->addWidget(widget_2);

        scrollArea_2 = new QScrollArea(groupBox_2);
        scrollArea_2->setObjectName("scrollArea_2");
        scrollArea_2->setFrameShape(QFrame::Shape::NoFrame);
        scrollArea_2->setWidgetResizable(true);
        questionListWidget = new QWidget();
        questionListWidget->setObjectName("questionListWidget");
        questionListWidget->setGeometry(QRect(0, 0, 1211, 474));
        questionListLayout = new QVBoxLayout(questionListWidget);
        questionListLayout->setObjectName("questionListLayout");
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        questionListLayout->addItem(verticalSpacer_2);

        scrollArea_2->setWidget(questionListWidget);

        verticalLayout_3->addWidget(scrollArea_2);


        verticalLayout_4->addWidget(groupBox_2);

        widget_7 = new QWidget(subPage5);
        widget_7->setObjectName("widget_7");
        horizontalLayout_7 = new QHBoxLayout(widget_7);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        horizontalSpacer_5 = new QSpacerItem(1111, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_5);

        finish_questionnaire = new QPushButton(widget_7);
        finish_questionnaire->setObjectName("finish_questionnaire");

        horizontalLayout_7->addWidget(finish_questionnaire);

        finish_edit = new QPushButton(widget_7);
        finish_edit->setObjectName("finish_edit");

        horizontalLayout_7->addWidget(finish_edit);


        verticalLayout_4->addWidget(widget_7);

        stackedWidget->addWidget(subPage5);

        horizontalLayout->addWidget(stackedWidget);


        retranslateUi(QuestionnaireManagementWidget);

        pushButton_1->setDefault(true);
        stackedWidget->setCurrentIndex(4);
        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(QuestionnaireManagementWidget);
    } // setupUi

    void retranslateUi(QWidget *QuestionnaireManagementWidget)
    {
        QuestionnaireManagementWidget->setWindowTitle(QCoreApplication::translate("QuestionnaireManagementWidget", "Form", nullptr));
        pushButton_1->setText(QCoreApplication::translate("QuestionnaireManagementWidget", "\351\227\256\345\215\267\347\256\241\347\220\206", nullptr));
        pushButton_2->setText(QCoreApplication::translate("QuestionnaireManagementWidget", "\347\255\224\345\215\267\347\273\237\350\256\241", nullptr));
        pushButton_3->setText(QCoreApplication::translate("QuestionnaireManagementWidget", "\351\242\230\345\272\223\347\256\241\347\220\206", nullptr));
        pushButton_4->setText(QCoreApplication::translate("QuestionnaireManagementWidget", "\346\211\223\345\210\206\344\270\255\345\277\203", nullptr));
        label->setText(QCoreApplication::translate("QuestionnaireManagementWidget", "\346\220\234\347\264\242\357\274\232", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("QuestionnaireManagementWidget", "\350\257\267\350\276\223\345\205\245\351\227\256\345\215\267\345\220\215\347\247\260", nullptr));
        label_2->setText(QCoreApplication::translate("QuestionnaireManagementWidget", "\345\210\233\345\273\272\346\227\266\351\227\264\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("QuestionnaireManagementWidget", "\350\207\263", nullptr));
        pushButton->setText(QCoreApplication::translate("QuestionnaireManagementWidget", "\346\220\234\347\264\242", nullptr));
        add_questionnaire->setText(QCoreApplication::translate("QuestionnaireManagementWidget", "\346\226\260\345\273\272\351\227\256\345\215\267", nullptr));
        label_7->setText(QCoreApplication::translate("QuestionnaireManagementWidget", "\351\227\256\345\215\267\345\220\215\347\247\260\357\274\232", nullptr));
        lineEdit_2->setPlaceholderText(QCoreApplication::translate("QuestionnaireManagementWidget", "\350\257\267\350\276\223\345\205\245\351\227\256\345\215\267\345\220\215\347\247\260", nullptr));
        label_8->setText(QCoreApplication::translate("QuestionnaireManagementWidget", "\347\255\224\345\215\267\346\225\260\351\207\217\357\274\232", nullptr));
        comboBox_2->setItemText(0, QCoreApplication::translate("QuestionnaireManagementWidget", "\344\273\216\345\260\217\345\210\260\345\244\247", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("QuestionnaireManagementWidget", "\344\273\216\345\244\247\345\210\260\345\260\217", nullptr));

        pushButton_6->setText(QCoreApplication::translate("QuestionnaireManagementWidget", "\346\220\234\347\264\242", nullptr));
        pushButton_5->setText(QCoreApplication::translate("QuestionnaireManagementWidget", "\346\226\260\345\242\236\351\242\230\347\233\256", nullptr));
        label_6->setText(QCoreApplication::translate("QuestionnaireManagementWidget", "\346\214\211\351\242\230\345\236\213\347\255\233\351\200\211", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("QuestionnaireManagementWidget", "\346\227\240\347\255\233\351\200\211", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("QuestionnaireManagementWidget", "\346\211\223\345\210\206\351\242\230", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("QuestionnaireManagementWidget", "\351\200\211\346\213\251\351\242\230", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("QuestionnaireManagementWidget", "\344\270\273\350\247\202\351\242\230", nullptr));

        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("QuestionnaireManagementWidget", "\346\214\211\346\214\207\346\240\207\347\255\233\351\200\211", nullptr));

        const bool __sortingEnabled = treeWidget->isSortingEnabled();
        treeWidget->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem1 = treeWidget->topLevelItem(0);
        ___qtreewidgetitem1->setText(0, QCoreApplication::translate("QuestionnaireManagementWidget", "\346\227\240\347\255\233\351\200\211", nullptr));
        QTreeWidgetItem *___qtreewidgetitem2 = treeWidget->topLevelItem(1);
        ___qtreewidgetitem2->setText(0, QCoreApplication::translate("QuestionnaireManagementWidget", "\345\205\203\347\264\240", nullptr));
        QTreeWidgetItem *___qtreewidgetitem3 = ___qtreewidgetitem2->child(0);
        ___qtreewidgetitem3->setText(0, QCoreApplication::translate("QuestionnaireManagementWidget", "\345\255\227\347\254\246", nullptr));
        QTreeWidgetItem *___qtreewidgetitem4 = ___qtreewidgetitem2->child(1);
        ___qtreewidgetitem4->setText(0, QCoreApplication::translate("QuestionnaireManagementWidget", "\347\274\251\345\206\231\350\257\215", nullptr));
        QTreeWidgetItem *___qtreewidgetitem5 = ___qtreewidgetitem2->child(2);
        ___qtreewidgetitem5->setText(0, QCoreApplication::translate("QuestionnaireManagementWidget", "\345\233\276\346\240\207", nullptr));
        QTreeWidgetItem *___qtreewidgetitem6 = ___qtreewidgetitem2->child(3);
        ___qtreewidgetitem6->setText(0, QCoreApplication::translate("QuestionnaireManagementWidget", "\345\210\273\345\272\246\347\272\277", nullptr));
        QTreeWidgetItem *___qtreewidgetitem7 = ___qtreewidgetitem2->child(4);
        ___qtreewidgetitem7->setText(0, QCoreApplication::translate("QuestionnaireManagementWidget", "\350\276\271\346\241\206\347\256\255\345\244\264", nullptr));
        QTreeWidgetItem *___qtreewidgetitem8 = treeWidget->topLevelItem(2);
        ___qtreewidgetitem8->setText(0, QCoreApplication::translate("QuestionnaireManagementWidget", "\350\211\262\345\275\251", nullptr));
        QTreeWidgetItem *___qtreewidgetitem9 = ___qtreewidgetitem8->child(0);
        ___qtreewidgetitem9->setText(0, QCoreApplication::translate("QuestionnaireManagementWidget", "\347\212\266\346\200\201\346\214\207\347\244\272", nullptr));
        QTreeWidgetItem *___qtreewidgetitem10 = ___qtreewidgetitem8->child(1);
        ___qtreewidgetitem10->setText(0, QCoreApplication::translate("QuestionnaireManagementWidget", "\345\233\276\345\275\242\345\222\214\345\233\276\350\241\250", nullptr));
        QTreeWidgetItem *___qtreewidgetitem11 = ___qtreewidgetitem8->child(2);
        ___qtreewidgetitem11->setText(0, QCoreApplication::translate("QuestionnaireManagementWidget", "\346\214\211\351\224\256\345\222\214\346\216\247\344\273\266", nullptr));
        QTreeWidgetItem *___qtreewidgetitem12 = ___qtreewidgetitem8->child(3);
        ___qtreewidgetitem12->setText(0, QCoreApplication::translate("QuestionnaireManagementWidget", "\346\226\207\345\255\227\345\222\214\346\240\207\347\255\276", nullptr));
        QTreeWidgetItem *___qtreewidgetitem13 = ___qtreewidgetitem8->child(4);
        ___qtreewidgetitem13->setText(0, QCoreApplication::translate("QuestionnaireManagementWidget", "\350\203\214\346\231\257\345\222\214\347\225\214\351\235\242\346\225\264\344\275\223", nullptr));
        QTreeWidgetItem *___qtreewidgetitem14 = treeWidget->topLevelItem(3);
        ___qtreewidgetitem14->setText(0, QCoreApplication::translate("QuestionnaireManagementWidget", "\347\225\214\351\235\242", nullptr));
        QTreeWidgetItem *___qtreewidgetitem15 = treeWidget->topLevelItem(4);
        ___qtreewidgetitem15->setText(0, QCoreApplication::translate("QuestionnaireManagementWidget", "\344\277\241\346\201\257", nullptr));
        QTreeWidgetItem *___qtreewidgetitem16 = treeWidget->topLevelItem(5);
        ___qtreewidgetitem16->setText(0, QCoreApplication::translate("QuestionnaireManagementWidget", "\344\272\244\344\272\222", nullptr));
        treeWidget->setSortingEnabled(__sortingEnabled);

        label_9->setText(QCoreApplication::translate("QuestionnaireManagementWidget", "\351\227\256\345\215\267\345\220\215\347\247\260\357\274\232", nullptr));
        lineEdit_3->setPlaceholderText(QCoreApplication::translate("QuestionnaireManagementWidget", "\350\257\267\350\276\223\345\205\245\351\227\256\345\215\267\345\220\215\347\247\260", nullptr));
        pushButton_7->setText(QCoreApplication::translate("QuestionnaireManagementWidget", "\346\220\234\347\264\242", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("QuestionnaireManagementWidget", "\351\227\256\345\215\267\346\211\223\345\210\206", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("QuestionnaireManagementWidget", "\351\242\230\347\233\256\346\211\223\345\210\206", nullptr));
        groupBox->setTitle(QCoreApplication::translate("QuestionnaireManagementWidget", "\345\237\272\346\234\254\344\277\241\346\201\257", nullptr));
        label_4->setText(QCoreApplication::translate("QuestionnaireManagementWidget", "\351\227\256\345\215\267\345\220\215\347\247\260\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("QuestionnaireManagementWidget", "\351\227\256\345\215\267\346\217\217\350\277\260\357\274\232", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("QuestionnaireManagementWidget", "\346\267\273\345\212\240\351\242\230\347\233\256", nullptr));
        add_question_type2->setText(QCoreApplication::translate("QuestionnaireManagementWidget", "\346\267\273\345\212\240\351\200\211\346\213\251\351\242\230", nullptr));
        add_question_type1->setText(QCoreApplication::translate("QuestionnaireManagementWidget", "\346\267\273\345\212\240\346\211\223\345\210\206\351\242\230", nullptr));
        add_question_type3->setText(QCoreApplication::translate("QuestionnaireManagementWidget", "\346\267\273\345\212\240\344\270\273\350\247\202\351\242\230", nullptr));
        add_question_type4->setText(QCoreApplication::translate("QuestionnaireManagementWidget", "\344\273\216\351\242\230\345\272\223\346\267\273\345\212\240", nullptr));
        finish_questionnaire->setText(QCoreApplication::translate("QuestionnaireManagementWidget", "\345\256\214\346\210\220\351\227\256\345\215\267", nullptr));
        finish_edit->setText(QCoreApplication::translate("QuestionnaireManagementWidget", "\347\274\226\350\276\221\345\256\214\346\210\220", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QuestionnaireManagementWidget: public Ui_QuestionnaireManagementWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUESTIONNAIREMANAGEMENTWIDGET_H
