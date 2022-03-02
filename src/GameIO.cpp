#include "GameIO.h"
#include <string>
#include <iostream>
#include <ostream>
#include <fstream>
#include <tuple>

int GameIO::getTileNo(int row, int col)
{
	switch (row)
	{
		//1st row
	case 0:
		switch (col)
		{
			//(1,1)
		case 0:
			return 0;
			break;
			//(1,2)
		case 1:
			return 1;
			break;
			//(1,3)
		case 2:
			return 2;
			break;
			//(1,4)
		case 3:
			return 3;
			break;
		}
		break;
		//2nd row
	case 1:
		switch (col)
		{
			//(2,1)
		case 0:
			return 4;
			break;
			//(2,2)
		case 1:
			return 5;
			break;
			//(2,3)
		case 2:
			return 6;
			break;
			//(2,4)
		case 3:
			return 7;
			break;
		}
		break;
		//3rd row
	case 2:
		switch (col)
		{
			//(3,1)
		case 0:
			return 8;
			break;
			//(3,2)
		case 1:
			return 9;
			break;
			//(3,3)
		case 2:
			return 10;
			break;
			//(3,4)
		case 3:
			return 11;
			break;
		}
		break;
		//4th row
	case 3:
		switch (col)
		{
			//(4,1)
		case 0:
			return 12;
			break;
			//(4,2)
		case 1:
			return 13;
			break;
			//(4,3)
		case 2:
			return 14;
			break;
			//(4,4)
		case 3:
			return 15;
			break;
		}
		break;
	}
}

tuple<int, int> GameIO::returnRowCols(int tileNumber)
{
	int rowReturn, colReturn;

	if (tileNumber <= 3)
	{
		rowReturn = 0;
		switch (tileNumber)
		{
		case 0:
			colReturn = 0;
			break;
		case 1:
			colReturn = 1;
			break;
		case 2:
			colReturn = 2;
			break;
		case 3:
			colReturn = 3;
			break;
		}
	}
	else if (tileNumber >= 4 && tileNumber <= 7)
	{
		rowReturn = 1;
		switch (tileNumber)
		{
		case 4:
			colReturn = 0;
			break;
		case 5:
			colReturn = 1;
			break;
		case 6:
			colReturn = 2;
			break;
		case 7:
			colReturn = 3;
			break;
		}
	}
	else if (tileNumber >= 8 && tileNumber <= 11)
	{
		rowReturn = 2;
		switch (tileNumber)
		{
		case 8:
			colReturn = 0;
			break;
		case 9:
			colReturn = 1;
			break;
		case 10:
			colReturn = 2;
			break;
		case 11:
			colReturn = 3;
			break;
		}
	}
	else if (tileNumber >= 12 && tileNumber <= 15)
	{
		rowReturn = 3;
		switch (tileNumber)
		{
		case 12:
			colReturn = 0;
			break;
		case 13:
			colReturn = 1;
			break;
		case 14:
			colReturn = 2;
			break;
		case 15:
			colReturn = 3;
			break;
		}
	}

	return { rowReturn, colReturn };
}

void GameIO::saveGame(Logic& logic)
{
	string FILENAME_TO_SAVE;
	cout << "Enter name of game to save: ";
	cin >> FILENAME_TO_SAVE;

	FILENAME_TO_SAVE = FILENAME_TO_SAVE + ".txt";

	ofstream saveGame;
	saveGame.open(FILENAME_TO_SAVE);
	string scoreStr = to_string(logic.getScore());

	saveGame << "Score: " << scoreStr << endl;

	int row, col;

	for (row = 0; row < 4; row++)
	{
		for (col = 0; col < 4; col++)
		{
			saveGame << this->getTileNo(row, col) << ":";
			if (logic.getTileNum(row, col) == 0)
				saveGame << "0";
			else if (logic.getTileNum(row, col) == 1)
				saveGame << "*";
			else
			{
				int valToSave;
				valToSave = logic.getTileNum(row, col);
				saveGame << valToSave;
			}
			if (this->getTileNo(row, col) != 15)
				saveGame << endl;
		}
	}
	saveGame.close();
}

void GameIO::loadGame()
{
	array<array<int, 4>, 4> tempTiles;
	string scoreStr, FILENAME_TO_LOAD;
	int scoreInt;
	bool fileWasOpened;
	cout << "Enter name of save game: ";
	cin >> FILENAME_TO_LOAD;

	FILENAME_TO_LOAD = FILENAME_TO_LOAD + ".txt";

	ifstream saveGame(FILENAME_TO_LOAD);
	if (saveGame)
	{
		fileWasOpened = true;
		//load score
		getline(saveGame, scoreStr);
		int pos = scoreStr.find(":");
		scoreStr = scoreStr.substr(pos + 1);
		scoreInt = stoi(scoreStr);

		string line, tileNoStr, tileValStr;
		int tileNoInt, tileValInt;

		int row = 0;
		int col = 0;
		while (saveGame.eof() != true)
		{
			getline(saveGame, line);
			pos = line.find(":");
			tileValStr = line.substr(pos + 1);

			tileNoStr = line.substr(0, pos);
			if (pos > 0)
			{
				tileNoInt = stoi(tileNoStr);
				tie(row, col) = returnRowCols(tileNoInt);
			}

			if (tileValStr.compare("0") == 0)
				tempTiles[row][col] = 0;
			else if (tileValStr.compare("*") == 0)
				tempTiles[row][col] = 1;
			else
			{
				tileValInt = stoi(tileValStr);
				tempTiles[row][col] = tileValInt;
			}
		}
		Logic loadedGame(tempTiles, scoreInt);
	}
	else
	{
		fileWasOpened = false;
		cout << endl << "ERROR: File couldn't be loaded!" << endl << endl;
	}
	saveGame.close();

	if (fileWasOpened == true)
	{
		Logic loadedGame(tempTiles, scoreInt);
		loadedGame.launchGame(true);
	}
}