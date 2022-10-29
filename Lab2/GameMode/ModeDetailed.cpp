#include "ModeDetailed.h"
ModeDetailed::ModeDetailed( int _countSteps,
                            std::vector<std::string> _strategyName,
                            std::vector<std::string> _configsLine) : Mode(_countSteps,
                                                                          _strategyName,
                                                                          _configsLine) {
    gameModeStart();
}

void ModeDetailed::gameModeStart() {
    CreatePlayers();
    while(countSteps >= ++curStep) {
        makeUpVotePlayers();
        updatePointsPerTurn();
        updateTotalPoints();
        printGame();
        std::cin >> key;
        if(key == quit) return;
        else if(key == ret) {
            std::cout << "The game continues\n";
        } else {
            throw std::invalid_argument("Input not recognized\n");
        }
   }
}

void ModeDetailed::printGame() {
    std::cout << "NumberPlayer\t\tStep\t\tNameStrategy\t\tVoice\t\tPointsPerTurn\t\tTotalPoints\n";
    for(int i = 0; i < 3; ++i) {
        std::cout << std::setw(6) <<  i+1;
        std::cout << std::setw(20) << curStep;
        std::cout << std::setw(27) << strategyName[i];
        std::cout << std::setw(14) << votePlayer[i];
        std::cout << std::setw(19) << matrix.matrixPoint[row][i];
        std::cout << std::setw(23) << vectorTotalPoint[i] << "\n";
    }
    std::cout << "press  to continue enter: return\n";
    std::cout << "if you want to stop the game enter: quit\n";
    std::cout << "Enter:";
    std::cout<< "\n";
}