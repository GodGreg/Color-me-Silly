#ifndef Cell_H
#define Cell_H
#include <vector>

class Cell: public Observer {
	int row,col;
	Colour colour;
	vector<* Observers> ob
	public:
		Cell(int r, int c); //Constructor
		void notify(move m, Cell &from); //Notify surrounding peices
		void attach(observer *o); //Add an Observer
		int getRow();
		int getCol();
		void toggle();
}

#endif