#include "Move.h"

bool Move::valid(Direction D) {
	if (move[D] > 0) {
		move[D] = move[D] - 1;
		return true;
	}
	return false;
}

//constructor
Move::Move(int p) {
	if (p == 1) {
		move[Direction::N] = 1;
		move[Direction::S] = 1;
		move[Direction::W] = 1;
		move[Direction::E] = 1;
		move[Direction::NE] = 1;
		move[Direction::SE] = 1;
		move[Direction::SW] = 1;
		move[Direction::NW] = 1;
	}
	if (p == 2) {
		move[Direction::N] = 1;
		move[Direction::S] = 1;
		move[Direction::W] = 1;
		move[Direction::E] = 1;
		move[Direction::NE] = 0;
		move[Direction::SE] = 0;
		move[Direction::SW] = 0;
		move[Direction::NW] = 0;
	}
}