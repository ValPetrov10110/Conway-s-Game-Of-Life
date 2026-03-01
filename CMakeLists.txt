cmake_minimum_required(VERSION 3.15)

project(GameOfLife LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(
	GameOfLife
	main.cpp
	Simulation.cpp
	Checker.cpp
	Input.cpp
	LoadSave.cpp
)

target_compile_options(GameOfLife PRIVATE -Wall -Wextra - Wpedantic)
