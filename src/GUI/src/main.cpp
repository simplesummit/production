#include <QSplashScreen>
#include <QApplication>
#include <QQmlApplicationEngine>
#include <QGuiApplication>
#include <QTimer>

#include "stack.h"
#include "splashscreen.h"


using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Stack s;
    s.show();
    QTimer::singleShot(4500, &s, &Stack::EndSplash);
    a.processEvents();

    return a.exec();
}

