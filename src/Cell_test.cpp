#include "Cell.h"

#include <gtest/gtest.h>

TEST(CellTest, testCountSize3One) {
	int values[]{1, 0, 0, 0, 0, 0, 0, 0, 0};
	Cell cell{1, values};
	ASSERT_EQ(1, cell.count(0, 0));
}

TEST(CellTest, testCountEight) {
	int values[]{1, 1, 1, 1, 1, 1, 1, 1, 1};
	Cell cell{1, values};
	ASSERT_EQ(8, cell.count(0, 0));
	ASSERT_EQ(1, cell.value(0, 0));
}

TEST(CellTest, testCountSize2) {
	int values[]{0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1};
	Cell cell{2, values};
	ASSERT_EQ(0, cell.count(0, 0));
	ASSERT_EQ(3, cell.count(1, 0));
	ASSERT_EQ(3, cell.count(0, 1));
	ASSERT_EQ(5, cell.count(1, 1));
}
