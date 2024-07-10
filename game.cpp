#include "game.h"

game::game()
{
	memset(field, ' ', 9);

	cout << '\t' << '1' << " | " << '2' << " | " << '3' << '\n';
	cout << '\t' << "----------" << '\n';
	cout << '\t' << '4' << " | " << '5' << " | " << '6' << '\n';
	cout << '\t' << "----------" << '\n';
	cout << '\t' << '7' << " | " << '8' << " | " << '9' << '\n' << '\n';

	string moveFirst;

	do
	{
		cout << "вы хотите ходить первым? (да/нет) ";
		cin >> moveFirst;
		cout << '\n';
		for (int i = 0; i < moveFirst.length(); ++i)
		{
			moveFirst[i] = tolower(moveFirst[i]);
		}
	} while ((moveFirst != "да") && (moveFirst != "нет"));

	if (moveFirst == "да")
	{
		playerChar = 'X';
		pcChar = 'O';
		moveNow = 1;
		cout << "ваш знак: X\n";
	}
	else
	{
		playerChar = 'O';
		pcChar = 'X';
		moveNow = 0;
	}
}

void game::gameField()
{
	cout << '\t' << field[0] << " | " << field[1] << " | " << field[2] << '\n';
	cout << '\t' << "----------" << '\n';
	cout << '\t' << field[3] << " | " << field[4] << " | " << field[5] << '\n';
	cout << '\t' << "----------" << '\n';
	cout << '\t' << field[6] << " | " << field[7] << " | " << field[8] << "\n\n";
}

void game::movePlayer()
{
	int space = 0;

	do
	{
		cout << "на какую клетку вы хотите поставить " << '\'' << playerChar << '\'' << "? (1-9) ";
		cin >> space;
		cout << '\n';
	} while (islegal(space));
	--space;
	field[space] = playerChar;

	moveNow = false;
}

void game::movePC()
{
	int i = 0;
	for (; i < 9; ++i)
	{
		if ((field[PCmove[i]] != playerChar) && (field[PCmove[i]] != pcChar))
		{
			field[PCmove[i]] = pcChar;
			break;
		}
	}

	cout << "компьютер поставил знак на клетку номер: " << PCmove[i] + 1 << "\n\n";

	moveNow = true;
}

void game::victoryDraw()
{
	int winPos[8][3] = { {6,7,8}, { 3, 4, 5 }, { 0,1,2 }, { 6,3,0 }, { 7,4,1 }, { 8,5,2 }, { 6,4,2 }, { 0,4,8 } };

	int i = 0;

	for (; i < 8; ++i)
	{
		if ((field[winPos[i][0]] == playerChar) && (field[winPos[i][1]] == playerChar) && (field[winPos[i][2]] == playerChar))
		{
			gameField();
			cout << "вы выйграли" << endl;
			system("pause");
			exit(1); //win player
		}
		else if ((field[winPos[i][0]] == pcChar) && (field[winPos[i][1]] == pcChar) && (field[winPos[i][2]] == pcChar))
		{
			cout << "выйграл компьютер" << endl;
			system("pause");
			exit(0); //win PC
		}
	}

	for (i = 0; i < 9; ++i)
	{
		if (field[i] == ' ')
		{
			return; //continue game
		}
	}
	cout << "ничья" << endl;
	system("pause");
	exit(2); //Draw
}

bool game::islegal(int space)
{
	if ((space > 0) && (space < 10))
	{
		if ((field[space - 1] != playerChar) && (field[space - 1] != pcChar))
		{
			return false;
		}
	}
	return true;
}

bool game::GetMoveNow()
{
	return moveNow;
}