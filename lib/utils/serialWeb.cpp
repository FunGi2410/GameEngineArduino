#include "serialWeb.h"
#include "OTAWeb.h"

AsyncWebSerial webSerial;

void serialWebInit() {
  webSerial.begin(&server);

  webSerial.onMessage([](uint8_t *data, size_t len) {
    String msg;
    for (size_t i = 0; i < len; i++) {
      msg += char(data[i]);
    }
    Serial.println("Nhận từ Web: " + msg);
    webSerial.println("ESP32 đã nhận: " + msg);
  });

  server.begin();

  webSerial.println("WebSerial đã sẵn sàng!");
}

void serialWebPrint(){
  static unsigned long last = 0;
  static int counter = 0;

  if (millis() - last > 2000) {
    last = millis();
    counter++;
    webSerial.println("Counter = " + String(counter));
  }

  webSerial.loop();
}
