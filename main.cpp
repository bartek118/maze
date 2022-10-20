#include "maze.hpp"

class main {
	public:
		void start() {
			Maze* m = new Maze();
			m->print();
			delete m;
		}
};

int main() {
	class main obj;
	obj.start();
	return 0;
}
