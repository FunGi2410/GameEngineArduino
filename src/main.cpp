#include <Arduino.h>
#include "OTAWeb.h"
#include "FuMDNS.h"
#include "SerialWeb.h"
#include <TFT_eSPI.h>
#include "../lib/FGEngine/Render/TFTSetting.h"

const char* ssid = "Nha Tro 7 Treo";
const char* password = "02022025";

Player player;

void setup() {
  Serial.begin(115200);

  setupOTA(ssid, password);
  serialWebInit();
  setupHost();

  setup_tft7735();
}

void loop() {
  player.setPosition(0, 0);
  player.setShape(RECTANGLE);
  player.setColor(TFT_BLUE);
  player.setSize(5, 20, 10);

  player.addComponent();
}
