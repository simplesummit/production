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
    QWidget *l_small_img;
    QPushButton *l_small_txt;
    QWidget *m_large_box;
    QPushButton *m_large_txt;
    QWidget *m_large_img;
    QWidget *m_small_box;
    QWidget *m_small_img;
    QPushButton *m_small_txt;
    QWidget *r_small_box;
    QWidget *r_small_img;
    QPushButton *r_small_txt;

    void setupUi(QWidget *HomePage)
    {
        if (HomePage->objectName().isEmpty())
            HomePage->setObjectName(QStringLiteral("HomePage"));
        HomePage->setEnabled(true);
        HomePage->resize(1920, 1080);
        HomePage->setStyleSheet(QLatin1String("#HomePage {\n"
"background-image: url(:/img/assets/img/homepage.png) !important;\n"
"}"));
        centralwidget = new QWidget(HomePage);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        centralwidget->setGeometry(QRect(0, 0, 1920, 1080));
        centralwidget->setStyleSheet(QLatin1String("#centralwidget {\n"
"	border-image: url(:/img/assets/img/homepage.png) 0 0 0 0 stretch stretch;\n"
"background-image: url(:/img/assets/img/homepage.png) !important;\n"
"background-color: #323232;\n"
"}"));
        l_small_box = new QWidget(centralwidget);
        l_small_box->setObjectName(QStringLiteral("l_small_box"));
        l_small_box->setGeometry(QRect(220, 710, 390, 270));
        l_small_box->setStyleSheet(QLatin1String("background-color: #323232  !important;\n"
"border-radius: 10px;"));
        l_small_img = new QWidget(l_small_box);
        l_small_img->setObjectName(QStringLiteral("l_small_img"));
        l_small_img->setGeometry(QRect(0, 0, 391, 221));
        l_small_img->setStyleSheet(QLatin1String("background-color: #5f5f5f !important;\n"
"border-bottom-left-radius: 0px;\n"
"border-bottom-right-radius: 0px;\n"
"border-image: url(:/img/assets/img/smoke_img.png);"));
        l_small_txt = new QPushButton(l_small_box);
        l_small_txt->setObjectName(QStringLiteral("l_small_txt"));
        l_small_txt->setGeometry(QRect(20, 230, 351, 31));
        QFont font;
        font.setFamily(QStringLiteral("Lemon/Milk,sans-serif"));
        font.setPointSize(16);
        l_small_txt->setFont(font);
        l_small_txt->setStyleSheet(QLatin1String("text-align: left;\n"
"color: white;\n"
"font-size: 16pt;\n"
"font-family: \"Lemon/Milk\", sans-serif;"));
        m_large_box = new QWidget(centralwidget);
        m_large_box->setObjectName(QStringLiteral("m_large_box"));
        m_large_box->setGeometry(QRect(710, 190, 500, 350));
        m_large_box->setCursor(QCursor(Qt::PointingHandCursor));
        m_large_box->setStyleSheet(QLatin1String("background-color: #323232 !important;\n"
"border-radius: 20px;\n"
""));
        m_large_txt = new QPushButton(m_large_box);
        m_large_txt->setObjectName(QStringLiteral("m_large_txt"));
        m_large_txt->setGeometry(QRect(18, 304, 461, 41));
        m_large_txt->setFont(font);
        m_large_txt->setStyleSheet(QLatin1String("color: rgb(243, 243, 243);\n"
"border-radius: 0px;\n"
"font-size: 16pt;\n"
"text-align: left;\n"
"font-family: \"Lemon/Milk\", sans-serif;"));
        m_large_img = new QWidget(m_large_box);
        m_large_img->setObjectName(QStringLiteral("m_large_img"));
        m_large_img->setGeometry(QRect(0, 0, 501, 301));
        m_large_img->setStyleSheet(QLatin1String("background-color: rgb(95, 95, 95);\n"
"border-bottom-left-radius: 0px;\n"
"border-bottom-right-radius: 0px;\n"
"border-image: url(:/img/assets/img/summit.jpg);"));
        m_small_box = new QWidget(centralwidget);
        m_small_box->setObjectName(QStringLiteral("m_small_box"));
        m_small_box->setGeometry(QRect(765, 710, 390, 270));
        m_small_box->setStyleSheet(QLatin1String("background-color: #323232;\n"
"border-radius: 10px;"));
        m_small_img = new QWidget(m_small_box);
        m_small_img->setObjectName(QStringLiteral("m_small_img"));
        m_small_img->setGeometry(QRect(0, 0, 391, 221));
        m_small_img->setStyleSheet(QLatin1String("background-color: #5f5f5f !important;\n"
"border-bottom-left-radius: 0px;\n"
"border-bottom-right-radius: 0px;\n"
"border-image: url(:/img/assets/img/particles.png);"));
        m_small_txt = new QPushButton(m_small_box);
        m_small_txt->setObjectName(QStringLiteral("m_small_txt"));
        m_small_txt->setGeometry(QRect(20, 230, 351, 31));
        m_small_txt->setFont(font);
        m_small_txt->setStyleSheet(QLatin1String("text-align: left;\n"
"color: white;\n"
"font-size: 16pt;\n"
"font-family: \"Lemon/Milk\", sans-serif;"));
        r_small_box = new QWidget(centralwidget);
        r_small_box->setObjectName(QStringLiteral("r_small_box"));
        r_small_box->setGeometry(QRect(1300, 710, 390, 270));
        r_small_box->setStyleSheet(QLatin1String("background-color: #323232;\n"
"border-radius: 10px;"));
        r_small_img = new QWidget(r_small_box);
        r_small_img->setObjectName(QStringLiteral("r_small_img"));
        r_small_img->setGeometry(QRect(0, 0, 391, 221));
        r_small_img->setStyleSheet(QLatin1String("background-color: #5f5f5f !important;\n"
"border-bottom-left-radius: 0px;\n"
"border-bottom-right-radius: 0px;\n"
"border-image: url(:/img/assets/img/ml.png);"));
        r_small_txt = new QPushButton(r_small_box);
        r_small_txt->setObjectName(QStringLiteral("r_small_txt"));
        r_small_txt->setGeometry(QRect(20, 230, 351, 31));
        r_small_txt->setFont(font);
        r_small_txt->setStyleSheet(QLatin1String("text-align: left;\n"
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
        l_small_txt->setText(QApplication::translate("HomePage", "Smoke", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        m_large_box->setToolTip(QApplication::translate("HomePage", "m_large_box", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        m_large_txt->setText(QApplication::translate("HomePage", "Summit At A Glance", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        m_small_box->setToolTip(QApplication::translate("HomePage", "m_small_box", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        m_small_txt->setText(QApplication::translate("HomePage", "Particles", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        r_small_box->setToolTip(QApplication::translate("HomePage", "r_small_box", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        r_small_txt->setText(QApplication::translate("HomePage", "Machine Learning", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class HomePage: public Ui_HomePage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOMEPAGE_H
