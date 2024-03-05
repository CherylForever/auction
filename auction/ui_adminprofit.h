/********************************************************************************
** Form generated from reading UI file 'adminprofit.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINPROFIT_H
#define UI_ADMINPROFIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_adminProfit
{
public:

    void setupUi(QWidget *adminProfit)
    {
        if (adminProfit->objectName().isEmpty())
            adminProfit->setObjectName(QStringLiteral("adminProfit"));
        adminProfit->resize(764, 516);

        retranslateUi(adminProfit);

        QMetaObject::connectSlotsByName(adminProfit);
    } // setupUi

    void retranslateUi(QWidget *adminProfit)
    {
        adminProfit->setWindowTitle(QApplication::translate("adminProfit", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class adminProfit: public Ui_adminProfit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINPROFIT_H
