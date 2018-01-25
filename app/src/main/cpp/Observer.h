#ifndef Observer_H
#define Observer_H
 
class Cell;
class Move;
enum class Colour {GREEN,RED,BLUE,NONE};
enum class Direction {N,NE,E,SE,S,SW,W,NW,C,None};

class Observer {
	public:
		virtual void notify(Move m, Cell &from) = 0;
		~Observer() = default;
};

#endif