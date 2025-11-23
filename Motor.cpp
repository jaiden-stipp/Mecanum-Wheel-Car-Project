#include "Motor.h"
#include <iostream>

// TO-DO Implement Motor Drivers using PiGPIO

Motor::Motor(std::string name)
    : mSpeed(0), mDirection(FORWARD), mName(name), mID(++nextID) {}
int Motor::getSpeed() {
    return mSpeed;
}
Direction Motor::getDirection() {
    return mDirection;
}
std::string Motor::getName() {
    return mName;
}
int Motor::getID() {
    return mID;
}

// IMPORTANT TO CHANGE TO GPIO
void Motor::setSpeed(int speed) {
    mSpeed = speed;
}
// IMPORTANT TO CHANGE TO GPIO
void Motor::setDirection(Direction direction) {
    mDirection = direction;
}

void Motor::stop() {
    setSpeed(0);
    std::cout << "Motor has been stopped";
}
void Motor::displayStats(){
    std::cout << "Speed: " << getSpeed() << "\n";
    std::cout << "Direction: " << getDirection() << "\n";
    std::cout << "ID: " << getID() << "\n";
    std::cout << "Name: " << getName() << "\n\n";
}

int Motor::nextID = 0;


