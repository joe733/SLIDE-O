/*
  Code written by Nafih Ahammed in accordance with Hackster 'Touch Less, Do More' challenge.
  Gest-R is state of art multifunction capacitive Gesture switch.
 */


#define Output 5
bool state1 = false; // State of first capacitive proximity sensor.
bool state2 = false; // State of 2nd capacitive proximity sensor
int GestR = 0; // Gesture 1 implies downward motion and 0 implies uoward motion. 2 means start 'OFF-Timer' and -1 means start 'ON-Timer'.
int t = 5; // determines the delay of timer

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize Pins.
  pinMode(Output, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(2, INPUT);
  pinMode(3, INPUT);

  // Defining Interrupts
  attachInterrupt(digitalPinToInterrupt(2), prox1, RISING);
  attachInterrupt(digitalPinToInterrupt(3), prox2, RISING);
}

// the loop function runs over and over again forever
void loop() {
  switch (GestR){
    case 1:
      digitalWrite(LED, HIGH);
      break;
    case 0:
      digitalWrite(LED, LOW);
      break;
    case 2:
      blinkled();
      digitalWrite(LED, LOW);
      GestR = 0;
      break;
    case -1:
      blinkled();
      digitalWrite(LED, HIGH);
      GestR = 1;
  }
}

void prox1() {
  if (state2) {
    if (GestR == 0)
      GestR = -1;
    else
      GestR = 0;
      
    state2 = false;
  }
  else
    state1 = true;
}

void prox2() {
  if (state1) {
    if (GestR == 1)
      GestR = 2;
    else
      GestR = 1;
      
    state1 = false;
  }
  else
    state2 = true;
}

void blinkled() {
  for (int t = 0; t<5; t++){
      digitalWrite(LED_BUILTIN, HIGH);
      delay(1000);
      digitalWrite(LED_BUILTIN, LOW);
      delay(1000);
    }
}
