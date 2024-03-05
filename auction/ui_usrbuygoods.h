/********************************************************************************
** Form generated from reading UI file 'usrbuygoods.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USRBUYGOODS_H
#define UI_USRBUYGOODS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_usrBuyGoods
{
public:

    void setupUi(QWidget *usrBuyGoods)
    {
        if (usrBuyGoods->objectName().isEmpty())
            usrBuyGoods->setObjectName(QStringLiteral("usrBuyGoods"));
        usrBuyGoods->resize(400, 300);

        retranslateUi(usrBuyGoods);

        QMetaObject::connectSlotsByName(usrBuyGoods);
    } // setupUi

    void retranslateUi(QWidget *usrBuyGoods)
    {
        usrBuyGoods->setWindowTitle(QApplication::translate("usrBuyGoods", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class usrBuyGoods: public Ui_usrBuyGoods {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USRBUYGOODS_H
