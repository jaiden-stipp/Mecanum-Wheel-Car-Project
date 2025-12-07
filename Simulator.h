#ifndef _SIM_
#define _SIM_
#include "Car.h"
#include <iostream>
#include <vector>


class Simulator {
    private:
        int x;
        int y;
        int direction;
        Car* car;
        int mapHeight;
        int mapWidth;
        std::vector<std::vector<int>> map;
        
        void updatePositionBasedOnDirection(int steps);

    public:
        Simulator(int width, int height, Car* car);
        void updateCarPosition(int newX, int newY, int newDirection);
        void moveForward(int steps = 1);
        void moveBackward(int steps = 1);
        void moveLeft(int steps = 1);
        void moveRight(int steps = 1);
        void displayMap();
        void displayCarStatus() const;
        bool isCarWithinBounds() const;
        void captureCarScene();
};

#endif