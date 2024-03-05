/********************************************************************************
** Form generated from reading UI file 'usrupdatedate.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USRUPDATEDATE_H
#define UI_USRUPDATEDATE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_usrUpdateDate
{
public:

    void setupUi(QWidget *usrUpdateDate)
    {
        if (usrUpdateDate->objectName().isEmpty())
            usrUpdateDate->setObjectName(QStringLiteral("usrUpdateDate"));
        usrUpdateDate->resize(400, 300);

        retranslateUi(usrUpdateDate);

        QMetaObject::connectSlotsByName(usrUpdateDate);
    } // setupUi

    void retranslateUi(QWidget *usrUpdateDate)
    {
        usrUpdateDate->setWindowTitle(QApplication::translate("usrUpdateDate", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class usrUpdateDate: public Ui_usrUpdateDate {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USRUPDATEDATE_H
