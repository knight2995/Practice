#include "GameManager.h"
#include "Player_Kim.h"
#include "Player_¼¼¹Ì.h"
#include "Player_½ÂÇö.h"
#include "Player_Àç±æ.h"
int main()
{
	//p1 = Èæ p2 = ¹é
	Player *p1 = new Player_jagil2(Piece::BLACK);
	Player *p2 = new Player_Kim(Piece::WHITE);
	GameManager game(p1, p2);


	game.displayBoard();
	game.start();


	int stop;
	cin >> stop;

}