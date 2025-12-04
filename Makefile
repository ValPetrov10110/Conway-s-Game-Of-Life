CXX = g++

CXXFLAGS = -std=c++17 -Wall -Wextra -Wpedantic

TARGET = main

SRC = main.cpp Simulation.cpp Checker.cpp Input.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -rf $(TARGET)
