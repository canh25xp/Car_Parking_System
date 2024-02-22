#include "Barrier.h"

Barrier::Barrier(int pin, int min, int max) {
    attach(pin, min, max); // Attach the servo to the specified pin
}

void Barrier::Open() {
    write(0); // Set the servo angle to fully open position (adjust as needed)
}

void Barrier::Close() {
    write(90); // Set the servo angle to fully closed position (adjust as needed)
}

void Barrier::Test() {
    for (int i = 0; i <= 180; i++) {
        write(i);
        delay(10);
    }
}