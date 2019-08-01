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
#include <QtCharts>
#include <QThread>

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
    range[0] = 25;
    range[1] = 42;
    pos = QRect(20,20,1880,880);
    qDebug() << "Initalizating Smoke Sim...";
    this->setGeometry(0, 0, 1920, 1080);
    this->setStyleSheet("background-image:url(:/img/assets/img/smoke.png)");
    wShadow = new QWidget(this);
    dShadow = new QGraphicsDropShadowEffect();
    dShadow->setBlurRadius(10);
    dShadow->setColor(QColor(0,121,52));
    dShadow->setOffset(0, 0);
    wShadow->setGeometry(pos);
    wShadow->setGraphicsEffect(dShadow);

    graph = new Graph(this);
    connect(&timer, &QTimer::timeout, this, &Smoke::redrawPlot);
}

/** Start simulation. 
 *
 * For a deeper dive into how this app gets the simulation into this class,
 * see the Simulation page.
 */

void Smoke::startSim() {
    isActive = true;
    int test = system("nohup ./smokeParticles &");
    Q_ASSERT(test >= 0);

    loadingPoint:
    this_thread::sleep_for(dura);
    unsigned int kWID = Simulation::readCommand("wmctrl -l | grep 'Smoke' | awk '{print $1}'");

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
void Smoke::endSim() {
    isActive = false;
    qw = nullptr;
    m_window = nullptr;
}

/** Start plotting the temperature */
void Smoke::startPlot() {
    timer.start(100);
}

/** Get update values, and update the graph's content and y-axis. */
void Smoke::redrawPlot() {
    cpu_data = Simulation::update_cpu();
    gpu_data = Simulation::update_gpu();
    if(gpu_data > range[1]) {
        range[1] = gpu_data;
    } else if(cpu_data > range[1]) {
        range[1] = cpu_data;
    }
    if(gpu_data < range[0]) {

        range[0] = gpu_data;
    } else if(cpu_data < range[0]) {
        range[0] = cpu_data;
    }
    static QTime time(QTime::currentTime());
    double key = time.elapsed()/1000.0;
    static double lastPointKey = 0;
    if(key - lastPointKey > 0.002) {
	
	graph->plot(key, cpu_data, gpu_data);
        lastPointKey = key;
    }

    graph->setXRange(key);
    graph->setYRange(range);
    graph->replot();
}

Smoke::~Smoke() {
    delete qw;
    delete m_window;
    delete wShadow;
    delete dShadow;
    delete graph;
}
