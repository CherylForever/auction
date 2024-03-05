/********************************************************************************
** Form generated from reading UI file 'usrdeletedate.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USRDELETEDATE_H
#define UI_USRDELETEDATE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_usrDeleteDate
{
public:

    void setupUi(QWidget *usrDeleteDate)
    {
        if (usrDeleteDate->objectName().isEmpty())
            usrDeleteDate->setObjectName(QStringLiteral("usrDeleteDate"));
        usrDeleteDate->resize(400, 300);

        retranslateUi(usrDeleteDate);

        QMetaObject::connectSlotsByName(usrDeleteDate);
    } // setupUi

    void retranslateUi(QWidget *usrDeleteDate)
    {
        usrDeleteDate->setWindowTitle(QApplication::translate("usrDeleteDate", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class usrDeleteDate: public Ui_usrDeleteDate {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USRDELETEDATE_H
