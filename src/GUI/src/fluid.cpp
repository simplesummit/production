/*! \class Fluid
 *  \brief The main fluid simulation class that the user interacts with.
 *  \author    Tyler Duckworth
 *  \date      2019
 *  \copyright BSD 3-Clause "New" or "Revised" License
 *
 *  Inheriting from the Simulation class, Fluid follows the same process
 *  of embedding its own window in the application, seen here.
*/
#include "fluid.h"

#include <QDebug>
#include <QGraphicsDropShadowEffect>

#include <stdio.h>
#include <iostream>
#include <unistd.h>
#include <thread>

/**  Create a Fluid element
 * \param parent Element for Fluid to be under. (Optional)
 * 
 * Sets the geometry for the page to be 1080p. (Subject to change)
 *
 * Pairs the UI template with this page.
 *
 * NOTE: Could remove .ui file completely and use instead a pixmap 
 * as the background.
 */
Fluid::Fluid(QWidget *parent) : QWidget(parent)
{

    qDebug() << "Initalizating Fluid Sim...";
    this->setGeometry(0, 0, 1920, 1080);
    this->setStyleSheet("background-image:url(:/img/assets/img/fluid.png)");
    QWidget *test = new QWidget(this);
    QGraphicsDropShadowEffect *dShadow = new QGraphicsDropShadowEffect();
    dShadow->setBlurRadius(10);
    dShadow->setColor(QColor(0,121,52));
    dShadow->setOffset(0, 0);
    test->setGeometry(20, 20, 1880, 880);
    test->setGraphicsEffect(dShadow);
}

/** Start simulation. 
 *
 * For a deeper dive into how this app gets the simulation into this class,
 * see the Simulation page.
 */
void Fluid::StartSim() {
    isActive = true;
    qDebug() << "Starting Fluid Sim...";
    int test = system("nohup ../../../bin/particles &");
    qDebug() << test;
    this_thread::sleep_for(dura);
    unsigned int kWID = Simulation::GetStdoutFromCommand("wmctrl -l | grep 'CUDAParticles' | awk '{print $1}'");
     qDebug() << "Smoke WID: " << kWID;
    m_window = QWindow::fromWinId(kWID);
    m_window->setFlags(Qt::FramelessWindowHint);
    qw = QWidget::createWindowContainer(m_window);
    qw->setGeometry(20,20,1880,880);
    qw->setParent(this);
}

/**  End simulation */
void Fluid::EndSim() {
    isActive = false;
    qw = nullptr;
    m_window = nullptr;
}

/** Repaint the canvas
 *
 * Sets the settings of the canvas to allow for background-image.
 */
void Fluid::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    option.init(this);
    style()->drawPrimitive(QStyle::PE_Widget, &option, &painter, this);
}
Fluid::~Fluid() {
    delete qw;
    delete m_window;
}
