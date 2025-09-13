#pragma once
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>

extern AsyncWebServer server;

void setupOTA(const char* ssid, const char* password);
void runOTA();
