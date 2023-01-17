#pragma once
#include <stdio.h>
#include <iostream>
#include "Ship.hpp"

class RandomPlacementShips : public Ship
{

public:
    RandomPlacementShips();

    int GetRandomCoordinate(int N);

    void CreateRandomShip(int cout, int sizeShip);
};

