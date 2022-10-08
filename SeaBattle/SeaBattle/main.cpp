#include "RandomPlacementShips.hpp"
#include <iostream>
#include "OptionaleGame.hpp"
#include <functional>

int main()
{
    setlocale(LC_ALL, "ru");
    RandomPlacementShips r;
    r.PrintMap();
    //r.InputCoordinates();
    
    OptionaleGame o(r, &RandomPlacementShips::GetSizeShip);
    

    
    o.PrintMap();
    
    return 0;
}
