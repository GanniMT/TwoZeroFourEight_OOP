#pragma once
#include "TwoZeroFourEight.h"

using namespace std;

class Logic : public TwoZeroFourEight
{
	public:
		Logic() : TwoZeroFourEight() {}
		Logic(array<array<int, 4>, 4> tilesInput, int score)
			: TwoZeroFourEight(tilesInput, score) {}
		
		void checkIfGameOver();

		//Tile Generation
		int randTileGen();
		int randRowColGen();
		void spawnInitialRandTiles();
		void spawnRandTile();

		//Player Input
		string playerInput();
		bool moveTilesUp();
		bool moveTilesLeft();
		bool moveTilesDown();
		bool moveTilesRight();
		bool confirmKS();
		bool processKS();

		void launchGame(bool loadedGame);
};

