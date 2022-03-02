#include "Logic.h"
#include "TwoZeroFourEight.h"
#include "HoF.h"
#include "GameGUI.h"

void Logic::checkIfGameOver()
{
	bool areTilesAvailable = false;
	bool is2048Present = false;

	//Checking for any available tiles
	for (int row = 0; row < 4; row++)
	{
		for (int col = 0; col < 4; col++)
		{
			if (this->getTileNum(row, col) == 0)
				areTilesAvailable = true;
		}
	}

	//Checking if 2048 tile is present
	for (int row = 0; row < 4; row++)
	{
		for (int col = 0; col < 4; col++)
		{
			if (this->getTileNum(row, col) == 2048)
			{
				is2048Present = true;
				break;
			}
		}
		if (is2048Present == true)
			break;
	}

	if (is2048Present == true)
	{
		this->setIsGameWon(true);
		this->setIsGameOver(true);
	}
	else if (areTilesAvailable == false)
	{
		this->setIsGameOver(true);
	}
}

int Logic::randTileGen()
{
	int randomNum = 1 + (rand() % 10);

	if (randomNum >= 1 && randomNum <= 5) //50% probability
		return 2;
	else if (randomNum >= 6 && randomNum <= 10) //50% probability
		return 4;
}

int Logic::randRowColGen()
{
	int randRowOrColumn = rand() % 4;
	return randRowOrColumn;
}

void Logic::spawnInitialRandTiles()
{
	int firstValue = this->randTileGen();
	int secondValue = this->randTileGen();

	int randRow1, randCol1;
	int randRow2, randCol2;

	randRow1 = this->randRowColGen();
	randCol1 = this->randRowColGen();
	randRow2 = this->randRowColGen();
	randCol2 = this->randRowColGen();

	if (randRow1 == randRow2)
	{
		while (randRow1 == randRow2)
		{
			randRow2 = this->randRowColGen();
		}
	}
	else if (randCol1 == randCol2)
	{
		while (randCol1 == randCol2)
		{
			randCol2 = this->randRowColGen();
		}
	}

	this->setTileNum(randRow1, randCol1, firstValue);
	this->setTileNum(randRow2, randCol2, secondValue);
}

void Logic::spawnRandTile()
{
	char randVal = this->randTileGen();
	int randRow, randCol;
	bool availableTile = false;

	while (availableTile == false)
	{
		randRow = this->randRowColGen();
		randCol = this->randRowColGen();

		if (this->getTileNum(randRow, randCol) == 0)
		{
			availableTile = true;
			this->setTileNum(randRow, randCol, randVal);
		}
	}
}

string Logic::playerInput()
{
	cout << "Enter your next move: ";

	char keystroke;
	cin >> keystroke;
	if (keystroke == 'W' || keystroke == 'w')
		return "MOVE_UP";
	else if (keystroke == 'A' || keystroke == 'a')
		return "MOVE_LEFT";
	else if (keystroke == 'S' || keystroke == 's')
		return "MOVE_DOWN";
	else if (keystroke == 'D' || keystroke == 'd')
		return "MOVE_RIGHT";
	else if (keystroke == 'N' || keystroke == 'n')
		return "NEW_GAME";
	else if (keystroke == 'H' || keystroke == 'h')
		return "HALL_FAME";
	else if (keystroke == 'X' || keystroke == 'x')
		return "SAVE_GAME";
	else if (keystroke == 'Q' || keystroke == 'q')
		return "QUIT";
	else if (keystroke == 'L' || keystroke == 'l')
		return "LOAD_GAME";
	else
		return "BAD_KEYSTROKE";
}

bool Logic::moveTilesUp()
{
	bool tilesMoved = false;
	for (int col = 0; col < 4; col++)
	{
		for (int row = 0; row < 4; row++)
		{
			// 'row2' is used to compare two rows with each other
			for (int row2 = row + 1; row2 <= 3; row2++)
			{
				if (this->getTileNum(row2, col) != 0)
				{
					if (this->getTileNum(row, col) == 0)
					{
						this->setTileNumFromTile(row, col, row2, col);
						this->setTileNum(row2, col, 0);
						tilesMoved = true;
					}
					else
					{
						if (this->getTileNum(row, col) == this->getTileNum(row2, col))
						{
							//two mine tiles colliding
							this->mulTileByTwo(row, col);
							this->setTileNum(row2, col, 0);
							tilesMoved = true;
						}
						break;
					}
				}
			}
		}
	}
	return tilesMoved;
}

bool Logic::moveTilesLeft()
{
	bool tilesMoved = false;
	for (int row = 0; row < 4; row++)
	{
		for (int col = 0; col < 4; col++)
		{
			// 'col2' is used to compare two columns with each other
			for (int col2 = col + 1; col2 <= 3; col2++)
			{
				if (this->getTileNum(row, col2) != 0)
				{
					if (this->getTileNum(row, col) == 0)
					{
						this->setTileNumFromTile(row, col, row, col2);
						this->setTileNum(row, col2, 0);
						tilesMoved = true;
					}
					else
					{
						if (this->getTileNum(row, col) == this->getTileNum(row, col2))
						{
							this->mulTileByTwo(row, col);
							this->getTileNum(row, col2);
							this->addToScore(row, col);
							tilesMoved = true;
						}
						break;
					}
				}
			}
		}
	}
	return tilesMoved;
}

