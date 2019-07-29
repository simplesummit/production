/*! \class Smoke 
 *  \brief The main fluid simulation class that the user interacts with.
 *  \author    Tyler Duckworth
 *  \date      2019
 *  \copyright BSD 3-Clause "New" or "Revised" License
 *
 *  Inheriting from the Simulation class, Fluid follows the same process
 *  of embedding its own window in the application, seen here.
 *
*/

#include "smoke.h"
#include "stack.h"

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
Smoke::Smoke(QWidget *parent) : QWidget(parent)
{
    pos = QRect(20,20,1880,880);
    qDebug() << "Initalizating Smoke Sim...";
    this->setGeometry(0, 0, 1920, 1080);
    this->setStyleSheet("background-image:url(:/img/assets/img/smoke.png)");
    QWidget *test = new QWidget(this);
    QGraphicsDropShadowEffect *dShadow = new QGraphicsDropShadowEffect();
    dShadow->setBlurRadius(10);
    dShadow->setColor(QColor(0,121,52));
    dShadow->setOffset(0, 0);
    test->setGeometry(pos);
    test->setGraphicsEffect(dShadow);
}

/** Start simulation. 
 *
 * For a deeper dive into how this app gets the simulation into this class,
 * see the Simulation page.
 */

void Smoke::StartSim() {
    isActive = true;
    qDebug() << "Starting Smoke Sim...";
    int test = system("nohup ./smokeParticles &");
    qDebug() << test;
    loadingPoint:
    this_thread::sleep_for(dura);
    unsigned int kWID = Simulation::GetStdoutFromCommand("wmctrl -l | grep 'Smoke' | awk '{print $1}'");
	std::cout << kWID << "\n";
	if (kWID > 1000) {
		qDebug() << "Smoke WID: " << kWID;
	} else {
		qDebug() << "Failed To Get kWID... Trying again";
		goto loadingPoint;
	}
    m_window = QWindow::fromWinId(kWID);
    m_window->setFlags(Qt::FramelessWindowHint);
    qw = QWidget::createWindowContainer(m_window);
    qw->setGeometry(pos);
    qw->setParent(this);
}

/** Repaint the canvas
 *
 * Sets the settings of the canvas to allow for background-image.
 */
void Smoke::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    option.init(this);
    style()->drawPrimitive(QStyle::PE_Widget, &option, &painter, this);
}

/**  End simulation */
void Smoke::EndSim() {
    isActive = false;
    qw = nullptr;
    m_window = nullptr;
}

Smoke::~Smoke() {
    delete qw;
    delete m_window;
}
