Gamepad
=========

A user interacts with Leconte through a Logitech Gamepad F310 controller. Detecting and using the unique inputs of a controller was a challenge, but one that we overcame. 

## QGamepad

Qt has its own library for reading gamepad input called [QGamepad](https://doc.qt.io/qt-5/qgamepad.html). Leconte uses this to parse input and navigate. 

QGamepad is mostly used in `stack.cpp`:
```cpp 
#include <QtGamepad/QGamepad>
...
auto gamepads = QGamepadManager::instance()->connectedGamepads();
if (gamepads.isEmpty()) {
    return;
}
m_gamepad = new QGamepad(*gamepads.begin(), this);  
```

This code instantiates the gamepad, using QGamepadManager to see if there are any gamepads plugged in. To share input between widgets, Stack uses the signal-and-slot system from Qt. 

Here are two examples:
```cpp
connect(m_gamepad, &QGamepad::buttonGuideChanged, this, &Stack::closeApp);
connect(m_gamepad, &QGamepad::axisLeftXChanged, homePage, &HomePage::getLeftX);
```

The first example shows a button change. When the Guide button (the home button) is pressed or released, a boolean is emitted, indicating the state the button has. Stack has a slot to parse this an end the application.

```cpp
/**  Exit the application.
 *  \param _isChanged Status of button. (True is pushed)
 */
void Stack::closeApp(bool _isChanged) {
    if(_isChanged) {
        QApplication::exit();
    }
}
```

The second example shows an axis change, which emits a double value with a range of -1 to 1. This is used by HomePage to navigate through the application. To see how it does this, and for a look at the slot, see the Navigation page.

## Future

As the application becomes more complex, we will add signals and slots for the gamepad to enable more functionality. 