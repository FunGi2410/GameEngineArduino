#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <Update.h>
#include "firmwareWeb.h"  // chứa chuỗi HTML uploadForm

AsyncWebServer server(80);

// Trang gốc hiển thị form upload
void handleRoot(AsyncWebServerRequest *request) {
  request->send(200, "text/html", uploadForm);
}

// Gửi kết quả sau khi update xong
void updateComplete(AsyncWebServerRequest *request) {
  bool hasError = Update.hasError();
  request->send(200, "text/plain", hasError ? "Update Failed!" : "Update Success! Rebooting...");
  delay(500);
  ESP.restart();
}

// Xử lý OTA
void setupOTA(const char* ssid, const char* password) {
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  // Route trang gốc
  server.on("/", HTTP_GET, handleRoot);

  // Route nhận file OTA
  server.on(
    "/update",
    HTTP_POST,
    updateComplete,  // gọi sau khi upload hoàn tất
    [](AsyncWebServerRequest *request, String filename, size_t index, uint8_t *data, size_t len, bool final) {
      if (!index) {
        Serial.printf("Update Start: %s\n", filename.c_str());
        if (!Update.begin(UPDATE_SIZE_UNKNOWN)) {
          Update.printError(Serial);
        }
      }
      // Ghi dữ liệu nhận được
      if (Update.write(data, len) != len) {
        Update.printError(Serial);
      }
      // Kết thúc update
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

// Với AsyncWebServer, không cần runOTA() gọi trong loop nữa
void runOTA() {
  // KHÔNG cần code gì ở đây
}
