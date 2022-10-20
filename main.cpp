#include "maze.hpp"
#include "main.hpp"

#include <iostream>
#include <cstdlib>

void main::start(int argc, char* argv[]) {
        Maze* m;
        if(argc == 1) {
                m = new Maze();
        }
        else if(argc == 2) {
                m = new Maze(atoi(argv[1]));
        }
        else {
                std::cout << "Usage: " << argv[0] << " n" << std::endl;
                std::cout << "n - size of the maze" << std::endl;
                exit(0);
        }
        m->print();
	m->saveToFile();
        delete m;
}

int main(int argc, char* argv[]) {
	class main obj;
	obj.start(argc, argv);
	return 0;
}
