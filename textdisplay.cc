#include "textdisplay.h"
#include "state.h"
#include <iostream>
#include <sstream>

using namespace std;


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
void TextDisplay::notify(move m, Cell &from) {
	const int r = from.getRow();
	const int c = from.getCol();
	Colour colours = whoNotified.getInfo().colour;
	if (colours == Colour::Black)
		theDisplay[r][c] = 'B';
	if (colours == Colour::White)
		theDisplay[r][c] = 'W';
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

