/********************************************************************************
** Form generated from reading UI file 'usrauctable.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USRAUCTABLE_H
#define UI_USRAUCTABLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_usrAuctable
{
public:

    void setupUi(QWidget *usrAuctable)
    {
        if (usrAuctable->objectName().isEmpty())
            usrAuctable->setObjectName(QStringLiteral("usrAuctable"));
        usrAuctable->resize(400, 300);

        retranslateUi(usrAuctable);

        QMetaObject::connectSlotsByName(usrAuctable);
    } // setupUi

    void retranslateUi(QWidget *usrAuctable)
    {
        usrAuctable->setWindowTitle(QApplication::translate("usrAuctable", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class usrAuctable: public Ui_usrAuctable {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USRAUCTABLE_H
