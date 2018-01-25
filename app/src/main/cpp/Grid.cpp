#include <sstream>
#include "Grid.h"
#include "Cell.cpp"
#include "Move.h"
using namespace std; 
class TextDisplay;
class Move;

void Grid::init(int n){ //Randomly initializes the board
	td = new TextDisplay(n);
	//sets the new grid
	size = n;
    int green = 0;
    int red = 0;

	for(int i = 0; i < n; i ++){
		vector<Cell> A;
		theGrid.push_back(A);
		for(int j = 0; j < n; j++) {
            Cell B{i,j};
			theGrid[i].push_back(B);
		}	
	}
	
	//sets observers
	for(int r = 0; r < n; r++){
		for(int c = 0; c < n; c++) {
			theGrid[r][c].attach(td);
            theGrid[r][c].attach(&theGrid[r][c]);
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
    for(int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j++) {
            int randy = rand();
            srand(randy);
             if (randy % 2 == 1) {
                 theGrid[i][j].setColour(Colour::RED);
                 red++;
             }
             else {
                theGrid[i][j].setColour(Colour::GREEN);
                green++;
            }
            Move m{0};
            theGrid[i][j].notifyObservers(m);
        }
    }
}
bool Grid::winner() {
	return true;
}
std::string Grid::Display(){
    return td->UpdateDisplay();
}

void Grid::use(int row, int col, int p) {
	Move m{p};
	theGrid[row][col].setDir(Direction::C);
	theGrid[row][col].notifyObservers(m);
}

std::ostream& operator<<(std::ostream &out, const Grid &g) {
	//out << *(g.td);
	return out;
}
//Constructs a blank text display
TextDisplay::TextDisplay(int n) : gridSize{n} {
    for(int i = 0; i < n; i ++){
        vector<char> A;
        theDisplay.push_back(A);
        for(int j = 0; j < n; j++) {
            theDisplay[i].push_back('-');
        }
    }
}

//Gets Notified of a change on the board
void TextDisplay::notify(Move m, Cell &from) {
    const int r = from.getRow();
    const int c = from.getCol();
    Colour colours = from.getColour();
    if (colours == Colour::GREEN) {
        theDisplay[r][c] = 'G';
    }
    if (colours == Colour::RED) {
        theDisplay[r][c] = 'R';
    }
}
std::string TextDisplay::UpdateDisplay() {
    display = "";
    stringstream sss;
    const int size = gridSize;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            sss << theDisplay[i][j];
        }

    }
    sss >> display;
    return display;
}

//Output display to the screen - friend of grids display
std::ostream& operator<<(std::ostream &out, const TextDisplay &td) {
    const int size = td.gridSize;
    for (int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            out << td.theDisplay[i][j];
        }
        out << endl;
    }
    return out;
}