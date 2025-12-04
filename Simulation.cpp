#include <iostream>
#include <limits>
#include <thread>
#include <chrono>
#include "Checker.h"
#include "Simulation.h"

void clearInputBuffer(){
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void printGrid(char2Dvector& grid, int& x, int& y){
	system("clear");
	std::cout << '\n';
	for(int row = 0; row < x; row++){
		std::cout << '\t';
		for(int col = 0; col < y; col++){
			std::cout << grid[row][col] << " ";
		}
		std::cout << '\n';
	}	
}

void startSimulation(char2Dvector& grid, int& x, int& y){
	system("clear");
	printGrid(grid, x, y);
	int generation{};
	std::cout << "WARNING: In order to exit the simulation you must hold Ctrl + C\n";
	std::cout << "\nPress any key to start simulation...";
	clearInputBuffer();
	std::cin.get();

	while(true){
		// std::cout << "Generation: " << generation++ << "\n"; [Too buggy; I'll see what I can do]

		// When I do loop for multiple generations I do want to include this line underneath as well
		std::vector<std::vector<char>> preGenGrid = grid;

		// First 2 for loops are to iterate through the entire grid
		for(int row = 0; row < x; row++){
			for(int col = 0; col < y; col++){
				if(row == 0){ // Takes care of top row edge case
					if(col == 0){ // Takes care of left top row edge case
						checkUpperLeft(preGenGrid, grid, row, col);	
					}
					else if(col + 1 == y){ // Takes care of right top row edge case
						checkUpperRight(preGenGrid, grid, row, col);
					}
					else{ // For the rest of the middle cells
						checkTop(preGenGrid, grid, row, col);
					}
				}
				else if(row + 1 == x){ // Takes care of the bottom row edge case
					if(col == 0){ // Takes care of the bottom left edge case
						checkLowerLeft(preGenGrid, grid, row, col);
					}
					else if(col + 1 == y){ // Takes care of the bottom right edge case
						checkLowerRight(preGenGrid, grid, row, col);
					}
					else{ // Takes care of the rest of the middle cells
						checkBottom(preGenGrid, grid, row, col);
					}	
				}
				else{ // Takes care of the rest of the middle cells
					if(col == 0){ // Takes the edge case for the left middle cells
						checkLeft(preGenGrid, grid, row, col);
					}
					else if(col + 1 == y){ // Takes the edge case for the right middle edge case
						checkRight(preGenGrid, grid, row, col);
					}
					else{ // Takes care of the rest of the middle cells
						checkMiddle(preGenGrid, grid, row, col);
					}
				}
			}
		}

		printGrid(grid, x, y);

		std::this_thread::sleep_for(std::chrono::milliseconds(150)); // Adjust this to set the speed of the simulation
	}
}

