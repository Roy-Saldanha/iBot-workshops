int analogPin = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int volume = analogRead(analogPin);

  if (volume > 525) {
    Serial.println("Loud claps detected");
  }
  else
  {
    Serial.println("No sound");
  }

  delay(50);
}
