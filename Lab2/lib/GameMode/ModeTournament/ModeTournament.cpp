//
// Created by Макар Михалёв on 29.10.2022.
//

#include "ModeTournament.h"

ModeTournament::ModeTournament(int _countSteps,
               std::vector<std::string> _strategyName,
               std::string _configsLine,
               std::string _matrixLine) : Mode(_countSteps,
                                               _strategyName,
                                               _configsLine,
                                               _matrixLine) {
    gameModeStart();
}

int ModeTournament::getIndexStrategy(int index) {
    switch(index) {
        case 0: return player1;
        case 1:  return player2;
        case 2: return player3;
    }
    return 0;
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

    for(int i = 0; i < 3; ++i) {
        vectorPlayers[i] = StrategyFactory::get().orderStrategy(strategyName[getIndexStrategy(i)]);
        vectorPlayers[i]->strategyDevelopment(configsLine);
        printStrategy[i] = strategyName[getIndexStrategy(i)];
    }

    return true;
}

void ModeTournament::supportMessageClient() {
    std::cout << "\nCurrent game results:\n";
}

void ModeTournament::printCurrentGameResults() {
    std::cout << "NumberPlayer\t\tNameStrategy\t\tVoice\t\tPointsPerTurn\n";
    for(int i = 0; i < 3; ++i) {
        std::cout << std::setw(6) <<  i+1;
        std::cout << std::setw(31) << printStrategy[i];
        std::cout << std::setw(14) << votePlayer[i];
        std::cout << std::setw(19) << matrix.matrixPoint[row][i] << "\n";
    }
}

void ModeTournament::updateTotalPoints(int value) {
    for(int i = 0; i < 3; ++i) {
        vectorTotalPoint[getIndexStrategy(i)] += matrix.matrixPoint[row][i];
    }
}

void ModeTournament::PrintStartOfTheRound() {
    std::cout << "\nStart of the round:\n\n";
}

void ModeTournament::gameModeStart() {
    supportMessageClient();
    while(threePlayerGeneration()) {
        PrintStartOfTheRound();
        while(countSteps != step++) {
            makeUpVotePlayers();
            updatePointsPerTurn();
            updateTotalPoints(1);
            printCurrentGameResults();
            updateStrategy();
        }
        step = 0;
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