#include <Arduino.h>
#include "OTAWeb.h"
#include "FuMDNS.h"

#include "blinkLed.h"

const char* ssid = "Nha Tro 7 Treo";
const char* password = "02022025";

void setup() {
  // cmd
  Serial.begin(115200);
  setupOTA(ssid, password);
  setupHost();

  blinkLed_init();
}

void loop() {
  runOTA();
  blinkLed_ctrl();
}
