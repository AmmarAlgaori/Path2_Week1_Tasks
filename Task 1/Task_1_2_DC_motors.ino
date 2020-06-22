#define in4 2
#define in3 3
#define en2 4
#define en1 5
#define in2 6
#define in1 7
#define button 8

int rotationDirection = 0;

void setup() {
  //set the mode of the pins
  pinMode(in4, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(en2, OUTPUT);
  pinMode(en1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  analogWrite(en1, 255);
  analogWrite(en2, 255);
  //set motor 1 initial direction
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  //set motor 2 initial direction
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void loop() {
  if (digitalRead(button) == 0){    
    if ( rotationDirection == 0) {
      //motor 1 direction
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      //motor 2 direction
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
    
      rotationDirection = 1;
      delay(50);
    }
    
    else if (rotationDirection == 1) {
      //motor 1 direction
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      //motor 2 direction
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
    
      rotationDirection = 0;
      delay(50);
    }
  }
}
