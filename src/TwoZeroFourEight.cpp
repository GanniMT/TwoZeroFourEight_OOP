#include "TwoZeroFourEight.h"

using namespace std;

bool TwoZeroFourEight::isTilesEmpty()
{
	bool numIsEmpty = true;
	for (int row = 0; row < 4; row++)
	{
		for (int col = 0; col < 4; col++)
		{
			if (getTileNum(row, col) != 0)
			{
				numIsEmpty = false;
				break;
			}
		}
		if (numIsEmpty == false)
			break;
	}
	return numIsEmpty;
}