bool Logic::moveTilesDown()
{
	bool tilesMoved = false;
	for (int col = 0; col < 4; col++)
	{
		for (int row = 3; row >= 0; row--)
		{
			// 'row2' is used to compare two rows with each other
			for (int row2 = row - 1; row2 >= 0; row2--)
			{
				if (this->getTileNum(row2, col) != 0)
				{
					if (this->getTileNum(row, col) == 0)
					{
						this->setTileNumFromTile(row, col, row2, col);
						this->setTileNum(row2, col, 0);
						tilesMoved = true;
					}
					else
					{
						if (this->getTileNum(row, col) == this->getTileNum(row2, col))
						{
							this->mulTileByTwo(row, col);
							this->setTileNum(row2, col, 0);
							this->addToScore(row, col);
							tilesMoved = true;
						}
						break;
					}
				}
			}
		}
	}
	return tilesMoved;
}

bool Logic::moveTilesRight()
{
	bool tilesMoved = false;
	for (int row = 0; row < 4; row++)
	{
		for (int col = 3; col > 0; col--)
		{
			// 'col2' is used to compare two columns with each other
			for (int col2 = col - 1; col2 >= 0; col2--)
			{
				if (this->getTileNum(row, col2) != 0) //two tiles aren't empty
				{
					if (this->getTileNum(row, col) == 0)
					{
						this->setTileNumFromTile(row, col, row, col2);
						this->setTileNum(row, col2, 0);
						tilesMoved = true;
					}
					else
					{
						if (this->getTileNum(row, col) == this->getTileNum(row, col2))
						{
							this->mulTileByTwo(row, col);
							this->setTileNum(row, col2, 0);
							this->addToScore(row, col);
							tilesMoved = true;
						}
						break;
					}
				}
			}
		}
	}
	return tilesMoved;
}

bool Logic::confirmKS()
{
	Logic newGame;
	GameGUI invalidKeystroke;
	char keystroke2;
	bool isKeystrokeValid;
	do {
		cout << endl << " Are you sure you want to start a new game? (Y/N): ";
		cin >> keystroke2;
		if (keystroke2 == 'Y' || keystroke2 == 'y')
		{
			isKeystrokeValid = true;
			newGame.launchGame(false);
			return true;
		}
		else if (keystroke2 == 'N' || keystroke2 == 'n')
		{
			isKeystrokeValid = true;
			return false;
		}
		else
		{
			isKeystrokeValid = false;
			invalidKeystroke.printInvalidKeystroke();
		}
	} while (isKeystrokeValid == false);

}

bool Logic::processKS()
{
	bool tilesMoved = true, tilesNotMoved = false;
	string keystroke;
	keystroke = this->playerInput();
	GameGUI dispInvKS;

	if (keystroke == "MOVE_UP")
	{
		bool haveTilesMoved = this->moveTilesUp();
		if (haveTilesMoved == false)
		{
			dispInvKS.printInvalidKeystroke();
			return tilesNotMoved;
		}
		else
			return tilesMoved;
	}
	else if (keystroke == "MOVE_LEFT")
	{
		bool haveTilesMoved = this->moveTilesLeft();
		if (haveTilesMoved == false)
		{
			dispInvKS.printInvalidKeystroke();
			return tilesNotMoved;
		}
		else
			return tilesMoved;
	}
	else if (keystroke == "MOVE_DOWN")
	{
		bool haveTilesMoved = this->moveTilesDown();
		if (haveTilesMoved == false)
		{
			dispInvKS.printInvalidKeystroke();
			return tilesNotMoved;
		}
		else
			return tilesMoved;
	}
	else if (keystroke == "MOVE_RIGHT")
	{
		bool haveTilesMoved = this->moveTilesRight();
		if (haveTilesMoved == false)
		{
			dispInvKS.printInvalidKeystroke();
			return tilesNotMoved;
		}
		else
			return tilesMoved;
	}
	else if (keystroke == "NEW_GAME")
	{
		bool haveTilesMoved = this->confirmKS();
		if (haveTilesMoved == false)
		{
			dispInvKS.printInvalidKeystroke();
			return tilesNotMoved;
		}
		else
			return tilesMoved;
	}
	else if (keystroke == "HALL_FAME")
	{
		HoF HallOfFame;
		HallOfFame.printHoF(*this, true);
		return tilesNotMoved;
	}
	else if (keystroke == "SAVE_GAME")
	{
		GameIO SaveGame;
		SaveGame.saveGame(*this);
		return tilesNotMoved;
	}
	else if (keystroke == "QUIT")
		exit(0);
	else if (keystroke == "LOAD_GAME")
	{
		GameIO LoadSaveGame;
		LoadSaveGame.loadGame();
		return tilesNotMoved;
	}
	else if (keystroke == "BAD_KEYSTROKE")
	{
		GameGUI keystrokeAlert;
		keystrokeAlert.printInvalidKeystroke();
		return tilesNotMoved;
	}
}

void Logic::launchGame(bool loadedGame)
{
	GameGUI gameGUI;

	bool isKeystrokeValid = true;

	if (this->isTilesEmpty() == true)
		this->spawnInitialRandTiles();

	do {
		this->checkIfGameOver();
		gameGUI.printInterface(*this);

		if (this->getIsGameWon() == true)
		{
			string playerName;
			HoF addingWinner;
			gameGUI.printWinGame(*this);

			cout << "Enter your name: ";
			cin.ignore(); // Clearing buffer
			getline(cin, playerName);

			addingWinner.addToHoF(playerName, this->getScore());
			addingWinner.printHoF(*this, false);
		}
		else if (this->getIsGameOver() == true)
			gameGUI.printLostGame(*this);
		else
		{
			if (loadedGame == true)
			{
				loadedGame = false;
				isKeystrokeValid = false;
			}
			if (isKeystrokeValid == true)
			{
				this->spawnRandTile();
			}
			isKeystrokeValid = this->processKS();
		}
	} while (this->getIsGameOver() == false);
}