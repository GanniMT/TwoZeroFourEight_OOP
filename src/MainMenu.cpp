#include "MainMenu.h"
#include "Logic.h"
#include "HoF.h"
#include "GameGUI.h"
#include <iostream>

int MainMenu::printInterface(Logic& logic)
{
	char choice;
	cout << " Welcome to ";
	textColour(1);
	cout << "2";
	textColour(2);
	cout << "0";
	textColour(3);
	cout << "4";
	textColour(4);
	cout << "8";
	resetColour();
	cout << "...with an added twist!" << endl << endl;

	cout << " 1. Play" << endl;
	cout << " 2. Load a game" << endl;
	cout << " 3. Display Hall of Fame" << endl;
	cout << " 4. Exit" << endl << endl;

	cout << " Enter choice: ";
	cin >> choice;

	if (choice == '1' || choice == '2' || choice == '3' || choice == '4')
		return (choice - '0');
	else
		return 0;
}

void MainMenu::menuSelect()
{
	Logic logic;
	HoF inputOutput;
	int choice;
	do {
		choice = this->printInterface(logic);
		switch (choice)
		{
		case 1:
			logic.launchGame(false);
			break;
		case 2:
			inputOutput.loadGame();
			break;
		case 3:
			inputOutput.printHoF(logic, false);
			break;
		case 4:
			exit(0);
			break;
		default:
			GameGUI invalidKS;
			invalidKS.printInvalidKeystroke();
			cout << endl;
			break;
		}
	} while (choice != 4);
}