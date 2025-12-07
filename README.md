# Mecanum Wheel Car Simulator
> A simple text-based simulator for a four-wheeled mecanum-drive car. This project was created as a final for TCES 203 by Jaiden Stipp

## Features

- Simulated `Car` composed of four `Motor` objects (Motor objects can be implemented to run on Raspberry Pi commands later)
- Direction-aware movement and turns (FORWARD / BACKWARD / LEFT / RIGHT)
- Text-based 2D map visualization showing car position and orientation
- Simple `Camera` capture that prints the car's facing direction (Can be implemented with real camera Later)
- Interactive menu and a built-in demo sequence

## Repository layout

- `main.cpp` — program entry, interactive menu and demo
- `Car.h` / `Car.cpp` — high-level car control and movement logic
- `Motor.h` / `Motor.cpp` — motor abstraction and diagnostics
- `Simulator.h` / `Simulator.cpp` — 2D text map and environment integration
- `Camera.h` / `Camera.cpp` — simulated camera capture
- `README.md` — this file

## Build (Windows PowerShell / WSL)

Requirements: a C++ compiler (g++ or clang++) that supports C++14.

Example (PowerShell):

```powershell
g++ -std=c++14 -O2 *.cpp -o MecanumWheelProject.exe
.\MecanumWheelProject.exe
```

Example (WSL / Linux / macOS):

```bash
g++ -std=c++14 -O2 *.cpp -o MecanumWheelProject
./MecanumWheelProject
```

If you use `clang++`, replace `g++` with `clang++` in the examples above.

## Running the simulator

1. Build as shown above.
2. Run the produced executable.
3. Use the interactive menu to move the car, run the demo, capture the scene, or view motor diagnostics.

Menu options include (from `main.cpp`):

- `1` Move Forward
- `2` Move Backward
- `3` Move Left
- `4` Move Right
- `5` Turn Left
- `6` Turn Right
- `7` Stop
- `8` Loop Around Obstacles (demo pattern)
- `9` Capture Scene
- `10` Display Car Status
- `11` Display Motor Diagnostics
- `12` Run Demo Sequence
- `0` Quit

When prompted for speed, enter a value 0–255. When prompted for steps, enter a positive integer that advances the simulated car on the map.
## Reflection

- The most challenging part of this project was implementing the simulator logic so that movement commands behave relative to the car's current facing. I experimented with several approaches (including creating a vector of the directions and iterating over it based upon the car's current direction) before settling on a system that uses a switch statement at each movement command to determine the movemnt direction.
- Another difficulty was managing class ownership and object interactions in C++. Passing objects between Simulator and Car via pointers took some trial and error, especially when I was balancing who is responsible for state and who issues commands.
- This project taught me to design an effective class structure and to use an enum to handle program wide directions. Moving from Java/Python to C++ OOP had a bit of a learning curve, but by the time I implemented `main.cpp`, I felt comfortable with memory/addressing, header separation, and class interfaces.
- During this project, I also learned how to build a cool README (to display on Github) like this through YouTube! 
## Demos

### Demo 1 (Demo Sequence)
In this demo, I demonstrate the Demo Sequence in `main.cpp` and then exit. 
```
=== MECANUM WHEEL CAR SIMULATOR ===
Initializing car and simulator...
Car and simulator initialized successfully!
The car starts at position (5, 5) facing FORWARD
+--------------------+
|                    |
|                    |
|                    |
|                    |
|                    |
|          ^         |
|                    |
|                    |
|                    |
|                    |
+--------------------+

========== MECANUM WHEEL CAR SIMULATOR ==========
1. Move Forward
2. Move Backward
3. Move Left
4. Move Right
5. Turn Left
6. Turn Right
7. Stop
8. Loop Around Obstacles (Demo Pattern)
9. Capture Scene
10. Display Car Status
11. Display Motor Diagnostics
12. Run Demo Sequence
0. Quit
================================================
Enter your choice: 12

[DEMO] Starting demo sequence...
+--------------------+
|                    |
|                    |
|                    |
|                    |
|                    |
|          ^         |
|                    |
|                    |
|                    |
|                    |
+--------------------+
Car Position: (10, 5)
Car Direction: FORWARD

[DEMO 1] Moving forward at speed 200...
+--------------------+
|                    |
|                    |
|          ^         |
|                    |
|                    |
|                    |
|                    |
|                    |
|                    |
|                    |
+--------------------+
Car Position: (10, 2)
Car Direction: FORWARD

[DEMO 2] Turning right...
+--------------------+
|                    |
|                    |
|          >         |
|                    |
|                    |
|                    |
|                    |
|                    |
|                    |
|                    |
+--------------------+
Car Position: (10, 2)
Car Direction: RIGHT

[DEMO 3] Moving in new direction (right)...
+--------------------+
|                    |
|                    |
|             >      |
|                    |
|                    |
|                    |
|                    |
|                    |
|                    |
|                    |
+--------------------+
Car Position: (13, 2)
Car Direction: RIGHT

[DEMO 4] Looping around obstacles
Enter speed (0-255): 100
[Car] Starting loop around obstacles pattern...
[Car] Moving forward...
[Car] Turning left...
[Car] Moving forward...
[Car] Turning left...
[Car] Moving forward...
[Car] Turning left...
[Car] Moving forward...
[Car] Turning left...
[Car] Loop pattern complete!
+--------------------+
|                    |
|                    |
|             >      |
|                    |
|                    |
|                    |
|                    |
|                    |
|                    |
|                    |
+--------------------+
Car Position: (13, 2)
Car Direction: RIGHT

[DEMO 4] Capturing scene...
Capturing scene at position (13, 2) facing RIGHT

[DEMO 5] Stopping car...
Car Diagnostics:
Motor Front Left (ID: 1):
Speed: 0
Direction: FORWARD
ID: 1
Name: Front Left

Motor Front Right (ID: 2):
Speed: 0
Direction: FORWARD
ID: 2
Name: Front Right

Motor Rear Left (ID: 3):
Speed: 0
Direction: FORWARD
ID: 3
Name: Rear Left

Motor Rear Right (ID: 4):
Speed: 0
Direction: FORWARD
ID: 4
Name: Rear Right


[DEMO] Demo sequence complete!

========== MECANUM WHEEL CAR SIMULATOR ==========
1. Move Forward
2. Move Backward
3. Move Left
4. Move Right
5. Turn Left
6. Turn Right
7. Stop
8. Loop Around Obstacles (Demo Pattern)
9. Capture Scene
10. Display Car Status
11. Display Motor Diagnostics
12. Run Demo Sequence
0. Quit
================================================
Enter your choice: 0

Exiting simulator. Goodbye!
```
Demo behaves as intended
### Demo 2 (Moving along edges)
In this demo, I demonstrate a movement sequence that goes beyond the bounds and moves around the border of the simulator. Should demonstrate how the car moves in the direction it is currently facing relative to the given command
```
=== MECANUM WHEEL CAR SIMULATOR ===
Initializing car and simulator...
Car and simulator initialized successfully!
The car starts at position (5, 5) facing FORWARD
+--------------------+
|                    |
|                    |
|                    |
|                    |
|                    |
|          ^         |
|                    |
|                    |
|                    |
|                    |
+--------------------+

========== MECANUM WHEEL CAR SIMULATOR ==========
1. Move Forward
2. Move Backward
3. Move Left
4. Move Right
5. Turn Left
6. Turn Right
7. Stop
8. Loop Around Obstacles (Demo Pattern)
9. Capture Scene
10. Display Car Status
11. Display Motor Diagnostics
12. Run Demo Sequence
0. Quit
================================================
Enter your choice: 1
Enter speed (0-255): 100
Enter number of steps: 10

Moving forward with speed 100 for 10 steps...
+--------------------+
|          ^         |
|                    |
|                    |
|                    |
|                    |
|                    |
|                    |
|                    |
|                    |
|                    |
+--------------------+
Car Position: (10, 0)
Car Direction: FORWARD

========== MECANUM WHEEL CAR SIMULATOR ==========
1. Move Forward
2. Move Backward
3. Move Left
4. Move Right
5. Turn Left
6. Turn Right
7. Stop
8. Loop Around Obstacles (Demo Pattern)
9. Capture Scene
10. Display Car Status
11. Display Motor Diagnostics
12. Run Demo Sequence
0. Quit
================================================
Enter your choice: 6
Enter speed (0-255): 100

Turning right with speed 100...
+--------------------+
|          >         |
|                    |
|                    |
|                    |
|                    |
|                    |
|                    |
|                    |
|                    |
|                    |
+--------------------+
Car Position: (10, 0)
Car Direction: RIGHT

========== MECANUM WHEEL CAR SIMULATOR ==========
1. Move Forward
2. Move Backward
3. Move Left
4. Move Right
5. Turn Left
6. Turn Right
7. Stop
8. Loop Around Obstacles (Demo Pattern)
9. Capture Scene
10. Display Car Status
11. Display Motor Diagnostics
12. Run Demo Sequence
0. Quit
================================================
Enter your choice: 1
Enter speed (0-255): 100
Enter number of steps: 100

Moving forward with speed 100 for 100 steps...
+--------------------+
|                   >|
|                    |
|                    |
|                    |
|                    |
|                    |
|                    |
|                    |
|                    |
|                    |
+--------------------+
Car Position: (19, 0)
Car Direction: RIGHT

========== MECANUM WHEEL CAR SIMULATOR ==========
1. Move Forward
2. Move Backward
3. Move Left
4. Move Right
5. Turn Left
6. Turn Right
7. Stop
8. Loop Around Obstacles (Demo Pattern)
9. Capture Scene
10. Display Car Status
11. Display Motor Diagnostics
12. Run Demo Sequence
0. Quit
================================================
Enter your choice: 4
Enter speed (0-255): 100
Enter number of steps: 20

Moving right with speed 100 for 20 steps...
+--------------------+
|                    |
|                    |
|                    |
|                    |
|                    |
|                    |
|                    |
|                    |
|                    |
|                   >|
+--------------------+
Car Position: (19, 9)
Car Direction: RIGHT

========== MECANUM WHEEL CAR SIMULATOR ==========
1. Move Forward
2. Move Backward
3. Move Left
4. Move Right
5. Turn Left
6. Turn Right
7. Stop
8. Loop Around Obstacles (Demo Pattern)
9. Capture Scene
10. Display Car Status
11. Display Motor Diagnostics
12. Run Demo Sequence
0. Quit
================================================
Enter your choice: 2
Enter speed (0-255): 50
Enter number of steps: 10

Moving backward with speed 50 for 10 steps...
+--------------------+
|                    |
|                    |
|                    |
|                    |
|                    |
|                    |
|                    |
|                    |
|                    |
|         >          |
+--------------------+
Car Position: (9, 9)
Car Direction: RIGHT

========== MECANUM WHEEL CAR SIMULATOR ==========
1. Move Forward
2. Move Backward
3. Move Left
4. Move Right
5. Turn Left
6. Turn Right
7. Stop
8. Loop Around Obstacles (Demo Pattern)
9. Capture Scene
10. Display Car Status
11. Display Motor Diagnostics
12. Run Demo Sequence
0. Quit
================================================
Enter your choice: 5
Enter speed (0-255): 100

Turning left with speed 100...
+--------------------+
|                    |
|                    |
|                    |
|                    |
|                    |
|                    |
|                    |
|                    |
|                    |
|         ^          |
+--------------------+
Car Position: (9, 9)
Car Direction: FORWARD

========== MECANUM WHEEL CAR SIMULATOR ==========
1. Move Forward
2. Move Backward
3. Move Left
4. Move Right
5. Turn Left
6. Turn Right
7. Stop
8. Loop Around Obstacles (Demo Pattern)
9. Capture Scene
10. Display Car Status
11. Display Motor Diagnostics
12. Run Demo Sequence
0. Quit
================================================
Enter your choice: 1
Enter speed (0-255): 50
Enter number of steps: 5

Moving forward with speed 50 for 5 steps...
+--------------------+
|                    |
|                    |
|                    |
|                    |
|         ^          |
|                    |
|                    |
|                    |
|                    |
|                    |
+--------------------+
Car Position: (9, 4)
Car Direction: FORWARD

========== MECANUM WHEEL CAR SIMULATOR ==========
1. Move Forward
2. Move Backward
3. Move Left
4. Move Right
5. Turn Left
6. Turn Right
7. Stop
8. Loop Around Obstacles (Demo Pattern)
9. Capture Scene
10. Display Car Status
11. Display Motor Diagnostics
12. Run Demo Sequence
0. Quit
================================================
Enter your choice: 0

Exiting simulator. Goodbye!
```
Demo behaves as intended

## Demo 3 (Camera, Status, and Motors)
In this demo, I demonstrate the Camera, Car Status, and Motor Diagnostics options in the menu
```
=== MECANUM WHEEL CAR SIMULATOR ===
Initializing car and simulator...
Car and simulator initialized successfully!
The car starts at position (5, 5) facing FORWARD
+--------------------+
|                    |
|                    |
|                    |
|                    |
|                    |
|          ^         |
|                    |
|                    |
|                    |
|                    |
+--------------------+

========== MECANUM WHEEL CAR SIMULATOR ==========
1. Move Forward
2. Move Backward
3. Move Left
4. Move Right
5. Turn Left
6. Turn Right
7. Stop
8. Loop Around Obstacles (Demo Pattern)
9. Capture Scene
10. Display Car Status
11. Display Motor Diagnostics
12. Run Demo Sequence
0. Quit
================================================
Enter your choice: 1
Enter speed (0-255): 100
Enter number of steps: 1 

Moving forward with speed 100 for 1 steps...
+--------------------+
|                    |
|                    |
|                    |
|                    |
|          ^         |
|                    |
|                    |
|                    |
|                    |
|                    |
+--------------------+
Car Position: (10, 4)
Car Direction: FORWARD

========== MECANUM WHEEL CAR SIMULATOR ==========
1. Move Forward
2. Move Backward
3. Move Left
4. Move Right
5. Turn Left
6. Turn Right
7. Stop
8. Loop Around Obstacles (Demo Pattern)
9. Capture Scene
10. Display Car Status
11. Display Motor Diagnostics
12. Run Demo Sequence
0. Quit
================================================
Enter your choice: 9

Capturing scene...
Capturing scene at position (10, 4) facing FORWARD

========== MECANUM WHEEL CAR SIMULATOR ==========
1. Move Forward
2. Move Backward
3. Move Left
4. Move Right
5. Turn Left
6. Turn Right
7. Stop
8. Loop Around Obstacles (Demo Pattern)
9. Capture Scene
10. Display Car Status
11. Display Motor Diagnostics
12. Run Demo Sequence
0. Quit
================================================
Enter your choice: 10

Car Position: (10, 4)
Car Direction: FORWARD

========== MECANUM WHEEL CAR SIMULATOR ==========
1. Move Forward
2. Move Backward
3. Move Left
4. Move Right
5. Turn Left
6. Turn Right
7. Stop
8. Loop Around Obstacles (Demo Pattern)
9. Capture Scene
10. Display Car Status
11. Display Motor Diagnostics
12. Run Demo Sequence
0. Quit
================================================
Enter your choice: 11

Car Diagnostics:
Motor Front Left (ID: 1):
Speed: 100
Direction: FORWARD
ID: 1
Name: Front Left

Motor Front Right (ID: 2):
Speed: 100
Direction: FORWARD
ID: 2
Name: Front Right

Motor Rear Left (ID: 3):
Speed: 100
Direction: FORWARD
ID: 3
Name: Rear Left

Motor Rear Right (ID: 4):
Speed: 100
Direction: FORWARD
ID: 4
Name: Rear Right


========== MECANUM WHEEL CAR SIMULATOR ==========
1. Move Forward
2. Move Backward
3. Move Left
4. Move Right
5. Turn Left
6. Turn Right
7. Stop
8. Loop Around Obstacles (Demo Pattern)
9. Capture Scene
10. Display Car Status
11. Display Motor Diagnostics
12. Run Demo Sequence
0. Quit
================================================
Enter your choice: 7

Stopping car...
+--------------------+
|                    |
|                    |
|                    |
|                    |
|          ^         |
|                    |
|                    |
|                    |
|                    |
|                    |
+--------------------+
Car Position: (10, 4)
Car Direction: FORWARD

========== MECANUM WHEEL CAR SIMULATOR ==========
1. Move Forward
2. Move Backward
3. Move Left
4. Move Right
5. Turn Left
6. Turn Right
7. Stop
8. Loop Around Obstacles (Demo Pattern)
9. Capture Scene
10. Display Car Status
11. Display Motor Diagnostics
12. Run Demo Sequence
0. Quit
================================================
Enter your choice: 0

Exiting simulator. Goodbye!
```
Demo works as intended


## Directions file format (planned)

> Note: File input is a planned feature and is not implmented yet. Integration requires a file parser that reads files in the format shown below:

```
FORWARD 200 3      # move forward at speed 200 for 3 steps
TURNRIGHT 150      # turn right (rotation uses speed value as placeholder)
RIGHT 200 2        # move right at speed 200 for 2 steps
CAPTURE            # take a camera capture at current position
STOP               # stop the car
```





