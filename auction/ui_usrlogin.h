/********************************************************************************
** Form generated from reading UI file 'usrlogin.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USRLOGIN_H
#define UI_USRLOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_usrLogin
{
public:

    void setupUi(QWidget *usrLogin)
    {
        if (usrLogin->objectName().isEmpty())
            usrLogin->setObjectName(QStringLiteral("usrLogin"));
        usrLogin->resize(400, 300);

        retranslateUi(usrLogin);

        QMetaObject::connectSlotsByName(usrLogin);
    } // setupUi

    void retranslateUi(QWidget *usrLogin)
    {
        usrLogin->setWindowTitle(QApplication::translate("usrLogin", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class usrLogin: public Ui_usrLogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USRLOGIN_H
