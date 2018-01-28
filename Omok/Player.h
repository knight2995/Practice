#pragma once

#include "GameBoard.h"
#include <random>
//이 클래스 상속 받아서 사용
class Player
{
	
protected:

	//쥐고 있는 돌
	Piece p;
	
	//이름
	string name;

public:

	Player(Piece p) :p(p) {};

	//한수 두기
	//반환값 Point 정의는 GameBoard.h 참고할 것
	//GameBoard(0~14,0~14)
	//board로 부터 현재 오목판 상황을 체크하여 둘 곳에
	//Point를 리턴하면 됨
	//board 접근 Piece getPiece(int x, int y) const; 참고
	//None= 아무것도 안 둠
	//BLACK = 흑 WHITE = 백
	virtual Point playTrick(const GameBoard& board) = 0;
	// Test
	/*
	{
		random_device rn;
		mt19937_64 rnd(rn());

		//< 2단계. 분포 설정 ( 정수 )
		uniform_int_distribution<int> range(0, 14);

		return Point(range(rnd), range(rnd));
		
	}
	*/
	
	


	void setName(string name) { this->name = name; };
	string getName() { return name; }
	Piece getPiece(){ return p; }
	

};