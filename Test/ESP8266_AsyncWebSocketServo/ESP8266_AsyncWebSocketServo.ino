#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>

#include "Barrier.h"
#include "index.h"

// Wifi credentials
const char* SSID = "Laptop";
const char* PSWD = "Password";

bool STATE = 0;

// Create Servo instance
#define SERVO_PIN D3
Barrier barrier(SERVO_PIN);

// Create AsyncWebServer object on port 80
AsyncWebServer server(80);
AsyncWebSocket ws("/ws");

void setup() {
    Serial.begin(115200);
    Serial.println("");

    // barrier.Test();
    barrier.Close();

    // Connect to Wi-Fi
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

    // Init Web Socket
    ws.onEvent(onEvent);
    server.addHandler(&ws);

    // Route for root / web page
    server.on("/", HTTP_GET, [] (AsyncWebServerRequest* request) {
        request->send_P(200, "text/html", index_html, processor);
    });

    // Start server
    server.begin();
}

void loop() {
    ws.cleanupClients();
    if (STATE) {
        barrier.Open();
    }
    else {
        barrier.Close();
    }
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


void onEvent(AsyncWebSocket* server, AsyncWebSocketClient* client, AwsEventType type,
             void* arg, uint8_t* data, size_t len) {
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
        case WS_EVT_PONG:
        case WS_EVT_ERROR:
            break;
    }
}

void initWebSocket() {
    ws.onEvent(onEvent);
    server.addHandler(&ws);
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