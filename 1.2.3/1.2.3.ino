#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 display(128, 64, &Wire, -1);
int i=0;

void setup()
{

  Wire.begin();
  Serial.begin(115200);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
}
void loop()
{
  display.clearDisplay();
  display.setCursor(0, 0);
  display.print("Hello world!");
  display.drawCircle((64+i)%128,32,5,SSD1306_WHITE);
  i++;
  display.display();
  delay(10);
}