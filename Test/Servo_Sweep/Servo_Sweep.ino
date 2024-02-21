#include <Servo.h>

#define SERVO_PIN D4
Servo myservo;

void setup() {
    myservo.attach(SERVO_PIN, 500, 2400);
}

void loop() {
    int pos;

    for (pos = 0; pos <= 180; pos += 1) {
        myservo.write(pos);
        delay(10);
    }
    for (pos = 180; pos >= 0; pos -= 1) {
        myservo.write(pos);
        delay(10);       
    }
}