int voltage=0;
void setup(){
  pinMode(A0,INPUT);
  pinMode(11,OUTPUT);
  Serial.begin(9600);
}
void buzz(){
  tone(11,1000);
  delay(500);
  noTone(11);
  delay(500);
}
void loop(){
  voltage=analogRead(A0)/200;
  if(voltage==0)
  {
    buzz();
    Serial.println("Obstacle detected");
  }
  delay(10);
}