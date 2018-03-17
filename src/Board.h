#ifndef BOARD_H_
#define BOARD_H_

using namespace std;

#include <string>
#include "Cell.h"

class Board {
	int _size;
	int * _cells;
public:
	Board(int size);
	virtual ~Board();

	string toString();
	string toString_();
	void put(const int x, const int y);
	Board next();
};

#endif /* BOARD_H_ */
