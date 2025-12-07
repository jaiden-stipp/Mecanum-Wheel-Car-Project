#include "Motor.h"
#include <iostream>


std::string directionToString(Direction direction) {
    switch (direction) {
        case FORWARD: return "FORWARD";
        case BACKWARD: return "BACKWARD";
        case LEFT: return "LEFT";
        case RIGHT: return "RIGHT";
        default: return "UNKNOWN";
    }
    
}
int Motor::nextID = 0;
Motor::Motor(std::string name) : mSpeed(0), mDirection(FORWARD), mName(name), mID(++nextID) {

}

int Motor::getSpeed() const {
    return mSpeed;
}

Direction Motor::getDirection() const {
    return mDirection;
}

std::string Motor::getName() const {
    return mName;
}

int Motor::getID() const {
    return mID;
}

void Motor::setSpeed(int speed) {
    if (speed < 0) {speed = 0;}
    if (speed > 255) {speed = 255;}
    mSpeed = speed;
}

void Motor::setDirection(Direction direction) {
    mDirection = direction;
}

void Motor::stop() {
    setSpeed(0);
    std::cout << "Motor has been stopped";
}
void Motor::displayStats() const {
    std::cout << "Speed: " << getSpeed() << "\n";
    std::cout << "Direction: " << directionToString(mDirection) << "\n";
    std::cout << "ID: " << getID() << "\n";
    std::cout << "Name: " << getName() << "\n\n";
}




