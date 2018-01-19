#include "Cell.h"
#include <iostream>
#include "Move.h"
#include "Move.cpp"
#include <cstdlib>
using namespace std;

Cell::Cell(int r, int c) : row{r}, col{c} {
}//Constructor

void Cell::notify(Move m,Cell &from){ //Notify surrounding peices
	int R = this->row - from.getRow();
	int C = this->col - from.getCol();
	//cout << "NOTIFY" << "[" << this->row << "," << this->col << "]" << endl;
	Direction D;
	
	//colour = Colour:GREEN
	//Use this when you want to add more peices
	
	
	if (R == -1 && C == 1)
		D = Direction::NE;
	else if (R == -1 && C == 0)
		D = Direction::N;
	else if (R == -1 && C == -1)
		D = Direction::NW;
	
	else if (R == 0 && C == 1)
		D = Direction::E;
	
	else if (R == 1 && C == 1)
		D = Direction::SE;
	else if (R == 1 && C == 0)
		D = Direction::S;
	else if (R == 1 && C == -1)
		D = Direction::SW;
	
	else if (R == 0 && C == -1)
		D = Direction::W;
	else
		return;
	
	if (m.valid(D) && (from.getDir() == D || from.getDir() == Direction::None)) {
		LastDir = D;
		this->toggle();
		this->notifyObservers(m);
	}
}


void Cell::attach(Observer *o){ //Add an Observer
	ob.emplace_back(o); 
}
void Cell::notifyObservers(Move m){
	int size = ob.size(); 
	for(int i = 0; i < size; i++)
		ob.at(i)->notify(m,*this);
}
void Cell::setColour(Colour c) {
	colour = c;
}

int Cell::getRow() {return row;}
int Cell::getCol() {return col;}
Direction Cell::getDir() {return LastDir;}
Colour Cell::getColour() {return colour;}
void Cell::setDir(Direction D) {LastDir = D;}
void Cell::toggle() {colour == Colour::RED ? colour = Colour::GREEN : colour = Colour::RED;}
