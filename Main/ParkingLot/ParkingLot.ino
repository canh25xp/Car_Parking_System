#include <NewPing.h>

#define TRIG1 D1
#define ECHO1 D2
#define TRIG2 D3
#define ECHO2 D4
#define TRIG3 D5
#define ECHO3 D6
#define MAX_DISTANCE 50 // in cm

// NewPing setup of pins and maximum distance
NewPing sonar1(TRIG1, ECHO1, MAX_DISTANCE);
NewPing sonar2(TRIG2, ECHO2, MAX_DISTANCE);
NewPing sonar3(TRIG3, ECHO3, MAX_DISTANCE);

void setup() {
    Serial.begin(9600);
}

void loop() {
    delay(2000);
    Serial.print(sonar1.ping_cm());
    Serial.println("cm");
    Serial.print(sonar2.ping_cm());
    Serial.println("cm");
    Serial.print(sonar3.ping_cm());
    Serial.println("cm");
    Serial.println("------");
}