#include <Servo.h>

Servo servo;

void setup() {
  pinMode(A3, INPUT);
  Serial.begin(9600);
  servo.attach(10);
}

void loop() {
  for (int i = 0; i < 180; i++) {
    servo.write(i);
    delay(10);
  }
  for (int i = 0; i < 180; i++) {
    servo.write(180 - i);
    delay(10);
  }
}