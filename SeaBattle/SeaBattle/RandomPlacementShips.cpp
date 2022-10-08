#include "RandomPlacementShips.hpp"

RandomPlacementShips::RandomPlacementShips()
{
    CreateRandomShip(1, ShipType::TorpedoBoats);
    CreateRandomShip(2, ShipType::Destroyers);
    CreateRandomShip(3, ShipType::Cruiser);
    CreateRandomShip(4, ShipType::Battleship);
};

int RandomPlacementShips::GetRandomCoordinate(int N) {
    return rand() % N;
}

void RandomPlacementShips::CreateRandomShip(int count, int sizeShip)
{
    int countShipPlace = 0;

    while (countShipPlace != count)
    {
        x = GetRandomCoordinate(sizeMap - 1);
        y = GetRandomCoordinate(sizeMap - 1);
        path = GetRandomCoordinate(4);

        if (CasePath(sizeShip) == true && CheckNearPath(sizeShip) == true)
        {
            FillNumShip(sizeShip);
            countShipPlace++;
        }
    }
}

