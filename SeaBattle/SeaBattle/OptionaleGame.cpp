#include "OptionaleGame.hpp"

// -1 промах

void OptionaleGame::AssignToSupXY()
{
    supX = x;
    supY = y;
}

void OptionaleGame::AssignToXY(int cX, int cY)
{
    x = cX;
    y = cY;
}

void OptionaleGame::AssignToXY()
{
    x = supX;
    y = supY;
}

void OptionaleGame::AssignNumShip(int numShip, RandomPlacementShips& objectClassR)
{
    StatShip[numShip]--;
    map[y][x] = numShip;
    FillingEmptyCells(objectClassR);
}

void OptionaleGame::FindPath(int sizeShip, RandomPlacementShips& objectClassR)
{
    while(true)
    {
        AssignToSupXY();
        ChoosePath();
        
        if(CheckCoordinates(y, x) == true  && objectClassR.GetNumShip(y, x) > 0)
        {
            return;
        }
        else
        {
            x = supX;
            y = supY;
            path++;
            path %= 4;
        }
    }
}

void OptionaleGame::FillingEmptyCells(RandomPlacementShips& objectClassR)
{
    for(int i = 0; i < 3; ++i)
    {
        for(int j = 0; j < 3; ++j)
        {
            if(this->CheckCoordinates(y+arrShift[j], x+arrShift[i]) == true && objectClassR.GetNumShip(y+arrShift[j], x+arrShift[i]) == 0)
            {
                map[y+arrShift[j]][x+arrShift[i]] = -1;
            }
        }
    }
}

void OptionaleGame::TryKillShip(int sizeShip, RandomPlacementShips& objectClassR, int numShip)
{
    AssignNumShip(numShip, objectClassR);
    if(sizeShip == 1)
    {
        return;
    }
    
    while(sizeShip != 0)
    {
        sizeShip--;
        FindPath(sizeShip, objectClassR);
        AssignNumShip(numShip, objectClassR);
    }
}

void OptionaleGame::TryShotTorpedoBoats(RandomPlacementShips& objectClassR)
{
    if(x == -1)
    {
        statusFindTorpedoBoats++;
        AssignToXY(arrX[statusFindTorpedoBoats], arrY[statusFindTorpedoBoats]);
    }
    
    int  numShip = objectClassR.GetNumShip(y, x);
    int  sizeShip = objectClassR.GetSizeShip(numShip);
    
    if(numShip > 0)
    {
        AssignToSupXY();
        TryKillShip(sizeShip, objectClassR, numShip);
        AssignToXY();
        
        if (sizeShip == 4)
        {
            statusFindTorpedoBoats = 4;
            return;
        }
    } else
    {
        map[y][x] = -1;
    }
    x--;
    y++;
}

void OptionaleGame::FillArr()
{
    arrShift.reserve(3);
    arrShift.push_back(-1);
    arrShift.push_back(0);
    arrShift.push_back(1);
    
    arrX.reserve(4);
    arrX.push_back(3);
    arrX.push_back(7);
    arrX.push_back(9);
    arrX.push_back(9);
    
    arrY.reserve(4);
    arrY.push_back(0);
    arrY.push_back(0);
    arrY.push_back(2);
    arrY.push_back(6);
}

void OptionaleGame::CopyArrStatShip(RandomPlacementShips& objectClassR,std::function<int(RandomPlacementShips&, int)> getSizeShip)
{
    for(int i = 1; i < sizeMap+1; ++i)
    {
        this->StatShip[i] = getSizeShip(objectClassR, i);
    }
}

int OptionaleGame::GetRandomCoordinate(int N)
{
    return rand() % N;
}

void OptionaleGame::TryGetShip(RandomPlacementShips& objectClassR)
{
    while(map[y][x] != 0)
    {
        x = GetRandomCoordinate(sizeMap-1);
        y = GetRandomCoordinate(sizeMap-1);
    }
    
    if(objectClassR.GetNumShip(y, x) > 0)
    {
        int numShip = objectClassR.GetNumShip(y, x);
        TryKillShip(objectClassR.GetSizeShip(numShip), objectClassR, numShip);
        // AssignNumShip(objectClassR.GetNumShip(y, x), objectClassR);
    }
    else
    {
        map[y][x] = -1;
    }
}

void OptionaleGame::Shot(RandomPlacementShips& objectClassR)
{
    switch(statusFindTorpedoBoats)
    {
        case 0: TryShotTorpedoBoats(objectClassR); break;
        case 1: TryShotTorpedoBoats(objectClassR); break;
        case 2: TryShotTorpedoBoats(objectClassR); break;
        case 3: TryShotTorpedoBoats(objectClassR); break;
        default:TryGetShip(objectClassR);
    }
}

OptionaleGame::OptionaleGame(RandomPlacementShips& objectClassR, std::function<int(RandomPlacementShips&, int)> getSizeShip):Ship(1)
{
    FillArr();
    CopyArrStatShip(objectClassR, getSizeShip);
};
