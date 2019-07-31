/*! \class Graph
 *  \brief Temperature graph class for CPU and GPU.
 *  \author    Tyler Duckworth
 *  \date      2019
 *  \copyright BSD 3-Clause "New" or "Revised" License
 *
 *  Inherits from QCustomPlot. The main goal of this is to consolidate the code for the graph in each simulation to have  more readable codebase.
 *
 *  Sets up the styles for both "graphs" and includes methods to plot points and update the y-axis.
*/

#include "graph.h"

/** Creates a Graph element
 * \param parent Element for the Graph to be a child of.
 *
 * Sets the styles, creates the GPU and CPU lines, and sizes the graph.
 */
Graph::Graph(QWidget *parent)
{
    this->setParent(this);
    this->setGeometry(1000, 910, 400, 150);
    QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
    timeTicker->setTimeFormat("%s");
    this->addGraph();
    this->graph(0)->setPen(QPen(QColor(232, 76, 50)));
    this->graph(0)->setAntialiasedFill(false);
    this->graph(0)->setLineStyle(QCPGraph::lsLine);

    this->addGraph();
    this->graph(1)->setPen(QPen(QColor(25, 49, 81)));
    this->graph(1)->setAntialiasedFill(false);
    this->graph(1)->setLineStyle(QCPGraph::lsLine);

    this->xAxis->setTicker(timeTicker);
    this->axisRect()->setupFullAxesBox();
    this->yAxis->setRange(30, 50);
    this->xAxis->setRange(0,100);
    this->yAxis->setVisible(true);
    this->xAxis->setVisible(false);
    this->yAxis2->setVisible(false);
    this->yAxis->setTicks(true);
    this->xAxis2->setTicks(false);
    this->plotLayout()->insertRow(0);
    this->plotLayout()->addElement(0,0, new QCPTextElement(this, "Temperature \u00b0C"));
}

/** Sets the x-axis dynamically to allow it to move with time.
 * \param time Current timestamp to add to the domain.
 */
void Graph::setXRange(double time) {
    this->xAxis->setRange(time, 8, Qt::AlignRight);
}

/** Sets the range to dynamically process with the input.
 * \param arr Array of minimum and maximum value across CPU and GPU.
 */
void Graph::setYRange(float arr[]) {
    this->yAxis->setRange(arr[0] + 2, arr[1] + 2);
}

/** Plots the new data on both graphs.
 * \param key Timestamp for the x-value of the points.
 * \param cpu Temperature for the CPU in degrees Celsius.
 * \param gpu Temperature for the GPU in degrees Celsius.
 *
 * For more info on how the program reads temperature, refer to the page in the documentation.
 */
void Graph::plot(double key, float cpu, float gpu) {
    this->graph(0)->addData(key, (double)cpu);
    this->graph(1)->addData(key, (double)gpu);
}

Graph::~Graph() {

}
