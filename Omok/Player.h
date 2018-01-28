#pragma once

#include "GameBoard.h"
#include <random>
//�� Ŭ���� ��� �޾Ƽ� ���
class Player
{
	
protected:

	//��� �ִ� ��
	Piece p;
	
	//�̸�
	string name;

public:

	Player(Piece p) :p(p) {};

	//�Ѽ� �α�
	//��ȯ�� Point ���Ǵ� GameBoard.h ������ ��
	//GameBoard(0~14,0~14)
	//board�� ���� ���� ������ ��Ȳ�� üũ�Ͽ� �� ����
	//Point�� �����ϸ� ��
	//board ���� Piece getPiece(int x, int y) const; ����
	//None= �ƹ��͵� �� ��
	//BLACK = �� WHITE = ��
	virtual Point playTrick(const GameBoard& board) = 0;
	// Test
	/*
	{
		random_device rn;
		mt19937_64 rnd(rn());

		//< 2�ܰ�. ���� ���� ( ���� )
		uniform_int_distribution<int> range(0, 14);

		return Point(range(rnd), range(rnd));
		
	}
	*/
	
	


	void setName(string name) { this->name = name; };
	string getName() { return name; }
	Piece getPiece(){ return p; }
	

};