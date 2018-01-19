#ifndef MOVE_H
#define MOVE_H
#include <map>
#include "Observer.h"

class Move {
	std::map <Direction, int> move;
public:
	Move(int p);
	//Returns true if the direction is valid, if it is, reduces the count of that direction by 1
	bool valid(Direction D);
};

#endif