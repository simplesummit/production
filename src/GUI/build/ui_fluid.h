/********************************************************************************
** Form generated from reading UI file 'fluid.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FLUID_H
#define UI_FLUID_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Fluid
{
public:
    QWidget *widget;

    void setupUi(QWidget *Fluid)
    {
        if (Fluid->objectName().isEmpty())
            Fluid->setObjectName(QStringLiteral("Fluid"));
        Fluid->resize(1920, 1080);
        widget = new QWidget(Fluid);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 0, 1920, 1080));
        widget->setStyleSheet(QLatin1String("#widget {\n"
"	background-image: url(:/img/assets/img/fluid.png);\n"
"}"));

        retranslateUi(Fluid);

        QMetaObject::connectSlotsByName(Fluid);
    } // setupUi

    void retranslateUi(QWidget *Fluid)
    {
        Fluid->setWindowTitle(QApplication::translate("Fluid", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Fluid: public Ui_Fluid {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FLUID_H
