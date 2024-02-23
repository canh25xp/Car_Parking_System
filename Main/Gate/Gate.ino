#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <SPI.h>
#include <MFRC522.h>

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include <ESP8266WiFiMulti.h>

#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>

#include "Barrier.h" // Handle the servo
#include "index.h"

// Set the LCD number of columns and rows
#define LCD_COLS        16
#define LCD_ROWS        2

// Pins connections
#define LCD_SDA         SDA     // D2
#define LCD_SCL         SCL     // D1

#define RFID_RST_PIN    D4
#define RFID_SDA_PIN    SS      // D8
#define RFID_SCK_PIN    SCK     // D5
#define RFID_MOSI_PIN   MOSI    // D7
#define RFID_MISO_PIN   MISO    // D6

#define SERVO_PIN       D3

// Wifi credential
const char* SSID = "ESP8266_NodeMCU";
const char* PSWD = "123456788";

// Create LCD instance
LiquidCrystal_I2C lcd(0x27, LCD_COLS, LCD_ROWS);

// Create RFID instance
MFRC522 rfid(RFID_SDA_PIN, RFID_RST_PIN);

// Create Servo instance
Barrier barrier(SERVO_PIN);

//Create WiFiMulti instance
ESP8266WiFiMulti WiFiMulti;

// Create AsyncWebServer object on port 80
AsyncWebServer server(80);
AsyncWebSocket ws("/ws");


IPAddress ParkingLotIP(192, 168, 4, 1);
const char* sonar1 = "http://192.168.4.1/sonar1";
const char* sonar2 = "http://192.168.4.1/sonar2";
const char* sonar3 = "http://192.168.4.1/sonar3";
const char* status = "http://192.168.4.1/status";
const char* count = "http://192.168.4.1/count";

bool STATE = 1;

unsigned long lastTime = 0;
unsigned long timerDelay = 3000;

#define MAX_ARRAY 10
String UID_array[MAX_ARRAY] = {};

String UID = "";
bool flag = 0;

void setup() {
    // INITIALIZATION
    Serial.begin(115200); // Initialize Serial Communication

    SPI.begin(); // Initialize SPI bus

    rfid.PCD_Init(); // Initialize MFRC522 RFID

    lcd.init(); // Initialize LCD

    // WIFI CONNECTION
    Serial.println(""); // Skip the first line of garbage characters
    Serial.printf("Connecting to %s\n", SSID);
    WiFi.begin(SSID, PSWD);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("");
    Serial.println("Connected");
    Serial.printf("IP address: %s\n", WiFi.localIP().toString().c_str());
    WiFi.printDiag(Serial);

    // Init and Test the servo (Sweep from 0 to 180 degree)
    // barrier.Test();
    barrier.Open();

    lcd.backlight();
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("PARKING SYSTEM");
    lcd.setCursor(0, 1);
    lcd.print("HUST PRODUCTION");

    // Init Web Socket
    ws.onEvent(onEvent);
    server.addHandler(&ws);

    // Route for root / web page
    server.on("/", HTTP_GET, [] (AsyncWebServerRequest* request) {
        request->send_P(200, "text/html", index_html, processor);
    });

    // Start server
    server.begin();

    Serial.println();
    Serial.println("Server Started");
}

