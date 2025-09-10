
#include <Update.h>

#include "serialWeb.h"

#include "OTAWeb.h"
 
int counter = 0;

String htmlPage() {
  String page = "<!DOCTYPE html><html><head><meta charset='utf-8'>";
  page += "<title>ESP32 Web Data</title></head><body>";
  page += "<h1>ESP32 Data Demo</h1>";
  page += "<p>Counter value: <span id='val'>0</span></p>";
  
  page += "<script>";
  page += "setInterval(()=>{fetch('/data').then(r=>r.text()).then(t=>{";
  page += "document.getElementById('val').innerText=t;});},1000);";
  page += "</script>";
  
  page += "</body></html>";
  return page;
}

void serialData() {
  server.send(200, "text/plain", (Update.hasError()) ? "Serial Data" : String(counter));
}

void serialWebRun() {    
    server.on("/update", HTTP_POST, serialData);
}