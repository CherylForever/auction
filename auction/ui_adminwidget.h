/********************************************************************************
** Form generated from reading UI file 'adminwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINWIDGET_H
#define UI_ADMINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_adminWidget
{
public:

    void setupUi(QWidget *adminWidget)
    {
        if (adminWidget->objectName().isEmpty())
            adminWidget->setObjectName(QStringLiteral("adminWidget"));
        adminWidget->resize(400, 300);

        retranslateUi(adminWidget);

        QMetaObject::connectSlotsByName(adminWidget);
    } // setupUi

    void retranslateUi(QWidget *adminWidget)
    {
        adminWidget->setWindowTitle(QApplication::translate("adminWidget", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class adminWidget: public Ui_adminWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINWIDGET_H
