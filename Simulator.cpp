#include "Simulator.h"
#include "Motor.h"
#include <iostream>
#include <cmath>

Simulator::Simulator(int width, int height, Car* car) : mapWidth(width), mapHeight(height), car(car), x(width/2), y(height/2), direction(0) {
    map.resize(height, std::vector<int>(width, '.'));
}

void Simulator::updateCarPosition(int newX, int newY, int newDirection) {
    x = newX;
    y = newY;
    direction = newDirection;
}

void Simulator::updatePositionBasedOnDirection(int steps) {
    for (int i = 0; i < steps; i++) {
        Direction dir = car->getCarDirection();
        if (dir == FORWARD) {
            if (y > 0) y--;
        } else if (dir == BACKWARD) {
            if (y < mapHeight - 1) y++;
        } else if (dir == LEFT) {
            if (x > 0) x--;
        } else if (dir == RIGHT) {
            if (x < mapWidth - 1) x++;
        }
    }
}

void Simulator::moveForward(int steps) {
    updatePositionBasedOnDirection(steps);
}

void Simulator::moveBackward(int steps) {
    for (int i = 0; i < steps; i++) {
        if (y < mapHeight - 1) y++;
    }
}

void Simulator::moveLeft(int steps) {
    for (int i = 0; i < steps; i++) {
        if (x > 0) x--;
    }
}

void Simulator::moveRight(int steps) {
    for (int i = 0; i < steps; i++) {
        if (x < mapWidth - 1) x++;
    }
}

void Simulator::displayMap() {
    char directionChar;
    Direction dir = car->getCarDirection();
    switch (dir) {
        case FORWARD: directionChar = '^'; break;
        case BACKWARD: directionChar = 'v'; break;
        case LEFT: directionChar = '<'; break;
        case RIGHT: directionChar = '>'; break;
        default: directionChar = '?'; break;
    }
    
    std::cout << "+";
    for (int j = 0; j < mapWidth; ++j) std::cout << "-";
    std::cout << "+\n";
    
    for (int i = 0; i < mapHeight; ++i) {
        std::cout << "|";
        for (int j = 0; j < mapWidth; ++j) {
            if (i == y && j == x) {
                std::cout << directionChar;
            } else {
                std::cout << ' ';
            }
        }
        std::cout << "|\n";
    }
    
    std::cout << "+";
    for (int j = 0; j < mapWidth; ++j) std::cout << "-";
    std::cout << "+\n";
}

void Simulator::displayCarStatus() const {
    std::cout << "Car Position: (" << x << ", " << y << ")\n";
    Direction dir = car->getCarDirection();
    std::cout << "Car Direction: " << directionToString(dir) << "\n";
}

bool Simulator::isCarWithinBounds() const {
    return (x >= 0 && x < mapWidth && y >= 0 && y < mapHeight);
}

void Simulator::captureCarScene() {
    car->captureScene(x, y, car->getCarDirection());
}
