#include "game.h"
#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	game play;
	while (true)
	{
		switch (play.moveNow)
		{
		case(1):
			play.movePlayer();

			system("cls");

			break;
		case(0):
			system("cls");

			play.movePC();
			play.gameField();

			break;
		}
		play.victoryDraw();
	}

	return 0;
}
