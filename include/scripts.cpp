#include <Arduino.h>
#include "Keyboard.h"

void typeKey(int key)
{
    Keyboard.press(key);
    delay(50);
    Keyboard.release(key);
}

void script1()
{
    // INSERT SCRIPT1 HERE
}

void script2()
{
    // INSERT SCRIPT2 HERE
}