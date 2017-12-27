#ifndef Observer_H
#define Observer_H

//These are the enums defined for the game
const enum Colour {RED, GREEN, BLUE, NONE}
const enum Activity {ALL, NONE}
const enum Direction {N,NE,E,SE,S,SW,W,NW}

class Observer {
	public:
		virtual void notify(move m, Cell &from) = 0;
		~Observer() = default;
};

#endif