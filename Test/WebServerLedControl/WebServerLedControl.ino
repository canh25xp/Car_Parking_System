#include <WiFi.h>

// Replace with your network credentials
const char* SSID     = "Michael";
const char* PASSWORD = "HelloWorld";


// Set web server port number to 80
WiFiServer server(80);

// Variable to store the HTTP request
String header;

// Auxiliar variables to store the current output state
String FLASH_STATE = "off";
String LED_STATE = "off";

// Assign output variables to GPIO pins
const int FLASH_PIN = 4;
const int LED_PIN = 33;

// Current time
unsigned long currentTime = millis();
// Previous time
unsigned long previousTime = 0;
// Define timeout time in milliseconds (example: 2000ms = 2s)
const long timeoutTime = 2000;

void setup() {
    Serial.begin(115200);
    // Initialize the output variables as outputs
    pinMode(FLASH_PIN, OUTPUT);
    pinMode(LED_PIN, OUTPUT);
    // Set outputs to LOW
    digitalWrite(FLASH_PIN, LOW);
    digitalWrite(LED_PIN, HIGH);  // the built-in led is active low

    // Connect to Wi-Fi network with SSID and password
    Serial.print("Connecting to ");
    Serial.println(SSID);
    WiFi.begin(SSID, PASSWORD);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    // Print local IP address and start web server
    Serial.println("");
    Serial.println("WiFi connected.");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
    server.begin();
}

void loop() {
    WiFiClient client = server.available();   // Listen for incoming clients

    if (client) {                             // If a new client connects,
        currentTime = millis();
        previousTime = currentTime;
        Serial.println("New Client.");          // print a message out in the serial port
        String currentLine = "";                // make a String to hold incoming data from the client
        while (client.connected() && currentTime - previousTime <= timeoutTime) {  // loop while the client's connected
            currentTime = millis();
            if (client.available()) {             // if there's bytes to read from the client,
                char c = client.read();             // read a byte, then
                Serial.write(c);                    // print it out the serial monitor
                header += c;
                if (c == '\n') {                    // if the byte is a newline character
                    // if the current line is blank, you got two newline characters in a row.
                    // that's the end of the client HTTP request, so send a response:
                    if (currentLine.length() == 0) {
                        // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
                        // and a content-type so the client knows what's coming, then a blank line:
                        client.println("HTTP/1.1 200 OK");
                        client.println("Content-type:text/html");
                        client.println("Connection: close");
                        client.println();

                        // turns the GPIOs on and off
                        if (header.indexOf("GET /flash/on") >= 0) {
                            Serial.println("FLASH on");
                            FLASH_STATE = "on";
                            digitalWrite(FLASH_PIN, HIGH);
                        }
                        else if (header.indexOf("GET /flash/off") >= 0) {
                            Serial.println("FLASH off");
                            FLASH_STATE = "off";
                            digitalWrite(FLASH_PIN, LOW);
                        }
                        else if (header.indexOf("GET /led/on") >= 0) {
                            Serial.println("LED on");
                            LED_STATE = "on";
                            digitalWrite(LED_PIN, LOW);
                        }
                        else if (header.indexOf("GET /led/off") >= 0) {
                            Serial.println("LED off");
                            LED_STATE = "off";
                            digitalWrite(LED_PIN, HIGH);
                        }

                        // Display the HTML web page
                        client.println("<!DOCTYPE html><html>");
                        client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
                        client.println("<link rel=\"icon\" href=\"data:,\">");
                        // CSS to style the on/off buttons 
                        // Feel free to change the background-color and font-size attributes to fit your preferences
                        client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
                        client.println(".button { background-color: #4CAF50; border: none; color: white; padding: 16px 40px;");
                        client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
                        client.println(".button2 {background-color: #555555;}</style></head>");

                        // Web Page Heading
                        client.println("<body><h1>ESP32 Web Server</h1>");

                        // Display current state, and ON/OFF buttons for FLASH_PIN
                        client.println("<p>FLASH_STATE " + FLASH_STATE + "</p>");
                        // If the FLASH_STATE is off, it displays the ON button       
                        if (FLASH_STATE == "off") {
                            client.println("<p><a href=\"/flash/on\"><button class=\"button\">ON</button></a></p>");
                        }
                        else {
                            client.println("<p><a href=\"/flash/off\"><button class=\"button button2\">OFF</button></a></p>");
                        }

                        // Display current state, and ON/OFF buttons for LED_PIN  
                        client.println("<p>LED_STATE " + LED_STATE + "</p>");
                        // If the LED_STATE is off, it displays the ON button       
                        if (LED_STATE == "off") {
                            client.println("<p><a href=\"/led/on\"><button class=\"button\">ON</button></a></p>");
                        }
                        else {
                            client.println("<p><a href=\"/led/off\"><button class=\"button button2\">OFF</button></a></p>");
                        }
                        client.println("</body></html>");

                        // The HTTP response ends with another blank line
                        client.println();
                        // Break out of the while loop
                        break;
                    }
                    else { // if you got a newline, then clear currentLine
                        currentLine = "";
                    }
                }
                else if (c != '\r') {  // if you got anything else but a carriage return character,
                    currentLine += c;      // add it to the end of the currentLine
                }
            }
        }
        // Clear the header variable
        header = "";
        // Close the connection
        client.stop();
        Serial.println("Client disconnected.");
        Serial.println("");
    }
}