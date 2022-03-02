#pragma once
#include "Logic.h"
#include <tuple>

using namespace std;

class GameIO
{
	public:
		// Intermediary Functions
		int getTileNo(int rowReturn, int colReturn);
		tuple<int, int> returnRowCols(int tileNumber);

		// Saving and Loading Game
		void saveGame(Logic& logic);
		void loadGame();
};