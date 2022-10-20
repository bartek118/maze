#ifndef MAZE_HPP
#define MAZE_HPP

class Maze {
	public:
		Maze(unsigned n) {
			size = n;
			generateMaze();
		}

		Maze() : Maze(20) {}

		~Maze();

		void print();

	private:
		bool* mazeArray;
		unsigned size;
		void generateMaze();
};

#endif
