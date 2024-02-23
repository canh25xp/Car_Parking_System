/*
  Rui Santos
  Complete project details at https://RandomNerdTutorials.com/esp8266-nodemcu-client-server-wi-fi/

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files.

  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.
*/

// Import required libraries
#include <ESP8266WiFi.h>
#include "ESPAsyncWebServer.h"

#include <Wire.h>

// Set your access point network credentials
const char* SSID = "ESP8266_NodeMCU";
const char* PSWD = "12345678";

// Create AsyncWebServer object on port 80
AsyncWebServer server(80);

void setup() {
    // Serial port for debugging purposes
    Serial.begin(115200);
    Serial.println();

    // Setting the ESP as an access point
    Serial.println("Setting AP");
    // Remove the password parameter, if you want the AP (Access Point) to be open
    WiFi.softAP(SSID, PSWD);

    IPAddress IP = WiFi.softAPIP(); // Default address 192.168.4.1
    Serial.print("AP IP address: ");
    Serial.println(IP);

    server.on("/temperature", HTTP_GET, [] (AsyncWebServerRequest* request) {
        request->send_P(200, "text/plain", "temp");
    });
    server.on("/humidity", HTTP_GET, [] (AsyncWebServerRequest* request) {
        request->send_P(200, "text/plain", "humi");
    });
    server.on("/pressure", HTTP_GET, [] (AsyncWebServerRequest* request) {
        request->send_P(200, "text/plain", "pres");
    });

    server.on("/status", HTTP_GET, [] (AsyncWebServerRequest* request) {
        request->send_P(200, "text/plain", String(WiFi.softAPgetStationNum()).c_str());
    });


    bool status;


    // Start server
    server.begin();
}

void loop() {
    Serial.printf("Stations connected = %d\n", WiFi.softAPgetStationNum());
    delay(3000);
}