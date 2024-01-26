// A simple Sketch for testing out the Arduino board or the ESP32 board. No IO pin connection is needed.

// Config the ledPin acording to the testing board
// const int ledPin = 4; // The flashlight on the ESP32-CAM board (GPIO 4)
// const int ledPin = LED_BUILTIN; // The built-in led on the Arduino board (GPIO 13)
const int ledPin = 2; // The built-in led on the nodeMCU board

void setup(){
    pinMode(ledPin, OUTPUT); // initialize digital pin LED_BUILTIN as an output.
}

void loop(){
    digitalWrite(ledPin, HIGH); // turn the LED on (HIGH is the voltage level)
    delay(1000);                // wait for a second
    digitalWrite(ledPin, LOW);  // turn the LED off by making the voltage LOW
    delay(1000);                // wait for a second
}