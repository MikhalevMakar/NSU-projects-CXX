#pragma once
#include "Ship.h"
#include <windows.h>
#include <conio.h>
#include <iostream>
enum { reverse = 32, down = 119, up = 115, left = 97, right = 100, put = 13 };

class ManualInstalShips : public Ship
{
	int key = 0;
public:
	ManualInstalShips();
	
	void ArrangementShips(int sizeShip, int count);
	
	void Shift—ursor();

	void ChooseKey();
};