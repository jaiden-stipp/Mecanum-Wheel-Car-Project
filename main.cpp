#include "Car.h"
#include "Simulator.h"
#include <iostream>
#include <string>
#include <thread>
#include <chrono>

void displayMenu() {
    std::cout << "\n========== MECANUM WHEEL CAR SIMULATOR ==========\n";
    std::cout << "1. Move Forward\n";
    std::cout << "2. Move Backward\n";
    std::cout << "3. Move Left\n";
    std::cout << "4. Move Right\n";
    std::cout << "5. Turn Left\n";
    std::cout << "6. Turn Right\n";
    std::cout << "7. Stop\n";
    std::cout << "8. Loop Around Obstacles (Demo Pattern)\n";
    std::cout << "9. Capture Scene\n";
    std::cout << "10. Display Car Status\n";
    std::cout << "11. Display Motor Diagnostics\n";
    std::cout << "12. Run Demo Sequence\n";
    std::cout << "0. Quit\n";
    std::cout << "================================================\n";
    std::cout << "Enter your choice: ";
}

int getIntInput() {
    int input;
    while (!(std::cin >> input)) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Invalid input. Please enter a number: ";
    }
    return input;
}

int getSpeed() {
    std::cout << "Enter speed (0-255): ";
    int speed = getIntInput();
    if (speed < 0) speed = 0;
    if (speed > 255) speed = 255;
    return speed;
}

int getSteps() {
    std::cout << "Enter number of steps: ";
    int steps = getIntInput();
    if (steps < 1) steps = 1;
    return steps;
}

void handleMovement(Car& car, Simulator& sim, const std::string& direction, bool requiresSteps = true) {
    int speed = getSpeed();
    if (requiresSteps) {
        int steps = getSteps();
        std::cout << "\nMoving " << direction << " with speed " << speed << " for " << steps << " steps...\n";
        if (direction == "forward") {
            car.moveForward(speed);
            sim.moveForward(steps);
        } else if (direction == "backward") {
            car.moveBackward(speed);
            sim.moveBackward(steps);
        } else if (direction == "left") {
            car.moveLeft(speed);
            sim.moveLeft(steps);
        } else if (direction == "right") {
            car.moveRight(speed);
            sim.moveRight(steps);
        }
    } else {
        std::cout << "\nTurning " << direction << " with speed " << speed << "...\n";
        if (direction == "left") {
            car.turnLeft(speed);
        } else if (direction == "right") {
            car.turnRight(speed);
        }
    }
    sim.displayMap();
    sim.displayCarStatus();
}

void runDemoSequence(Car& car, Simulator& sim) {
    std::cout << "\n[DEMO] Starting demo sequence...\n";
    sim.displayMap();
    sim.displayCarStatus();
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    
    std::cout << "\n[DEMO 1] Moving forward at speed 200...\n";
    car.moveForward(200);
    sim.moveForward(3);
    sim.displayMap();
    sim.displayCarStatus();
    std::this_thread::sleep_for(std::chrono::milliseconds(800));
    
    std::cout << "\n[DEMO 2] Turning right...\n";
    car.turnRight(150);
    sim.displayMap();
    sim.displayCarStatus();
    std::this_thread::sleep_for(std::chrono::milliseconds(600));
    
    std::cout << "\n[DEMO 3] Moving in new direction (right)...\n";
    car.moveRight(200);
    sim.moveRight(3);
    sim.displayMap();
    sim.displayCarStatus();
    std::this_thread::sleep_for(std::chrono::milliseconds(800));
    
    std::cout << "\n[DEMO 4] Looping around obstacles\n";
    int speed = getSpeed();
    car.loopAroundObstacles(speed);
    sim.displayMap();
    sim.displayCarStatus();
    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    std::cout << "\n[DEMO 4] Capturing scene...\n";
    sim.captureCarScene();
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    
    
    std::cout << "\n[DEMO 5] Stopping car...\n";
    car.stop();
    car.displayDiagnostics();
    std::this_thread::sleep_for(std::chrono::milliseconds(600));
    
    std::cout << "\n[DEMO] Demo sequence complete!\n";
}

int main() {
    std::cout << "=== MECANUM WHEEL CAR SIMULATOR ===\n";
    std::cout << "Initializing car and simulator...\n";
    
    Car car;
    car.setCarDirection(FORWARD);
    
    Simulator sim(20, 10, &car);
    
    std::cout << "Car and simulator initialized successfully!\n";
    std::cout << "The car starts at position (" << 5 << ", " << 5 << ") facing " << directionToString(car.getCarDirection()) << "\n";
    sim.displayMap();
    int choice;
    bool running = true;
    
    while (running) {
        displayMenu();
        choice = getIntInput();
        
        switch (choice) {
            case 1: {
                handleMovement(car, sim, "forward", true);
                break;
            }
            case 2: {
                handleMovement(car, sim, "backward", true);
                break;
            }
            case 3: {
                handleMovement(car, sim, "left", true);
                break;
            }
            case 4: {
                handleMovement(car, sim, "right", true);
                break;
            }
            case 5: {
                handleMovement(car, sim, "left", false);
                break;
            }
            case 6: {
                handleMovement(car, sim, "right", false);
                break;
            }
            case 7: {
                std::cout << "\nStopping car...\n";
                car.stop();
                sim.displayMap();
                sim.displayCarStatus();
                break;
            }
            case 8: {
                int speed = getSpeed();
                car.loopAroundObstacles(speed);
                sim.displayMap();
                sim.displayCarStatus();
                break;
            }
            case 9: {
                std::cout << "\nCapturing scene...\n";
                sim.captureCarScene();
                break;
            }
            case 10: {
                std::cout << "\n";
                sim.displayCarStatus();
                break;
            }
            case 11: {
                std::cout << "\n";
                car.displayDiagnostics();
                break;
            }
            case 12: {
                runDemoSequence(car, sim);
                break;
            }
            case 0: {
                std::cout << "\nExiting simulator. Goodbye!\n";
                running = false;
                break;
            }
            default: {
                std::cout << "\nInvalid choice. Please try again.\n";
                break;
            }
        }
    }
    
    return 0;
}
