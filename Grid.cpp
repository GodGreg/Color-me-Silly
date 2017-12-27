#include "Grid.h"

void Grid::init(int size){ //Randomly initializes the board
	td = new TextDisplay(n);
	//sets the new grid
	for(size_t i = 0; i < n; i ++){
		vector<Cell> A;
		theGrid.push_back(A);
		for(size_t j = 0; j < n; j++) {
			theGrid[i].push_back(Cell{i,j});
		}	
	}
	
	//sets observers
	for(int r = 0; r < n; r++){
		for(int c = 0; c < n; c++) {
			theGrid[r][c].attach(td);	
			if (r-1 > 0)
				theGrid[r][c].attach(&theGrid[r-1][c]);
			if (c-1 > 0 && r-1 > 0)
				theGrid[r][c].attach(&theGrid[r-1][c-1]);
			if (r+1 < n && c-1 > 0)
				theGrid[r][c].attach(&theGrid[r+1][c-1]);
			if (r+1 < n)
				theGrid[r][c].attach(&theGrid[r+1][c]);
			if (r+1 < n && c+1 < n)
				theGrid[r][c].attach(&theGrid[r+1][c+1]);
			if (r-1 > 0 && c+1 < n)
				theGrid[r][c].attach(&theGrid[r-1][c+1]);
			if (c+1 < n)
				theGrid[r][c].attach(&theGrid[r][c+1]);
			if (c-1 > 0)
				theGrid[r][c].attach(&theGrid[r][c-1]);
	
		}
	}

}
void Grid::winner() {
	return true;
}

void Grid::use(int row, int col) {
	theGrid[row][col].notify();
}

std::ostream& operator<<(std::ostream &out, const Grid &g) {
	out << *(g.td);
	return out;
}