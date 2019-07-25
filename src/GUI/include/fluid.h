#ifndef FLUID_H
#define FLUID_H

#include "simulation.h"

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

    unsigned int pgID = 0x03; //!< Page ID

private:
    QWindow *m_window; //!< Window the simulation is routed to
    QWidget *qw; //!< Container for m_window
    QStyleOption option; //!< Overrides the QWidget's style for custom background.


    bool isActive; //!< Simulation Status
    std::chrono::milliseconds dura{120}; //!< Pause for the simulation.

signals:

public slots:
};

#endif // FLUID_H
