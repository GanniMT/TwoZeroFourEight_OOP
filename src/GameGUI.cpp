#include "GameGUI.h"

int GameGUI::howManyDigits(int number)
{
    if (number < 10)
        return 1;
    if (number < 100)
        return 2;
    if (number < 1000)
        return 3;
    if (number < 10000)
        return 4;
}

void GameGUI::centreTile(int number)
{
    int width = 7;
    int remainingWidth = width - this->howManyDigits(number);
    int rightWidth = remainingWidth / 2;
    int leftWidth = remainingWidth - rightWidth;

    for (int i = 0; i < leftWidth; i++)
        cout << " ";

    switch (number)
    {
    case 2:
        this->boldTextColour(1);
        break;
    case 4:
        this->boldTextColour(2);
        break;
    case 8:
        this->boldTextColour(3);
        break;
    case 16:
        this->boldTextColour(4);
        break;
    case 32:
        this->boldTextColour(5);
        break;
    case 64:
        this->boldTextColour(6);
        break;
    case 128:
        this->boldTextColour(3);
        break;
    case 256:
        this->boldTextColour(4);
        break;
    case 512:
        this->boldTextColour(5);
        break;
    case 1024:
        this->boldTextColour(6);
        break;
    case 2048:
        this->boldTextColour(7);
        break;
    }

    cout << number;
    this->resetColour();

    for (int i = 0; i < rightWidth; i++)
        cout << " ";
}

int GameGUI::printInterface(Logic& logic)
{
    this->clearScreen();
    this->boldTextColour(2);
    cout << " -------------------------------------" << endl;
    cout << " |  Join the tiles and get to 2048!  |" << endl;
    cout << " -------------------------------------" << endl;
    cout << endl;
    this->resetColour();


    for (int k = 0; k < 4; k++) {
        cout << "--------";
    }
    cout << '-' << endl;

    for (int i = 0; i < 4; i++) {
        cout << "|";

        for (int j = 0; j < 4; j++)
        {
            if (logic.getTileNum(i, j) > 1)
                this->centreTile(logic.getTileNum(i, j));
            else if (logic.getTileNum(i, j) == 0)
                cout << "       ";
            cout << "|";
        }

        cout << endl;
        for (int k = 0; k < 4; k++)
            cout << "--------";
        cout << '-' << endl;

    }

    this->boldTextColour(2);
    cout << endl;
    cout << " SCORE : ";
    cout << logic.getScore() << endl;
    this->printControls(1);
    this->resetColour();

    return 0;
}

void GameGUI::printInvalidKeystroke()
{
    cout << endl;
    this->textColour(1);
    cout << " Wrong keystroke! Please try again" << endl;
    this->resetColour();
}

void GameGUI::printLostGame(Logic& logic)
{
    this->boldTextColour(1);
    cout << " You Lost!" << endl;
    cout << " Score: " << logic.getScore() << endl << endl;
    this->resetColour();
}

void GameGUI::printWinGame(Logic& logic)
{
    this->boldTextColour(3);
    cout << " You Won!" << endl;
    cout << " Score: " << logic.getScore() << endl << endl;
    this->resetColour();
}

void GameGUI::printControls(int mode)
{
    switch (mode)
    {
    case 1: //Gameplay
        cout << " -----------------------------------------------" << endl;
        cout << " | CONTROLS:                                   |" << endl;
        cout << " |---------------------------------------------|" << endl;
        cout << " | N: New Game      X: Save Game  L: Load Game |" << endl;
        cout << " | H: Hall of Fame  Q: Quit                    |" << endl;
        cout << " -----------------------------------------------" << endl;
        cout << endl;
        break;
    case 2: //Hall of Fame
        cout << " -----------------------------------------------" << endl;
        cout << " | CONTROLS:                                   |" << endl;
        cout << " |---------------------------------------------|" << endl;
        cout << " | H: Return To Game   S: Save Game   Q: Quit  |" << endl;
        cout << " | L: Load Game                                |" << endl;
        cout << " -----------------------------------------------" << endl;
        cout << endl;
        break;
    }

}