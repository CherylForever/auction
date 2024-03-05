/********************************************************************************
** Form generated from reading UI file 'usrinsertdate.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USRINSERTDATE_H
#define UI_USRINSERTDATE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_usrInsertDate
{
public:

    void setupUi(QWidget *usrInsertDate)
    {
        if (usrInsertDate->objectName().isEmpty())
            usrInsertDate->setObjectName(QStringLiteral("usrInsertDate"));
        usrInsertDate->resize(400, 300);

        retranslateUi(usrInsertDate);

        QMetaObject::connectSlotsByName(usrInsertDate);
    } // setupUi

    void retranslateUi(QWidget *usrInsertDate)
    {
        usrInsertDate->setWindowTitle(QApplication::translate("usrInsertDate", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class usrInsertDate: public Ui_usrInsertDate {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USRINSERTDATE_H
