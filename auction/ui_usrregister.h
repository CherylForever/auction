/********************************************************************************
** Form generated from reading UI file 'usrregister.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USRREGISTER_H
#define UI_USRREGISTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_usrRegister
{
public:

    void setupUi(QWidget *usrRegister)
    {
        if (usrRegister->objectName().isEmpty())
            usrRegister->setObjectName(QStringLiteral("usrRegister"));
        usrRegister->resize(400, 300);

        retranslateUi(usrRegister);

        QMetaObject::connectSlotsByName(usrRegister);
    } // setupUi

    void retranslateUi(QWidget *usrRegister)
    {
        usrRegister->setWindowTitle(QApplication::translate("usrRegister", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class usrRegister: public Ui_usrRegister {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USRREGISTER_H
