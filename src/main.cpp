#include <Arduino.h>
#include "Keyboard.h"
#include "scripts.cpp"

// script pins
#define SCRIPT1_GND 4
#define SCRIPT1 5
#define SCRIPT1_PWR 6
#define SCRIPT2_GND 7
#define SCRIPT2 8
#define SCRIPT2_PWR 9

void setup()
{
  // failsafe
  pinMode(2, INPUT);
  pinMode(3, OUTPUT);
  digitalWrite(3, HIGH);

  // script1
  pinMode(SCRIPT1_GND, OUTPUT);
  pinMode(SCRIPT1, INPUT);
  pinMode(SCRIPT1_PWR, OUTPUT);
  digitalWrite(SCRIPT1_GND, LOW);
  digitalWrite(SCRIPT1_PWR, HIGH);
  // script2
  pinMode(SCRIPT2_GND, OUTPUT);
  pinMode(SCRIPT2, INPUT);
  pinMode(SCRIPT2_PWR, OUTPUT);
  digitalWrite(SCRIPT2_GND, LOW);
  digitalWrite(SCRIPT2_PWR, HIGH);

  delay(500);
  // failsafe
  if (digitalRead(2) == LOW)
    return;

  Keyboard.begin();

  //* SCRIPT 1
  if (digitalRead(SCRIPT1) == HIGH)
  {
    delay(500);

    script1();

    Keyboard.end();
    return;
  }
  //* SCRIPT 2
  if (digitalRead(SCRIPT2) == HIGH)
  {
    delay(500);

    script2();

    Keyboard.end();
    return;
  }

  Keyboard.end();
}

void loop()
{
}