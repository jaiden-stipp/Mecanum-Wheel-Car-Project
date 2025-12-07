#include "Camera.h"
#include "Motor.h"
#include <iostream>

void Camera::startStream() {
    std::cout << "Camera stream started\n";
}

void Camera::stopStream() {
    std::cout << "Camera stream stopped\n";
}

void Camera::capture(int x, int y, Direction direction) {
    std::cout << "Capturing scene at position (" << x << ", " << y << ") facing " << directionToString(direction) << "\n";
}
