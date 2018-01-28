#pragma once
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int WIDTH = 15;
const int HEIGHT = 15;
enum class Piece{ NONE,BLACK,WHITE};

struct Point
{
	int x;
	int y;
	Point(int x, int y) :x(x), y(y) {};
};


class GameBoard
{
private:

	Piece board[WIDTH][HEIGHT];

public:

	GameBoard();

	//���
	void displayBoard();

	//
	bool setBoard(const Piece p, Point point);
	
	// �߰� �� �˰���
	bool checkAlgorithm(Point p);

	Piece getPiece(int x, int y) const;

};