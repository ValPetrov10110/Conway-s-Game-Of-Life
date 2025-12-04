#pragma once

#include <vector>
#include "Checker.h"

using char2Dvector = std::vector<std::vector<char>>;

void startSimulation(char2Dvector& grid, int& x, int& y);
void printGrid(char2Dvector& grid, int& x, int& y);
void clearInputBuffer();
