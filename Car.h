#ifndef _CAR_
#define _CAR_

#include <iostream>
#include "Motor.h"

class Car {
    private:
        Motor frontLeft;
        Motor frontRight;
        Motor backLeft;
        Motor backRight;
    public:
        Car();
        void moveForward(int speed);
        void displayDiagnostics();
        void moveBackward(int speed);
        void turnLeft(int speed);
        void turnRight(int speed);
        void setCarDirection(Direction direction);
        void stop();
        void startCar(int speed);
};

#endif 