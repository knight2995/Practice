#pragma once
#include "Player.h"

class Player_Kim : public Player
{

public:

	virtual Point playTrick(const GameBoard& board);

	Player_Kim(Piece p) : Player(p) { this->name = "김동현"; }
	Point check(const GameBoard& board, Point p);
	bool isFirst(const GameBoard& board);

	bool isAvailabe(const GameBoard& board, Point p);
};

Point Player_Kim::playTrick(const GameBoard& board)
{
	
	
	
	random_device rn;
	mt19937_64 rnd(rn());

	//< 2단계. 분포 설정 ( 정수 )
	uniform_int_distribution<int> range(0, 14);
	/*
	while (1)
	{
		Point p(range(rnd), range(rnd));
		if (board.getPiece(p.x, p.y) == Piece::NONE)
			return p;
	}
	*/
	
	if (isFirst(board))
	{
		return Point(range(rnd), range(rnd));
	}



	//상대 3줄 연속 찾는 방법
	for (int j = 0; j < HEIGHT; j++)
	{
		for (int i = 0; i < WIDTH; i++)
		{
			Point _p = check(board, Point(i, j));
			if (board.getPiece(_p.x,_p.y) != Piece::NONE)
				continue;
			else
			{
				//return _p;
				while (1)
				{
					if (isAvailabe(board, _p))
						return _p;
					_p = Point(range(rnd), range(rnd));

				}
				
			}
		}
	}
	
}

Point Player_Kim::check(const GameBoard& board,Point p)
{

	int x = p.x;
	int y = p.y;

	Piece stone = board.getPiece(x, y);
	if (stone == Piece::NONE)
		return p;

	Piece myStone = this->p;
	Piece enemyStone = this->p == Piece::BLACK ? enemyStone = Piece::WHITE : Piece::BLACK;



	int count = 0;
	//가로
	if (x <= 11)
	{
		//6목 이상 방지
		for (int i = 0; i < WIDTH - x; i++)
		{
			if (board.getPiece(x + i, y) == myStone || board.getPiece(x + i, y) == Piece::NONE)
				break;
			count++;

		}
	}

	if (count == 3)
	{
		return Point(p.x +count, p.y);
	}


	count = 0;
	//세로
	if (y <= 11)
	{
		//6목 이상 방지
		for (int i = 0; i < WIDTH - y; i++)
		{
			if (board.getPiece(x, y + i) == myStone || board.getPiece(x , y +i) == Piece::NONE)
				break;
			count++;

		}
	}
	if (count == 3)
		return Point(p.x , p.y + count);

	count = 0;
	//대각선 ↘
	if (x <= 11 && y <= 11)
	{
		//6목 이상 방지
		for (int i = 0; i < WIDTH - (x > y ? x : y); i++)
		{
			if (board.getPiece(x + i, y + i) == myStone || board.getPiece(x + i, y + i) == Piece::NONE)
				break;
			count++;

		}
	}
	if (count == 3)
		return Point(p.x + count, p.y + count);

	count = 0;
	//대각선 ↗
	if (x <= 11 && y <= 11)
	{
		//6목 이상 방지
		for (int i = 0; i < WIDTH - (x > y ? x : y); i++)
		{
			if (board.getPiece(x + i, y - i) == myStone || board.getPiece(x + i, y - i) == Piece::NONE)
				break;
			count++;

		}
	}
	if (count == 3)
		return Point(p.x - count, p.y - count);

	return p;
}

inline bool Player_Kim::isFirst(const GameBoard & board)
{
	for (int j = 0; j < HEIGHT; j++)
	{
		for (int i = 0; i < WIDTH; i++)
		{
			if (board.getPiece(i, j) != Piece::NONE)
				return false;
		}
	}
	return true;
}

inline bool Player_Kim::isAvailabe(const GameBoard & board, Point p)
{
	if (p.x >= WIDTH || p.y >= HEIGHT)
		return false;

	if (board.getPiece(p.x, p.y) != Piece::NONE)
		return false;

	return true;
}
