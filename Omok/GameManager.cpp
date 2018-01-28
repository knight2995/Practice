#include "GameManager.h"

void GameManager::start()
{
	cout << "========���� ���� �մϴ�========" << endl;
	cout << "======== ���� �ʱ�ȭ �� ========" << endl;
	_getch();
	cout << "������ " << player1->getName() << "�� �Դϴ�." << endl;

	int count = 0;
	Player *currentPlayer = player1;

	while (1)
	{

		cout << currentPlayer->getName() << "�� �����ϼ��� !" << endl;
		//_getch();

		
		Point p = currentPlayer->playTrick(board);

		bool isSuccess = board.setBoard(currentPlayer->getPiece(), p);
		if (isSuccess == false)
		{
			
			cout<<currentPlayer->getName() << "�Բ��� �� �� �μ̽��ϴ�. -> �й�" << endl;
			cout << "�� �� = ( "<<p.x << "," << p.y << ")" << endl;
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

		//üũ
		if (check())
		{
			cout << currentPlayer->getName() << "�Բ��� �¸��ϼ̽��ϴ�." << endl;
			break;
		}
		//�� ä��
		if (count == WIDTH * HEIGHT)
		{
			cout << " �������� �� á���ϴ�." << endl;
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
	//���� ���� �밢 üũ
	//���� ������ �˰����� �� ������ üũ

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
	//����
	if (x <= 11)
	{
		//6�� �̻� ����
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
	//����
	if (y <= 11)
	{
		//6�� �̻� ����
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
	//�밢�� ��
	if (x <= 11 && y <= 11)
	{
		//6�� �̻� ����
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
	//�밢�� ��
	if (x <= 11 && y <= 11)
	{
		//6�� �̻� ����
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
