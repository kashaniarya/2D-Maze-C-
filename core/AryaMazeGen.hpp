// AryaMazeGen.hpp
// Arya Kashani
// akashan1
// 10847777
// ICS 46 Project 1

#ifndef ARYAMAZEGEN_HPP
#define ARYAMAZEGEN_HPP

#include "MazeGenerator.hpp"
#include "Maze.hpp"
#include "Direction.hpp"
#include <vector>
#include <random>

class AryaMazeGen : public MazeGenerator {
	public:
		AryaMazeGen() = default;
		void generateMaze(Maze& maze);
	private:
		std::vector<Direction> getValidDirection(Maze& maze, int x, int y);
		void genMaze(Maze& maze, int x, int y);
		std::vector<std::vector<bool>> visited;
		std::random_device device;
		std::default_random_engine engine{device()};
};

#endif