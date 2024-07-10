#pragma once

#include <iostream>
#include <Windows.h>

using namespace std;

class game
{
public:
	game();
	void gameField();
	void movePlayer();
	void movePC();
	void victoryDraw();
	bool islegal(int space);
	bool GetMoveNow();

private:
	const int PCmove[9] = { 4, 0, 2, 6, 8, 7, 1, 5, 3 };
	char field[9];
	char playerChar;
	char pcChar;
	bool moveNow;
};