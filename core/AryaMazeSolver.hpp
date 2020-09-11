// AryaMazeSolver.hpp
// Arya Kashani
// akashan1
// 10847777
// ICS 46 Project 1

#ifndef ARYAMAZESOLVER_HPP
#define ARYAMAZESOLVER_HPP

#include "MazeSolver.hpp"
#include "MazeSolution.hpp"
#include "Maze.hpp"
#include "Direction.hpp"
#include <vector>
#include <random>

class AryaMazeSolver : public MazeSolver {
	public:
		AryaMazeSolver() = default;
		void solveMaze(const Maze& maze, MazeSolution& mazeSolution);
	private:
		void solveMaze_recursion(const Maze& maze, MazeSolution& mazeSolution);
		std::vector<Direction> getValidDirection(const Maze& maze, MazeSolution& mazeSolution);
		std::vector<std::vector<bool>> visited;
		std::random_device device;
		std::default_random_engine engine{device()};
};

#endif