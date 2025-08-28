#include "FuMDNS.h"
#include <Arduino.h>

const char* HOST = "eps32-update";

void setupHost(){
    if (MDNS.begin(HOST)) {
        Serial.println("Server started");
        Serial.printf("Open http://%s.local\n", HOST);
    }
}