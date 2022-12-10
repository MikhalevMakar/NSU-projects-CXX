//
// Created by Макар Михалёв on 29.10.2022.
//
#include "ModeFast.h"

ModeFast::ModeFast(int _countSteps,
                   std::vector<std::string> _strategyName,
                   std::string _configsLine,
                   std::string _matrixLine) : Mode(_countSteps,
                                                    _strategyName,
                                                    _configsLine,
                                                    _matrixLine) {
    gameModeStart();
}

void ModeFast::gameModeStart() {
    CreatePlayers();
    while(countSteps >= ++curStep) {
        makeUpVotePlayers();
        updatePointsPerTurn();
        updateTotalPoints();
        updateStrategy();
    }
    printGame();
}

void ModeFast::printGame() {
    std::cout << "\nFinal table of the game:\n\n";
    std::cout << "NumberPlayer\t\tNameStrategy\t\tTotalPoints\n";
    for(int i = 0; i < 3; ++i) {
        std::cout << std::setw(6) <<  i+1;
        std::cout << std::setw(31) << strategyName[i];
        std::cout << std::setw(17) << vectorTotalPoint[i] << "\n";
    }
    std::cout << "\nWIN Strategy:" << pickingWinner() <<"!\n\n";
}
