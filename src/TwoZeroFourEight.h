#pragma once
#include <string>
#include <iostream>
#include <array>

using namespace std;

class TwoZeroFourEight
{
	private:
		array<array<int, 4>, 4> tiles;
		int score;
		bool isGameWon;
		bool isGameOver;

	public:
		TwoZeroFourEight()
		{
			srand((int)time(0));
			tiles.fill({ 0 });
			this->setScore(0);
			this->setIsGameWon(false);
			this->setIsGameOver(false);
		}

		TwoZeroFourEight(array<array<int, 4>, 4> tilesInput, int score)
		{
			srand((int)time(0));
			for (int row = 0; row < 4; row++)
			{
				for (int col = 0; col < 4; col++)
					this->setTileNum(row, col, tilesInput[row][col]);
			}
			this->setScore(score);
			this->setIsGameWon(false);
			this->setIsGameOver(false);
		}

		//functions related to Number array
		int getTileNum(int row, int col) { return tiles[row][col]; }
		void setTileNum(int row, int col, int num) { tiles[row][col] = num; }
		void setTileNumFromTile(int rowEdit, int colEdit, int rowSource, int colSource) { tiles[rowEdit][colEdit] = tiles[rowSource][colSource]; }
		void mulTileByTwo(int row, int column) { tiles[row][column] *= 2; }
		bool isTilesEmpty();

		// Functions concerning score
		int getScore() { return score; }
		void setScore(int score) { this->score = score; }
		void addToScore(int rowSource, int colSource) { score += tiles[rowSource][colSource]; }
		void subtFromScore(int rowSource, int colSource) { score -= tiles[rowSource][colSource]; }

		//related to isGameOver and isGameWon
		bool getIsGameWon() { return isGameWon; }
		void setIsGameWon(bool isGameWon) { this->isGameWon = isGameWon; }
		bool getIsGameOver() { return isGameOver; }
		void setIsGameOver(bool isGameOver) { this->isGameOver = isGameOver; }
};

