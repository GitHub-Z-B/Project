/********************************************************************************
** Form generated from reading UI file 'evaluationalgorithms.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EVALUATIONALGORITHMS_H
#define UI_EVALUATIONALGORITHMS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EvaluationAlgorithms
{
public:
    QGridLayout *gridLayout;
    QTextEdit *textEdit;
    QTableWidget *Algorithms_table;
    QComboBox *comboBox;
    QPushButton *start_btn;

    void setupUi(QWidget *EvaluationAlgorithms)
    {
        if (EvaluationAlgorithms->objectName().isEmpty())
            EvaluationAlgorithms->setObjectName("EvaluationAlgorithms");
        EvaluationAlgorithms->resize(1384, 733);
        gridLayout = new QGridLayout(EvaluationAlgorithms);
        gridLayout->setObjectName("gridLayout");
        textEdit = new QTextEdit(EvaluationAlgorithms);
        textEdit->setObjectName("textEdit");

        gridLayout->addWidget(textEdit, 1, 0, 1, 1);

        Algorithms_table = new QTableWidget(EvaluationAlgorithms);
        if (Algorithms_table->columnCount() < 2)
            Algorithms_table->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        Algorithms_table->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        Algorithms_table->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        Algorithms_table->setObjectName("Algorithms_table");

        gridLayout->addWidget(Algorithms_table, 1, 1, 1, 1);

        comboBox = new QComboBox(EvaluationAlgorithms);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setMinimumSize(QSize(200, 0));
        comboBox->setMaximumSize(QSize(500, 16777215));

        gridLayout->addWidget(comboBox, 0, 0, 1, 1);

        start_btn = new QPushButton(EvaluationAlgorithms);
        start_btn->setObjectName("start_btn");

        gridLayout->addWidget(start_btn, 0, 1, 1, 1);


        retranslateUi(EvaluationAlgorithms);

        QMetaObject::connectSlotsByName(EvaluationAlgorithms);
    } // setupUi

    void retranslateUi(QWidget *EvaluationAlgorithms)
    {
        EvaluationAlgorithms->setWindowTitle(QCoreApplication::translate("EvaluationAlgorithms", "Form", nullptr));
        QTableWidgetItem *___qtablewidgetitem = Algorithms_table->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("EvaluationAlgorithms", "\346\226\260\345\273\272\345\210\227", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = Algorithms_table->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("EvaluationAlgorithms", "\346\226\260\345\273\272\345\210\227", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("EvaluationAlgorithms", "\351\242\221\346\225\260\345\210\206\346\236\220", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("EvaluationAlgorithms", "\344\272\244\345\217\211\345\210\206\346\236\220", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("EvaluationAlgorithms", "\346\217\217\350\277\260\346\200\247\347\273\237\350\256\241\345\210\206\346\236\220", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("EvaluationAlgorithms", "\346\255\243\346\200\201\346\200\247\345\210\206\346\236\220", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("EvaluationAlgorithms", "\344\277\241\345\272\246\345\210\206\346\236\220", nullptr));
        comboBox->setItemText(5, QCoreApplication::translate("EvaluationAlgorithms", "\346\225\210\345\272\246\345\210\206\346\236\220", nullptr));
        comboBox->setItemText(6, QCoreApplication::translate("EvaluationAlgorithms", "\345\214\272\345\210\206\345\272\246\345\210\206\346\236\220", nullptr));
        comboBox->setItemText(7, QCoreApplication::translate("EvaluationAlgorithms", "\347\206\265\346\235\203\346\263\225", nullptr));
        comboBox->setItemText(8, QCoreApplication::translate("EvaluationAlgorithms", "\345\261\202\346\254\241\345\210\206\346\236\220\346\263\225", nullptr));
        comboBox->setItemText(9, QCoreApplication::translate("EvaluationAlgorithms", "\345\233\240\345\255\220\345\210\206\346\236\220", nullptr));
        comboBox->setItemText(10, QCoreApplication::translate("EvaluationAlgorithms", "\345\217\230\345\274\202\347\263\273\346\225\260\346\263\225", nullptr));
        comboBox->setItemText(11, QCoreApplication::translate("EvaluationAlgorithms", "\347\206\265\346\235\203-\345\217\230\345\274\202\347\263\273\346\225\260\347\273\204\345\220\210\346\263\225", nullptr));
        comboBox->setItemText(12, QCoreApplication::translate("EvaluationAlgorithms", "\347\201\260\350\211\262\345\205\263\350\201\224\345\210\206\346\236\220", nullptr));
        comboBox->setItemText(13, QCoreApplication::translate("EvaluationAlgorithms", "\345\215\225\346\240\267\346\234\254T\346\243\200\351\252\214", nullptr));
        comboBox->setItemText(14, QCoreApplication::translate("EvaluationAlgorithms", "\351\205\215\345\257\271\346\240\267\346\234\254T\346\243\200\351\252\214", nullptr));
        comboBox->setItemText(15, QCoreApplication::translate("EvaluationAlgorithms", "\347\213\254\347\253\213\346\240\267\346\234\254T\346\243\200\351\252\214", nullptr));
        comboBox->setItemText(16, QCoreApplication::translate("EvaluationAlgorithms", "\347\233\270\345\205\263\346\200\247\345\210\206\346\236\220", nullptr));
        comboBox->setItemText(17, QCoreApplication::translate("EvaluationAlgorithms", "Kendall\344\270\200\350\207\264\346\200\247\346\243\200\351\252\214", nullptr));
        comboBox->setItemText(18, QCoreApplication::translate("EvaluationAlgorithms", "\346\250\241\347\263\212\347\273\274\345\220\210\350\257\204\344\273\267\346\263\225", nullptr));
        comboBox->setItemText(19, QCoreApplication::translate("EvaluationAlgorithms", "\345\256\242\350\247\202\345\222\214\344\270\273\350\247\202\350\257\204\344\273\267\347\232\204\345\276\227\345\210\206\347\256\227\346\263\225", nullptr));

        start_btn->setText(QCoreApplication::translate("EvaluationAlgorithms", "\345\274\200\345\247\213\345\210\206\346\236\220", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EvaluationAlgorithms: public Ui_EvaluationAlgorithms {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EVALUATIONALGORITHMS_H
