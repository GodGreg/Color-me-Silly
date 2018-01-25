#ifndef GRID_H
#define GRID_H
#include <vector>
#include "Cell.h"
#include "Move.h"
using namespace std;
class TextDisplay;

class Grid {
	vector<vector<Cell>> theGrid;
	TextDisplay *td = nullptr; // The text display.
	int size;
public:
	void init(int size); //Randomly initializes the board
	bool winner();
	void use(int row, int col, int p);
	friend std::ostream &operator<<(std::ostream &out, const Grid &g);
	std::string Display();
};

class TextDisplay: public Observer {
	std::vector<std::vector<char>> theDisplay;
	const int gridSize;
	string display;
public:
	TextDisplay(int n);
	void notify(Move m,Cell &from) override;
	std::string UpdateDisplay();
	friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};
#endif