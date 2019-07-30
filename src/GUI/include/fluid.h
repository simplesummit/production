#ifndef FLUID_H
#define FLUID_H

#include "simulation.h"
#include "qcustomplot.h"

#include <QGraphicsDropShadowEffect>
#include <QWidget>
#include <QWindow>
#include <QPainter>
#include <QStyleOption>

#include <chrono>
#include <string>

using namespace std;

class Fluid : public QWidget, public Simulation
{
    Q_OBJECT
public:
    explicit Fluid(QWidget *parent = nullptr);
    ~Fluid();
    void StartSim();
    void EndSim();
    void paintEvent(QPaintEvent *);
    void InitThread();

    unsigned int pgID = 0x03; //!< Page ID

private:
    QWindow *m_window; //!< Window the simulation is routed to
    QWidget *qw; //!< Container for m_window
    QWidget *wShadow; //!< Widget for drop shadow
    QGraphicsDropShadowEffect *dShadow;
    QStyleOption option; //!< Overrides the QWidget's style for custom background.
    QRect pos; //!< Global Position
    QTimer timer; //!< Periodical timer to redraw the plot
    QCustomPlot* plot; //!< Temperature graph

    bool isActive; //!< Simulation Status
    std::chrono::milliseconds dura{1000}; //!< Pause for the simulation.
    float gpu_data; //!< Buffer for GPU Temperature
    float cpu_data; //!< Buffer for CPU Temperature
    float range[2];

signals:

public slots:
    void redraw_plot();
};

#endif // FLUID_H
