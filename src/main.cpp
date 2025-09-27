#include <Arduino.h>
#include "OTAWeb.h"
#include "FuMDNS.h"
#include "SerialWeb.h"
#include "../lib/FGEngine/Render/TFTSetting.h"

const char* ssid = "Nha Tro 7 Treo";
const char* password = "02022025";

void setup() {
  Serial.begin(115200);

  setupOTA(ssid, password);
  serialWebInit();
  setupHost();
}

void loop() {
}
