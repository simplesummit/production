/*! \class Smoke 
 *  \brief The main fluid simulation class that the user interacts with.
 *  \author    Tyler Duckworth
 *  \date      2019
 *  \copyright GNU Public License v3
 *
 *  Inheriting from the Simulation class, Fluid follows the same process
 *  of embedding its own window in the application, seen here.
 *
*/

#include "paint.h"
#include "stack.h"
#include "simulation.h"

#include <QDebug>
#include <QPainter>

#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <thread>
#include <unistd.h>

using namespace std;

/**  Create a Smoke element
 * \param parent Element for Smoke to be under. (Optional)
 * 
 * Sets the geometry for the page to be 1080p. (Subject to change)
 *
 * Pairs the UI template with this page.
 *
 * NOTE: Could remove .ui file completely and use instead a pixmap 
 * as the background.
 */
Paint::Paint(QWidget *parent) : QWidget(parent)
{
//    pos = QRect(20,20,1880,880);
    //qDebug() << "Initalizating Smoke Sim...";
    this->setGeometry(0, 0, 1920, 1080);
    /* CHANGE THIS */
    this->setStyleSheet("background-image:url(:/img/assets/img/smoke.png)");
    QWidget *test = new QWidget(this);
    QGraphicsDropShadowEffect *dShadow = new QGraphicsDropShadowEffect();
    dShadow->setBlurRadius(10);
    dShadow->setColor(QColor(0,121,52));
    dShadow->setOffset(0, 0);
    test->setGeometry(20,20,1880,880);
    test->setGraphicsEffect(dShadow);
}

/** Start simulation. 
 *
 * For a deeper dive into how this app gets the simulation into this class,
 * see the Simulation page.
 */
void Paint::StartSim() {
    isActive = true;
    //qDebug() << "Starting Smoke Sim...";
    //qDebug() << test;
    int test = system("chromium-browser --app=http://localhost:8000 --force-device-scale-factor=1.0 --disable-web-security --hide-scrollbars --start-minimized --user-data-dir --window-size=5,5 &");
    this_thread::sleep_for(dura);

    unsigned int kWID = Simulation::GetStdoutFromCommand("wmctrl -l | grep 'localhost' | awk '{print $1}'");
     //qDebug() << "Smoke WID: " << kWID;
    m_window = QWindow::fromWinId(kWID);
    m_window->setFlags(Qt::FramelessWindowHint);
    qw = QWidget::createWindowContainer(m_window);
    qw->setGeometry(20,20,1880,880);
    qw->setParent(this);
}

/** Repaint the canvas
 *
 * Sets the settings of the canvas to allow for background-image.
 */
void Paint::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    option.init(this);
    style()->drawPrimitive(QStyle::PE_Widget, &option, &painter, this);
}

/**  End simulation */
void Paint::EndSim() {
    isActive = false;
    qw = nullptr;
    m_window = nullptr;
}

Paint::~Paint() {
    delete qw;
    delete m_window;
}
