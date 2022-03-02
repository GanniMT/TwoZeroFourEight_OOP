#pragma once
#include "GameIO.h"
#include "Logic.h"
#include "Player.h"
#include <vector>
#include <algorithm>

using namespace std;

class HoF : public GameIO
{
	private:
		vector <Player> winners;

	public:
		void addWinner(string playerName, int score) { winners.push_back(Player(playerName, score)); }
		void sortWinners() { sort(winners.begin(), winners.end(), [](Player &a, Player &b) {return a.getScore() > b.getScore(); }); }
		void addSortWinners(string playerName, int score);

		void loadHoF();
		void addToHoF(string playerName, int score);
		void printHoF(Logic& logic, bool isComingFromGame);
};

