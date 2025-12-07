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

static int dirToIndex(Direction d) {
    switch (d) {
        case FORWARD: return 0;
        case RIGHT: return 1;
        case BACKWARD: return 2;
        case LEFT: return 3;
        default: return 0;
    }
}

void Simulator::updatePositionBasedOnDirection(Direction moveDir, int steps) {
    for (int i = 0; i < steps; i++) {
        Direction facing = car->getCarDirection();
        int facingIdx = dirToIndex(facing);
        int moveIdx = dirToIndex(moveDir);
        int absoluteIdx = (facingIdx + moveIdx) % 4;

        // absoluteIdx: 0 = forward (up), 1 = right, 2 = backward (down), 3 = left
        if (absoluteIdx == 0) {
            if (y > 0) y--;
        } else if (absoluteIdx == 1) {
            if (x < mapWidth - 1) x++;
        } else if (absoluteIdx == 2) {
            if (y < mapHeight - 1) y++;
        } else if (absoluteIdx == 3) {
            if (x > 0) x--;
        }
    }
}

void Simulator::moveForward(int steps) {
    updatePositionBasedOnDirection(FORWARD, steps);
}

void Simulator::moveBackward(int steps) {
    updatePositionBasedOnDirection(BACKWARD, steps);
}

void Simulator::moveLeft(int steps) {
    updatePositionBasedOnDirection(LEFT, steps);
}

void Simulator::moveRight(int steps) {
    updatePositionBasedOnDirection(RIGHT, steps);
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
