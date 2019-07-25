/*! \class HomePage
 *  \brief The landing page for the application.
 *  \author    Tyler Duckworth
 *  \date      2019
 *  \copyright BSD 3-Clause "New" or "Revised" License
 *
 * The user uses this page to navigate to the rest and to interact
 * with the application as a whole.
 *
 * For that reason, this is made to be as responsive as possible.
 */

#include "homepage.h"
#include "ui_homepage.h"

#include <QDebug>
#include <QtGamepad/QGamepad>
#include <QGraphicsDropShadowEffect>
#include <QStateMachine>

#include <cmath>
#include <iostream>
#include <string>

#define PI 3.14159265

/** Creates a HomePage object
 * Sets up the Qt-generated UI, arranges the children cards, and defaults all
 * the data structures.
 */
HomePage::HomePage(QGamepad *gamepad, QWidget *parent) : QWidget(parent), ui(new Ui::HomePage), m_gamepad(gamepad)
{
    ui->setupUi(this);
    children = this->findChildren<QWidget *>(QRegularExpression("box$"));
    state = ST_LG_CARD;


    lg_x1 = (this->width() - lg_card.width()) / 2;

    sm_x1 = (this->width() - sm_card.width()) / 2;
    sm_x2 = (0.5 * this->width() - sm_card.width()) / 4;
    sm_x3 = this->width() - sm_x2;
    QRect screen = QGuiApplication::primaryScreen()->geometry();
    this->setGeometry(0,0, screen.width(), screen.height());
    ui->centralwidget->setGeometry(0,0, screen.width(), screen.height());

    lg_card = QSize(this->width() * 0.2604, this->height() * 0.29);
    sm_card = QSize(this->width() * 0.204, this->height() * 0.225);
    lg_x1 = (this->width() - lg_card.width()) / 2;

    sm_x1 = (this->width() - sm_card.width()) / 2;
    sm_x2 = (0.5 * this->width() - sm_card.width()) / 2;
    sm_x3 = sm_x2 + (this->width()/2);

    ui->m_large_box->setGeometry(lg_x1, this->height()*p2, lg_card.width(), lg_card.height());
    ui->m_small_box->setGeometry(sm_x1, this->height()*0.66, sm_card.width(), sm_card.height());
    ui->l_small_box->setGeometry(sm_x2, this->height()*0.66, sm_card.width(), sm_card.height());
    ui->r_small_box->setGeometry(sm_x3, this->height()*0.66, sm_card.width(), sm_card.height());

    ui->m_large_img->setGeometry(0, 0, lg_card.width(), 0.86*lg_card.height());
    ui->m_small_img->setGeometry(0, 0, sm_card.width(), 0.82*sm_card.height());
    ui->l_small_img->setGeometry(0, 0, sm_card.width(), 0.82*sm_card.height());
    ui->r_small_img->setGeometry(0, 0, sm_card.width(), 0.82*sm_card.height());

    ui->m_large_txt->setGeometry(lg_card.width()*0.05, 0.875*lg_card.height(), lg_card.width()*0.9, 0.11*lg_card.height());
    ui->m_small_txt->setGeometry(sm_card.width()*0.05, 0.85*sm_card.height(), sm_card.width()*0.9, 0.11*sm_card.height());
    ui->l_small_txt->setGeometry(sm_card.width()*0.05, 0.85*sm_card.height(), sm_card.width()*0.9, 0.11*sm_card.height());
    ui->r_small_txt->setGeometry(sm_card.width()*0.05, 0.85*sm_card.height(), sm_card.width()*0.9, 0.11*sm_card.height());

    for(QWidget *t : children) {
        //Put in .h
        QPropertyAnimation *a = new QPropertyAnimation(t, "geometry");
        a->setEasingCurve(QEasingCurve::BezierSpline);
        a->setDuration(250);
        a->setStartValue(t->geometry());
        a->setEndValue(t->geometry());
        animationList.append(a);
    }
}

/** Draws drop shadows periodically.
 *
 *  Inherits from QWidget. Redraws the widget every cycle.
 */
