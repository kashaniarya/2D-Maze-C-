// AryaMazeSolver.cpp
// Arya Kashani
// akashan1
// 10847777
// ICS 46 Project 1

#include "AryaMazeSolver.hpp"
#include <ics46/factory/DynamicFactory.hpp>
ICS46_DYNAMIC_FACTORY_REGISTER(MazeSolver, AryaMazeSolver,"Arya's Alogirthm (Required)");

std::vector<Direction> AryaMazeSolver::getValidDirection(const Maze& maze, MazeSolution& mazeSolution) {
	std::vector<Direction> d_arr;
	if(mazeSolution.getCurrentCell().first < mazeSolution.getWidth()-1 && maze.wallExists(mazeSolution.getCurrentCell().first,mazeSolution.getCurrentCell().second,Direction::right) != true && visited.at(mazeSolution.getCurrentCell().second).at(mazeSolution.getCurrentCell().first+1) == false) {
		d_arr.push_back(Direction::right);
	}
	if(mazeSolution.getCurrentCell().first > 0 && maze.wallExists(mazeSolution.getCurrentCell().first,mazeSolution.getCurrentCell().second,Direction::left) != true && visited.at(mazeSolution.getCurrentCell().second).at(mazeSolution.getCurrentCell().first-1) == false) {
		d_arr.push_back(Direction::left);
	}
	if(mazeSolution.getCurrentCell().second < mazeSolution.getHeight()-1 && maze.wallExists(mazeSolution.getCurrentCell().first,mazeSolution.getCurrentCell().second,Direction::down) != true && visited.at(mazeSolution.getCurrentCell().second+1).at(mazeSolution.getCurrentCell().first) == false) {
		d_arr.push_back(Direction::down);
	}
	if(mazeSolution.getCurrentCell().second > 0 && maze.wallExists(mazeSolution.getCurrentCell().first,mazeSolution.getCurrentCell().second,Direction::up) != true && visited.at(mazeSolution.getCurrentCell().second-1).at(mazeSolution.getCurrentCell().first) == false) {
		d_arr.push_back(Direction::up);
	}
	return d_arr;
}

void AryaMazeSolver::solveMaze_recursion(const Maze& maze, MazeSolution& mazeSolution) {
	visited.at(mazeSolution.getCurrentCell().second).at(mazeSolution.getCurrentCell().first) = true;
	std::vector<Direction> valid_directions = getValidDirection(maze, mazeSolution);
	Direction d;
	while(mazeSolution.isComplete() == false) {  
		if(valid_directions.size() > 0) {
			std::uniform_int_distribution<int> distribution(0,valid_directions.size()-1);
			d = valid_directions.at(distribution(engine));
			mazeSolution.extend(d);
		}
		else {
			mazeSolution.backUp();
		}
		solveMaze_recursion(maze, mazeSolution);
		valid_directions = getValidDirection(maze, mazeSolution);
	}
}

void AryaMazeSolver::solveMaze(const Maze& maze, MazeSolution& mazeSolution) {
	mazeSolution.restart();
	for(int i=0; i < mazeSolution.getHeight(); i++) {
		std::vector<bool> v;
		for(int j=0; j < mazeSolution.getWidth(); j++) {
			v.push_back(false);
		}
		visited.push_back(v);
	}
	solveMaze_recursion(maze, mazeSolution);
}