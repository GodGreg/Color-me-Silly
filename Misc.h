#ifndef Misc_H
#define Misc_H
#include <map>

class move {
	std::map <Direction, int> move;
public
	bool valid(Direction D);
}

#endif