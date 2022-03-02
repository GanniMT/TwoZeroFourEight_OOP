#pragma once
#include <string>

using namespace std;

class Player
{
	private:
		string playerName;
		int score;
	public:

		Player(string playerName, int score)
		{
			this->playerName = playerName;
			this->score = score;
		}

		string getPlayerName() { return playerName; }
		int getScore() { return score; }
};

