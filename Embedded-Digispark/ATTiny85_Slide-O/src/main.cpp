#include <Arduino.h>
#include <DigiMouse.h>

#define KEY_MUTE 127
#define KEY_VOLUME_UP 128
#define KEY_VOLUME_DOWN 129

#define cSens1 0
#define cSens2 1
#define cSens3 2

unsigned long t1,t2,t3;
 

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
 else if (digitalRead(cSens3))
    t3=millis(); 
 else if(t3>t1 && t1!=0){                    //Comparing Timestamp
   DigiMouse.scroll(-3);
   t1=t2=t3=0;                      // Once executed Resetting all timestamps
 }
 else if(t3<t1 && t3!=0){
   DigiMouse.scroll(3);
   t1=t2=t3=0;                      // Once executed Resetting all timestamps
 }
 else if(t2 && !(t3||t1)){   
    DigiMouse.setButtons(1<<0); //left click
    DigiMouse.delay(100);
    DigiMouse.setButtons(0);
    t2=0;

 }
 else if(t3 && !(t2||t1)){   
    DigiMouse.setButtons(2<<0); //left click
    DigiMouse.delay(100);
    DigiMouse.setButtons(0);
    t3=0;

 }
 else if(t1 && !(t2||t3)){   
    DigiMouse.setButtons(3<<0); //left click
    DigiMouse.delay(100);
    DigiMouse.setButtons(0);
    t1=0;

 }
 else
   DigiMouse.update();

//  DigiMouse.delay(500);
}
