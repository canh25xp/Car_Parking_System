#ifndef BARRIER_H
#define BARRIER_H

#include <Servo.h>

class Barrier : public Servo {
public:
    Barrier(int pin, int min = 500, int max = 2400); // The nodeMCU need to config the min and max value
    void Init();
    void Test();        // Test the servo (Sweep from 0 to 180 degree)
    void Open();        // Method to open the barrier
    void Close();       // Method to close the barrier
};

#endif // BARRIER_H