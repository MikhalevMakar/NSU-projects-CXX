#include "ManualInstalShips.h"

void ManualInstalShips::Shift—ursor()
{
	COORD  console = {x, y};
	HANDLE hand = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hand, console);
}

void ManualInstalShips::ChooseKey()
{
	switch (key)
	{
	case down: y--; break;
	case up: y++; break;
	case right: x++; break;
	case left:  x--; break;
	case reverse:  path = !path; break;
	}
}

void ManualInstalShips::ArrangementShips(int sizeShip, int count)
{
	int cX, cY, countShipPlace = 0;
	while (countShipPlace != count)
	{
		PrintMap();
		key = _getch();
		ChooseKey();
		cX = x;
		cY = y;

		if (key == put && CheckNearPath(sizeShip) == true)
		{
			FillNumShip(sizeShip);
			countShipPlace++;
		}
		else if (CasePath(sizeShip) == true)
		{
			for (int i = 0; i < sizeShip; ++i)
			{
				Shift—ursor();
				std::cout << "*";
				ChoosePath();
			}
		}

		x = cX;
		y = cY;
		system("pause");
		system("cls");
	}
}

ManualInstalShips::ManualInstalShips()
{
	ArrangementShips(TorpedoBoats, 1);
	ArrangementShips(Destroyers, 2);
	ArrangementShips(Cruiser, 3);
	ArrangementShips(Battleship, 4);
} 