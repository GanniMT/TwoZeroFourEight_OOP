#include "GUI.h"
#include <iostream>

void GUI::clearScreen()
{
	cout << "\033[H\033[2J\033[3J";
}

void GUI::textColour(int colourCode)
{
	switch (colourCode)
	{
	case 1: //RED
		cout << "\033[0;31m";
		break;
	case 2: //YELLOW
		cout << "\033[0;33m";
		break;
	case 3: //GREEN
		cout << "\033[0;32m";
		break;
	case 4: //CYAN
		cout << "\033[0;36m";
		break;
	case 5: //BLUE
		cout << "\033[0;34m";
		break;
	case 6: //PURPLE
		cout << "\033[0;35m";
		break;
	}
}

void GUI::boldTextColour(int colourCode)
{
	switch (colourCode)
	{
	case 1: //BOLD RED
		cout << "\033[1;31m";
		break;
	case 2: //BOLD YELLOW
		cout << "\033[1;33m";
		break;
	case 3: //BOLD GREEN
		cout << "\033[1;32m";
		break;
	case 4: //BOLD CYAN
		cout << "\033[1;36m";
		break;
	case 5: //BOLD BLUE
		cout << "\033[1;34m";
		break;
	case 6: //BOLD PURPLE
		cout << "\033[1;35m";
		break;
	case 7: //BOLD WHITE
		cout << "\033[1;37m";
		break;
	}
}

void GUI::resetColour()
{
	cout << "\033[0m";
}