#include <iostream>
#include <thread>
#include <chrono>

#include "Input.h"
#include "Simulation.h"

constexpr int MAX = 50;
constexpr int MIN = 5;

int getUserIntInput(){
	std::cout << "> ";
	int userResponse{};
	std::cin >> userResponse;

	return userResponse;
}

int getXValue(){
	int xValue{};

	do{
		std::cout << "Enter how many rows [Maximum 50, Minimum 5]: ";
		std::cin >> xValue;
	}while(xValue < MIN || xValue > MAX);

	return xValue;
}

int getYValue(){
	int yValue{};

	do{
		std::cout << "Enter how many columns [Maximum 50, Minimum 5]: ";
		std::cin >> yValue;
	}while(yValue < MIN || yValue > MAX);

	return yValue;
}

void getUserCell(char2Dvector& grid, int& x, int& y){
	
	char replayValue{};
	do{
		std::cout << "\nEnter Cell's location[i.e., 8 12]: ";
		int xAxis{}, yAxis{};
		std::cin >> xAxis >> yAxis;
		if(xAxis > x || yAxis > y || xAxis <= 0 || yAxis <= 0){
			std::cout << "OUT-OF-BOUNDS ERROR: AUTOMATICALLY REDIRECTING\n";
			std::this_thread::sleep_for(std::chrono::seconds(2));
			system("clear");
			printGrid(grid, x, y);
			getUserCell(grid, x, y);
		}
		grid[yAxis - 1][xAxis - 1] = 'o';
		printGrid(grid, x, y);
		std::cout << "\nWould you like to input another location (Y/n): ";
		std::cin >> replayValue;

	}while(toupper(replayValue) != 'N');
}
