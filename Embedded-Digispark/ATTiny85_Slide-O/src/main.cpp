#include <Arduino.h>
#include <DigiMouse.h>

#define cSens1 0
#define cSens2 1
#define cSens3 2

unsigned long t1, t2, t3;

void setup()
{
  DigiMouse.begin(); // start or reenumerate USB - BREAKING CHANGE from old versions that didn't require this
  t1 = t2 = t3 = 0;
  pinMode(cSens1, INPUT);
  pinMode(cSens2, INPUT);
  pinMode(cSens3, INPUT);
}
void loop()
{
  // Creating Timestamp
  if (digitalRead(cSens1))
    t1 = millis();
  if (digitalRead(cSens2))
    t2 = millis();
  if (digitalRead(cSens3))
    t3 = millis();

  // Comparing Timestamps
  if (t3 > t1 && t1 != 0)
  {
    DigiMouse.scroll(2);
  }
  else if (t3 < t1 && t3 != 0)
  {
    DigiMouse.scroll(-2);
  }
  else
    DigiMouse.update();
  t1 = t2 = t3 = 0; // Once executed reset all timestamps
                    // DigiMouse.delay(500);
}