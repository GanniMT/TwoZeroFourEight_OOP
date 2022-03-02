#pragma once
#include "GUI.h"

using namespace std;

class MainMenu : public GUI
{
	public:
		int printInterface(Logic& logic);
		void menuSelect();
};

