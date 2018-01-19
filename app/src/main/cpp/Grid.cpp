#include <sstream>
#include "Grid.h"
#include "Cell.cpp"
#include "Move.h"
using namespace std; 
class TextDisplay;
class Move;

void Grid::init(int n){ //Randomly initializes the board
	//td = new TextDisplay(n);
	//sets the new grid
	size = n;
    int green = 0;
    int red = 0;
	for(int i = 0; i < n; i ++){
		vector<Cell> A;
		theGrid.push_back(A);
		for(int j = 0; j < n; j++) {
            Cell B{1,2};
            int randy = rand();
            if (randy % 2 == 0 && green < 14) {
                B.setColour(Colour::GREEN);
                green++;
            }
            if (randy % 2 == 1 && red < 14){
                B.setColour(Colour::RED);
                red++;
            }
			theGrid[i].push_back(B);
		}	
	}
	
	//sets observers
	for(int r = 0; r < n; r++){
		for(int c = 0; c < n; c++) {
			//theGrid[r][c].attach(td);
			if (r-1 >= 0)
				theGrid[r][c].attach(&theGrid[r-1][c]);
			if (c-1 >= 0 && r-1 >= 0)
				theGrid[r][c].attach(&theGrid[r-1][c-1]);
			if (r+1 < n && c-1 >= 0)
				theGrid[r][c].attach(&theGrid[r+1][c-1]);
			if (r+1 < n)
				theGrid[r][c].attach(&theGrid[r+1][c]);
			if (r+1 < n && c+1 < n)
				theGrid[r][c].attach(&theGrid[r+1][c+1]);
			if (r-1 >= 0 && c+1 < n)
				theGrid[r][c].attach(&theGrid[r-1][c+1]);
			if (c+1 < n)
				theGrid[r][c].attach(&theGrid[r][c+1]);
			if (c-1 >= 0)
				theGrid[r][c].attach(&theGrid[r][c-1]);
		}
	}

}
bool Grid::winner() {
	return true;
}
std::string Grid::Display(){
    stringstream ss;
    std::string display ="Test";
    int n = size;
    for(int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j++) {
            Colour colours = theGrid[i][j].getColour();
            if (colours == Colour::GREEN) {
                ss << "G";
            }
            else if (colours == Colour::RED) {
                ss << "R";
            }
            else
                ss << "-";
        }
    }
    ss >> display;
    return display;
}

void Grid::use(int row, int col, int p) {
	Move m{p};
	theGrid[row][col].setDir(Direction::None);
	theGrid[row][col].notifyObservers(m);
}

std::ostream& operator<<(std::ostream &out, const Grid &g) {
	//out << *(g.td);
	return out;
}