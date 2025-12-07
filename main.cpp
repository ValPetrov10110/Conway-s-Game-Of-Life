#include <iostream>
#include <fstream>
#include <vector>
#include <thread>
#include <chrono>
#include <filesystem>
#include "Simulation.h"
#include "Input.h"

// These are my function declarations
int startMenu();
int getUserIntInput();
void infoPage();
void gameScreen();
int getXValue();
int getYValue();
void getUserCell(std::vector<std::vector<char>>& grid, int& x, int& y);
void createPreset();
void loadPreset();
std::string fileCreation();
void printToFile(std::string fileName, int x, int y);
void showPresets();
void searchPresets(std::string fileName);

int main(){
	bool repeatValue = false;
		do{
			switch(startMenu()){
				case 1:
					system("clear");
					gameScreen();
				break;

				case 2:
					createPreset();
				break;

				case 3:
					loadPreset();
				break;

				case 4:
					infoPage();
					repeatValue = true;
				break;

				case 5:
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
	std::cout << "1.) Start Game\n2.) Create Preset\n3.) Load Preset\n4.) Info\n5.) Exit\n";
	
	return getUserIntInput();
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
	else{
		std::cout << "ERROR: infoPage.txt missing.\nFATAL ERROR: automatically restarting...";
		std::this_thread::sleep_for(std::chrono::seconds(5));
	}
	
	std::cout << "\nPress any key to return to main menu...";
	clearInputBuffer();
	std::cin.get();
	infoFile.close();
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

void createPreset(){
	system("clear");
	std::string fileName = fileCreation();

	int x = getXValue();
	int y = getYValue();

	printToFile(fileName, x, y);

}

void loadPreset(){
	system("clear");
	showPresets();
	std::cout << "\n\nEnter filename > ";
	std::string user_input{};
	std::cin >> user_input;
	
	searchPresets(user_input);
}

std::string fileCreation(){
	std::cout << "Enter name for preset: ";
	std::string saveName{};
	std::cin >> saveName;

	std::ofstream newPreset ("Saves/" + saveName + ".txt");
	newPreset.close();

	return saveName;
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

void searchPresets(std::string fileName){
	std::string path = "Saves/";
	for(const auto& directory : std::filesystem::directory_iterator(path)){
		std::string directoryFileName = directory.path().stem().string();

		if(directoryFileName != ".gitkeep"){
			if(directoryFileName == fileName){
				std::ifstream myFile(directory.path().string());
				std::string fileText{};
				int x{}, y{};

				while(std::getline(myFile, fileText)){
					x++;
					std::cout << fileText << '\n';
					y = fileText.length();
				}

				char2Dvector grid(x, std::vector<char>(y));
				while(std::getline(myFile, fileText)){
					for(int row = 0; row < x; row++){
						for(int col = 0; col < y; col++){
							grid[row][col] = fileText[col];
							std::cout << fileText[col];
						}
					}
				}
				myFile.close();
			}


		}
	}
}

