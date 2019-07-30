#ifndef STACK_H
#define STACK_H

#include "homepage.h"
#include "smoke.h"
#include "fluid.h"
#include "paint.h"
#include "splashscreen.h"

#include <QStackedWidget>
#include <QtGui>


using namespace std;

class Stack : public QStackedWidget
{
    Q_OBJECT
public:
    explicit Stack(QWidget *parent = nullptr);
    ~Stack();
    void EndSplash();

    QGamepad *m_gamepad; //!< Central object for Logitech F310 gamepad.

private:
    Smoke* simSmoke; //!< Smoke Simulation object
    HomePage* homePage; //!< Homepage object
    Fluid* simFluid; //!< Fluid Simulation object
    SplashScreen* splash; //!< Splashscreen object
    Paint* paint;
    QRect pos; //!< Global Position

    unsigned int destination; //!< Holds current destination. Only used when openPage is called.
    /*-------- IDs: Used for setCurrentIndex --------*/
    int idHomePage; //!< ID for the homepage
    int idSmoke; //!< ID for smoke simulation
    int idFluid; //!< ID for fluid simulation
    int idSplash; //!< ID for splashscreen
    int idPaint;
    //QWebEngineView *view;
protected:
    void paintEvent(QPaintEvent *);
signals:

public slots:
    void openPage(bool _isChanged);
    void closePage(bool _isChanged);
    void closeApp(bool _isChanged);
    void prepareNewPage(int index);
};

#endif // STACK_H
