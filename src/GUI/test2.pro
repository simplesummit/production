######################################################################
# Automatically generated by qmake (3.1) Wed Jun 26 11:46:48 2019
######################################################################

TEMPLATE = app
TARGET = GUI
INCLUDEPATH += include
DESTDIR = ../bin
OBJECTS_DIR = .
MOC_DIR = .

# The following define makes your compiler warn you if you use any
# feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
# Input
QT += quick gui widgets gamepad charts
# QT += quick gui widgets gamepad
HEADERS += \
    include/datatypes.h \
    include/homepage.h \
    include/stack.h \
    include/smoke.h \
    include/fluid.h \
    include/simulation.h \
    include/splashscreen.h \
    include/paint.h
FORMS += \
    assets/ui/homepage.ui
SOURCES += \
    src/homepage.cpp \
    src/main.cpp \
    src/stack.cpp \
    src/smoke.cpp \
    src/fluid.cpp \
    src/splashscreen.cpp \
    src/paint.cpp
RESOURCES += \
    mw_img.qrc
