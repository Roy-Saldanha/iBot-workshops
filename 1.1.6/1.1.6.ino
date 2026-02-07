int analogPin = A0,flag;

void setup() {
  Serial.begin(9600);
}

void loop() {
  flag=analogRead(analogPin)/512;
  if(flag==0)
  {
    Serial.println("IR source detected");
  }
  else
  {
    Serial.println("No IR source closeby");
  }
  delay(50);
}
