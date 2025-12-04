#include "Checker.h"

void checkUpperLeft(char2Dvector preGenGrid, char2Dvector& grid, int& x, int& y){
	int aliveCells{};


void checkUpperRight(char2Dvector preGenGrid, char2Dvector& grid, int& x, int& y){
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

void checkLowerLeft(char2Dvector preGenGrid, char2Dvector& grid, int& x, int& y){
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

void checkLowerRight(char2Dvector preGenGrid, char2Dvector& grid, int& x, int& y){
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

void checkLeft(char2Dvector preGenGrid, char2Dvector& grid, int& x, int& y){
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

void checkRight(char2Dvector preGenGrid, char2Dvector& grid, int& x, int& y){
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

void checkMiddle(char2Dvector preGenGrid, char2Dvector& grid, int& x, int& y){
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

void checkTop(char2Dvector preGenGrid, char2Dvector& grid, int& x, int& y){
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

void checkBottom(char2Dvector preGenGrid, char2Dvector& grid, int& x, int& y){
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

