#pragma once
#include "Logic.h"

using namespace std;

class GUI
{
	public:
		void clearScreen();
		void textColour(int colourCode);
		void boldTextColour(int colourCode);
		void resetColour();

		virtual int printInterface(Logic& logic) = 0;
};

