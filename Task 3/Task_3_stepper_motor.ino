#include <Stepper.h>

#define in4 2
#define in3 3
#define en2 4
#define en1 5
#define in2 6
#define in1 7
#define button1 8
#define button2 9
#define STEPS 45

Stepper stepper(STEPS,7,6,3,2);

int state = 0;

void setup() {
  //set the mode of the pins
  pinMode(in4, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(en2, OUTPUT);
  pinMode(en1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  analogWrite(en1, 255);
  analogWrite(en2, 255);
  //set the speed of fot he stepper motor
  stepper.setSpeed(5);
}

void loop() {
  //button 1 is used to turn the motor on and off
  if (digitalRead(button1) == 0){    
    if ( state == 0) {
      state = 1;
      delay(300);
    }
    else if (state == 1 || state == -1) {
      state = 0;
      delay(300);
    }
  }
  //button 2 is used to reverse the direction of the motor
  if (digitalRead(button2) == 0){    
    if ( state == 1 || state == -1) {
      state = -state;
      delay(300);
    }
  }
  stepper.step(state);
}
