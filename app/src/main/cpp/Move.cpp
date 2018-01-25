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
        move[Direction::C] = 0;
	}
	if (p == 3) {
		move[Direction::N] = 1;
		move[Direction::S] = 1;
		move[Direction::W] = 1;
		move[Direction::E] = 1;
		move[Direction::NE] = 0;
		move[Direction::SE] = 0;
		move[Direction::SW] = 0;
		move[Direction::NW] = 0;
		move[Direction::C] = 1;
	}
	if (p == 4) {
		move[Direction::N] = 2;
		move[Direction::S] = 2;
		move[Direction::W] = 2;
		move[Direction::E] = 2;
		move[Direction::NE] = 0;
		move[Direction::SE] = 0;
		move[Direction::SW] = 0;
		move[Direction::NW] = 0;
		move[Direction::C] = 1;
	}
	if (p == 2) {
		move[Direction::N] = 0;
		move[Direction::S] = 0;
		move[Direction::W] = 0;
		move[Direction::E] = 0;
		move[Direction::NE] = 1;
		move[Direction::SE] = 1;
		move[Direction::SW] = 1;
		move[Direction::NW] = 1;
		move[Direction::C] = 1;
	}

}