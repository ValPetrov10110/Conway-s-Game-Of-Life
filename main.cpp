#include <iostream>
#include <fstream>
#include <vector>
#include <thread>
#include <chrono>
#include "Simulation.h"

// These are my function declarations
int startMenu();
int getUserIntInput();
void infoPage();
void gameScreen();
int getXValue();
int getYValue();
void getUserCell(std::vector<std::vector<char>>& grid, int& x, int& y);

int main(){
	bool repeatValue = false;
		do{
			switch(startMenu()){
				case 1:
					system("clear");
					gameScreen();
				break;

				case 2:
					infoPage();
					repeatValue = true;
				break;

				case 3:
					std::cout << "Thank you for visiting! Goodbye.\n";
					repeatValue = false;
				break;

				default:
					std::cout << "Somehow you got this message? Please enter an integer (1-3)\n";
					std::cout << "Press any key to continue...";
					clearInputBuffer();
					std::cin.get();
					repeatValue = true;
			}
	}while(repeatValue);

	return EXIT_SUCCESS;
}

// This function displays the main menu screen to the user
int startMenu(){
	system("clear");
	std::cout << "Conway's Game of Life In C++\n----------------------------\n";
	std::cout << "1.) Start Game\n2.) Info\n3.) Exit\n";
	
	return getUserIntInput();
}

// This function accepts users input for INTS
int getUserIntInput(){
	std::cout << "> ";
	int userResponse{};
	std::cin >> userResponse;

	return userResponse;
}

// This function displays the info to the user through file I/O
void infoPage(){
	system("clear");
	std::string fileText{};
	std::fstream infoFile ("infoPage.txt");

	if(infoFile.is_open()){
		while(std::getline(infoFile, fileText)){
			std::cout << fileText << '\n';
		}
	}
	// I will worry about if the file doesn't open later on in the program
	
	std::cout << "\nPress any key to return to main menu...";
	clearInputBuffer();
	std::cin.get();
	infoFile.close();
}

int getXValue(){
	const int MAX_X = 50;
	const int MIN_X = 5;
	int xValue{};

	do{
		std::cout << "Enter how many rows [Maximum 50, Minimum 5]: ";
		std::cin >> xValue;
	}while(xValue < MIN_X || xValue > MAX_X);

	return xValue;
}

int getYValue(){
	const int MAX_Y = 50;
	const int MIN_Y = 5;
	int yValue{};

	do{
		std::cout << "Enter how many columns [Maximum 50, Minimum 5]: ";
		std::cin >> yValue;
	}while(yValue < MIN_Y || yValue > MAX_Y);

	return yValue;
}

void gameScreen(){
	int xValue = getXValue();
	int yValue = getYValue();
	std::vector<std::vector<char>> grid(xValue, std::vector<char>(yValue, '.'));
	
	printGrid(grid, xValue, yValue);
	std::cout << '\n';

	getUserCell(grid, xValue, yValue);
	startSimulation(grid, xValue, yValue);
}

void getUserCell(std::vector<std::vector<char>>& grid, int& x, int& y){
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
