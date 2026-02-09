#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 display(128, 64, &Wire, -1);

int r = 0, d = 1, l = 2, u = 3;
bool last[4]={false,false,false,false};
bool b[4]={false,false,false,false};
int block[2]={6,3};
int UP = A0,RIGHT=A1,LEFT=A2,DOWN=A3;
int buttons[4]={UP,RIGHT,LEFT,DOWN};
int width=3;
int x_dim=128/width,y_dim=64/width;

void drawBlock(int *arr) {
  int x = width * (*(arr + 0));
  int y = width * (*(arr + 1));
  display.fillRect(x, y, width, width, SSD1306_WHITE);
  return;
}
void moveBlock(int vel){
  switch (vel)
    {
    case 0:
      block[0] = (block[0] + 1) % x_dim;
      break;
    case 1:
      block[1] = (block[1] + 1) % y_dim;
      break;
    case 2:
      block[0] = (block[0] - 1 + x_dim) % x_dim;
      break;
    case 3:
      block[1] = (block[1] - 1 + y_dim) % y_dim;
      break;
    }
}
void setup()
{  
  Wire.begin();
  Serial.begin(115200);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  for(int i=0;i<4;i++)
  {
    pinMode(buttons[i],INPUT);
  }
}
int updateParams(int old_vel){
  for(int i=0;i<4;i++)
  {
    b[i]=analogRead(buttons[i])/1023;
  }
  if (!last[0] && b[0]) return 3;//UP
  if (!last[1] && b[1]) return 0;//RIGHT
  if (!last[2] && b[2]) return 2;//LEFT
  if (!last[3] && b[3]) return 1;//DOWN

  for(int i=0;i<4;i++)
  {
    last[i]=b[i];
  }
  return old_vel;
}

int vel=r;

void loop()
{
  display.clearDisplay();
  vel=updateParams(vel);
  moveBlock(vel);
  drawBlock(block);
  display.display();
}
