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
    range[0] = 38;
    range[1] = 42;
    qDebug() << "Initalizating Fluid Sim...";
    this->setGeometry(0, 0, 1920, 1080);
    this->setStyleSheet("background-image:url(:/img/assets/img/fluid.png)");
    wShadow = new QWidget(this);
    dShadow = new QGraphicsDropShadowEffect();
    dShadow->setBlurRadius(10);
    dShadow->setColor(QColor(0,121,52));
    dShadow->setOffset(0, 0);
    wShadow->setGeometry(20, 20, 1880, 880);
    wShadow->setGraphicsEffect(dShadow);

    plot = new QCustomPlot(this);
    QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
    timeTicker->setTimeFormat("%s");
    plot->setGeometry(1000, 910, 400, 150);

    plot->addGraph();
    plot->graph(0)->setPen(QPen(QColor(232, 76, 50)));
    plot->graph(0)->setAntialiasedFill(false);
    plot->graph(0)->setLineStyle(QCPGraph::lsLine);

    plot->addGraph();
    plot->graph(1)->setPen(QPen(QColor(25, 49, 81)));
    plot->graph(1)->setAntialiasedFill(false);
    plot->graph(1)->setLineStyle(QCPGraph::lsLine);

    plot->xAxis->setTicker(timeTicker);
    plot->axisRect()->setupFullAxesBox();
    plot->yAxis->setRange(30, 50);
    plot->xAxis->setRange(0,100);
    plot->yAxis->setVisible(true);
    plot->xAxis->setVisible(false);
    plot->yAxis2->setVisible(false);
    plot->yAxis->setTicks(true);
    plot->xAxis2->setTicks(false);
    plot->plotLayout()->insertRow(0);
    plot->plotLayout()->addElement(0,0, new QCPTextElement(plot, "Temperature \u00b0C"));

    connect(&timer, &QTimer::timeout, this, &Fluid::redraw_plot);
}

/** Start simulation. 
 *
 * For a deeper dive into how this app gets the simulation into this class,
 * see the Simulation page.
 */
void Fluid::StartSim() {
    isActive = true;
    qDebug() << "Starting Fluid Sim...";
    int test = system("nohup ./particles &");

    loadingPoint:
    this_thread::sleep_for(dura);
    unsigned int kWID = Simulation::GetStdoutFromCommand("wmctrl -l | grep 'CUDAParticles' | awk '{print $1}'");
	if (kWID > 1000) {
		qDebug() << "Particles WID: " << kWID;
	} else {
		qDebug() << "Failed To Get kWID... Trying again";
		goto loadingPoint;
	}
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

void Fluid::InitThread() {
    timer.start(100);
}

void Fluid::redraw_plot() {
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

        plot->graph(0)->addData(key, (double)cpu_data);
        plot->graph(1)->addData(key, (double)gpu_data);
        lastPointKey = key;
    }

    plot->xAxis->setRange(key, 8, Qt::AlignRight);
    plot->yAxis->setRange(range[0] + 2, range[1] + 2);
    plot->replot();
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
    delete plot;
    delete wShadow;
    delete dShadow;
}
