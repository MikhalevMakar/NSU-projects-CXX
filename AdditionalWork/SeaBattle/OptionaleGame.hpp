#pragma once
#include "Ship.hpp"
#include "RandomPlacementShips.hpp" 
#include <vector>
#include <functional>

class OptionaleGame : public Ship
{
    std::vector<int> arrShift;
    int supX,supY;
    int statusFindTorpedoBoats = 0;
    std::vector<int> arrX;
    std::vector<int> arrY;
public:
    OptionaleGame(RandomPlacementShips& objectClassR, std::function<int(RandomPlacementShips&, int)> getSizeShip);
    
    void TryShotTorpedoBoats(RandomPlacementShips& objectClassR);
    
    void CopyArrStatShip(RandomPlacementShips& objectClassR, std::function<int(RandomPlacementShips&, int)> getSizeShip);
    
    void FindPath(int sizeShip, RandomPlacementShips& objectClassR);
    
    void AssignNumShip();
    
    void AssignToXY(int cX, int cY);
   
    void TryKillShip(int sizeShip, RandomPlacementShips& objectClassR, int numShip);
    
    void FillArr();
    
    void TryGetShip(RandomPlacementShips& objectClassR);
    
    void Shot(RandomPlacementShips& objectClassR);
    
    void AssignToSupXY();
    
    void AssignToXY();
    
    void AssignNumShip(int numShip, RandomPlacementShips& objectClassR);
    
    int GetRandomCoordinate(int N);
    
    void FillingEmptyCells(RandomPlacementShips& objectClassR);
};


