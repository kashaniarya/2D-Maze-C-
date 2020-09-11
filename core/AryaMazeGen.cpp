// AryaMazeGen.cpp
// Arya Kashani
// akashan1
// 10847777
// ICS 46 Project 1

#include <ics46/factory/DynamicFactory.hpp>
#include "AryaMazeGen.hpp"
ICS46_DYNAMIC_FACTORY_REGISTER(MazeGenerator, AryaMazeGen,"Arya's Alogirthm (Required)");

std::vector<Direction> AryaMazeGen::getValidDirection(Maze& maze, int x, int y) {
	std::vector<Direction> d_arr;
	if(x < maze.getWidth()-1 && maze.wallExists(x,y,Direction::right) && visited.at(y).at(x+1) == false) {
		d_arr.push_back(Direction::right);
	}
	if(x > 0 && maze.wallExists(x,y,Direction::left) && visited.at(y).at(x-1) == false) {
		d_arr.push_back(Direction::left);
	}
	if(y < maze.getHeight()-1 && maze.wallExists(x,y,Direction::down) && visited.at(y+1).at(x) == false) {
		d_arr.push_back(Direction::down);
	}
	if(y > 0 && maze.wallExists(x,y,Direction::up) && visited.at(y-1).at(x) == false) {
		d_arr.push_back(Direction::up);
	}
	return d_arr;
}

void AryaMazeGen::genMaze(Maze& maze, int x, int y) { 
	visited.at(y).at(x) = true;
	std::vector<Direction> d_arr = getValidDirection(maze,x,y);
	while(d_arr.size() > 0) {
		//choose random direction
		std::uniform_int_distribution<int> distribution(0,d_arr.size()-1);
		Direction d = d_arr.at(distribution(engine));
		//break/remove wall
		maze.removeWall(x, y, d);
		//recurisvely call genMaze
		if(d == Direction::right) {
			x++;
		}
		else if(d == Direction::left) {
			x--;
		}
		else if(d == Direction::down) {
			y++;
		}
		else if(d == Direction::up){
			y--;
		}
		genMaze(maze, x, y);
		//update validDirection 
		d_arr = getValidDirection(maze, x, y);
	}
}

void AryaMazeGen::generateMaze(Maze& maze) {
	maze.removeAllWalls();
	maze.addAllWalls();
	for(int i=0; i < maze.getHeight(); i++) {
		std::vector<bool> v;
		for(int j=0; j < maze.getWidth(); j++) {
			v.push_back(false);
		}
		visited.push_back(v);
	}
	genMaze(maze, 0, 0);
}