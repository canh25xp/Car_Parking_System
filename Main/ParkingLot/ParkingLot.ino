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
const char* SSID = "Laptop";
const char* PSWD = "Password";

// Set your Static IP address
IPAddress local_IP(192, 168, 1, 184);
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);

// Create ultrasonic sensor instances
NewPing sonar1(TRIG1, ECHO1, MAX_DISTANCE);
NewPing sonar2(TRIG2, ECHO2, MAX_DISTANCE);
NewPing sonar3(TRIG3, ECHO3, MAX_DISTANCE);

int val1 = 0;
int val2 = 0;
int val3 = 0;

AsyncWebServer server(80);

void setup() {
    Serial.begin(115200);
    Serial.println("");

    // Configures static IP address
    // if (!WiFi.config(local_IP, gateway, subnet)) {
    //     Serial.println("STA Failed to configure");
    // }

    Serial.print("Connecting to ");
    Serial.println(SSID);
    WiFi.begin(SSID, PSWD);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("");
    Serial.println("Connected");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());

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