#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
#include <thread>
#include <chrono>

// These are my function declarations
int startMenu();
int getUserIntInput();
void infoPage();
void gameScreen();
int getXValue();
int getYValue();
void printGrid(std::vector<std::vector<char>> grid, int& x, int& y);
void getUserCell(std::vector<std::vector<char>>& grid, int& x, int& y);
void startSimulation(std::vector<std::vector<char>>& grid, int& x, int& y);
void clearInputBuffer();
void checkUpperLeft(std::vector<std::vector<char>> preGenGrid, std::vector<std::vector<char>>& grid, int& x, int &y);
void checkUpperRight(std::vector<std::vector<char>> preGenGrid, std::vector<std::vector<char>>& grid, int& x, int& y);
void checkLowerLeft(std::vector<std::vector<char>> preGenGrid, std::vector<std::vector<char>>& grid, int& x, int& y);
void checkLowerRight(std::vector<std::vector<char>> preGenGrid, std::vector<std::vector<char>>& grid, int& x, int& y);
void checkLeft(std::vector<std::vector<char>> preGenGrid, std::vector<std::vector<char>>& grid, int& x, int& y);
void checkRight(std::vector<std::vector<char>> preGenGrid, std::vector<std::vector<char>>& grid, int& x, int& y);
void checkMiddle(std::vector<std::vector<char>> preGenGrid, std::vector<std::vector<char>>& grid, int& x, int& y);
void checkTop(std::vector<std::vector<char>> preGenGrid, std::vector<std::vector<char>>& grid, int& x, int& y);
void checkBottom(std::vector<std::vector<char>> preGenGrid, std::vector<std::vector<char>>& grid, int& x, int& y);


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

