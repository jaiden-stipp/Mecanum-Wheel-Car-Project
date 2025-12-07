#ifndef _CAR_
#define _CAR_


#include "Motor.h"
#include "Camera.h"
#include <vector>

const int NUM_MOTORS = 4;

class Car {
    private:
        Camera carCamera;
        std::vector<Motor> motors;
        Direction currentDirection = FORWARD;
        void setMotors(Direction fl, Direction fr, Direction rl, Direction rr, int speed);
    public:
        Car();
        void moveForward(int speed);
        void moveBackward(int speed);
        void moveLeft(int speed);
        void moveRight(int speed);
        void turnLeft(int speed);
        void turnRight(int speed);
        void stop();
        void loopAroundObstacles(int speed);
        Direction getCarDirection() const;
        void setCarDirection(Direction direction);
        void moveInDirection(Direction direction, int speed);
        void displayDiagnostics() const;

        void captureScene(int x, int y, Direction direction);
};
#endif 