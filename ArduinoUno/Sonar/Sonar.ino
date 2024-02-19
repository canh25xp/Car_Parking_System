/*
 * Posted on https://randomnerdtutorials.com
 * created by http://playground.arduino.cc/Code/NewPing
*/

#include <NewPing.h>

#define ECHO1 2
#define TRIG1 3
#define ECHO2 4
#define TRIG2 5
#define ECHO3 6
#define TRIG3 7
#define MAX_DISTANCE 200

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