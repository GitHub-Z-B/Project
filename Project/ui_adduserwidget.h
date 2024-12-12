/********************************************************************************
** Form generated from reading UI file 'adduserwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDUSERWIDGET_H
#define UI_ADDUSERWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddUserWidget
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;
    QPushButton *Save_btn;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_7;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *Name_Edit;
    QComboBox *Sex_comboBox;
    QLineEdit *High_Edit;
    QLineEdit *Widght_Edit;
    QLineEdit *workplace_Edit;

    void setupUi(QWidget *AddUserWidget)
    {
        if (AddUserWidget->objectName().isEmpty())
            AddUserWidget->setObjectName("AddUserWidget");
        AddUserWidget->setEnabled(true);
        AddUserWidget->resize(1012, 529);
        gridLayout = new QGridLayout(AddUserWidget);
        gridLayout->setObjectName("gridLayout");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 3, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 2, 1, 1);

        Save_btn = new QPushButton(AddUserWidget);
        Save_btn->setObjectName("Save_btn");

        gridLayout->addWidget(Save_btn, 1, 2, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label_2 = new QLabel(AddUserWidget);
        label_2->setObjectName("label_2");

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(AddUserWidget);
        label_3->setObjectName("label_3");

        verticalLayout->addWidget(label_3);

        label_4 = new QLabel(AddUserWidget);
        label_4->setObjectName("label_4");

        verticalLayout->addWidget(label_4);

        label_5 = new QLabel(AddUserWidget);
        label_5->setObjectName("label_5");

        verticalLayout->addWidget(label_5);

        label_7 = new QLabel(AddUserWidget);
        label_7->setObjectName("label_7");

        verticalLayout->addWidget(label_7);


        gridLayout->addLayout(verticalLayout, 0, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 0, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        Name_Edit = new QLineEdit(AddUserWidget);
        Name_Edit->setObjectName("Name_Edit");

        verticalLayout_2->addWidget(Name_Edit);

        Sex_comboBox = new QComboBox(AddUserWidget);
        Sex_comboBox->setObjectName("Sex_comboBox");

        verticalLayout_2->addWidget(Sex_comboBox);

        High_Edit = new QLineEdit(AddUserWidget);
        High_Edit->setObjectName("High_Edit");

        verticalLayout_2->addWidget(High_Edit);

        Widght_Edit = new QLineEdit(AddUserWidget);
        Widght_Edit->setObjectName("Widght_Edit");

        verticalLayout_2->addWidget(Widght_Edit);

        workplace_Edit = new QLineEdit(AddUserWidget);
        workplace_Edit->setObjectName("workplace_Edit");

        verticalLayout_2->addWidget(workplace_Edit);


        gridLayout->addLayout(verticalLayout_2, 0, 2, 1, 1);


        retranslateUi(AddUserWidget);

        QMetaObject::connectSlotsByName(AddUserWidget);
    } // setupUi

    void retranslateUi(QWidget *AddUserWidget)
    {
        AddUserWidget->setWindowTitle(QCoreApplication::translate("AddUserWidget", "Form", nullptr));
        Save_btn->setText(QCoreApplication::translate("AddUserWidget", "\344\277\235\345\255\230", nullptr));
        label_2->setText(QCoreApplication::translate("AddUserWidget", "\347\224\250\346\210\267\345\220\215", nullptr));
        label_3->setText(QCoreApplication::translate("AddUserWidget", "\346\200\247\345\210\253", nullptr));
        label_4->setText(QCoreApplication::translate("AddUserWidget", "\350\272\253\351\253\230\357\274\210CM\357\274\211", nullptr));
        label_5->setText(QCoreApplication::translate("AddUserWidget", "\344\275\223\351\207\215\357\274\210KG\357\274\211", nullptr));
        label_7->setText(QCoreApplication::translate("AddUserWidget", "\345\267\245\344\275\234\345\215\225\344\275\215", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddUserWidget: public Ui_AddUserWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDUSERWIDGET_H
