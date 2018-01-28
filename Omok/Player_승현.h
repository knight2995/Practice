#pragma once
#include "Player.h"
class Player_Hyun : public Player
{
public:
	virtual Point playTrick(const GameBoard& board);

	Player_Hyun(Piece p) : Player(p)
	{
		this->name = "ÀÌ½ÂÇö";
	};
};

Point Player_Hyun::playTrick(const GameBoard& board)
{
	static int x = 0;
	static int y = 0;
	while (1)
	{
		if (p == Piece::WHITE)
		{
			for (x = 0; x < 14; x++)
			{
				for (y = 0; x < 14; y++)
				{
					if (board.getPiece(x, y) == Piece::NONE)
					{
						return Point(x, y);
					}
					else if (board.getPiece(x, y) == Piece::BLACK)
					{
						break;
					}
					else
						continue;
				}
			}
		}
	}
};