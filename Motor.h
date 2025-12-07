#ifndef _MOTOR_
#define _MOTOR_

#include <string>


enum Direction {FORWARD, BACKWARD, LEFT, RIGHT};

std::string directionToString(Direction direction);

class Motor {
    private:
        int mSpeed = 0;
        Direction mDirection;
        const int mID;
        static int nextID;
        const std::string mName = "";
    public:
        Motor(std::string name = "Unnamed");
        int getSpeed() const;
        Direction getDirection() const;
        std::string getName() const;
        int getID() const;
        void setSpeed(int speed);
        void setDirection(Direction direction);
        
        void stop();
        void displayStats() const;
        
    
};
#endif