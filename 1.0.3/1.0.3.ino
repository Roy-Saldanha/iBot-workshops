int input, prevInput, flag = 0, state = 0;
void setup() {
  pinMode(11, OUTPUT);
  pinMode(A0, INPUT);
}
void loop() {
  input = analogRead(A0) / 1023;
  if (input == 1) {
    if (input == prevInput && flag == 0) {
      state = !state;
      digitalWrite(11, state);
      flag = 1;
    }
  } else {
    flag = 0;
  }
  prevInput = input;
  delay(50);
}