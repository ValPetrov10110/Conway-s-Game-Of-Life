#pragma once

#include <vector>

using char2Dvector = std::vector<std::vector<char>>;

void checkUpperLeft(char2Dvector preGenGrid, char2Dvector& grid, int& x, int& y);
void checkUpperRight(char2Dvector preGenGrid, char2Dvector& grid, int& x, int& y);
void checkLowerLeft(char2Dvector preGenGrid, char2Dvector& grid, int& x, int& y);
void checkLowerRight(char2Dvector preGenGrid, char2Dvector& grid, int& x, int& y);
void checkLeft(char2Dvector preGenGrid, char2Dvector& grid, int& x, int& y);
void checkRight(char2Dvector preGenGrid, char2Dvector& grid, int& x, int& y);
void checkMiddle(char2Dvector preGenGrid, char2Dvector& grid, int& x, int& y);
void checkTop(char2Dvector preGenGrid, char2Dvector& grid, int& x, int& y);
void checkBottom(char2Dvector preGenGrid, char2Dvector& grid, int& x, int& y);
