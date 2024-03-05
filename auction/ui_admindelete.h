/********************************************************************************
** Form generated from reading UI file 'admindelete.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINDELETE_H
#define UI_ADMINDELETE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_adminDelete
{
public:

    void setupUi(QWidget *adminDelete)
    {
        if (adminDelete->objectName().isEmpty())
            adminDelete->setObjectName(QStringLiteral("adminDelete"));
        adminDelete->resize(400, 300);

        retranslateUi(adminDelete);

        QMetaObject::connectSlotsByName(adminDelete);
    } // setupUi

    void retranslateUi(QWidget *adminDelete)
    {
        adminDelete->setWindowTitle(QApplication::translate("adminDelete", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class adminDelete: public Ui_adminDelete {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINDELETE_H
