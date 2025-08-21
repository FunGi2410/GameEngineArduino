#include <Arduino.h>
#include "OTAWeb.h"
#include "FuMDNS.h"

const char* ssid = "Nha Tro 7 Treo";
const char* password = "02022025";

void setup() {
  Serial.begin(115200);
  setupOTA(ssid, password);
  setupHost();
}

void loop() {
  runOTA();
}
