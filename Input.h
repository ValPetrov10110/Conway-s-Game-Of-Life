#pragma once

#include <vector>

using char2Dvector = std::vector<std::vector<char>>;

int getUserIntInput();
int getXValue();
int getYValue();
void getUserCell(char2Dvector& grid, int& x, int& y);
