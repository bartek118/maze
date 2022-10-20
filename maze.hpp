#ifndef MAZE_HPP
#define MAZE_HPP

class Maze {
	public:
		Maze() {
			size = 20;
			generateMaze();
		}

		~Maze();

		void print();

	private:
		bool* mazeArray;
		unsigned size;
		void generateMaze();
};

#endif
