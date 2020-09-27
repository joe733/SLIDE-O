#include <Arduino.h>
 #include <DigiMouse.h>

#define cSens1 0
#define cSens2 1
#define cSens3 2

unsigned long t1;
unsigned long t2;
unsigned long t3;
 
bool upscroll;
bool dscroll;

void setup() {
  DigiMouse.begin(); //start or reenumerate USB - BREAKING CHANGE from old versions that didn't require this
  pinMode(cSens1, INPUT);
  pinMode(cSens2, INPUT);
  pinMode(cSens3, INPUT);
}

void loop() {
 if (digitalRead(cSens1))             //Creating Timestamp
   t1=millis();
 else if (digitalRead(cSens2))
   t2=millis();
 else if (digitalRead(cSens3)){
   t3=millis();
 }
 
 else if(t3>t1 && t1!=0){                    //Comparing Timestamp
   DigiMouse.scroll(2);
   t1=t2=t3=0;                      // Once executed Resetting all timestamps
 }
 else if(t3<t1 && t3!=0){
   DigiMouse.scroll(-2);
   t1=t2=t3=0;                      // Once executed Resetting all timestamps
 }
 else
   DigiMouse.update();

//  DigiMouse.delay(500);
}
