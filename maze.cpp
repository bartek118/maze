#include "maze.hpp"

#include <iostream>
#include <fstream>

#include <ctime>
#include <cstdlib>

#include <stack>
#include <utility>
#include <vector>

void Maze::generateMaze() {
	unsigned size2 = (2*this->size+1)*(2*this->size+1);
	this->mazeArray = new bool[size2];

	for(unsigned i = 0; i < size2; i++) {
		this->mazeArray[i] = true;
	}
	
	unsigned short* visited = new unsigned short[this->size*this->size];
	for(unsigned i = 0; i < this->size*this->size; i++) {
		visited[i] = 0;
	}

	srand(time(NULL));

	unsigned x = rand()%this->size, y = rand()%this->size;
	visited[x*this->size + y] = 2;

	std::stack< std::pair<unsigned, unsigned> > S;
	S.push(std::make_pair(x,y));

	while(!S.empty()) {
		std::pair<unsigned, unsigned> P = S.top();
		S.pop();

		visited[P.first*this->size + P.second] = 1;
		this->mazeArray[(2*P.first+1)*(2*this->size+1) + 2*P.second + 1] = false;

		std::vector< std::pair<unsigned, unsigned> > neighbors;
		
		if(P.first > 0 && visited[(P.first-1)*this->size + P.second] == 0) {
			neighbors.push_back(std::make_pair(P.first-1, P.second));
			visited[(P.first-1)*this->size + P.second] = 2;
			this->mazeArray[2*P.first*(2*this->size+1) + 2*P.second + 1] = false;
		}

		if(P.second > 0 && visited[P.first*this->size + P.second - 1] == 0) {
			neighbors.push_back(std::make_pair(P.first, P.second-1));
			visited[P.first*this->size + P.second - 1] = 2;
			this->mazeArray[(2*P.first+1)*(2*this->size+1) + 2*P.second] = false;
		}

		if(P.first + 1 < size && visited[(P.first+1)*this->size + P.second] == 0) {
			neighbors.push_back(std::make_pair(P.first+1, P.second));
			visited[(P.first+1)*this->size + P.second] = 2;
			this->mazeArray[(2*P.first+2)*(2*this->size+1) + 2*P.second + 1] = false;
		}

		if(P.second + 1 < size && visited[P.first*this->size + P.second + 1] == 0) {
			neighbors.push_back(std::make_pair(P.first, P.second+1));
			visited[P.first*this->size + P.second + 1] = 2;
			this->mazeArray[(2*P.first+1)*(2*this->size+1) + 2*P.second + 2] = false;
		}

		while(neighbors.size() > 0) {
			unsigned short k = rand()%neighbors.size();
			S.push(neighbors[k]);
			neighbors.erase(neighbors.begin()+k);
		}
	}
}

Maze::~Maze() {
	delete [] this->mazeArray;
}

void Maze::print() {
	for(unsigned i = 0; i <= 2*this->size; i++) {
		for(unsigned j = 0; j <= 2*this->size; j++) {
			if(this->mazeArray[i*(2*this->size+1) + j]) {
				std::cout << "#";
			}
			else {
				std::cout << " ";
			}
		}
		std::cout << std::endl;
	}
}

void Maze::saveToFile() {
	std::ofstream file("outputMaze.out");
	for(unsigned i = 0; i <= 2*this->size; i++) {
		for(unsigned j = 0; j <= 2*this->size; j++) {
			file << mazeArray[i*(2*this->size+1) + j];
		}
		file << std::endl;
	}
	file.close();
}
