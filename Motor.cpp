#include "Motor.h"
#include <iostream>

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
void Motor::setSpeed(int speed) {
    mSpeed = speed;
}
void Motor::setDirection(Direction direction) {
    mDirection = direction;
}
void Motor::setName(std::string name) {
    mName = name;
}
void Motor::setID(int ID) {
    mID = ID;
}
void Motor::stop() {
    setSpeed(0);
    std::cout << "Motor has been stopped";
}
void Motor::displayStats(){
    std::cout << "Speed: " << getSpeed() << "\n";
    std::cout << "Direction: " << getDirection() << "\n";
    std::cout << "ID: " << getID() << "\n";
    std::cout << "Name: " << getName() << "\n";
}

int main() {
    Motor motor1;
    motor1.displayStats();
    motor1.setSpeed(50);
    motor1.setDirection(EAST);
    motor1.setName("Mach-1");
    motor1.setID(1);
    motor1.displayStats();

}
