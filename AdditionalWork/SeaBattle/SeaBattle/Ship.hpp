#pragma once
#include <stdio.h>
#include <array>
#include <vector>

enum { sizeMap = 10 };

enum ShipType {
    Nothing,
    Battleship,
    Cruiser,
    Destroyers,
    TorpedoBoats
};

class Ship
{
protected:
    std::vector<std::vector<int>> map;
    int x= 0, y= 0, path = 2;
    int numShip = 1;
    int  StatShip[sizeMap + 1] = { 0 };
    
public:
    Ship();
    
    Ship(int other);
    
    void FillMap();
    
    bool CheckStatShip();

    void InputCoordinates();

    void PrintMap();

    bool CheckNearPath(int sizeShip);

    bool CheckCoordinates(int cY, int cX);

    void ChoosePath();

    bool CasePath(int sizeShip);

    void FillNumShip(int sizeShip);

    int GetNumShip(int i, int j);

    int GetSizeShip(int index);
};

