#ifndef Cell_H
#define Cell_H
#include <vector>
#include "Observer.h"

using namespace std;
class Move; //Forward Delcaration

class Cell: public Observer {
	int row,col;
	Colour colour;
	vector<Observer*> ob;
	Direction LastDir = Direction::None;
	public:
		Cell(int r, int c); //Constructor
		void notify(Move m,Cell &from) override; //Notify surrounding peices
		void notifyObservers(Move m);
		void attach(Observer *o); //Add an Observer
		int getRow();
		int getCol();
		Direction getDir();
		void setDir(Direction D);
		Colour getColour();
		void setColour(Colour c);
		void toggle();
};

#endif