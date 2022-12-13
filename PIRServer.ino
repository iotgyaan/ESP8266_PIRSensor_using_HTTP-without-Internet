#include <ESP8266WiFi.h>
#include "ESPAsyncWebServer.h"

const char* ssid = "ESP8266-Access-Point";
const char* password = "123456789";

const int ledPin = 2;

AsyncWebServer server(80);

void setup(){
  Serial.begin(115200);        // initialize serial
  pinMode(ledPin, OUTPUT);
  WiFi.softAP(ssid, password);

  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(IP);
  
  server.on("/ledon", HTTP_GET, [](AsyncWebServerRequest *request){
   request->send_P(100, "text/plain", "ON responce!");
   Serial.println("Send ON!"); 
   digitalWrite(ledPin, HIGH);       
  });

  server.on("/ledoff", HTTP_GET, [](AsyncWebServerRequest *request){
   request->send_P(100, "text/plain", "OFF responce!");
   Serial.println("Send OFF!"); 
   digitalWrite(ledPin, LOW);
  });
  
  server.begin();
}

void loop() {   
  
}   
