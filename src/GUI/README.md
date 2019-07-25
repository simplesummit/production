# Leconte

A GUI application to run on Leconte, an outreach machine for the Oak Ridge National Laboratory. Enables the user to select and play three different simulations: A Smoke Simulation, a 3D Particle Simulation, and a Machine Learning drawing game. For more info on the specifics of these simulations, see this project's documentation.

## Installation

### Platforms

This app was created on, and runs on, an NVIDIA Jetson TX2, a ARM-64 board with a GPU. Because of the architecture, developing it required some platform-specific configuration. 

### Libraries

Leconte was created with Qt5, an open-source C++ GUI library used in many popular applications. 
To download it manually, see Qt's Wiki.
For [Windows](https://doc.qt.io/qt-5/windows.html) and [Mac](https://doc.qt.io/qt-5/macos.html), see the linked documentation. (Note: If you have HomeBrew on Mac, you can run ```brew install qt```)

With Linux distros, there is more than likely something available on the installed package manager. 

If you want to build Qt from source (on any platform), see [here](https://doc.qt.io/qt-5/build-sources.html) for details. 

In addition to Qt5, Leconte uses QtGamepad and QtQuick, two addons to Qt. If you installed Qt with an app, you can go back and probably configure it in your installation settings. 

More likely than not, you will be able to find a version available via a package manager. 


### Install On Jetsons

If you are developing/deploying on a Jetson, there are a couple steps you need to go through.
1. Make sure you have the latests version of JetPack and L4T.
2. Run the scripts under the scripts/ folder. 


## Usage
To build the app, make sure you have qmake installed for Qt5. (Run with the ```--version``` flag to find out)
If you do, run ```qmake``` in the home directory.

After this is done, run ```sudo make```. The resulting binary should be named GUI. Run this with a joystick plugged in, and enjoy!

## License

This project is held under the BSD 3-Clause License. See [LICENSE](LICENSE) for more details.

## Collaborators

This project was made possible with the help of:

- The Oak Ridge Leadership Computing Facility (OLCF)
- The National Transportation Research Center (NTRC)
- The L&N STEM Academy

A special thanks to:

- Jim Rogers, our manager for this endeavour.
- Clint LaFollette, our teacher-mentor.
- Brian Smith, our advisor the software of this project.
