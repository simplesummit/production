#ifndef GRAPH_H
#define GRAPH_H

#include "qcustomplot.h"

class Graph : public QCustomPlot
{
    Q_OBJECT
public:
    explicit Graph(QWidget *parent = nullptr);
    ~Graph();
    void setYRange(float arr[]);
    void setXRange(double time);
    void plot(double key, float cpu, float gpu);
};

#endif // GRAPH_H
