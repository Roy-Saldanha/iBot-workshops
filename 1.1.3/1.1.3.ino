int pirPin = 2;

void setup() {
  pinMode(pirPin, INPUT);
  Serial.begin(9600);
  Serial.println("Calibrating sensor...");  //aparently this needs some warm-up delay (10 seconds)
  delay(10000);
}

void loop() {
  int motion = digitalRead(pirPin);

  if (motion == HIGH) {
    Serial.println("Motion detected");
  } else {
    Serial.println("No motion");
  }
  delay(500);
}
