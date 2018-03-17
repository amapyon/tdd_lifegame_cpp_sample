#ifndef CELL_H_
#define CELL_H_

class Cell {
private:
	int _size;
	int * _values;
public:
	Cell(int size, int * values);
	virtual ~Cell();

	int value(const int x, const int y);
	int count(const int x, const int y);
};

#endif /* CELL_H_ */
