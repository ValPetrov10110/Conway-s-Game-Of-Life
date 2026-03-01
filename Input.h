#pragma once

#include <vector>

using char2Dvector = std::vector<std::vector<char>>;

int getUserIntInput();
int getXValue();
std::size_t getYValue();
void getUserCell(char2Dvector& grid, int& x, std::size_t& y);
