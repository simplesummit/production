    #ifndef PARTICLES_H
#define PARTICLES_H

#include "simulation.h"

#include <QGraphicsDropShadowEffect>
#include <QStyleOption>
#include <QWidget>
#include <QWindow>
#include <QtCharts>

#include <chrono>
#include <string>

using namespace std;

class Smoke : public QWidget, public Simulation
{
    Q_OBJECT
public:
    explicit Smoke(QWidget *parent = nullptr);
    ~Smoke();
    void StartSim();
    void EndSim();
    void paintEvent(QPaintEvent *);

    unsigned int pgID = 0x02; //!< Page ID

private:
    QWindow *m_window; //!< Window the simulation is routed to
    QWidget *qw; //!< Container for m_window
    QStyleOption option; //!< Overrides the QWidget's style for custom background.
    QRect pos; //!< Global Position

    bool isActive; //!< Simulation Status
    chrono::milliseconds dura{120}; //!< Pause for simulation.

signals:

public slots:
};

#endif // PARTICLES_H
