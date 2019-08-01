#ifndef PAINT_H
#define PAINT_H

#include "simulation.h"
#include "qcustomplot.h"
#include "graph.h"

#include <QGraphicsDropShadowEffect>
#include <QStyleOption>
#include <QWidget>
#include <QWindow>

#include <chrono>
#include <string>

using namespace std;

class Paint : public QWidget, public Simulation
{
    Q_OBJECT
public:
    explicit Paint(QWidget *parent = nullptr);
    ~Paint();
    void startSim();
    void endSim();
    void paintEvent(QPaintEvent *);
    void startPlot();

    unsigned int pgID = 0x04; //!< Page ID

private:
    QWindow *m_window; //!< Window the simulation is routed to
    QWidget *qw; //!< Container for m_window
    QStyleOption option; //!< Overrides the QWidget's style for custom background.
    QWidget *wShadow; //!< Widget for drop shadow
    QGraphicsDropShadowEffect *dShadow; //!< Drop Shadow Effect
    QRect pos; //!< Global Position
    QTimer timer; //!< Periodical timer to redraw the plot
    Graph* graph; //!< Temperature graph

    bool isActive; //!< Simulation Status
    chrono::milliseconds dura{100}; //!< Pause for simulation
    float gpu_data; //!< Buffer for GPU Temperature
    float cpu_data; //!< Buffer for CPU Temperature
    float range[2]; //!< Holds minimum and max for the graph

signals:

public slots:
    void redrawPlot();
};

#endif // PAINT_H
