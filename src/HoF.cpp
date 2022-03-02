#include "HoF.h"
#include "GameGUI.h"
#include "MainMenu.h"
#include "Logic.h"
#include <string>
#include <iostream>
#include <ostream>
#include <fstream>
#include <stdlib.h>

#define HALL_OF_FAME "hof.txt"

void HoF::addSortWinners(string playerName, int score)
{
	this->addWinner(playerName, score);
	this->sortWinners();
}

void HoF::loadHoF()
{
	ifstream loadingHoF(HALL_OF_FAME);
	if (loadingHoF)
	{
		string line, playerName, scoreStr;
		int pos, score;

		while (loadingHoF.eof() != true)
		{
			getline(loadingHoF, line);
			pos = line.find(":");
			scoreStr = line.substr(pos + 1);
			score = stoi(scoreStr);
			playerName = line.substr(0, pos);

			this->addWinner(playerName, score);
		}
		this->sortWinners();
	}
	else
		cout << "ERROR: Hall of Fame file couldn't be loaded!";
	loadingHoF.close();
}

void HoF::addToHoF(string playerName, int score)
{
	addWinner(playerName, score);

	this->loadHoF();

	sortWinners();
	ofstream savingHoF;
	savingHoF.open(HALL_OF_FAME); //deletes content and rewrites to file again
	for (int i = 0; i < winners.size(); i++)
	{
		savingHoF << winners[i].getPlayerName() << ": " << winners[i].getScore();
		if (i < winners.size() - 1)
			savingHoF << endl;
	}
	savingHoF.close();
}

void HoF::printHoF(Logic& logic, bool isComingFromGame)
{
	GameGUI gui;
	MainMenu backToMainMenu;
	int tempNum[4][4]; //create temporary array
	if (isComingFromGame == true)
	{
		for (int row = 0; row <= 3; row++)
		{
			for (int col = 0; col <= 3; col++)
				tempNum[row][col] = logic.getTileNum(row, col);
		}
		int tempScore = logic.getScore();

	}
	if (winners.empty() == true)
		this->loadHoF();

	gui.clearScreen();
	gui.boldTextColour(2);
	cout << " -------------------------------------" << endl;
	cout << " |            Hall of Fame           |" << endl;
	cout << " -------------------------------------" << endl;
	cout << endl;
	gui.resetColour();

	for (int i = 0; i < winners.size(); i++)
		cout << "  " << winners[i].getPlayerName() << ": " << winners[i].getScore() << endl;

	gui.boldTextColour(2);
	bool isKeystrokeValid = false;
	if (isComingFromGame == true)
	{
		gui.printControls(2);
		gui.resetColour();
		while (isKeystrokeValid == false)
		{
			string nextCommand;
			gui.resetColour();
			cout << " Enter keystroke: ";
			cin >> nextCommand;
			if (nextCommand == "H" || nextCommand == "h")
			{
				isKeystrokeValid = true;
				logic.launchGame(true);
			}
			else if (nextCommand == "S" || nextCommand == "s")
			{
				isKeystrokeValid = true;
				this->saveGame(logic);
			}
			else if (nextCommand == "Q" || nextCommand == "q")
			{
				isKeystrokeValid = true;
				exit(0);
			}
			else if (nextCommand == "L" || nextCommand == "l")
			{
				isKeystrokeValid = true;
				this->loadGame();
			}
			else
			{
				isKeystrokeValid = false;
				gui.printInvalidKeystroke();
			}
		}
	}
	else
	{
		while (isKeystrokeValid == false)
		{
			string nextCommand;
			gui.boldTextColour(2);
			cout << endl << " Press 'M' to go back to Main Menu" << endl << endl;
			gui.resetColour();
			cout << " Enter keystroke: ";
			cin >> nextCommand;
			if (nextCommand == "M" || nextCommand == "m")
			{
				isKeystrokeValid = true;
				backToMainMenu.printInterface(logic);
			}
			else
			{
				isKeystrokeValid = false;
				gui.printInvalidKeystroke();
			}
		}
	}
}
