/********************************************************************************
** Form generated from reading UI file 'configlistitem.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIGLISTITEM_H
#define UI_CONFIGLISTITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConfigListItem
{
public:
    QHBoxLayout *horizontalLayout_2;
    QWidget *widget_config;
    QHBoxLayout *horizontalLayout;
    QLabel *JI_Name_label;
    QSpacerItem *horizontalSpacer;
    QPushButton *Edit_btn;
    QPushButton *Delete_btn;

    void setupUi(QWidget *ConfigListItem)
    {
        if (ConfigListItem->objectName().isEmpty())
            ConfigListItem->setObjectName("ConfigListItem");
        ConfigListItem->resize(1050, 100);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ConfigListItem->sizePolicy().hasHeightForWidth());
        ConfigListItem->setSizePolicy(sizePolicy);
        ConfigListItem->setMinimumSize(QSize(0, 100));
        ConfigListItem->setMaximumSize(QSize(16777215, 100));
        horizontalLayout_2 = new QHBoxLayout(ConfigListItem);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        widget_config = new QWidget(ConfigListItem);
        widget_config->setObjectName("widget_config");
        widget_config->setStyleSheet(QString::fromUtf8("QWidget#widget_config{background-color: rgb(255, 255, 255);}"));
        horizontalLayout = new QHBoxLayout(widget_config);
        horizontalLayout->setObjectName("horizontalLayout");
        JI_Name_label = new QLabel(widget_config);
        JI_Name_label->setObjectName("JI_Name_label");

        horizontalLayout->addWidget(JI_Name_label);

        horizontalSpacer = new QSpacerItem(699, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        Edit_btn = new QPushButton(widget_config);
        Edit_btn->setObjectName("Edit_btn");

        horizontalLayout->addWidget(Edit_btn);

        Delete_btn = new QPushButton(widget_config);
        Delete_btn->setObjectName("Delete_btn");

        horizontalLayout->addWidget(Delete_btn);


        horizontalLayout_2->addWidget(widget_config);


        retranslateUi(ConfigListItem);

        QMetaObject::connectSlotsByName(ConfigListItem);
    } // setupUi

    void retranslateUi(QWidget *ConfigListItem)
    {
        ConfigListItem->setWindowTitle(QCoreApplication::translate("ConfigListItem", "Form", nullptr));
        JI_Name_label->setText(QCoreApplication::translate("ConfigListItem", "\346\277\200\345\212\261\351\205\215\347\275\256\345\220\215\347\247\260\346\277\200\345\212\261\351\205\215\347\275\256\345\220\215\347\247\260", nullptr));
        Edit_btn->setText(QCoreApplication::translate("ConfigListItem", "\347\274\226\350\276\221", nullptr));
        Delete_btn->setText(QCoreApplication::translate("ConfigListItem", "\345\210\240\351\231\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ConfigListItem: public Ui_ConfigListItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGLISTITEM_H
