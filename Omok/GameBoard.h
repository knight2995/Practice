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

	//출력
	void displayBoard();

	//
	bool setBoard(const Piece p, Point point);
	
	// 추가 룰 알고리즘
	bool checkAlgorithm(Point p);

	Piece getPiece(int x, int y) const;

};