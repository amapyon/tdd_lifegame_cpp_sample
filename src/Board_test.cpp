#include "Board.h"

#include <gtest/gtest.h>

using namespace std;

TEST(BoardTest, testInit1) {
	Board board{1};

	string expected =
			"┌─┐\n"
			"│□│\n"
			"└─┘";
	ASSERT_EQ(expected, board.toString());
}

TEST(BoardTest, testPutSize1) {
	Board board{1};
	board.put(0, 0);

	string expected =
			"┌─┐\n"
			"│■│\n"
			"└─┘";
	ASSERT_EQ(expected, board.toString());
}

TEST(BoardTest, testPutSize2) {
	Board board{2};
	board.put(0, 0);
	board.put(1, 1);

	string expected =
			"┌──┐\n"
			"│■□│\n"
			"│□■│\n"
			"└──┘";
	ASSERT_EQ(expected, board.toString());
}

TEST(BoardTest, testNextBlock) {
	Board board1{2};
	board1.put(0, 0);
	board1.put(0, 1);
	board1.put(1, 0);
	board1.put(1, 1);

	Board board2 = board1.next();

	string expected =
			"┌──┐\n"
			"│■■│\n"
			"│■■│\n"
			"└──┘";
	ASSERT_EQ(expected, board2.toString());

}

TEST(BoardTest, testNextBlinker) {
	Board board1{3};
	board1.put(1, 0);
	board1.put(1, 1);
	board1.put(1, 2);

	Board board2 = board1.next();
	{
		string expected =
			"┌───┐\n"
			"│□□□│\n"
			"│■■■│\n"
			"│□□□│\n"
			"└───┘";
		ASSERT_EQ(expected, board2.toString());
	}

	Board board3 = board2.next();
	{
		string expected =
			"┌───┐\n"
			"│□■□│\n"
			"│□■□│\n"
			"│□■□│\n"
			"└───┘";
		ASSERT_EQ(expected, board3.toString());
	}
}

TEST(BoardTest, testNextOctagon) {
	Board board1{8};
	board1.put(3, 0); board1.put(4, 0);
	board1.put(2, 1); board1.put(5, 1);
	board1.put(1, 2); board1.put(6, 2);
	board1.put(0, 3); board1.put(7, 3);
	board1.put(0, 4); board1.put(7, 4);
	board1.put(1, 5); board1.put(6, 5);
	board1.put(2, 6); board1.put(5, 6);
	board1.put(3, 7); board1.put(4, 7);

	{
		string expected =
			"┌────────┐\n"
			"│□□□■■□□□│\n"
			"│□□■□□■□□│\n"
			"│□■□□□□■□│\n"
			"│■□□□□□□■│\n"
			"│■□□□□□□■│\n"
			"│□■□□□□■□│\n"
			"│□□■□□■□□│\n"
			"│□□□■■□□□│\n"
			"└────────┘";
		ASSERT_EQ(expected, board1.toString());
	}

	Board board2 = board1.next();
	{
		string expected =
			"┌────────┐\n"
			"│□□□■■□□□│\n"
			"│□□■■■■□□│\n"
			"│□■□□□□■□│\n"
			"│■■□□□□■■│\n"
			"│■■□□□□■■│\n"
			"│□■□□□□■□│\n"
			"│□□■■■■□□│\n"
			"│□□□■■□□□│\n"
			"└────────┘";
		ASSERT_EQ(expected, board2.toString());
	}

	Board board3 = board2.next();
	{
		string expected =
			"┌────────┐\n"
			"│□□■□□■□□│\n"
			"│□□■□□■□□│\n"
			"│■■□■■□■■│\n"
			"│□□■□□■□□│\n"
			"│□□■□□■□□│\n"
			"│■■□■■□■■│\n"
			"│□□■□□■□□│\n"
			"│□□■□□■□□│\n"
			"└────────┘";
		ASSERT_EQ(expected, board3.toString());
	}

	Board board4 = board3.next();
	{
		string expected =
			"┌────────┐\n"
			"│□□□□□□□□│\n"
			"│□□■□□■□□│\n"
			"│□■□■■□■□│\n"
			"│□□■□□■□□│\n"
			"│□□■□□■□□│\n"
			"│□■□■■□■□│\n"
			"│□□■□□■□□│\n"
			"│□□□□□□□□│\n"
			"└────────┘";
		ASSERT_EQ(expected, board4.toString());
	}

	Board board5 = board4.next();
	{
		string expected =
			"┌────────┐\n"
			"│□□□□□□□□│\n"
			"│□□■■■■□□│\n"
			"│□■□■■□■□│\n"
			"│□■■□□■■□│\n"
			"│□■■□□■■□│\n"
			"│□■□■■□■□│\n"
			"│□□■■■■□□│\n"
			"│□□□□□□□□│\n"
			"└────────┘";
		ASSERT_EQ(expected, board5.toString());
	}

	Board board6 = board5.next();
	{
		string expected =
			"┌────────┐\n"
			"│□□□■■□□□│\n"
			"│□□■□□■□□│\n"
			"│□■□□□□■□│\n"
			"│■□□□□□□■│\n"
			"│■□□□□□□■│\n"
			"│□■□□□□■□│\n"
			"│□□■□□■□□│\n"
			"│□□□■■□□□│\n"
			"└────────┘";
		ASSERT_EQ(expected, board6.toString());
	}
}
