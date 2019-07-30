/*! \class Stack
 *  \brief The hub for all application pages.
 *  \author    Tyler Duckworth
 *  \date      2019
 *  \copyright BSD 3-Clause "New" or "Revised" License
 *
 * Stack inherits from QStackedWidget, which allows it to hold multiple
 * widgets simultaneously. The widget on "top" is chosen by selecting its
 * id and is the one visible to the user.
 */

#include "stack.h"
#include "homepage.h"
#include "smoke.h"
#include "paint.h"

#include <QStackedWidget>
#include <QtGamepad/QGamepad>
/**  Create a Stack element
 * \param parent Element for Stack to be under. (Optional)
 *
 * showFullScreen() maximizes the application to enable full usage of
 * the screen.
 *
 * Contains only five connect statements in the entire application
 * and the only QGamepad object, as to remove any confusion at
 * runtime and to allow for the abstraction of slots specific to child
 * widgets.
 */
Stack::Stack(QWidget *parent) : QStackedWidget(parent)
{
    auto gamepads = QGamepadManager::instance()->connectedGamepads();
    if (gamepads.isEmpty()) {
        return;
    }
    m_gamepad = new QGamepad(*gamepads.begin(), this);    pos = QRect(20,20,1880,880);
    showFullScreen();
    QPixmap pixmap(":/img/assets/img/splash.png");
    splash = new SplashScreen(pixmap);
    homePage = new HomePage(m_gamepad);
    simSmoke = new Smoke;
    simFluid = new Fluid;
    paint = new Paint;
    //view = new QWebEngineView(this);

    idSplash = this->addWidget(splash);
    idHomePage = this->addWidget(homePage);
    idSmoke = this->addWidget(simSmoke);
    idFluid = this->addWidget(simFluid);
    idPaint = this->addWidget(paint);
    destination = homePage->activePage();

    /*-------- SLOTS --------*/
    connect(m_gamepad, &QGamepad::buttonAChanged, this, &Stack::openPage);
    connect(m_gamepad, &QGamepad::buttonBChanged, this, &Stack::closePage);
    connect(m_gamepad, &QGamepad::buttonGuideChanged, this, &Stack::closeApp);
    connect(m_gamepad, &QGamepad::axisLeftXChanged, homePage, &HomePage::getLeftX);
    connect(m_gamepad, &QGamepad::axisLeftYChanged, homePage, &HomePage::getLeftY);
    connect(this, &Stack::currentChanged, this, &Stack::prepareNewPage);
    this->setStyleSheet("background-color: black");

}

/** Change the visible page.
 * \param _isChanged Status of button. (True is pushed)
 *
 * The function gets the destination from HomePage and sets that to be the active page.
 *
 * In the case of the smoke and fluid simulations, it needs to run the StartSim() method to start (or restart) the process of embedding the simulation in the window.
 */
void Stack::openPage(bool _isChanged) {
    if(_isChanged) {
        if(this->currentIndex() == idFluid || this->currentIndex() == idSmoke) {
            this->setCurrentIndex(idHomePage);
        } else {
            int destination = homePage->activePage();
            if(destination == 2) {
                simSmoke->StartSim();
                this->setCurrentIndex(idSmoke);
            } else if(destination == 3) {
                simFluid->StartSim();
                this->setCurrentIndex(idFluid);
            } else if(destination == 4) {
                paint->StartSim();
                this->setCurrentIndex(idPaint);
            }
        }
    }
}

/** Return to previous screen.
 * \param _isChanged Status of button. (True is pushed)
 *
 * If the current page is not the HomePage, the slot switches back to the HomePage.
 *
 * This is about as deep as the navigation goes currently.
 */
void Stack::closePage(bool _isChanged) {

    if(_isChanged) {
        if(this->currentIndex() == idSmoke) {
            system("killall smokeParticles");
            this->setCurrentIndex(idHomePage);
        } else if(this->currentIndex() == idFluid) {
            system("killall particles");
            this->setCurrentIndex(idHomePage);
        } else if(this->currentIndex() == idPaint) {
            system("killall chromium-browser");
            this->setCurrentIndex(idHomePage);
        }
    }
}

/**  Exit the application.
 *  \param _isChanged Status of button. (True is pushed)
 */
void Stack::closeApp(bool _isChanged) {
    if(_isChanged) {
        QApplication::exit();
    }
}

/** Update the potential destination.
 *
 * Sets the destination to the selected page when a new pages
 * is selected.
 */
void Stack::paintEvent(QPaintEvent *) {
    if(this->currentIndex() != homePage->activePage()) {
        destination = homePage->activePage();
    }
}

/** Activates necessary methods to allow the page to run smoothly.
 * \param index Index for the new page
 *
 * Meant to prepare the threads for the CPU and GPU processing.
 */
void Stack::prepareNewPage(int index) {
    switch(index) {
        case 1:
            qDebug() << "HOMEPAGE";
        break;
        case 2:
            qDebug() << "SMOKE";
            simSmoke->InitThread();
        break;
        case 3:
            qDebug() << "FLUID";
        break;
        case 4:
            qDebug() << "ML";
        break;
        default:
            qDebug() << "ERROR";
        break;
    }
}

/** Closes splashscreen. */
void Stack::EndSplash() {
    this->setCurrentIndex(idHomePage);
}

Stack::~Stack() {
    delete simSmoke;
    delete homePage;
    delete simFluid;
}
