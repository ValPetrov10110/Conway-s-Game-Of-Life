#include <iostream>
#include <fstream>
#include <vector>
#include <limits>

// These are my function declarations
int startMenu();
int getUserIntInput();
void infoPage();
void gameScreen();
int getXValue();
int getYValue();
void printGrid(std::vector<std::vector<char>> grid, int& x, int& y);
void getUserCell(std::vector<std::vector<char>>& grid, int& x, int& y);
void startSimulation(std::vector<std::vector<char>> grid, int& x, int& y);
void clearInputBuffer();

int main(){

	switch(startMenu()){
		case 1:
			system("clear");
			gameScreen();
		break;

		case 2:
			system("clear");
			infoPage();
		break;

		case 3:
			std::cout << "Thank you for visiting! Goodbye.\n";
		break;

		default:
			std::cout << "Somehow you got this message?\n";
	}

	return EXIT_SUCCESS;
}

// This function displays the main menu screen to the user
int startMenu(){
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
	std::string fileText{};
	std::fstream infoFile ("infoPage.txt");

	if(infoFile.is_open()){
		while(std::getline(infoFile, fileText)){
			std::cout << fileText << '\n';
		}
	}
	// I will worry about if the file doesn't open later on in the program
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

void printGrid(std::vector<std::vector<char>> grid, int& x, int& y){
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

void getUserCell(std::vector<std::vector<char>>& grid, int& x, int& y){
	char replayValue{};
	do{
		std::cout << "Enter Cell's location[i.e., 8 12]: ";
		int xAxis{}, yAxis{};
		std::cin >> xAxis >> yAxis;
		grid[yAxis - 1][xAxis - 1] = 'o';
		printGrid(grid, x, y);
		std::cout << "\nWould you like to input another location (Y/n): ";
		std::cin >> replayValue;

	}while(toupper(replayValue) != 'N');
}

void startSimulation(std::vector<std::vector<char>> grid, int& x, int& y){
	system("clear");
	printGrid(grid, x, y);
	std::cout << "\nPress any key to start simulation...";
	clearInputBuffer();
	std::cin.get();
}

void clearInputBuffer(){
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
