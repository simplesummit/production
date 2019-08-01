Stack
=========

Stack is the central widget for Leconte as a whole. It holds each individual page and the main gamepad object.

## QStackedWidget

Stack inherits from QStackedWidget, a Qt class that enables the widget to hold other widgets and cycle through them visually based on a layer system. The widget at the top of the "stack" is the only one visible. The rest are hidden from view. 

At the beginning, the SplashScreen page is visible, but fades out and the HomePage takes its place. From here, the user cycles through which page is active depending on which card on HomePage they select. 

## Slots

Stack also holds three slots, each of which deal with buttons for the application to use. 

It has `Stack::closeApp()` which closes the application when the guide button is pressed. 

```cpp
void Stack::closeApp(bool _isChanged) {
    if(_isChanged) {
        QApplication::exit();
    }
}
```

`Stack::openPage()` for when the destination needs to be changed, using `HomePage::activePage` to find where to navigate. It also calls `Simulation::startSim()` which helps start the chosen sim in a timely manner. For more info on what it does, see here. 

```cpp
void Stack::openPage(bool _isChanged) {
    if(_isChanged) {
        if(this->currentIndex() == idFluid || this->currentIndex() == idSmoke) {
            this->setCurrentIndex(idHomePage);
        } else {
            int destination = homePage->activePage();
            if(destination == 2) {
                simSmoke->startSim();
                this->setCurrentIndex(idSmoke);
            } else if(destination == 3) {
                simFluid->startSim();
                this->setCurrentIndex(idFluid);
            } else if(destination == 4) {
                paint->startSim();
                this->setCurrentIndex(idPaint);
            }
        }
    }
}
```

Finally, Stack has `Stack::closePage()`, a slot which transitions from the current page back to HomePage. It also kills any remaining background processes from the previous simulation, preventing them from compounding and taking up too much CPU or GPU on the Jetsons. 

```cpp
void Stack::closePage(bool _isChanged) {
    int killall;
    if(_isChanged) {
        if(this->currentIndex() == idSmoke) {
            killall = system("killall smokeParticles");
            this->setCurrentIndex(idHomePage);
        } else if(this->currentIndex() == idFluid) {
            killall = system("killall particles");
            this->setCurrentIndex(idHomePage);
        } else if(this->currentIndex() == idPaint) {
            killall = system("killall chromium-browser");
            this->setCurrentIndex(idHomePage);
        }
        Q_ASSERT(killall >= 0);
    }
}
```

## Future

I would like to add transitions in this class to allow for a cleaner user experience and more fleshed out application. This place seems the perfect one to do it. 