#include "TFTSetting.h"

TFT_eSPI tft = TFT_eSPI();  // Tạo đối tượng TFT

void init() {
  tft.init();               
  tft.setRotation(1);       
  tft.fillScreen(TFT_BLACK);  

  tft.setTextColor(TFT_WHITE, TFT_BLACK);  
  tft.drawString("Hello ESP32!", 10, 10, 2);

  tft.fillRect(20, 40, 60, 30, TFT_RED);

  // player = tft.drawRect(pos, scale, color);
  // player = tft.drawRect(pos);
  // player.setPos(pos)

  
  tft.fillCircle(60, 120, 20, TFT_GREEN);
}

void run() {
    
  tft.fillScreen(TFT_BLUE);
  delay(1000);
  tft.fillScreen(TFT_BLACK);
  delay(1000);
}