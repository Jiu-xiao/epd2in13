#include <SPI.h>
#include "epd2in13.h"
#include "epdpaint.h"
#include "imagedata.h"
#define COLORED     0
#define UNCOLORED   1
unsigned char image[1024];
Paint paint(image, 0, 0);
Epd epd;
unsigned long time_start_ms;
unsigned long time_now_s;
void setup() {
  epd.Init(lut_full_update);
  epd.ClearFrameMemory(0xFF);   // bit set = white, bit reset = black
  
  paint.SetRotate(ROTATE_0);
  paint.SetWidth(128);    // width should be the multiple of 8 
  paint.SetHeight(12);

  paint.Clear(COLORED);
  paint.DrawStringAt(0, 0, "Serive by LC", &Font12, UNCOLORED);
  epd.SetFrameMemory(paint.GetImage(), 0, 0, paint.GetWidth(), paint.GetHeight());

  paint.Clear(UNCOLORED);
  paint.DrawStringAt(0, 0, "Booting up ......", &Font12, COLORED);
  epd.SetFrameMemory(paint.GetImage(), 0, 13, paint.GetWidth(), paint.GetHeight());

  paint.Clear(UNCOLORED);
  paint.DrawStringAt(0, 0, "Please wait.", &Font12, COLORED);
  epd.SetFrameMemory(paint.GetImage(), 0, 25, paint.GetWidth(), paint.GetHeight());

  paint.SetWidth(64);
  paint.SetHeight(64);
  
  paint.Clear(UNCOLORED);
  paint.DrawRectangle(0, 0, 50, 50, COLORED);
  paint.DrawLine(0, 0, 50, 50, COLORED);
  paint.DrawLine(50, 0, 0, 50, COLORED);
  epd.SetFrameMemory(paint.GetImage(), 40, 60, paint.GetWidth(), paint.GetHeight());
  epd.DisplayFrame();

  delay(5000);
  epd.Init(lut_partial_update);
}

void loop() {
  paint.SetWidth(128);
  paint.SetHeight(24);
  paint.Clear(UNCOLORED);
  epd.SetFrameMemory(paint.GetImage(), 0, 13, paint.GetWidth(), paint.GetHeight());
  epd.DisplayFrame();

  delay(5000);
}
