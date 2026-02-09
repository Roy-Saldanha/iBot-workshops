#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 display(128, 64, &Wire, -1);
int volume_level;

void setup() {
  Wire.begin();
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  Serial.begin(9600);
  pinMode(A0, INPUT);
}
void loop() {
  display.clearDisplay();
  volume_level = ((44 * (analogRead(A0) - 650)) / 130) + 64;
  display.fillRect(0, 12, volume_level, 20, SSD1306_WHITE);
  display.display();
  delay(30);
}
