#include "Checker.h"

void checkUpperLeft(char2Dvector preGenGrid, char2Dvector& grid, int& x, int& y){
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

void checkUpperRight(char2Dvector preGenGrid, char2Dvector& grid, int& x, int& y){

}

void checkLowerLeft(char2Dvector preGenGrid, char2Dvector& grid, int& x, int& y){

}

void checkLowerRight(char2Dvector preGenGrid, char2Dvector& grid, int& x, int& y){

}

void checkLeft(char2Dvector preGenGrid, char2Dvector& grid, int& x, int& y){

}

void checkRight(char2Dvector preGenGrid, char2Dvector& grid, int& x, int& y){

}

void checkMiddle(char2Dvector preGenGrid, char2Dvector& grid, int& x, int& y){

}

void checkTop(char2Dvector vpreGenGrid, char2Dvector& grid, int& x, int& y){

}

void checkBottom(char2Dvector preGenGrid, char2Dvector& grid, int& x, int& y){

}

