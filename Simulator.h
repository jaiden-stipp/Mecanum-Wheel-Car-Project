#ifndef _SIM_
#define _SIM_
#include "Car.h"
#include <iostream>


class Simulator {
    private:
        int x;
        int y;
        int direction;
        const Car car;

    public:
        void mainLoop();
        int updatePos();
        void move(int direction);
};

#endif