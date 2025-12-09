#include "LoadSave.h"
#include "Input.h"
#include "Simulation.h"
#include <iostream>
#include <fstream>
#include <filesystem>

void createPreset(){
	system("clear");
	std::string fileName = fileCreation();

	int x = getXValue();
	int y = getYValue();

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
		std::string fileName = static_cast<std::string>(directory.path().stem());
		
		if(fileName != ".gitkeep"){
			std::cout << fileName << '\n';
		}
	}
}

void printToFile(std::string fileName, int x, int y){
	system("clear");
	std::ofstream fileOutput ("Saves/" + fileName + ".txt");
	std::vector<std::vector<char>> fileGrid(x, std::vector<char>(y, '.'));
	printGrid(fileGrid, x, y);
	getUserCell(fileGrid, x, y);
	
	for(int row = 0; row < x; row++){
		for(int col = 0; col < y; col++){
			fileOutput << fileGrid[row][col];
		}
		fileOutput << '\n';
	}
}

void loadPreset(){
	system("clear");
	showPresets();
	std::cout << "\n\nEnter filename > ";
	std::string user_input{};
	std::cin >> user_input;
	
	searchPresets(user_input);
}

void searchPresets(std::string fileName){
	std::string path = "Saves/";
	for(const auto& directory : std::filesystem::directory_iterator(path)){
		std::string directoryFileName = directory.path().stem().string();

		if(directoryFileName != ".gitkeep"){
			if(directoryFileName == fileName){
				std::ifstream myFile(directory.path().string());
				std::string fileText{};
				int x{}, y{};
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
