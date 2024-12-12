/********************************************************************************
** Form generated from reading UI file 'triggeractiondialog.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRIGGERACTIONDIALOG_H
#define UI_TRIGGERACTIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_TriggerActionDialog
{
public:
    QVBoxLayout *verticalLayout;
    QTreeWidget *treeWidget;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *TriggerActionDialog)
    {
        if (TriggerActionDialog->objectName().isEmpty())
            TriggerActionDialog->setObjectName("TriggerActionDialog");
        TriggerActionDialog->resize(372, 488);
        verticalLayout = new QVBoxLayout(TriggerActionDialog);
        verticalLayout->setObjectName("verticalLayout");
        treeWidget = new QTreeWidget(TriggerActionDialog);
        treeWidget->setObjectName("treeWidget");

        verticalLayout->addWidget(treeWidget);

        buttonBox = new QDialogButtonBox(TriggerActionDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(TriggerActionDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, TriggerActionDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, TriggerActionDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(TriggerActionDialog);
    } // setupUi

    void retranslateUi(QDialog *TriggerActionDialog)
    {
        TriggerActionDialog->setWindowTitle(QCoreApplication::translate("TriggerActionDialog", "Dialog", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("TriggerActionDialog", "Buttons", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TriggerActionDialog: public Ui_TriggerActionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRIGGERACTIONDIALOG_H
