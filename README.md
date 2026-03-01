# Conway's Game of Life (C++ Terminal Simulation)

A terminal-based implementation of Conway's Game of Life written in C++. This project simulates cellular atomaton on a 2D grid and supports loading and saving predefined patterns.

## About The Game
Conway's Game of Life is a zero-player cellular automaton simulation where each cell evolves according to a set of rules:
1. Any live cell with fewer than two live neighbors dies
2. Any live cell with two or three live neighbors survives
3. Any live cell with more than three live neighbors dies
4. Any dead cell with exactly three live neighbors becomes alive

## Features
- Interactive grid configuration
- Load predefined patterns from files
- Modular multi-file C++ 
- Clean grid refreshing
- CMake build system

## Requirements
- CMake >= 3.15
- C++17-compatible compiler

## Build Instructions
Clone the repository:
```
git clone https://github.com/ValPetrov10110/Conway-s-Game-Of-Life.git
cd Conway-s-Game-Of-Life
```

Create a build directory and compile
```
mkdir build
cd build
cmake ..
make
```

Make sure to run the program from the project root
```
cd ..
./build/GameOfLife
```

## Project Structure

Directory hierarchy
```
Conways-s-Game-Of-Life/
  CmakeLists.txt
  main.cpp
  Simulation.cpp
  Simulation.h
  Checker.cpp
  Checker.h
  Input.cpp
  Input.h
  LoadSave.cpp
  LoadSave.h
  Saves/
  README.md
```

Components roles
- Simulation: Core Game of Life update logic
- Checker: Neighbor counting and rule evaluation
- Input: User interaction handling
- LoadSave: loading/saving logic
- Saves/: predefined pattern files

## Known Issues
- Non-numeric input for coordinates may cause undefined behavior
- Program expects to be run from the repository root so `Saves/` works correctly

## License
Open source project under the MIT License

