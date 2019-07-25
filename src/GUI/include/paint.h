#ifndef PAINT_H
#define PAINT_H

#include "simulation.h"

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
    void StartSim();
    void EndSim();
    void paintEvent(QPaintEvent *);

    unsigned int pgID = 0x03; //!< Page ID

private:
    QWindow *m_window; //!< Window the simulation is routed to
    QWidget *qw; //!< Container for m_window
    QStyleOption option; //!< Overrides the QWidget's style for custom background.

    bool isActive; //!< Simulation Status
    chrono::milliseconds dura{1000}; //!< Pause for simulation.

signals:

public slots:
};

#endif // PAINT_H
