#ifndef _MOTOR_
#define _MOTOR_
#include <iostream>
#include <string>


enum Direction {FORWARD, BACKWARD, LEFT, RIGHT};

class Motor {
    private:
        int mSpeed = 0;
        Direction mDirection = FORWARD;
        const int mID;
        static int nextID;
        const std::string mName = "";
    public:
        Motor(std::string name = "Unnamed");
        int getSpeed();
        Direction getDirection();
        std::string getName();
        int getID();
        void setSpeed(int speed);
        void setDirection(Direction direction);
        
        void stop();
        void displayStats();
        void setup();
    
};
#endif