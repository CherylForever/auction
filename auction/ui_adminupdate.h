/********************************************************************************
** Form generated from reading UI file 'adminupdate.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINUPDATE_H
#define UI_ADMINUPDATE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_adminUpdate
{
public:

    void setupUi(QWidget *adminUpdate)
    {
        if (adminUpdate->objectName().isEmpty())
            adminUpdate->setObjectName(QStringLiteral("adminUpdate"));
        adminUpdate->resize(400, 300);

        retranslateUi(adminUpdate);

        QMetaObject::connectSlotsByName(adminUpdate);
    } // setupUi

    void retranslateUi(QWidget *adminUpdate)
    {
        adminUpdate->setWindowTitle(QApplication::translate("adminUpdate", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class adminUpdate: public Ui_adminUpdate {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINUPDATE_H