void HomePage::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    for(QWidget *t : children) {
        childName = t->toolTip().toUtf8().constData();
        dShadow = new QGraphicsDropShadowEffect(this);
        if(isPressed && childName == activeCard) {
            dShadowColor = Qt::red;
        } else if(childName == activeCard) {
            dShadowColor = QColor(0, 121, 52);
        } else {
            dShadowColor = Qt::black;
        }
        dShadow->setOffset(0, 0);
        dShadow->setBlurRadius(25);
        dShadow->setColor(dShadowColor);
        t->setGraphicsEffect(dShadow);

        dShadow = nullptr;
    }

}
/** Get the active page
 * \return Returns an integer to signify card.
 *
 * Used globally in Stack.
 */
int HomePage::activePage() {
    switch(state) {
        case ST_LG_CARD:
            return 1;
            break;
        case ST_SM_LFT:
            return 2;
            break;
        case ST_SM_MID:
            return 3;
            break;
        case ST_SM_RGT:
            return 4;
            break;
    }
    return 0;
}

///@{


/** Reads the "Y" button and starts the animation.
  * \warning Used for diagnostics only.
  */
void HomePage::getYButton(bool _isPressed) {
    if(_isPressed) {
        animation->start();
    }
}
/** Reads the gamepad's x-axis and determines the "active" card.
  *
  * Using atan2 to calculate the rotation of the joystick, it picks the card that falls
  * within its range.
  */
void HomePage::getLeftX(double value) {
    value = round(value);
    double ly_axis = round(m_gamepad->axisLeftY()) * -1;
    double deg = round(std::atan2(ly_axis, value) * 180 / PI);

    if(deg > -145 && deg < -125) {
        state = ST_SM_LFT;
        activeCard = "l_small_box";
        qDebug() << "Bottom Left";
    } else if(deg > -100 && deg < -80) {
        state = ST_SM_MID;
        activeCard = "m_small_box";
        qDebug() << "Bottom Middle";
    } else if(deg > -55 && deg < -35) {
        state = ST_SM_RGT;
        activeCard = "r_small_box";

        qDebug() << "Bottom Right";
    } else {
        activeCard = "m_large_box";
        state = ST_LG_CARD;
    }
}
/** Reads the gamepad's y-axis and determines the "active" card.
  *
  * Uses the same methods as getLeftX.
  * Also assigns the animation with an active card to make it float.
  */
void HomePage::getLeftY(double value) {
    value = round(value) * -1;
    double lx_axis = round(m_gamepad->axisLeftX());
    double deg = round(std::atan2(value, lx_axis) * 180 / PI);
    prevCard = activeCard;
    if(deg > -145 && deg < -125) {
        state = ST_SM_LFT;
        activeCard = "l_small_box";
        activeCardObj = ui->l_small_box;
    } else if(deg > -100 && deg < -80) {
        state = ST_SM_MID;
        activeCard = "m_small_box";
        activeCardObj = ui->m_small_box;
    } else if(deg > -55 && deg < -35) {
        activeCard = "r_small_box";
        state = ST_SM_RGT;
        activeCardObj = ui->r_small_box;
    } else {
        activeCard = "m_large_box";
        state = ST_LG_CARD;
        activeCardObj = ui->m_large_box;
    }

    animation = new QPropertyAnimation(activeCardObj, "geometry");
    animation->setStartValue(activeCardObj->geometry());
    animation->setDuration(200);
    animation->setEasingCurve(QEasingCurve::BezierSpline);
    animation->setEndValue(activeCardObj->geometry().translated(0,-20));
    // animation->start();
    if(activeCard != "m_large_box" && activeCardObj->y() < 690) {
       animationList.at(state)->start();
    } else if(activeCardObj->y() < 190) {
        animationList.at(state)->start();
    } else {
        animation->start();
    }
    for(int i = 0; i < children.size(); i++) {
        if(i != state) {
            animationList.at(i)->start();
        }
    }

}

///@}

HomePage::~HomePage() {
    delete ui;
    delete m_gamepad;
    delete dShadow;
    delete animation;
    delete activeCardObj;
}
