/********************************************************************************
** Form generated from reading UI file 'dogswidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOGSWIDGET_H
#define UI_DOGSWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DogsWidget
{
public:

    void setupUi(QWidget *DogsWidget)
    {
        if (DogsWidget->objectName().isEmpty())
            DogsWidget->setObjectName(QString::fromUtf8("DogsWidget"));
        DogsWidget->resize(400, 300);

        retranslateUi(DogsWidget);

        QMetaObject::connectSlotsByName(DogsWidget);
    } // setupUi

    void retranslateUi(QWidget *DogsWidget)
    {
        DogsWidget->setWindowTitle(QCoreApplication::translate("DogsWidget", "DogsWidget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DogsWidget: public Ui_DogsWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOGSWIDGET_H
