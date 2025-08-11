#pragma once
#include <WebServer.h>

extern WebServer server;

void setupOTA(const char* ssid, const char* password);
void runOTA();
