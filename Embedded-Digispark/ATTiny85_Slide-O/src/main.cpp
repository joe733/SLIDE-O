#include <Arduino.h>

#include <DigiMouse.h>

void setup() {
  DigiMouse.begin(); //start or reenumerate USB - BREAKING CHANGE from old versions that didn't require this
}

void loop() {

  DigiMouse.scroll(5);
  DigiMouse.delay(500);
  DigiMouse.scroll(-5);
  DigiMouse.delay(500);
}