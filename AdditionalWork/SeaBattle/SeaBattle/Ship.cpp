#include "Ship.hpp"
#include <iostream>

bool Ship::CheckStatShip()
{
    for(int i = 0; i < sizeMap; ++i)
    {
        if(StatShip[i] > 0) {
            return false;
        }
    }
    return true;
}

void Ship::InputCoordinates()
{
    while (true) {

        std::cout << "Введите координаты: ";
        std::cin >> y >> x;

        if (map[y][x] > 0)
        {
            std::cout << "Вы попали!1 " << std::endl;

            StatShip[map[y][x]]--;
            if (StatShip[map[y][x]] == 0) {
                std::cout << "Вы убили! " << std::endl;
            }
            map[y][x] = -1;
        }
        
        else
        {
            std::cout << "Вы промахнулись! " << std::endl;
        }

        PrintMap();
    }
}

void Ship::PrintMap()
{
    for(int i = 0; i < sizeMap; ++i)
    {
        for (int j = 0; j < sizeMap; ++j)
        {
            if (map[i][j] > 0)
                std::cout << map[i][j];
            else if (map[i][j] == 0)
                std::cout << "-";
            else
                std::cout << "x";
        }

        if (CheckStatShip() == true)
        {
            std::cout << "";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl << std::endl;
}

bool Ship::CheckNearPath(int sizeShip) {
    int cX = x;
    int cY = y;

    for (int i = 0; i < sizeShip; ++i)
    {
        if (map[y][x] > 0 ||
            (CheckCoordinates(y, x+1) == true && map[y][x+1] > 0) ||
            (CheckCoordinates(y, x-1) == true && map[y][x-1] > 0) ||
            (CheckCoordinates(y-1, x) == true && map[y-1][x] > 0) ||
            (CheckCoordinates(y+1, x) == true && map[y+1][x] > 0) ||
            (CheckCoordinates(y+1, x+1) == true && map[y+1][x+1] > 0) ||
            (CheckCoordinates(y+1, x-1) == true && map[y+1][x-1] > 0) ||
            (CheckCoordinates(y-1, x+1) == true && map[y-1][x+1] > 0) ||
            (CheckCoordinates(y-1, x-1) == true && map[y-1][x-1] > 0))
        {
            x = cX;
            y = cY;
            return false;
        }

        ChoosePath();
    }

    x = cX;
    y = cY;
    return true;
}

bool Ship::CheckCoordinates(int cY, int cX)
{
    return  (cX >= 0 && cY >= 0 && cX < sizeMap && cY < sizeMap) ? true : false;
}


bool Ship::CasePath(int sizeShip)
{
    sizeShip--;
    switch (path)
    {
    case 0: return CheckCoordinates(y, x+sizeShip) && CheckCoordinates(x, y);
    case 1: return CheckCoordinates(y, x-sizeShip) && CheckCoordinates(x, y);
    case 2: return CheckCoordinates(y+sizeShip, x) && CheckCoordinates(x, y);
    case 3: return CheckCoordinates(y-sizeShip, x) && CheckCoordinates(x, y);
    default: return false;
    }
}

void Ship::ChoosePath()
{
    switch (path)
    {
    case 0: x++; break;
    case 1: x--; break;
    case 2: y++; break;
    case 3: y--; break;
    }
}

void Ship::FillMap()
{
    map.resize(sizeMap);
    for(int i = 0; i < sizeMap; ++i)
    {
        map[i].resize(sizeMap);
    }
}

Ship::Ship() { FillMap(); }

Ship::Ship(int other):x(3), y(0) { FillMap(); }

void Ship::FillNumShip(int sizeShip)
{
    for (int i = 0; i < sizeShip; ++i)
    {
        map[y][x] = numShip;
        ChoosePath();
    }

    StatShip[numShip] = sizeShip;
    numShip++;
}

int Ship::GetNumShip(int i, int j)
{
    return map[i][j];
}

int Ship::GetSizeShip(int index)
{
    return StatShip[index];
}
