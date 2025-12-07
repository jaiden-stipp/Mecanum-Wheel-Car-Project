#include "Car.h"
#include <iostream>
#include <thread>
#include <chrono>

Car::Car() : motors({Motor("Front Left"), Motor("Front Right"), Motor("Rear Left"), Motor("Rear Right")}) {

};

void Car::setMotors(Direction fl, Direction fr, Direction rl, Direction rr, int speed) {
    for (Motor& motor : motors) {
        motor.setSpeed(speed);
    }
    
    motors[0].setDirection(fl);
    motors[1].setDirection(fr);
    motors[2].setDirection(rl);
    motors[3].setDirection(rr);
}
// moveInDirection replaces moveForward and moveBackward because the car can move in any direction with the Mecanum wheels
void Car::moveInDirection(Direction direction, int speed) {
    switch (direction) {
        case FORWARD:
            setMotors(FORWARD, FORWARD, FORWARD, FORWARD, speed);
            break;
        case BACKWARD:
            setMotors(BACKWARD, BACKWARD, BACKWARD, BACKWARD, speed);
            break;
        case LEFT:
            setMotors(LEFT, LEFT, LEFT, LEFT, speed);
            break;
        case RIGHT:
            setMotors(RIGHT, RIGHT, RIGHT, RIGHT, speed);
            break;
        default:
            std::cout << "Invalid direction!" << std::endl;
            break;
    }
}

void Car::turnLeft(int speed) {
    setMotors(BACKWARD, FORWARD, BACKWARD, FORWARD, speed);
    
    
    switch (currentDirection) {
        case FORWARD:
            currentDirection = LEFT;
            break;
        case BACKWARD:
            currentDirection = RIGHT;
            break;
        case LEFT:
            currentDirection = BACKWARD;
            break;
        case RIGHT:
            currentDirection = FORWARD;
            break;
    }
}

void Car::turnRight(int speed) {
    setMotors(FORWARD, BACKWARD, FORWARD, BACKWARD, speed);
    
    
    switch (currentDirection) {
        case FORWARD:
            currentDirection = RIGHT;
            break;
        case BACKWARD:
            currentDirection = LEFT;
            break;
        case LEFT:
            currentDirection = FORWARD;
            break;
        case RIGHT:
            currentDirection = BACKWARD;
            break;
    }
}

Direction Car::getCarDirection() const {
    return currentDirection;
}

void Car::setCarDirection(Direction direction) {
    currentDirection = direction;
}

void Car::stop() {
    setMotors(FORWARD, FORWARD, FORWARD, FORWARD, 0);
}
// Redundant with moveInDirection but kept for clarity
void Car::moveForward(int speed) {
    moveInDirection(FORWARD, speed);
}

void Car::moveBackward(int speed) {
    moveInDirection(BACKWARD, speed);
}

void Car::moveLeft(int speed) {
    moveInDirection(LEFT, speed);
}

void Car::moveRight(int speed) {
    moveInDirection(RIGHT, speed);
}

void Car::loopAroundObstacles(int speed) {
    // Simple loop pattern that traces a square pattern around obstacles
    std::cout << "[Car] Starting loop around obstacles pattern...\n";
    for (int i = 0; i < 4; i++) {
        std::cout << "[Car] Moving forward...\n";
        moveForward(speed);
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        
        std::cout << "[Car] Turning left...\n";
        turnLeft(150);
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    }
    std::cout << "[Car] Loop pattern complete!\n";
    stop();
}


void Car::displayDiagnostics() const {
    std::cout << "Car Diagnostics:\n";
    for (const Motor& motor : motors) {
        std::cout << "Motor " << motor.getName() << " (ID: " << motor.getID() << "):\n";
        motor.displayStats();
    }
}
void Car::captureScene(int x, int y, Direction direction) {
    carCamera.capture(x, y, direction);
}
