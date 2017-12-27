#ifndef GRID_H
#define GRID_H
#include "Observer.h"
#include <vector>

class Grid {
	vector<vector<Cell>> theGrid;
	TextDisplay *td = nullptr; // The text display.
	int size;
public:
	void init(int size); //Randomly initializes the board
	void winner();
	void use(int row, int col);
	friend std::ostream &operator<<(std::ostream &out, const Grid &g);
}
#endif