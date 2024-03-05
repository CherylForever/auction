/********************************************************************************
** Form generated from reading UI file 'usrsellgood.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USRSELLGOOD_H
#define UI_USRSELLGOOD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_usrSellGood
{
public:

    void setupUi(QWidget *usrSellGood)
    {
        if (usrSellGood->objectName().isEmpty())
            usrSellGood->setObjectName(QStringLiteral("usrSellGood"));
        usrSellGood->resize(400, 300);

        retranslateUi(usrSellGood);

        QMetaObject::connectSlotsByName(usrSellGood);
    } // setupUi

    void retranslateUi(QWidget *usrSellGood)
    {
        usrSellGood->setWindowTitle(QApplication::translate("usrSellGood", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class usrSellGood: public Ui_usrSellGood {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USRSELLGOOD_H
