#include "GameBoard.h"

ostream& operator<< (ostream& stream, const Piece& p)
{
	if (p == Piece::NONE)
		stream << "��";
	else if (p == Piece::BLACK)
		stream << "��";
	else if (p == Piece::WHITE)
		stream << "��";

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
	// TODO: ���⿡ ��ȯ ������ �����մϴ�.
	return board[x][y];
}

bool GameBoard::setBoard(const Piece p, Point point)
{
	if (board[point.x][point.y] != Piece::NONE)
	{
		cout << point.x << " " << point.y << endl;
		cerr << "�� ���� ���� �Դϴ�. �ٽ� �����ϼ���." << endl;
		return false;
	}
	else if (point.x >= WIDTH || point.y >= HEIGHT)
	{
		cerr << "������ �Ѿ�� ���� �Դϴ�. �ٽ� �����ϼ���." << endl;
		return false;
	}
	board[point.x][point.y] = p;

	//�߰� �˰���
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