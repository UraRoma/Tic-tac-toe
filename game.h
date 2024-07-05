#pragma once

#include <iostream>
#include <Windows.h>

using namespace std;

class game
{
public:
	bool moveNow;

	game();
	void gameField();
	void movePlayer();
	void movePC();
	void victoryDraw();
	bool islegal(int space);

private:
	char playerChar;
	char pcChar;
	char field[9];
	const int PCmove[9] = { 4, 0, 2, 6, 8, 7, 1, 5, 3 };
};