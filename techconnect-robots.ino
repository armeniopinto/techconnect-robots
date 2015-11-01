#include <Servo.h>

Servo left;
Servo right;

void setup() {
  Serial.begin(9600);
  
  pinMode(13, OUTPUT);
  pinMode(A5, INPUT);

  left.attach(9);
  right.attach(10);
}

void go() {
  left.write(180);
  right.write(0);
}

void retreat() {
  digitalWrite(13, HIGH);
  
  left.write(0);
  right.write(180);
  delay(1000);
  
  right.write(0);
  delay(500);

  digitalWrite(13, LOW);
}

void loop() {
  int value = analogRead(A5);
  Serial.println(value);
  if (value<200) {
    retreat();
  } else {
    go();
  }
}
