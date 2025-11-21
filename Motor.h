#ifndef _MOTOR_
#define _MOTOR_
#include <iostream>
#include <string>


enum Direction {NORTH, SOUTH, EAST, WEST};
class Motor {
    
    public:
        
        int getSpeed();
        Direction getDirection();
        std::string getName();
        int getID();
        void setSpeed(int speed);
        void setDirection(Direction direction);
        void setName(std::string name);
        void setID(int ID);
        void stop();
        void displayStats();
    private:
        
        int mSpeed = 0;
        Direction mDirection = NORTH;
        int mID = 0;
        std::string mName = "";
    
    
};
#endif