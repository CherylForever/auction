/********************************************************************************
** Form generated from reading UI file 'adminallgood.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINALLGOOD_H
#define UI_ADMINALLGOOD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_adminAllgood
{
public:

    void setupUi(QWidget *adminAllgood)
    {
        if (adminAllgood->objectName().isEmpty())
            adminAllgood->setObjectName(QStringLiteral("adminAllgood"));
        adminAllgood->resize(400, 300);

        retranslateUi(adminAllgood);

        QMetaObject::connectSlotsByName(adminAllgood);
    } // setupUi

    void retranslateUi(QWidget *adminAllgood)
    {
        adminAllgood->setWindowTitle(QApplication::translate("adminAllgood", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class adminAllgood: public Ui_adminAllgood {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINALLGOOD_H
