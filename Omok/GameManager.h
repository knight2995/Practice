#pragma once
#include "Player.h"
#include <conio.h>

class GameManager
{
private:

	GameBoard board;
	Player* player1;
	Player* player2;

	//己傍咯何 眉农
	bool check();

	//眉农
	bool checkPeice(Point p);

public:

	GameManager(Player* p1, Player* p2)
	{
		player1 = p1;
		player2 = p2;
	}

	void displayBoard()
	{
		system("cls");
		board.displayBoard();
	}

	void start();
	
	

};