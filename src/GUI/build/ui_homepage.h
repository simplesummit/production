/********************************************************************************
** Form generated from reading UI file 'homepage.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOMEPAGE_H
#define UI_HOMEPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HomePage
{
public:
    QWidget *centralwidget;
    QWidget *l_small_box;
    QWidget *widget_6;
    QPushButton *pushButton_2;
    QWidget *m_large_box;
    QPushButton *pushButton_3;
    QWidget *widget_7;
    QWidget *m_small_box;
    QWidget *widget_11;
    QPushButton *pushButton_7;
    QPushButton *pushButton_4;
    QWidget *r_small_box;
    QWidget *widget_12;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;

    void setupUi(QWidget *HomePage)
    {
        if (HomePage->objectName().isEmpty())
            HomePage->setObjectName(QStringLiteral("HomePage"));
        HomePage->setEnabled(true);
        HomePage->resize(1920, 1080);
        HomePage->setStyleSheet(QStringLiteral(""));
        centralwidget = new QWidget(HomePage);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        centralwidget->setGeometry(QRect(0, 0, 1920, 1080));
        centralwidget->setStyleSheet(QLatin1String("#centralwidget {\n"
"	background-image: url(:/img/assets/img/homepage.png);\n"
"}"));
        l_small_box = new QWidget(centralwidget);
        l_small_box->setObjectName(QStringLiteral("l_small_box"));
        l_small_box->setGeometry(QRect(220, 710, 390, 270));
        l_small_box->setStyleSheet(QLatin1String("background-color: #323232;\n"
"border-radius: 10px;"));
        widget_6 = new QWidget(l_small_box);
        widget_6->setObjectName(QStringLiteral("widget_6"));
        widget_6->setGeometry(QRect(0, 0, 391, 221));
        widget_6->setStyleSheet(QLatin1String("background-color: #5f5f5f !important;\n"
"border-bottom-left-radius: 0px;\n"
"border-bottom-right-radius: 0px;\n"
"border-image: url(:/img/assets/img/smoke_img.png);"));
        pushButton_2 = new QPushButton(l_small_box);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(20, 230, 211, 31));
        QFont font;
        font.setFamily(QStringLiteral("Lemon/Milk,sans-serif"));
        font.setPointSize(16);
        pushButton_2->setFont(font);
        pushButton_2->setStyleSheet(QLatin1String("text-align: left;\n"
"color: white;\n"
"font-size: 16pt;\n"
"font-family: \"Lemon/Milk\", sans-serif;"));
        m_large_box = new QWidget(centralwidget);
        m_large_box->setObjectName(QStringLiteral("m_large_box"));
        m_large_box->setGeometry(QRect(710, 190, 500, 350));
        m_large_box->setCursor(QCursor(Qt::PointingHandCursor));
        m_large_box->setStyleSheet(QLatin1String("background-color: #323232;\n"
"border-radius: 20px;\n"
""));
        pushButton_3 = new QPushButton(m_large_box);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(18, 304, 461, 41));
        pushButton_3->setFont(font);
        pushButton_3->setStyleSheet(QLatin1String("color: rgb(243, 243, 243);\n"
"font-size: 16pt;\n"
"text-align: left;\n"
"font-family: \"Lemon/Milk\", sans-serif;"));
        widget_7 = new QWidget(m_large_box);
        widget_7->setObjectName(QStringLiteral("widget_7"));
        widget_7->setGeometry(QRect(0, 0, 501, 301));
        widget_7->setStyleSheet(QLatin1String("background-color: rgb(95, 95, 95);\n"
"border-bottom-left-radius: 0px;\n"
"border-bottom-right-radius: 0px;\n"
"border-image: url(:/img/assets/img/summit.jpg);"));
        m_small_box = new QWidget(centralwidget);
        m_small_box->setObjectName(QStringLiteral("m_small_box"));
        m_small_box->setGeometry(QRect(765, 710, 390, 270));
        m_small_box->setStyleSheet(QLatin1String("background-color: #323232;\n"
"border-radius: 10px;"));
        widget_11 = new QWidget(m_small_box);
        widget_11->setObjectName(QStringLiteral("widget_11"));
        widget_11->setGeometry(QRect(0, 0, 391, 221));
        widget_11->setStyleSheet(QLatin1String("background-color: #5f5f5f !important;\n"
"border-bottom-left-radius: 0px;\n"
"border-bottom-right-radius: 0px;\n"
"border-image: url(:/img/assets/img/particles.png);"));
        pushButton_7 = new QPushButton(m_small_box);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(20, 230, 211, 31));
        pushButton_7->setStyleSheet(QLatin1String("text-align: left;\n"
"color: white;\n"
"font-size: 12pt;\n"
""));
        pushButton_4 = new QPushButton(m_small_box);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(20, 230, 211, 31));
        pushButton_4->setFont(font);
        pushButton_4->setStyleSheet(QLatin1String("text-align: left;\n"
"color: white;\n"
"font-size: 16pt;\n"
"font-family: \"Lemon/Milk\", sans-serif;"));
        r_small_box = new QWidget(centralwidget);
        r_small_box->setObjectName(QStringLiteral("r_small_box"));
        r_small_box->setGeometry(QRect(1300, 710, 390, 270));
        r_small_box->setStyleSheet(QLatin1String("background-color: #323232;\n"
"border-radius: 10px;"));
        widget_12 = new QWidget(r_small_box);
        widget_12->setObjectName(QStringLiteral("widget_12"));
        widget_12->setGeometry(QRect(0, 0, 391, 221));
        widget_12->setStyleSheet(QLatin1String("background-color: #5f5f5f !important;\n"
"border-bottom-left-radius: 0px;\n"
"border-bottom-right-radius: 0px;\n"
"border-image: url(:/img/assets/img/ml.png);"));
        pushButton_8 = new QPushButton(r_small_box);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(20, 230, 211, 31));
        pushButton_8->setStyleSheet(QLatin1String("text-align: left;\n"
"color: white;\n"
"font-size: 12pt;\n"
""));
        pushButton_9 = new QPushButton(r_small_box);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setGeometry(QRect(20, 230, 271, 31));
        pushButton_9->setFont(font);
        pushButton_9->setStyleSheet(QLatin1String("text-align: left;\n"
"color: white;\n"
"font-size: 16pt;\n"
"font-family: \"Lemon/Milk\", sans-serif;"));

        retranslateUi(HomePage);

        QMetaObject::connectSlotsByName(HomePage);
    } // setupUi

    void retranslateUi(QWidget *HomePage)
    {
        HomePage->setWindowTitle(QApplication::translate("HomePage", "Form", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        l_small_box->setToolTip(QApplication::translate("HomePage", "l_small_box", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pushButton_2->setText(QApplication::translate("HomePage", "Smoke", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        m_large_box->setToolTip(QApplication::translate("HomePage", "m_large_box", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pushButton_3->setText(QApplication::translate("HomePage", "Summit At A Glance", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        m_small_box->setToolTip(QApplication::translate("HomePage", "m_small_box", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pushButton_7->setText(QApplication::translate("HomePage", "PushButton", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("HomePage", "Particles", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        r_small_box->setToolTip(QApplication::translate("HomePage", "r_small_box", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pushButton_8->setText(QApplication::translate("HomePage", "PushButton", Q_NULLPTR));
        pushButton_9->setText(QApplication::translate("HomePage", "Machine Learning", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class HomePage: public Ui_HomePage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOMEPAGE_H
