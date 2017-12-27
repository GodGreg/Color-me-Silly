#include "Cell.h"
#include "Observer.h"


Cell::Cell(int r, int c) : row{r}, col{c} {}//Constructor
void Cell::notify(move m, Cell &from){ //Notify surrounding peices
	//int R = this->row - from.getRow();
	//int C = this->row - from.getCol();
	//Direction D;
	this->toggle();
	//Use this when you want to add more peices
	/*
	if (R == -1 && C == -1)
		D = Direction::NE
	else if (R == -1 && C == 0)
		D = Direction::E
	else if (R == -1 && C == 1)
		D = Direction::SE
	else if (R == 1 && C == -1)
		D = Direction::NW
	else if (R == 1 && C == 0)
		D = Direction::W
	else if (R == 1 && C == 1)
		D = Direction::SW
	else if (R == 0 && C == 1)
		D = Direction::S
	else if (R == 0 && C == -1)
		D = Direction::N
	
	if (m.valid(D))
		this->toggle();
	
	this->notify(m,*this);
	*/
}


void Cell::attach(observer &o){ //Add an Observer
	ob.emplaceback(o);
}

Cell::int getRow() {return row;}
Cell::int getCol() {return col;}
void Cell::toggle() {color == Colour::RED ? colour = Colour::RED : colour = Colour::GREEN}
