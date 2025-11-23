#include "Car.h"

// TO-DO: Figure out how Motors/Car Operates and moves and then make class accordingly
Car::Car() : frontLeft("front-left"),
      frontRight("front-right"),
      backLeft("back-left"),
      backRight("back-right") {
    
}
void Car::moveForward(int speed) {
    setCarDirection(FORWARD);
    startCar(speed);
}

void Car::startCar(int speed) {
    frontLeft.setSpeed(speed);
    frontRight.setSpeed(speed);
    backLeft.setSpeed(speed);
    backRight.setSpeed(speed);

}
void Car::setCarDirection(Direction direction) {
    switch (direction) {
        case FORWARD:
        case BACKWARD:
            frontLeft.setDirection(direction);
            frontRight.setDirection(direction);
            backLeft.setDirection(direction);
            backRight.setDirection(direction);
            break;
        case LEFT:
            frontLeft.
    }
}
void Car::displayDiagnostics() {
    frontLeft.displayStats();
    frontRight.displayStats();
    backLeft.displayStats();
    backRight.displayStats();
}
int main() {
    Car car1;
    car1.displayDiagnostics();
}