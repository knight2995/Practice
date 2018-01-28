#pragma once
#include "Player.h"

class Player_SEMI : public Player
{
private:


public:

	virtual Point playTrick(const GameBoard& board);

	Player_SEMI(Piece p) :Player(p) {
		this->name = "이세미";
	};
};

Point Player_SEMI::playTrick(const GameBoard& board)
{


	static int x = 7;
	static int y = 8;

	while (1)
	{
		random_device rn;
		mt19937_64 rnx(rn());
		uniform_int_distribution<int> range(x - 1, x + 1);

		mt19937_64 rny(rn());
		uniform_int_distribution<int> range2(y - 1, y + 1);

		return Point(range(rnx), range2(rny));

		if (board.getPiece(x, y) == Piece::NONE) //NONE상태인지 확인하고 반환
			return Point(x, y);
		else
			continue;

	}
}