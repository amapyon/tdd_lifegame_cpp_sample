#include "Board.h"

using namespace std;

Board::Board(int size) : _size{size} {
	int length = (_size + 2) * (_size + 2);
//	cout << "_size=" << _size << "length=" << length << endl;
	_cells = new int[length];
	for (int i = 0; i < length; i++ ) {
		*(_cells + i) = 0;
	}
}

Board::~Board() {
	delete _cells;
}

string Board::toString() {

	string result = "";
	result += "┌";
	for (int x = 0; x < _size; x++) {
		result += "─";
	}
	result += "┐\n";

	for (int y = 0; y < _size; y++) {
		result += "│";
		for (int x = 0; x < _size; x++) {
			int offset = (x + 1) + (y + 1) * (_size + 2);
			if (*(_cells + offset) == 1) {
				result += "■";
			} else {
				result += "□";
			}
		}
		result += "│\n";
	}

	result += "└";
	for (int x = 0; x < _size; x++) {
		result += "─";
	}
	result += "┘";
	return result;
}

string Board::toString_() {

	string result = "";

	for (int y = 0; y < _size + 2; y++) {
		for (int x = 0; x < _size + 2; x++) {
			int offset = x + y * (_size + 2);
			result += to_string(*(_cells + offset));
			result += ",";
		}
		result += "\n";
	}
	return result;
}

void Board::put(const int x, const int y) {
	int offset = (x + 1) + (y + 1) * (_size + 2);
	*(_cells + offset) = 1;
}

Board Board::next() {
	Board boardNext{_size};
	Cell cell{_size, _cells};

	for (int y = 0; y < _size; y++) {
		for (int x = 0; x < _size; x++) {
			int count = cell.count(x, y);
//			cout << "x=" << x << ",y=" << y << ",count=" << count << endl;
			switch (count) {
			case 0:
			case 1:
				break;
			case 2:
				if (cell.value(x, y) == 1) {
					boardNext.put(x, y);
				}
				break;
			case 3:
				boardNext.put(x, y);
				break;
			case 4:
			case 5:
			case 6:
			case 7:
			case 8:
				break;
			}
		}
	}

	return boardNext;
}
