#include <TFT_eSPI.h> 
#include <SPI.h>

#include "TFTSetting.h"
#include "D:\_ESP32_TFT_Monitor\2.GameEngineArduino\GameEngineArduino\.pio\libdeps\esp32dev\TFT_eSPI\User_Setups\Setup43_ST7735.h"
#include "D:\_ESP32_TFT_Monitor\2.GameEngineArduino\GameEngineArduino\.pio\libdeps\esp32dev\TFT_eSPI\User_Setup_Select.h"

TFT_eSPI tft = TFT_eSPI();      

void setup_tft7735(void) {
  tft.init();

  tft.setRotation(0);
  
  tft.fillScreen(TFT_BLACK);
}

void Player :: addComponent(){

  switch (shape)
  {
    case CIRCLE:
      tft.fillCircle( xPos+64, yPos+80, radius, color );
      break;
    
    case RECTANGLE:
      tft.fillRect( xPos+64, yPos+80, (int32_t)width, (int32_t)height, color );
      break;

    default:
      tft.fillCircle( xPos+64, yPos+80, radius, color );
      break;
  }
}

void Player :: setPosition(unsigned char x_pos, unsigned char y_pos){
  xPos = x_pos;
  yPos = y_pos;
}

void Player :: setColor(unsigned short input_color){
  color = input_color;
}

void Player :: setShape(unsigned char input_shape){
  shape = input_shape;
}

void Player :: setSize(unsigned char input_width, unsigned char input_height, unsigned char input_radius, ...){
  width = input_width;
  height = input_height;
  radius = input_radius;
}



