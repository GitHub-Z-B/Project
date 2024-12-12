/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>
#include <evaluatewidget.h>
#include <questionnairemanagementwidget.h>
#include <replaywidget.h>
#include <taskwidget.h>
#include <usermanagementwidget.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QWidget *widget_left;
    QToolButton *toolButton_1;
    QToolButton *toolButton_2;
    QToolButton *toolButton_3;
    QToolButton *toolButton_4;
    QStackedWidget *stackedWidget;
    TaskWidget *page_1;
    EvaluateWidget *page_2;
    ReplayWidget *page_3;
    UserManagementWidget *page_4;
    QuestionnaireManagementWidget *page_5;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1200, 768);
        MainWindow->setMinimumSize(QSize(1200, 768));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        widget_left = new QWidget(centralwidget);
        widget_left->setObjectName("widget_left");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget_left->sizePolicy().hasHeightForWidth());
        widget_left->setSizePolicy(sizePolicy);
        widget_left->setMinimumSize(QSize(55, 0));
        widget_left->setContextMenuPolicy(Qt::ContextMenuPolicy::NoContextMenu);
        widget_left->setStyleSheet(QString::fromUtf8("QWidget#widget_left{\n"
"background-color: #E5E5E5;\n"
"}\n"
"QToolButton:!checked{\n"
"border:none;\n"
"margin: 3px;\n"
"background-color: transparent;\n"
"}\n"
"QToolButton:checked{\n"
"border:none;\n"
"margin: 3px;\n"
"background-color: #FFFFFF;\n"
"border-radius:6px;\n"
"}"));
        toolButton_1 = new QToolButton(widget_left);
        toolButton_1->setObjectName("toolButton_1");
        toolButton_1->setGeometry(QRect(0, 10, 50, 50));
        toolButton_1->setMinimumSize(QSize(50, 50));
        toolButton_1->setMaximumSize(QSize(50, 50));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/mainwindow/1.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        toolButton_1->setIcon(icon);
        toolButton_1->setIconSize(QSize(24, 24));
        toolButton_1->setCheckable(true);
        toolButton_1->setChecked(true);
        toolButton_1->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextUnderIcon);
        toolButton_2 = new QToolButton(widget_left);
        toolButton_2->setObjectName("toolButton_2");
        toolButton_2->setGeometry(QRect(0, 70, 50, 50));
        toolButton_2->setMinimumSize(QSize(50, 50));
        toolButton_2->setMaximumSize(QSize(50, 50));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/mainwindow/2.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        toolButton_2->setIcon(icon1);
        toolButton_2->setIconSize(QSize(24, 24));
        toolButton_2->setCheckable(true);
        toolButton_2->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextUnderIcon);
        toolButton_3 = new QToolButton(widget_left);
        toolButton_3->setObjectName("toolButton_3");
        toolButton_3->setGeometry(QRect(0, 130, 50, 50));
        toolButton_3->setMinimumSize(QSize(50, 50));
        toolButton_3->setMaximumSize(QSize(50, 50));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/mainwindow/3.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        toolButton_3->setIcon(icon2);
        toolButton_3->setIconSize(QSize(24, 24));
        toolButton_3->setCheckable(true);
        toolButton_3->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextUnderIcon);
        toolButton_4 = new QToolButton(widget_left);
        toolButton_4->setObjectName("toolButton_4");
        toolButton_4->setGeometry(QRect(0, 190, 50, 76));
        toolButton_4->setMinimumSize(QSize(50, 76));
        toolButton_4->setMaximumSize(QSize(50, 50));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/mainwindow/UserManagement.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        toolButton_4->setIcon(icon3);
        toolButton_4->setIconSize(QSize(24, 24));
        toolButton_4->setCheckable(true);
        toolButton_4->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextUnderIcon);

        horizontalLayout->addWidget(widget_left);

        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        page_1 = new TaskWidget();
        page_1->setObjectName("page_1");
        stackedWidget->addWidget(page_1);
        page_2 = new EvaluateWidget();
        page_2->setObjectName("page_2");
        stackedWidget->addWidget(page_2);
        page_3 = new ReplayWidget();
        page_3->setObjectName("page_3");
        stackedWidget->addWidget(page_3);
        page_4 = new UserManagementWidget();
        page_4->setObjectName("page_4");
        stackedWidget->addWidget(page_4);
        page_5 = new QuestionnaireManagementWidget();
        page_5->setObjectName("page_5");
        stackedWidget->addWidget(page_5);

        horizontalLayout->addWidget(stackedWidget);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        toolButton_1->setText(QCoreApplication::translate("MainWindow", "\344\273\273\345\212\241", nullptr));
        toolButton_2->setText(QCoreApplication::translate("MainWindow", "\350\257\204\344\274\260", nullptr));
        toolButton_3->setText(QCoreApplication::translate("MainWindow", "\345\233\236\346\224\276", nullptr));
        toolButton_4->setText(QCoreApplication::translate("MainWindow", "\347\224\250\346\210\267\347\256\241\347\220\206", nullptr));
        (void)MainWindow;
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
