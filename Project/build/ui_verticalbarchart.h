/********************************************************************************
** Form generated from reading UI file 'verticalbarchart.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VERTICALBARCHART_H
#define UI_VERTICALBARCHART_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VerticalBarChart
{
public:
    QGridLayout *gridLayout_2;
    QWidget *completionTime_widget;
    QGridLayout *gridLayout;
    QTableWidget *Result_Widget;
    QWidget *VerticalBar_widget;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *VerticalBarChart)
    {
        if (VerticalBarChart->objectName().isEmpty())
            VerticalBarChart->setObjectName("VerticalBarChart");
        VerticalBarChart->resize(1542, 760);
        gridLayout_2 = new QGridLayout(VerticalBarChart);
        gridLayout_2->setObjectName("gridLayout_2");
        completionTime_widget = new QWidget(VerticalBarChart);
        completionTime_widget->setObjectName("completionTime_widget");
        completionTime_widget->setMinimumSize(QSize(500, 0));
        gridLayout = new QGridLayout(completionTime_widget);
        gridLayout->setObjectName("gridLayout");
        Result_Widget = new QTableWidget(completionTime_widget);
        if (Result_Widget->columnCount() < 5)
            Result_Widget->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        Result_Widget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        Result_Widget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        Result_Widget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        Result_Widget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        Result_Widget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        Result_Widget->setObjectName("Result_Widget");
        Result_Widget->setMinimumSize(QSize(500, 200));

        gridLayout->addWidget(Result_Widget, 0, 0, 1, 1);


        gridLayout_2->addWidget(completionTime_widget, 0, 0, 1, 1);

        VerticalBar_widget = new QWidget(VerticalBarChart);
        VerticalBar_widget->setObjectName("VerticalBar_widget");
        VerticalBar_widget->setMinimumSize(QSize(500, 500));

        gridLayout_2->addWidget(VerticalBar_widget, 3, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_2->addItem(verticalSpacer_3, 1, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 2, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 4, 0, 1, 1);


        retranslateUi(VerticalBarChart);

        QMetaObject::connectSlotsByName(VerticalBarChart);
    } // setupUi

    void retranslateUi(QWidget *VerticalBarChart)
    {
        VerticalBarChart->setWindowTitle(QCoreApplication::translate("VerticalBarChart", "Form", nullptr));
        QTableWidgetItem *___qtablewidgetitem = Result_Widget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("VerticalBarChart", "\346\226\260\345\273\272\345\210\227", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = Result_Widget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("VerticalBarChart", "\346\226\260\345\273\272\345\210\227", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = Result_Widget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("VerticalBarChart", "\346\226\260\345\273\272\345\210\227", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = Result_Widget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("VerticalBarChart", "\346\226\260\345\273\272\345\210\227", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = Result_Widget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("VerticalBarChart", "\346\226\260\345\273\272\345\210\227", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VerticalBarChart: public Ui_VerticalBarChart {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VERTICALBARCHART_H
