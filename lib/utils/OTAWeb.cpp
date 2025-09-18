#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <Update.h>
#include "firmwareWeb.h"  

AsyncWebServer server(80);

void handleRoot(AsyncWebServerRequest *request) {
  request->send(200, "text/html", uploadForm);
}

void updateComplete(AsyncWebServerRequest *request) {
  bool hasError = Update.hasError();
  request->send(200, "text/plain", hasError ? "Update Failed!" : "Update Success! Rebooting...");
  delay(500);
  ESP.restart();
}

void setupOTA(const char* ssid, const char* password) {
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  server.on("/", HTTP_GET, handleRoot);

  server.on(
    "/update",
    HTTP_POST,
    updateComplete,
    [](AsyncWebServerRequest *request, String filename, size_t index, uint8_t *data, size_t len, bool final) {
      if (!index) {
        Serial.printf("Update Start: %s\n", filename.c_str());
        if (!Update.begin(UPDATE_SIZE_UNKNOWN)) {
          Update.printError(Serial);
        }
      }
      if (Update.write(data, len) != len) {
        Update.printError(Serial);
      }
      if (final) {
        if (Update.end(true)) {
          Serial.printf("Update Success: %u bytes\nRebooting...\n", index + len);
        } else {
          Update.printError(Serial);
        }
      }
    }
  );

  server.begin();
}
