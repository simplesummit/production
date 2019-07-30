#ifndef PARTICLES_H
#define PARTICLES_H

#include "simulation.h"
#include "qcustomplot.h"

#include <QGraphicsDropShadowEffect>
#include <QStyleOption>
#include <QWidget>
#include <QWindow>
#include <QThread>
#include <QtCharts>

#include <string>

using namespace std;
using namespace QtCharts;

class Smoke : public QWidget, public Simulation
{
    Q_OBJECT
public:
    explicit Smoke(QWidget *parent = nullptr);
    ~Smoke();
    void StartSim();
    void EndSim();
    void paintEvent(QPaintEvent *);
    void InitThread();
    void update_cpu();
    void update_gpu();

    unsigned int pgID = 0x02; //!< Page ID

private:
    QWindow *m_window; //!< Window the simulation is routed to
    QWidget *qw; //!< Container for m_window
    QWidget *wShadow; //!< Widget for drop shadow
    QGraphicsDropShadowEffect *dShadow; //!< Drop Shadow Effect
    QStyleOption option; //!< Overrides the QWidget's style for custom background.
    QRect pos; //!< Global Position
    QTimer timer; //!< Periodical timer to redraw the plot
    QCustomPlot* plot; //!< Temperature graph

    bool isActive; //!< Simulation Status
    chrono::milliseconds dura{1000}; //!< Pause for simulation.
    float gpu_data; //!< Buffer for GPU Temperature
    float cpu_data; //!< Buffer for CPU Temperature
    float range[2];

signals:

public slots:
    void redraw_plot();
};

#endif // PARTICLES_H
