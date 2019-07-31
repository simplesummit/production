GUI Overview
=========

Leconte runs a user interface that allows visitors to play different simulations and see how they affect the CPU and GPU on the circuit board. Leconte is written in C++ and uses Qt to create the visuals of the application.

## What is Qt?

[Qt](https://www.qt.io/) is a GUI SDK (Software Development Kit) that serves as the base for Leconte's interface. It is used by many professional companies such as Mercedes-Benz, LG, AMD, and Ubuntu to create powerful and efficent applications across a range of devices.

## Organization

Qt is organized mainly into widgets, each with a base of QWidget, that serve purposes as various from reading gamepad input to animating complex. Widgets are organized into hierarchies, with a final parent of QApplication, which runs in the main loop of C++. 

### Signals and Slots

One of the most important things in Qt is the signal-and-slot system which enables communication between Widgets. When something happens in a widget, it can emit a **signal** that is detected by a **slot** in another widget. This allows for responsive behavior throughout the application. You will see this referenced throughout the document with this code:

```cpp
connect(&widget1, &Widget1::signal, &widget2, &Widget2::slot);
```

This line of code connects the signal of `Widget1` to the slot of `Widget2`. This technique is used to great effect throughout the application.

## Leconte's Organization

Leconte is split into a couple different elements. There are five Pages, widgets which hold the contents of what is on the screen. (Including Simulations) There is also the Stack class, where the Pages are combined to create a dynamic navigation environment. 

### Pages

#### HomePage

The HomePage class holds, well, the home screen for the application. It is the most complex part of the application, creating four diffferent interactive cards and executing animations for each one of them. It has some specific Gamepad controls and many slots that are used in the Stack class. 

HomePage also holds the navigation for the application, which is described in more detail here. 

#### SplashScreen

SplashScreen is a wrapper of the QSplashScreen widget. It adds a custom fade-out animation, a background image, and text to show a message. 

This class is the first thing that appears on the monitor when you boot up the application. `main.cpp` uses a [```single-shot QTimer```](https://doc.qt.io/qt-5/qtimer.html#singleShot) that lasts for 4.5 seconds, which matches up with the animation curve of SplashScreen, seen above. 

#### Paint, Smoke, and Fluid

The Paint, Smoke, and Fluid classes are all simulations. All inherit from the Simulation abstract class, which holds the basic building blocks of all the pages. For example, it holds the ```Simulation::update_cpu()``` method, which returns the current CPU temperature. 

Each of the simulations have a graph which displays the CPU and GPU temperature for the system, as to show any change created by the applications. Each graph is an object of the Graph class, which inherits from [QCustomPlot](https://www.qcustomplot.com/). For more info on how Leconte reads the temperature, see here. 

### For more info on the Stack class, see it's dedicated page.