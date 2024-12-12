/********************************************************************************
** Form generated from reading UI file 'screenimportitem.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCREENIMPORTITEM_H
#define UI_SCREENIMPORTITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ScreenImportItem
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label_10;
    QLineEdit *ScreenPath_Edit;
    QPushButton *SetPosition_btn;
    QPushButton *CloseExe_btn_;
    QPushButton *delete_btn;

    void setupUi(QWidget *ScreenImportItem)
    {
        if (ScreenImportItem->objectName().isEmpty())
            ScreenImportItem->setObjectName("ScreenImportItem");
        ScreenImportItem->resize(902, 74);
        horizontalLayout = new QHBoxLayout(ScreenImportItem);
        horizontalLayout->setObjectName("horizontalLayout");
        label_10 = new QLabel(ScreenImportItem);
        label_10->setObjectName("label_10");
        label_10->setMaximumSize(QSize(65, 16777215));

        horizontalLayout->addWidget(label_10);

        ScreenPath_Edit = new QLineEdit(ScreenImportItem);
        ScreenPath_Edit->setObjectName("ScreenPath_Edit");

        horizontalLayout->addWidget(ScreenPath_Edit);

        SetPosition_btn = new QPushButton(ScreenImportItem);
        SetPosition_btn->setObjectName("SetPosition_btn");
        SetPosition_btn->setMaximumSize(QSize(93, 16777215));
        QFont font;
        font.setFamilies({QString::fromUtf8("Microsoft YaHei")});
        font.setPointSize(9);
        font.setBold(false);
        SetPosition_btn->setFont(font);
        SetPosition_btn->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(SetPosition_btn);

        CloseExe_btn_ = new QPushButton(ScreenImportItem);
        CloseExe_btn_->setObjectName("CloseExe_btn_");
        CloseExe_btn_->setMaximumSize(QSize(93, 16777215));
        QFont font1;
        font1.setPointSize(9);
        font1.setBold(false);
        CloseExe_btn_->setFont(font1);
        CloseExe_btn_->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(CloseExe_btn_);

        delete_btn = new QPushButton(ScreenImportItem);
        delete_btn->setObjectName("delete_btn");

        horizontalLayout->addWidget(delete_btn);


        retranslateUi(ScreenImportItem);

        QMetaObject::connectSlotsByName(ScreenImportItem);
    } // setupUi

    void retranslateUi(QWidget *ScreenImportItem)
    {
        ScreenImportItem->setWindowTitle(QCoreApplication::translate("ScreenImportItem", "Form", nullptr));
        label_10->setText(QCoreApplication::translate("ScreenImportItem", "\347\224\273\351\235\242:", nullptr));
        SetPosition_btn->setText(QCoreApplication::translate("ScreenImportItem", "\350\256\276\347\275\256\344\275\215\347\275\256", nullptr));
        CloseExe_btn_->setText(QCoreApplication::translate("ScreenImportItem", "\345\205\263\351\227\255\347\224\273\351\235\242", nullptr));
        delete_btn->setText(QCoreApplication::translate("ScreenImportItem", "\345\210\240\351\231\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ScreenImportItem: public Ui_ScreenImportItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCREENIMPORTITEM_H
