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
    range[0] = 38;
    range[1] = 42;
//    pos = QRect(20,20,1880,880);
    qDebug() << "Initalizating NeuralPaint...";
    this->setGeometry(0, 0, 1920, 1080);
    /* CHANGE THIS */
    this->setStyleSheet("background-image:url(:/img/assets/img/smoke.png)");
    wShadow = new QWidget(this);
    dShadow = new QGraphicsDropShadowEffect();
    dShadow->setBlurRadius(10);
    dShadow->setColor(QColor(0,121,52));
    dShadow->setOffset(0, 0);
    wShadow->setGeometry(20,20,1880,880);
    wShadow->setGraphicsEffect(dShadow);

    plot = new QCustomPlot(this);
    plot->setBackground(QBrush(QColor("#3D3D3D")));
    QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
    timeTicker->setTimeFormat("%s");
    plot->setGeometry(1000, 910, 400, 150);

    plot->addGraph();
    plot->graph(0)->setPen(QPen(QColor("#E82D13")));
    plot->graph(0)->setAntialiasedFill(false);
    plot->graph(0)->setLineStyle(QCPGraph::lsLine);

    plot->addGraph();
    plot->graph(1)->setPen(QPen(QColor("#498FEB")));
    plot->graph(1)->setAntialiasedFill(false);
    plot->graph(1)->setLineStyle(QCPGraph::lsLine);

    plot->xAxis->setTicker(timeTicker);
    plot->yAxis->setTickLabelColor(Qt::white);
    plot->yAxis->setBasePen(QPen(Qt::white));
    plot->yAxis->setLabelColor(Qt::white);
    plot->yAxis->setTickPen(QPen(Qt::white));
    plot->yAxis->setSubTickPen(QPen(Qt::white));
    plot->xAxis2->setBasePen(QPen(Qt::white));
    plot->axisRect()->setupFullAxesBox();
    plot->yAxis->setRange(30, 50);
    plot->xAxis->setRange(0,100);
    plot->yAxis->setVisible(true);
    plot->xAxis->setVisible(false);
    plot->yAxis2->setVisible(false);
    plot->yAxis->setTicks(true);
    plot->xAxis2->setTicks(false);
    plot->plotLayout()->insertRow(0);
    QCPTextElement* txt = new QCPTextElement(plot, "Temperature \u00b0C");
    txt->setTextColor(Qt::white);
    plot->plotLayout()->addElement(0,0, txt);

    connect(&timer, &QTimer::timeout, this, &Paint::redraw_plot);
}

/** Start simulation. 
 *
 * For a deeper dive into how this app gets the simulation into this class,
 * see the Simulation page.
 */
void Paint::StartSim() {
    isActive = true;
    int test = system("chromium-browser --app=http://localhost:8000 --force-device-scale-factor=1.0 --disable-web-security --hide-scrollbars --start-minimized --user-data-dir --window-size=5,5 &");

    loadingPoint:
    this_thread::sleep_for(dura);
    unsigned int kWID = Simulation::GetStdoutFromCommand("wmctrl -l | grep 'localhost' | awk '{print $1}'");
    if (kWID > 1000) {
        qDebug() << "NeuralPaint WID: " << kWID;
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

/** Start plotting the temperature */
void Paint::startPlot() {
    timer.start(100);
}

/** Get update values, and update the graph's content and y-axis. */
void Paint::redraw_plot() {
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

Paint::~Paint() {
    delete qw;
    delete m_window;
}
