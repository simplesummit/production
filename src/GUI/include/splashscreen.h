#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

#include <QSplashScreen>
#include <QPropertyAnimation>

class SplashScreen : public QSplashScreen
{
    Q_OBJECT
public:
    explicit SplashScreen(const QPixmap &pixmap);
    void showEvent(QShowEvent *);

private:
    QPropertyAnimation *propAnim; //!< Fade-Out Animation
signals:

public slots:
};

#endif // SPLASHSCREEN_H
