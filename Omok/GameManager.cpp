#include "GameManager.h"

void GameManager::start()
{
	cout << "========게임 시작 합니다========" << endl;
	cout << "======== 보드 초기화 중 ========" << endl;
	_getch();
	cout << "선공은 " << player1->getName() << "님 입니다." << endl;

	int count = 0;
	Player *currentPlayer = player1;

	while (1)
	{

		cout << currentPlayer->getName() << "님 착수하세요 !" << endl;
		//_getch();

		
		Point p = currentPlayer->playTrick(board);

		bool isSuccess = board.setBoard(currentPlayer->getPiece(), p);
		if (isSuccess == false)
		{
			
			cout<<currentPlayer->getName() << "님께서 잘 못 두셨습니다. -> 패배" << endl;
			cout << "둔 곳 = ( "<<p.x << "," << p.y << ")" << endl;
			return;
		}
		
		/*
		while (1)
		{
			Point p = currentPlayer->playTrick(board);
			bool isSuccess = board.setBoard(currentPlayer->getPiece(), p);
			if (isSuccess)
				break;
		}
		*/
		count++;
		displayBoard();

		//체크
		if (check())
		{
			cout << currentPlayer->getName() << "님께서 승리하셨습니다." << endl;
			break;
		}
		//다 채움
		if (count == WIDTH * HEIGHT)
		{
			cout << " 오목판이 다 찼습니다." << endl;
			break;
		}

		if (currentPlayer == player1)
			currentPlayer = player2;
		else
			currentPlayer = player1;

	}
}

bool GameManager::check()
{
	//가로 세로 대각 체크
	//가장 간단한 알고리즘은 각 돌마다 체크

	for (int j = 0; j < HEIGHT; j++)
	{
		for (int i = 0; i < WIDTH; i++)
		{
			if (checkPeice(Point(i, j)))
			{
				return true;
			}
		}
	}
	return false;
}

bool GameManager::checkPeice(Point p)
{

	int x = p.x;
	int y = p.y;
	Piece stone = board.getPiece(x, y);
	if (stone == Piece::NONE)
		return false;

	int count = 0;
	//가로
	if (x <= 11)
	{
		//6목 이상 방지
		for (int i = 0; i < WIDTH - x; i++)
		{
			if (board.getPiece(x + i, y) != stone)
				break;
			count++;
			
		}
	}
	
	if (count == 5)
		return true;
	

	count = 0;
	//세로
	if (y <= 11)
	{
		//6목 이상 방지
		for (int i = 0; i < WIDTH - y; i++)
		{
			if (board.getPiece(x, y + i) != stone)
				break;
			count++;

		}
	}
	if (count == 5)
		return true;
		
	count = 0;
	//대각선 ↘
	if (x <= 11 && y <= 11)
	{
		//6목 이상 방지
		for (int i = 0; i < WIDTH - (x > y? x:y); i++)
		{
			if (board.getPiece(x+i, y + i) != stone)
				break;
			count++;

		}
	}
	if (count == 5)
		return true;

	count = 0;
	//대각선 ↗
	if (x <= 11 && y <= 11)
	{
		//6목 이상 방지
		for (int i = 0; i < WIDTH - (x > y ? x : y); i++)
		{
			if (board.getPiece(x + i, y - i) != stone)
				break;
			count++;

		}
	}
	if (count == 5)
		return true;

	return false;
}
