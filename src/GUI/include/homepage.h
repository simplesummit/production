#ifndef HOME_PAGE_H
#define HOME_PAGE_H

#include "datatypes.h"
#include "ui_homepage.h"

#include <QtGamepad/QGamepad>
#include <QGraphicsDropShadowEffect>
#include <QtGui>
#include <QList>
#include <QPropertyAnimation>
#include <QWidget>

class HomePage : public QWidget
{
    Q_OBJECT
public:
    explicit HomePage(QGamepad *gamepad, QWidget *parent = nullptr);
    ~HomePage();

    int activePage();
    unsigned int pgID = 0x01; //!< Page ID

private:
    // Non-Qt Variables
    Ui::HomePage* ui; //!< Qt-generated class for UI template.
    State state; //!< Custom enum for determining current card.
    bool isPressed = false; //!< State of button
    std::string activeCard = "m_large_box"; //!< Name of selected card.
    std::string prevCard; //!< Name of previous card.
    std::string childName; //!< Temporary variable for paintEvent()
    QSize lg_card;
    QSize sm_card;
    int lg_x1, lg_x2, lg_x3, sm_x1, sm_x2, sm_x3;
    const double p0 = 0.10;
    const double p1 = 0.540;
    const double p2 = 0.1760;
    const double p3 = 0.6574;

    // Qt Variables
    QGamepad* m_gamepad; //!< 2nd Gamepad object (To be deleted)
    QGraphicsDropShadowEffect *dShadow; //!< Drop shadow effect for cards.
    QPropertyAnimation* animation; //!< Hover animation for active card.
    QList<QPropertyAnimation *> animationList; //!< List of default position animations for cards.
    QList<QWidget *> children; //!< List of child cards.
    QWidget *activeCardObj; //!< Placeholder for active card in getLeftY()
    QColor dShadowColor; //!< Color object

protected:
    void paintEvent(QPaintEvent *event);

signals:

public slots:
    void getYButton(bool _isPressed);
    void getLeftX(double value);
    void getLeftY(double value);

};

#endif // HOME_PAGE_H
