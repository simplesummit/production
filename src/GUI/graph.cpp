#include "graph.h"

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

void Graph::setXRange(double time) {
    this->xAxis->setRange(time, 8, Qt::AlignRight);
}
void Graph::setYRange(float arr[]) {
    this->yAxis->setRange(arr[0] + 2, arr[1] + 2);
}
void Graph::plot(double key, float cpu, float gpu) {
    this->graph(0)->addData(key, (double)cpu);
    this->graph(1)->addData(key, (double)gpu);
}

Graph::~Graph() {

}
