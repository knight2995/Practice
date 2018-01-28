#pragma once
#include "Player.h"

class Player_jagil2 : public Player
{

public:

	virtual Point playTrick(const GameBoard& board);

	Player_jagil2(Piece p) : Player(p)
	{
		this->name = "이재길";
	}
};

Point Player_jagil2::playTrick(const GameBoard& board)
{
	//구현

	static int x = 0;
	static int y = 0;

	for (x; x < WIDTH; x++)
	{
		for (y; y< HEIGHT; y++)
		{
			int a = x + 1;
			int b = x + 2;
			int c = x + 3;
			int d = x + 4;
			int q = y + 1;
			int w = y + 2;
			int e = y + 3;
			int r = y + 4;
			if (board.getPiece(x, y) == Piece::BLACK && board.getPiece(a, y) == Piece::BLACK && board.getPiece(b, y) == Piece::BLACK
				&& board.getPiece(c, y) == Piece::BLACK)
			{
				return Point(d, y);
				continue;
			}



			if (board.getPiece(x, y) == Piece::WHITE && board.getPiece(a, y) == Piece::WHITE && board.getPiece(b, y) == Piece::WHITE
				&& board.getPiece(c, y) == Piece::WHITE)
			{
				return Point(d, y);
				continue;
			}



			if (board.getPiece(x, y) == Piece::BLACK && board.getPiece(a, y) == Piece::BLACK && board.getPiece(b, y) == Piece::BLACK)
			{
				return Point(c, y);
				continue;
			}



			if (board.getPiece(x, y) == Piece::WHITE && board.getPiece(a, y) == Piece::WHITE && board.getPiece(b, y) == Piece::WHITE)
			{
				return Point(c, y);
				continue;
			}



			if (board.getPiece(x, y) == Piece::BLACK && board.getPiece(x, q) == Piece::BLACK && board.getPiece(x, w) == Piece::BLACK
				&& board.getPiece(x, e) == Piece::BLACK)
			{
				return Point(x, r);
				continue;
			}



			if (board.getPiece(x, y) == Piece::WHITE && board.getPiece(x, q) == Piece::WHITE && board.getPiece(x, w) == Piece::WHITE
				&& board.getPiece(x, e) == Piece::WHITE)
			{
				return Point(x, r);
				continue;
			}


			if (board.getPiece(x, y) == Piece::BLACK && board.getPiece(x, q) == Piece::BLACK && board.getPiece(x, w) == Piece::BLACK)
			{
				return Point(x, e);
				continue;
			}



			if (board.getPiece(x, y) == Piece::WHITE && board.getPiece(x, q) == Piece::WHITE && board.getPiece(x, w) == Piece::WHITE)
			{
				return Point(x, e);
				continue;
			}


		}
	}
	static int i = 0;
	static int j = 0;

	for (i; i < WIDTH; i++)
	{
		for (j; j < HEIGHT; j++)
		{
			if (board.getPiece(i, j) == Piece::NONE)
			{
				return Point(i, j);
			}
		}
	}


}