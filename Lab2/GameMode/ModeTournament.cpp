//
// Created by Макар Михалёв on 29.10.2022.
//

#include "ModeTournament.h"

ModeTournament::ModeTournament(int _countSteps,
               std::vector<std::string> _strategyName,
               std::vector<std::string> _configsLine) : Mode(_countSteps,
                                                             _strategyName,
                                                             _configsLine) {
    gameModeStart();
}

bool ModeTournament::threePlayerGeneration() {
    player3++;
    if(player3 >= strategyName.size()) {
        player3 = (++player2) + 1;
    }
    if(player2+1 >= strategyName.size()) {
        player2 = (++player1) + 1;
        player3 = player2+1;
    }
    if(player1+2 >= strategyName.size()) return false;

    vectorPlayers = { strategyFactory.createStrategy(strategyName[player1]),
                      strategyFactory.createStrategy(strategyName[player2]),
                      strategyFactory.createStrategy(strategyName[player3]) };
    return true;
}
void ModeTournament::supportMessageClient() {
    std::cout << "\nCurrent game results:\n\n";
}

void ModeTournament::printCurrentGameResults() {
    std::cout << "NumberPlayer\t\tNameStrategy\t\tVoice\t\tPointsPerTurn\n";
    for(int i = 0; i < 3; ++i) {
        std::cout << std::setw(6) <<  i+1;
        std::cout << std::setw(31) << strategyName[i];
        std::cout << std::setw(14) << votePlayer[i];
        std::cout << std::setw(19) << matrix.matrixPoint[row][i] << "\n";
    }
}

void ModeTournament::updateTotalPoints(int value) {
    vectorTotalPoint[player1] += matrix.matrixPoint[row][0];
    vectorTotalPoint[player2] += matrix.matrixPoint[row][1];
    vectorTotalPoint[player3] += matrix.matrixPoint[row][2];
}

void ModeTournament::gameModeStart() {
    supportMessageClient();
    while(threePlayerGeneration()) {
        makeUpVotePlayers();
        updatePointsPerTurn();
        updateTotalPoints(1);
        printCurrentGameResults();
    }
    printGame();
}

void ModeTournament::printGame() {
        std::cout << "\nFinal table of the game:\n\n";
        std::cout << "NumberPlayer\t\tNameStrategy\t\tTotalPoints\n";
        for(int i = 0; i < strategyName.size(); ++i) {
            std::cout << std::setw(6) <<  i+1;
            std::cout << std::setw(31) << strategyName[i];
            std::cout << std::setw(17) << vectorTotalPoint[i] << "\n";
        }
        std::cout << "\nWIN Strategy:" << pickingWinner() <<"!\n\n";
}