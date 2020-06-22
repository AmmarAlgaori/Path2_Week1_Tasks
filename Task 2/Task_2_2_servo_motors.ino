#include <Servo.h>

#define button1 8
#define button2 9

Servo servo1;
Servo servo2;

int turn1 = 0;
int turn2 = 0;

void setup() {
  //set the mode of the pins
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  //set the pins of the servo motors
  servo1.attach(3);
  servo2.attach(5);
  //initialize the angle of the servo motors
  servo1.write(0);
  servo2.write(0);
}

void loop() {
  //button 1 is used to send angle to servo motor 1
  if (digitalRead(button1) == 0){
    if (turn1 == 0) {    
      servo1.write(180);
      turn1 = 1;
    }
    else if (turn1 == 1) {
      servo1.write(0);
      turn1 = 0;
    }
    delay(300);
  }
  //button 2 is used to send angle to servo motor 2
  if (digitalRead(button2) == 0){  
    if (turn2 == 0) {    
      servo2.write(180);
      turn2 = 1;
    }
    else if (turn2 == 1)  {
      servo2.write(0);
      turn2 = 0;
    }
    delay(300);
  }
}
