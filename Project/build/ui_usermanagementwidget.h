/********************************************************************************
** Form generated from reading UI file 'usermanagementwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERMANAGEMENTWIDGET_H
#define UI_USERMANAGEMENTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserManagementWidget
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QLineEdit *User_Edit;
    QLabel *label_2;
    QLineEdit *WorkPlace_Edit;
    QLabel *label;
    QComboBox *Sex_comboBox;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *NewUser_btn;
    QSpacerItem *horizontalSpacer_2;
    QTableWidget *User_Widget;

    void setupUi(QWidget *UserManagementWidget)
    {
        if (UserManagementWidget->objectName().isEmpty())
            UserManagementWidget->setObjectName("UserManagementWidget");
        UserManagementWidget->resize(1185, 754);
        verticalLayout = new QVBoxLayout(UserManagementWidget);
        verticalLayout->setObjectName("verticalLayout");
        widget = new QWidget(UserManagementWidget);
        widget->setObjectName("widget");
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        label_3 = new QLabel(widget);
        label_3->setObjectName("label_3");

        horizontalLayout->addWidget(label_3);

        User_Edit = new QLineEdit(widget);
        User_Edit->setObjectName("User_Edit");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(User_Edit->sizePolicy().hasHeightForWidth());
        User_Edit->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(User_Edit);

        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");

        horizontalLayout->addWidget(label_2);

        WorkPlace_Edit = new QLineEdit(widget);
        WorkPlace_Edit->setObjectName("WorkPlace_Edit");
        sizePolicy.setHeightForWidth(WorkPlace_Edit->sizePolicy().hasHeightForWidth());
        WorkPlace_Edit->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(WorkPlace_Edit);

        label = new QLabel(widget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        Sex_comboBox = new QComboBox(widget);
        Sex_comboBox->addItem(QString());
        Sex_comboBox->addItem(QString());
        Sex_comboBox->setObjectName("Sex_comboBox");

        horizontalLayout->addWidget(Sex_comboBox);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName("pushButton");
        pushButton->setMinimumSize(QSize(0, 29));

        horizontalLayout->addWidget(pushButton);

        horizontalSpacer = new QSpacerItem(569, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addWidget(widget);

        widget_2 = new QWidget(UserManagementWidget);
        widget_2->setObjectName("widget_2");
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        NewUser_btn = new QPushButton(widget_2);
        NewUser_btn->setObjectName("NewUser_btn");

        horizontalLayout_2->addWidget(NewUser_btn);

        horizontalSpacer_2 = new QSpacerItem(1065, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(widget_2);

        User_Widget = new QTableWidget(UserManagementWidget);
        if (User_Widget->columnCount() < 8)
            User_Widget->setColumnCount(8);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        User_Widget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        User_Widget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        User_Widget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        User_Widget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        User_Widget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        User_Widget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        User_Widget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        User_Widget->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        User_Widget->setObjectName("User_Widget");
        User_Widget->horizontalHeader()->setDefaultSectionSize(100);
        User_Widget->horizontalHeader()->setStretchLastSection(true);
        User_Widget->verticalHeader()->setVisible(false);

        verticalLayout->addWidget(User_Widget);


        retranslateUi(UserManagementWidget);

        QMetaObject::connectSlotsByName(UserManagementWidget);
    } // setupUi

    void retranslateUi(QWidget *UserManagementWidget)
    {
        UserManagementWidget->setWindowTitle(QCoreApplication::translate("UserManagementWidget", "Form", nullptr));
        label_3->setText(QCoreApplication::translate("UserManagementWidget", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        User_Edit->setPlaceholderText(QCoreApplication::translate("UserManagementWidget", "\350\257\267\350\276\223\345\205\245\347\224\250\346\210\267\345\220\215\346\220\234\347\264\242", nullptr));
        label_2->setText(QCoreApplication::translate("UserManagementWidget", "\345\267\245\344\275\234\345\215\225\344\275\215\357\274\232", nullptr));
        WorkPlace_Edit->setPlaceholderText(QCoreApplication::translate("UserManagementWidget", "\350\257\267\350\276\223\345\205\245\345\267\245\344\275\234\345\215\225\344\275\215", nullptr));
        label->setText(QCoreApplication::translate("UserManagementWidget", "\346\200\247\345\210\253\357\274\232", nullptr));
        Sex_comboBox->setItemText(0, QCoreApplication::translate("UserManagementWidget", "\347\224\267", nullptr));
        Sex_comboBox->setItemText(1, QCoreApplication::translate("UserManagementWidget", "\345\245\263", nullptr));

        pushButton->setText(QCoreApplication::translate("UserManagementWidget", "\346\220\234\347\264\242", nullptr));
        NewUser_btn->setText(QCoreApplication::translate("UserManagementWidget", "\346\226\260\345\273\272\347\224\250\346\210\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem = User_Widget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("UserManagementWidget", "\345\272\217\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = User_Widget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("UserManagementWidget", "\347\224\250\346\210\267\345\220\215\347\247\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = User_Widget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("UserManagementWidget", "\346\200\247\345\210\253", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = User_Widget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("UserManagementWidget", "\350\272\253\351\253\230\357\274\210cm\357\274\211", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = User_Widget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("UserManagementWidget", "\344\275\223\351\207\215\357\274\210kg\357\274\211", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = User_Widget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("UserManagementWidget", "\345\267\245\344\275\234\345\215\225\344\275\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = User_Widget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("UserManagementWidget", "\346\223\215\344\275\234", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = User_Widget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("UserManagementWidget", "\347\274\226\350\276\221", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserManagementWidget: public Ui_UserManagementWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERMANAGEMENTWIDGET_H
