#include "GameManager.h"
#include "Player_Kim.h"
#include "Player_����.h"
#include "Player_����.h"
#include "Player_���.h"
int main()
{
	//p1 = �� p2 = ��
	Player *p1 = new Player_jagil2(Piece::BLACK);
	Player *p2 = new Player_Kim(Piece::WHITE);
	GameManager game(p1, p2);


	game.displayBoard();
	game.start();


	int stop;
	cin >> stop;

}