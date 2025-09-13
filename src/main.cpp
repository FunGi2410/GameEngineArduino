#include <Arduino.h>
#include "OTAWeb.h"
#include "FuMDNS.h"

#include "blinkLed.h"

#include "serialWeb.h"

const char* ssid = "Nha Tro 7 Treo";
const char* password = "02022025";

void setup() {
  // cmd
  Serial.begin(115200);

  // WiFi.begin(ssid, password);
  //   while (WiFi.status() != WL_CONNECTED) {
  //     delay(500);
  //     Serial.print(".");
  //   }
  //   Serial.println("\nWiFi connected");
  //   Serial.print("ESP32 IP: ");
  //   Serial.println(WiFi.localIP());


  // serialWebInit();
  setupOTA(ssid, password);
  serialWebInit();
  setupHost();
}

void loop() {
  // serialWebPrint();
  // runOTA();
  serialWebPrint();
  // blinkLedCtrl(2, 500);
}
