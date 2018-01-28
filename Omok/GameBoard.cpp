#include "GameBoard.h"

ostream& operator<< (ostream& stream, const Piece& p)
{
	if (p == Piece::NONE)
		stream << "┼";
	else if (p == Piece::BLACK)
		stream << "○";
	else if (p == Piece::WHITE)
		stream << "●";

	return stream;
}

GameBoard::GameBoard()
{
	for (int j = 0; j < HEIGHT; j++)
		for (int i = 0; i < WIDTH; i++)
			board[i][j] = Piece::NONE;
}

void GameBoard::displayBoard()
{
	/*
	cout << " ";
	for (int i = 0; i < WIDTH; i++)
	cout  <<setw()<< i + 1 << "  ";
	*/
		
	cout << endl;
	for (int j = 0; j < HEIGHT; j++)
	{
		for (int i = 0; i < WIDTH; i++)
		{
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

bool GameBoard::checkAlgorithm(Point p)
{
	return true;
}

Piece GameBoard::getPiece(int x, int y) const
{
	// TODO: 여기에 반환 구문을 삽입합니다.
	return board[x][y];
}

bool GameBoard::setBoard(const Piece p, Point point)
{
	if (board[point.x][point.y] != Piece::NONE)
	{
		cout << point.x << " " << point.y << endl;
		cerr << "잘 못된 착수 입니다. 다시 착수하세요." << endl;
		return false;
	}
	else if (point.x >= WIDTH || point.y >= HEIGHT)
	{
		cerr << "범위를 넘어서는 착수 입니다. 다시 착수하세요." << endl;
		return false;
	}
	board[point.x][point.y] = p;

	//추가 알고리즘
	if (checkAlgorithm(point))
	{
		return true;
	}
	else
	{
		board[point.x][point.y] = Piece::NONE;
		return false;
	}
	
}