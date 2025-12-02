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
void startSimulation(std::vector<std::vector<char>>& grid, int& x, int& y);
void clearInputBuffer();
void checkUpperLeft(std::vector<std::vector<char>>& grid, int& x, int &y);
void checkUpperRight(std::vector<std::vector<char>>& grid, int& x, int& y);
void checkLowerLeft(std::vector<std::vector<char>>& grid, int& x, int& y);
void checkLowerRight(std::vector<std::vector<char>>& grid, int& x, int& y);
void checkLeft(std::vector<std::vector<char>>& grid, int& x, int& y);
void checkRight(std::vector<std::vector<char>>& grid, int& x, int& y);
void checkMiddle(std::vector<std::vector<char>>& grid, int& x, int& y);
void checkTop(std::vector<std::vector<char>>& grid, int& x, int& y);
void checkBottom(std::vector<std::vector<char>>& grid, int& x, int& y);


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

void startSimulation(std::vector<std::vector<char>>& grid, int& x, int& y){
	system("clear");
	printGrid(grid, x, y);
	std::cout << "\nPress any key to start simulation...";
	clearInputBuffer();
	std::cin.get();

	// First 2 for loops are to iterate through the entire grid
	for(int row = 0; row < x; row++){
		for(int col = 0; col < y; col++){
			if(row == 0){ // Takes care of top row edge case
				if(col == 0){ // Takes care of left top row edge case
					checkUpperLeft(grid, row, col);	
				}
				else if(col + 1 == y){ // Takes care of right top row edge case
					checkUpperRight(grid, row, col);
				}
				else{ // For the rest of the middle cells
					checkTop(grid, row, col);
				}
			}
			else if(row + 1 == x){ // Takes care of the bottom row edge case
				if(col == 0){ // Takes care of the bottom left edge case
					checkLowerLeft(grid, row, col);
				}
				else if(col + 1 == y){ // Takes care of the bottom right edge case
					checkLowerRight(grid, row, col);
				}
				else{ // Takes care of the rest of the middle cells
					checkBottom(grid, row, col);
				}	
			}
			else{ // Takes care of the rest of the middle cells
				if(col == 0){ // Takes the edge case for the left middle cells

				}
				else if(col + 1 == y){ // Takes the edge case for the right middle edge case

				}
				else{ // Takes care of the rest of the middle cells

				}
			}
		}
	}
	printGrid(grid, x, y);

}

void clearInputBuffer(){
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// This function is working properly; checks upper left cell
void checkUpperLeft(std::vector<std::vector<char>>& grid, int& x, int &y){
	int aliveCells{};

	if(grid[x][y + 1] == 'o'){
		aliveCells++;
	}
	if(grid[x + 1][y + 1] == 'o'){
		aliveCells++;
	}
	if(grid[x + 1][y] == 'o'){
		aliveCells++;
	}
	if(grid[x][y] == 'o'){
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
void checkUpperRight(std::vector<std::vector<char>>& grid, int& x, int& y){
	int aliveCells{};
	if(grid[x][y - 1] == 'o'){
		aliveCells++;
	}
	if(grid[x + 1][y - 1] == 'o'){
		aliveCells++;
	}
	if(grid[x + 1][y] == 'o'){
		aliveCells++;
	}

	if(grid[x][y] == 'o'){
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
void checkLowerLeft(std::vector<std::vector<char>>& grid, int& x, int& y){
	int aliveCells{};
	if(grid[x - 1][y] == 'o'){
		aliveCells++;
	}
	if(grid[x][y + 1] == 'o'){
		aliveCells++;
	}
	if(grid[x - 1][y + 1] == 'o'){
		aliveCells++;
	}

	if(grid[x][y] == 'o'){
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
void checkLowerRight(std::vector<std::vector<char>>& grid, int& x, int& y){
	int aliveCells{};
	if(grid[x][y - 1] == 'o'){
		aliveCells++;
	}
	if(grid[x - 1][y - 1] == 'o'){
		aliveCells++;
	}
	if(grid[x - 1][y] == 'o'){
		aliveCells++;
	}

	if(grid[x][y] == 'o'){
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

// This functionis working properly; checks the top row w/o corners
void checkTop(std::vector<std::vector<char>>& grid, int& x, int& y){
	int aliveCells{};
	if(grid[x][y - 1] == 'o'){
		aliveCells++;
	}
	if(grid[x][y + 1] == 'o'){
		aliveCells++;
	}
	if(grid[x + 1][y] == 'o'){
		aliveCells++;
	}
	if(grid[x + 1][y - 1] == 'o'){
		aliveCells++;
	}
	if(grid[x + 1][y + 1] == 'o'){
		aliveCells++;
	}

	if(grid[x][y] == 'o'){
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

void checkBottom(std::vector<std::vector<char>>& grid, int& x, int& y){
	int aliveCells{};
	if(grid[x][y - 1] == 'o'){
		aliveCells++;
	}
	if(grid[x - 1][y - 1] == 'o'){
		aliveCells++;
	}
	if(grid[x - 1][y] == 'o'){
		aliveCells++;
	}
	if(grid[x - 1][y + 1] == 'o'){
		aliveCells++;
	}
	if(grid[x][y + 1] == 'o'){
		aliveCells++;
	}

	if(grid[x][y] == 'o'){
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

void checkLeft(std::vector<std::vector<char>>& grid, int& x, int& y){

}

void checkRight(std::vector<std::vector<char>>& grid, int& x, int& y){

}


void checkMiddle(std::vector<std::vector<char>>& grid, int& x, int& y){

}


