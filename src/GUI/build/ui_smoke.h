/********************************************************************************
** Form generated from reading UI file 'smoke.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SMOKE_H
#define UI_SMOKE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Smoke
{
public:
    QWidget *widget;

    void setupUi(QWidget *Smoke)
    {
        if (Smoke->objectName().isEmpty())
            Smoke->setObjectName(QStringLiteral("Smoke"));
        Smoke->resize(1920, 1080);
        widget = new QWidget(Smoke);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 0, 1920, 1080));
        widget->setStyleSheet(QLatin1String("#widget {\n"
"	background-image: url(:/img/assets/img/smoke.png);\n"
"}"));

        retranslateUi(Smoke);

        QMetaObject::connectSlotsByName(Smoke);
    } // setupUi

    void retranslateUi(QWidget *Smoke)
    {
        Smoke->setWindowTitle(QApplication::translate("Smoke", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Smoke: public Ui_Smoke {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SMOKE_H
