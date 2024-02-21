#include <NewPing.h>

#include <ESP8266WiFi.h>
#include <ESPAsyncWebServer.h>

// Pins connections
#define TRIG1 D1
#define ECHO1 D2
#define TRIG2 D3
#define ECHO2 D5
#define TRIG3 D6
#define ECHO3 D7
#define MAX_DISTANCE 50 // in cm

// Wifi credential
const char* SSID = "Wifiname";
const char* PSWD = "Password";

// NewPing setup of pins and maximum distance
NewPing sonar1(TRIG1, ECHO1, MAX_DISTANCE);
NewPing sonar2(TRIG2, ECHO2, MAX_DISTANCE);
NewPing sonar3(TRIG3, ECHO3, MAX_DISTANCE);


AsyncWebServer server(80);

void setup() {
    Serial.begin(115200);

    Serial.println("");
    WiFi.begin(SSID, PSWD);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("");
    Serial.print("Connected to ");
    Serial.println(SSID);
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());

    server.on("/sonar1", HTTP_GET, [] (AsyncWebServerRequest* request) {
        request->send_P(200, "text/plain", String(sonar1.ping_cm()).c_str());
        });
    server.on("/sonar2", HTTP_GET, [] (AsyncWebServerRequest* request) {
        request->send_P(200, "text/plain", String(sonar2.ping_cm()).c_str());
        });
    server.on("/sonar3", HTTP_GET, [] (AsyncWebServerRequest* request) {
        request->send_P(200, "text/plain", String(sonar3.ping_cm()).c_str());
        });

    server.begin();
}

void loop() {
    // delay(2000);
    // Serial.print(sonar1.ping_cm());
    // Serial.println("cm");
    // Serial.print(sonar2.ping_cm());
    // Serial.println("cm");
    // Serial.print(sonar3.ping_cm());
    // Serial.println("cm");
    // Serial.println("------");
}