void startSimulation(std::vector<std::vector<char>>& grid, int& x, int& y){
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

void clearInputBuffer(){
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// This function is working properly; checks upper left cell
void checkUpperLeft(std::vector<std::vector<char>> preGenGrid, std::vector<std::vector<char>>& grid, int& x, int &y){
	int aliveCells{};

	if(preGenGrid[x][y + 1] == 'o'){
		aliveCells++;
	}
	if(preGenGrid[x + 1][y + 1] == 'o'){
		aliveCells++;
	}
	if(preGenGrid[x + 1][y] == 'o'){
		aliveCells++;
	}
	if(preGenGrid[x][y] == 'o'){
		if(aliveCells < 2){
			grid[x][y] = '.'; // Dies via underpopulation
		}
		else if(aliveCells == 2 || aliveCells == 3){
			grid[x][y] = 'o'; // Lives on to the next generation
		}
	}
	else{
		if(aliveCells == 3){
			grid[x][y] = 'o'; // Repopulates
		}
	}
}

// This function is working properly; checks upper right cell
void checkUpperRight(std::vector<std::vector<char>> preGenGrid, std::vector<std::vector<char>>& grid, int& x, int& y){
	int aliveCells{};
	if(preGenGrid[x][y - 1] == 'o'){
		aliveCells++;
	}
	if(preGenGrid[x + 1][y - 1] == 'o'){
		aliveCells++;
	}
	if(preGenGrid[x + 1][y] == 'o'){
		aliveCells++;
	}

	if(preGenGrid[x][y] == 'o'){
		if(aliveCells < 2){
			grid[x][y] = '.'; // Dies via underpopulation
		}
		else if(aliveCells == 2 || aliveCells == 3){
			grid[x][y] = 'o'; // Lives on to the next generation
		}
	}
	else{
		if(aliveCells == 3){
			grid[x][y] = 'o'; // Repopulates
		}
	}

}

// This function is working properly; checks lower left cell
void checkLowerLeft(std::vector<std::vector<char>> preGenGrid, std::vector<std::vector<char>>& grid, int& x, int& y){
	int aliveCells{};
	if(preGenGrid[x - 1][y] == 'o'){
		aliveCells++;
	}
	if(preGenGrid[x][y + 1] == 'o'){
		aliveCells++;
	}
	if(preGenGrid[x - 1][y + 1] == 'o'){
		aliveCells++;
	}

	if(preGenGrid[x][y] == 'o'){
		if(aliveCells < 2){
			grid[x][y] = '.'; // Dies via underpopulation
		}
		else if(aliveCells == 2 || aliveCells == 3){
			grid[x][y] = 'o'; // Lives on to the next generation
		}
	}
	else{
		if(aliveCells == 3){
			grid[x][y] = 'o'; // Repopulates
		}
	}
}

// This function is working properly; checks lower right cell
void checkLowerRight(std::vector<std::vector<char>> preGenGrid, std::vector<std::vector<char>>& grid, int& x, int& y){
	int aliveCells{};
	if(preGenGrid[x][y - 1] == 'o'){
		aliveCells++;
	}
	if(preGenGrid[x - 1][y - 1] == 'o'){
		aliveCells++;
	}
	if(preGenGrid[x - 1][y] == 'o'){
		aliveCells++;
	}

	if(preGenGrid[x][y] == 'o'){
		if(aliveCells < 2){
			grid[x][y] = '.'; // Dies via underpopulation
		}
		else if(aliveCells == 2 || aliveCells == 3){
			grid[x][y] = 'o'; // Lives on to the next generation
		}	
	}
	else{
		if(aliveCells == 3){
			grid[x][y] = 'o'; // Repopulates
		}
	}
}

// This function is working properly; checks the top row w/o corners
void checkTop(std::vector<std::vector<char>> preGenGrid, std::vector<std::vector<char>>& grid, int& x, int& y){
	int aliveCells{};
	if(preGenGrid[x][y - 1] == 'o'){
		aliveCells++;
	}
	if(preGenGrid[x][y + 1] == 'o'){
		aliveCells++;
	}
	if(preGenGrid[x + 1][y] == 'o'){
		aliveCells++;
	}
	if(preGenGrid[x + 1][y - 1] == 'o'){
		aliveCells++;
	}
	if(preGenGrid[x + 1][y + 1] == 'o'){
		aliveCells++;
	}

	if(preGenGrid[x][y] == 'o'){
		if(aliveCells < 2){
			grid[x][y] = '.'; // Dies via underpopulation
		}
		else if(aliveCells == 2 || aliveCells == 3){
			grid[x][y] = 'o'; // Lives on to the next generation
		}
		else{
			grid[x][y] = '.'; // Dies via overpopulation
		}
	}
	else{
		if(aliveCells == 3){
			grid[x][y] = 'o'; // Repopulates
		}
	}
}

// This function is working properly; checks the bottom row w/o corners
void checkBottom(std::vector<std::vector<char>> preGenGrid, std::vector<std::vector<char>>& grid, int& x, int& y){
	int aliveCells{};
	if(preGenGrid[x][y - 1] == 'o'){
		aliveCells++;
	}
	if(preGenGrid[x - 1][y - 1] == 'o'){
		aliveCells++;
	}
	if(preGenGrid[x - 1][y] == 'o'){
		aliveCells++;
	}
	if(preGenGrid[x - 1][y + 1] == 'o'){
		aliveCells++;
	}
	if(preGenGrid[x][y + 1] == 'o'){
		aliveCells++;
	}

	if(preGenGrid[x][y] == 'o'){
		if(aliveCells < 2){
			grid[x][y] = '.'; // Dies via underpopulation
		}
		else if(aliveCells == 2 || aliveCells == 3){
			grid[x][y] = 'o'; // Lives on to the next generation
		}
		else{
			grid[x][y] = '.'; // Dies via overpopulation
		}
	}
	else{
		if(aliveCells == 3){
			grid[x][y] = 'o'; // Repopulates
		}
	}
}

// This function is working properly; checks the left column w/o corners
void checkLeft(std::vector<std::vector<char>> preGenGrid, std::vector<std::vector<char>>& grid, int& x, int& y){
	int aliveCells{};
	if(preGenGrid[x - 1][y] == 'o'){
		aliveCells++;
	}
	if(preGenGrid[x - 1][y + 1] == 'o'){
		aliveCells++;
	}
	if(preGenGrid[x][y + 1] == 'o'){
		aliveCells++;
	}
	if(preGenGrid[x + 1][y + 1] == 'o'){
		aliveCells++;
	}
	if(preGenGrid[x + 1][y] == 'o'){
		aliveCells++;
	}
	
	if(preGenGrid[x][y] == 'o'){
		if(aliveCells < 2){
			grid[x][y] = '.'; // Dies via underpopulation
		}
		else if(aliveCells == 2 || aliveCells == 3){
			grid[x][y] = 'o'; // Lives on to the next generation
		}
		else{
			grid[x][y] = '.'; // Dies via overpopulation
		}
	}
	else{
		if(aliveCells == 3){
			grid[x][y] = 'o'; //Repopulates
		}
	}
}

// This function is working properly; checks the right column w/o corners 
void checkRight(std::vector<std::vector<char>> preGenGrid, std::vector<std::vector<char>>& grid, int& x, int& y){
	int aliveCells{};
	if(preGenGrid[x - 1][y] == 'o'){
		aliveCells++;
	}
	if(preGenGrid[x - 1][y - 1] == 'o'){
		aliveCells++;
	}
	if(preGenGrid[x][y - 1] == 'o'){
		aliveCells++;
	}
	if(preGenGrid[x + 1][y - 1] == 'o'){
		aliveCells++;
	}
	if(preGenGrid[x + 1][y] == 'o'){
		aliveCells++;
	}

	if(preGenGrid[x][y] == 'o'){
		if(aliveCells < 2){
			grid[x][y] = '.'; // Dies via underpopulation
		}
		else if(aliveCells == 2 || aliveCells == 3){
			grid[x][y] = 'o'; // Lives on to the next generation
		}
		else{
			grid[x][y] = '.'; // Dies via overpopulation
		}
	}
	else{
		if(aliveCells == 3){
			grid[x][y] = 'o'; // Repopulates 
		}
	}
}

// Pretty sure this is compelete (Not 100% tested)
void checkMiddle(std::vector<std::vector<char>> preGenGrid, std::vector<std::vector<char>>& grid, int& x, int& y){
	int aliveCells{};
	if(preGenGrid[x - 1][y - 1] == 'o'){
		aliveCells++;
	}
	if(preGenGrid[x - 1][y] == 'o'){
		aliveCells++;
	}
	if(preGenGrid[x - 1][y + 1] == 'o'){
		aliveCells++;
	}
	if(preGenGrid[x][y - 1] == 'o'){
		aliveCells++;
	}
	if(preGenGrid[x][y + 1] == 'o'){
		aliveCells++;
	}
	if(preGenGrid[x + 1][y - 1] == 'o'){
		aliveCells++;
	}
	if(preGenGrid[x + 1][y] == 'o'){
		aliveCells++;
	}
	if(preGenGrid[x + 1][y + 1] == 'o'){
		aliveCells++;
	}

	if(preGenGrid[x][y] == 'o'){
		if(aliveCells < 2){
			grid[x][y] = '.'; // Dies via underpopulation
		}
		else if(aliveCells == 2 || aliveCells == 3){
			grid[x][y] = 'o'; // Lives on to the next generation
		}
		else{
			grid[x][y] = '.'; // Dies via overpopulation
		}
	}
	else{
		if(aliveCells == 3){
			grid[x][y] = 'o'; //Repopulates;
		}
	}
}


