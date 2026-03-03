#include "LoadSave.h"
#include "Input.h"
#include "Simulation.h"
#include "Terminal.h"

#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>

void createPreset(){
	clearScreen();
	std::string fileName = fileCreation();

	int x = getXValue();
	std::size_t y = getYValue();

	printToFile(fileName, x, y);
}

std::string fileCreation(){
	std::cout << "Enter name for preset: ";
	std::string saveName{};
	std::cin >> saveName;
	std::ofstream newPreset ("Saves/" + saveName + ".txt");
	newPreset.close();

	return saveName;
}

void showPresets(){
	std::cout << "Presets\n-----------\n";
	std::string path = "Saves/";
	for(const auto& directory : std::filesystem::directory_iterator(path)){
		std::string fileName = directory.path().stem().string();
		
		if(fileName != ".gitkeep"){
			std::cout << fileName << '\n';
		}
	}
}

void printToFile(std::string fileName, int x, std::size_t y){
	clearScreen();
	std::ofstream fileOutput ("Saves/" + fileName + ".txt");
	std::vector<std::vector<char>> fileGrid(x, std::vector<char>(y, '.'));
	printGrid(fileGrid, x, y);
	getUserCell(fileGrid, x, y);
	
	for(int row = 0; row < x; row++){
		for(std::size_t col = 0; col < y; col++){
			fileOutput << fileGrid[row][col];
		}
		fileOutput << '\n';
	}
}

void loadPreset(){
	clearScreen();
	showPresets();
	std::cout << "\n\nEnter filename ('Q' to quit) > ";
	std::string user_input{};
	std::cin >> user_input;
	
	if(user_input.length() != 1 && (toupper(user_input[0]) != 'Q')){
		searchPresets(user_input);
	}
}

void searchPresets(std::string fileName){
	std::string path = "Saves/";
	for(const auto& directory : std::filesystem::directory_iterator(path)){
		std::string directoryFileName = directory.path().stem().string();

		if(directoryFileName != ".gitkeep"){
			if(directoryFileName == fileName){
				std::ifstream myFile(directory.path().string());
				std::string fileText{};
				int x{};
				std::size_t y{};
				char2Dvector grid;
			
				while(std::getline(myFile, fileText)){
					x++;
					y = fileText.length();
					std::vector<char> row(fileText.begin(), fileText.end());
					grid.push_back(row);
				}
				
				startSimulation(grid, x, y);
				
				myFile.close();
			}
		}


		}
}
