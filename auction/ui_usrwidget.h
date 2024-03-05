/********************************************************************************
** Form generated from reading UI file 'usrwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USRWIDGET_H
#define UI_USRWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_usrWidget
{
public:

    void setupUi(QWidget *usrWidget)
    {
        if (usrWidget->objectName().isEmpty())
            usrWidget->setObjectName(QStringLiteral("usrWidget"));
        usrWidget->resize(400, 300);

        retranslateUi(usrWidget);

        QMetaObject::connectSlotsByName(usrWidget);
    } // setupUi

    void retranslateUi(QWidget *usrWidget)
    {
        usrWidget->setWindowTitle(QApplication::translate("usrWidget", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class usrWidget: public Ui_usrWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USRWIDGET_H
