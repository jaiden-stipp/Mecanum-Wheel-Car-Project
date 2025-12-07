#ifndef _CAMERA_
#define _CAMERA_

#include "Motor.h"

class Camera {
    public:
        void startStream();
        void stopStream();
        void capture(int x, int y, Direction direction);
};
#endif