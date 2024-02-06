#include "WifiCam.hpp"

static const char* WIFI_SSID = "Michael";
static const char* WIFI_PASS = "HelloWorld";

esp32cam::Resolution initialResolution;

WebServer server(80);

void setup() {
    Serial.begin(115200);
    Serial.println();
    delay(2000);

    WiFi.persistent(false);
    WiFi.mode(WIFI_STA);
    WiFi.begin(WIFI_SSID, WIFI_PASS);
    if (WiFi.waitForConnectResult() != WL_CONNECTED) {
        Serial.printf("WiFi failure %d\n", WiFi.status());
        delay(5000);
        ESP.restart();
    }
    Serial.println("WiFi connected");

    initialResolution = esp32cam::Resolution::find(1024, 768);

    esp32cam::Config cfg;
    cfg.setPins(esp32cam::pins::AiThinker);
    cfg.setResolution(initialResolution);
    cfg.setJpeg(80);

    bool ok = esp32cam::Camera.begin(cfg);
    if (!ok) {
        Serial.println("camera initialize failure");
        delay(5000);
        ESP.restart();
    }
    Serial.println("camera initialize success");

    Serial.println("camera starting");
    Serial.print("http://");
    Serial.println(WiFi.localIP());

    addRequestHandlers();
    server.begin();
}

void loop() {
    server.handleClient();
}
