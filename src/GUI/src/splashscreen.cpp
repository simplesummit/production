/*! \class SplashScreen
 *  \brief The widget that holds the splash screen shown in the page.
 *  \author    Tyler Duckworth
 *  \date      2019
 *  \copyright GNU Public License v3
 *
 *  Serving as an extension of the QSplashScreen class, this allows the splashscreen to be
 * customized in more detail and with more effects.
 *
*/

#include "splashscreen.h"

#include <QFontDatabase>
#include <QDebug>
#include <QGraphicsOpacityEffect>
#include <QGuiApplication>
#include <QWidget>
#include <QtGui>

/** Creates a SplashScreen object.
 *
 * The main purpose of this is to set up the animation curve that the splash screen will follow.
 *
 * It will fade out using an InOutExpo easing curve to modify its opacity.
 *
 * In addition, the message font and font size is set.
 */
SplashScreen::SplashScreen(const QPixmap &pixmap) {
    QRect screen = QGuiApplication::primaryScreen()->geometry();
    QSplashScreen::setPixmap(pixmap.scaled(screen.width(), screen.height(), Qt::KeepAspectRatioByExpanding));
    int id = QFontDatabase::addApplicationFont(":/fonts/assets/fonts/LemonMilk.otf");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    this->setFont( QFont(family, 30, 0, false));

    this->setStyleSheet("background-image:url(:/img/assets/img/smoke.png)");

    QGraphicsOpacityEffect *eff = new QGraphicsOpacityEffect(this);
    this->setGraphicsEffect(eff);
    propAnim = new QPropertyAnimation(this);
    propAnim->setTargetObject(eff);
    propAnim->setPropertyName("opacity");
    propAnim->setDuration(4500);
    propAnim->setStartValue(1);
    propAnim->setKeyValueAt(0.25, 1);
    propAnim->setEndValue(0);
    propAnim->setEasingCurve(QEasingCurve::InOutExpo);
}

/** Creates a SplashScreen object.
 *
 * The main purpose of this is to set up the animation curve that the splash screen will follow.
 *
 * It will fade out using an InOutExpo easing curve to modify its opacity.
 *
 * In addition, the message font and font size is set.
 */
void SplashScreen::showEvent(QShowEvent *) {
    qDebug() << "SHOW EVENT";
    this->showMessage("\n\nLoading...", Qt::AlignCenter, Qt::white);
    propAnim->start(QPropertyAnimation::DeleteWhenStopped);
}
