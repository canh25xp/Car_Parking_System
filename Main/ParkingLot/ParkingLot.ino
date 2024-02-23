#include <NewPing.h>

#include <ESP8266WiFi.h>
#include <ESPAsyncWebServer.h>

// Pins connections
#define LOT_COUNT 3 // 3 sensor/parking lots
#define TRIG1 D1
#define ECHO1 D2
#define TRIG2 D3
#define ECHO2 D5
#define TRIG3 D6
#define ECHO3 D7
#define MAX_DISTANCE 50 // in cm
#define THRESHOLH 10

// Wifi credential
const char* SSID = "ESP8266_NodeMCU";
const char* PSWD = "12345678";

// Create ultrasonic sensor instances
NewPing sonar1(TRIG1, ECHO1, MAX_DISTANCE);
NewPing sonar2(TRIG2, ECHO2, MAX_DISTANCE);
NewPing sonar3(TRIG3, ECHO3, MAX_DISTANCE);

int val1 = 0;
int val2 = 0;
int val3 = 0;

// Create AsyncWebServer object on port 80
AsyncWebServer server(80);

void setup() {
    Serial.begin(115200);
    Serial.println("");

    // Setting the ESP as an access point
    Serial.println("Setting AP");
    // Remove the password parameter, if you want the AP (Access Point) to be open
    WiFi.softAP(SSID, PSWD);

    Serial.print("AP IP address: ");
    Serial.println(WiFi.softAPIP()); // Default address 192.168.4.1

    WiFi.printDiag(Serial);

    server.on("/sonar1", HTTP_GET, [] (AsyncWebServerRequest* request) {
        request->send_P(200, "text/plain", String(sonar1.ping_cm()).c_str());
        });
    server.on("/sonar2", HTTP_GET, [] (AsyncWebServerRequest* request) {
        request->send_P(200, "text/plain", String(sonar2.ping_cm()).c_str());
        });
    server.on("/sonar3", HTTP_GET, [] (AsyncWebServerRequest* request) {
        request->send_P(200, "text/plain", String(sonar3.ping_cm()).c_str());
        });
    server.on("/status", HTTP_GET, [] (AsyncWebServerRequest* request) {
        request->send_P(200, "text/plain", GetParkingLotStatus().c_str());
        });

    server.on("/count", HTTP_GET, [] (AsyncWebServerRequest* request) {
        request->send_P(200, "text/plain", String(WiFi.softAPgetStationNum()).c_str());
        });

    // Start server
    server.begin();
}

void loop() {
    Serial.println(GetParkingLotStatus());
    delay(1000);
}

String GetParkingLotStatus() {
    UpdateVal();
    return String(IsEmptyLot(val1)) + " " + String(IsEmptyLot(val2)) + " " + String(IsEmptyLot(val3));
}

void UpdateVal() {
    val1 = sonar1.ping_cm();
    val2 = sonar2.ping_cm();
    val3 = sonar3.ping_cm();
}

bool IsEmptyLot(int _distance) {
    return (_distance > 0 && _distance < THRESHOLH) ? true : false;
}