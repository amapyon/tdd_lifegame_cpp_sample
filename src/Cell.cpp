#include "Cell.h"


using namespace std;

Cell::~Cell() {
	// TODO Auto-generated destructor stub
}

Cell::Cell(int size, int * values) : _size{size}, _values{values} {
}

int Cell::value(const int x, const int y) {
	int offset = (x + 1) + (y + 1) * (_size + 2);
	return *(_values + offset);

}

int Cell::count(const int x, const int y) {
	int count = 0;
	int offset = x + y * (_size + 2);

//	cout << "x=" << x << ",y=" << y << "_size=" << _size << ",offset=" << offset << endl;

	if (*(_values + offset + 0) == 1) count++;
	if (*(_values + offset + 1) == 1) count++;
	if (*(_values + offset + 2) == 1) count++;
	if (*(_values + offset + 0 + (_size + 2)) == 1) count++;
	if (*(_values + offset + 2 + (_size + 2)) == 1) count++;
	if (*(_values + offset + 0 + (_size + 2) * 2) == 1) count++;
	if (*(_values + offset + 1 + (_size + 2) * 2) == 1) count++;
	if (*(_values + offset + 2 + (_size + 2) * 2) == 1) count++;
	return count;
}
