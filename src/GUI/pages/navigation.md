Navigation
=========

The HomePage class houses the main slots that convert gamepad input into noticable interactions on the UI. 

The gamepad's left joystick is used to navigate, like many other applications that use gamepad input. Since Leconte uses signals and slots, HomePage uses two signals emitted by the Gamepad: `QGamepad::axisLeftXChanged()` and  `QGamepad::axisLeftXChanged()`. 


## The Math

There are four cards on the HomePage, arranged with one at the top and three in a row at the bottom. To see which card is selected, we needed to calculate the rotation of the joystick, a process we achieved by using some trigonometry. 

Take, for instance, the method used in `HomePage::getLeftY`:
```cpp
#include <cmath>
...
void HomePage::getLeftY(double value) {
value = round(value) * -1;
double lx_axis = round(m_gamepad->axisLeftX());
double deg = round(std::atan2(value, lx_axis) * 180 / PI);
...
}
```

As you can see, the function gets the joystick input, rounds it, and uses it along with the x-axis in arctan2, which gives the complete angle of rotation. After converting this to radians, the function then processes it, calculating which card it is selecting.

```cpp
if(deg > -145 && deg < -125) {
    state = ST_SM_LFT;
    activeCard = "l_small_box";
} else if(deg > -100 && deg < -80) {
    state = ST_SM_MID;
    activeCard = "m_small_box";
} else if(deg > -55 && deg < -35) {
    state = ST_SM_RGT;
    activeCard = "r_small_box";
} else {
    activeCard = "m_large_box";
    state = ST_LG_CARD;
}
```

`state` is an enumerated type of each card and `activeCard` is used in `HomePage::paintEvent` to apply a green drop shadow to the active card. 

## Hover Effect

Along with a green drop shadow, the highlighted card also is raised 18 pixels to further emphasize its active state. This is done with the help of QPropertyAnimation, an animation effect in Qt that has a custom start and end value. 

There were a couple issues when first implementing this. For one, the cards would not return to their original place on release, so a base animation state was created. Secondly, the cards could be manipulated into continually raising, giving the top card the ability to be completely raised above the screen. To fix this, the base animation state was modified to force it to check the position of the card. 

This fixed the issues, but caused there to be a jarring fall of the cards whenever the joystick was released. 

## The Complication

Since there are four main cards can select, the HomePage needs to process changes in both the x-axis and y-axis. Since both of the signals fire at the same time, it is difficult to get a complete measurement without relying on just one. Because of this, there are som odd samples that occur with rotating rapidly. This produces a glitchly effect in the HomePage with both the drop shadow and the raising effect. 


## The Future

Both the drop shadow and raising effect bugs need to be fixed. A rethink in how the navigation works may be in order. 