#pragma once
#include "GUI.h"
#include "Logic.h"

using namespace std;

class GameGUI : public GUI
{
	public:

		// Functions related to Display during Game
		int howManyDigits(int number);
		void centreTile(int number);
		int printInterface(Logic& logic);

		// Errors and Alerts
		void printInvalidKeystroke();
		void printLostGame(Logic& logic);
		void printWinGame(Logic& logic);

		void printControls(int mode);

};