void loop() {
    if (STATE) {
        barrier.Open();
    }
    else {
        barrier.Close();
    }

    if ((millis() - lastTime) > timerDelay) {
        // Serial.println(millis());
        // Serial.print(httpGETRequest(count) + " lot(s) remain:");
        // Serial.println(httpGETRequest(status));

        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print(httpGETRequest(count) + " lot(s) remain:");
        lcd.setCursor(0, 1);
        lcd.print(httpGETRequest(status));

        lastTime = millis();
    }
    ws.cleanupClients(); // Limiting the number of web socket clients

    // Look for new cards
    if (!rfid.PICC_IsNewCardPresent()) {
        return;
    }
    // Select one of the cards
    if (!rfid.PICC_ReadCardSerial()) {
        return;
    }

    delay(1000);
    String UID_latest = RFID_GetUID();
    Serial.printf("Card Detected: %s\n", UID_latest.c_str());
    if (flag == 0) {
        UID = UID_latest;
        Serial.printf("Registered New Card: %s\n", UID_latest.c_str());
        flag = 1;
    }
    if (UID == UID_latest) {
        STATE = 0;
    }


    // lcd.clear();
    // lcd.setCursor(0, 0);
    // lcd.print(UID);




    // Check WiFi connection status
    // if ((WiFiMulti.run() == WL_CONNECTED)) {
    //     lcd.clear();
    //     lcd.setCursor(0, 0);
    //     lcd.print(httpGETRequest(count) + " lot(s) remain:");
    //     lcd.setCursor(0, 1);
    //     lcd.print(httpGETRequest(status));
    // }
    // else {
    //     Serial.println("WiFi Disconnected");
    // }
}

String RFID_GetUID() {
    String content = "";
    for (byte i = 0; i < rfid.uid.size; i++) {
        content.concat(String(rfid.uid.uidByte[i] < 0x10 ? " 0" : " "));
        content.concat(String(rfid.uid.uidByte[i], HEX));
    }
    content.toUpperCase();
    return content.substring(1);
}

bool CheckUID(String& UID) {
    bool isDuplicate = false;
    for (int i = 0; i < MAX_ARRAY; ++i) {
        if (UID_array[i] == UID) {
            isDuplicate = true;
            break;
        }
    }

    if (!isDuplicate) {
        // Find an empty slot in the array to append the newID
        for (int i = 0; i < MAX_ARRAY; ++i) {
            if (UID_array[i] == "") {
                UID_array[i] = UID;
                break;
            }
        }
    }

    return isDuplicate;
}

void PrintUID() {
    for (int i = 0; i < MAX_ARRAY; ++i) {
        Serial.println(UID_array[i]);
    }
}

String httpGETRequest(const char* serverName) {
    WiFiClient client;
    HTTPClient http;

    // Your IP address with path or Domain name with URL path 
    http.begin(client, serverName);

    // Send HTTP POST request
    int httpResponseCode = http.GET();

    String payload = "--";

    if (httpResponseCode > 0) {
        // Serial.print("HTTP Response code: ");
        // Serial.println(httpResponseCode);
        payload = http.getString();
    }
    else {
        // Serial.print("Error code: ");
        // Serial.println(httpResponseCode);
    }
    // Free resources
    http.end();

    return payload;
}

void handleWebSocketMessage(void* arg, uint8_t* data, size_t len) {
    AwsFrameInfo* info = (AwsFrameInfo*) arg;
    if (info->final && info->index == 0 && info->len == len && info->opcode == WS_TEXT) {
        data[len] = 0;
        if (strcmp((char*) data, "toggle") == 0) {
            STATE = !STATE;
            ws.textAll(String(STATE));
        }
    }
}


void onEvent(AsyncWebSocket* server, AsyncWebSocketClient* client, AwsEventType type, void* arg, uint8_t* data, size_t len) {
    switch (type) {
        case WS_EVT_CONNECT:
            Serial.printf("WebSocket client #%u connected from %s\n", client->id(), client->remoteIP().toString().c_str());
            break;
        case WS_EVT_DISCONNECT:
            Serial.printf("WebSocket client #%u disconnected\n", client->id());
            break;
        case WS_EVT_DATA:
            handleWebSocketMessage(arg, data, len);
            break;
        case WS_EVT_PONG: // Response to a ping request
            break;
        case WS_EVT_ERROR: // An error is received from the client
            break;
    }
}


String processor(const String& var) {
    Serial.println(var);
    if (var == "STATE") {
        if (STATE) {
            return "OPEN";
        }
        else {
            return "CLOSE";
        }
    }

    return String();
}