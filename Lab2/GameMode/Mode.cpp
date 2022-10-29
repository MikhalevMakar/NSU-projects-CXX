#include "Mode.h"

Mode::Mode(int _countSteps,
           std::vector<std::string>  _strategyName,
           std::vector<std::string> _configsLine) : countSteps(_countSteps),
                                                    strategyName(_strategyName),
                                                    configsLine(_configsLine) {
    vectorTotalPoint.resize(strategyName.size());
}

void Mode::CreatePlayers() {
    for(int i = 0; i < 3; ++i) {
        vectorPlayers.push_back(strategyFactory.createStrategy(strategyName[i]));
    }
    if(vectorPlayers.size() != 3) throw std::invalid_argument("nameStrategy less 3");
}

void Mode::makeUpVotePlayers() {
    votePlayer.clear();
    for(int player = numFirstPlayer; player < lastPlayer; ++player) {
        votePlayer += vectorPlayers[player]->vote();
    }
}

void Mode::updatePointsPerTurn() {
   for(int  curRow = 0; curRow < 8; ++curRow) {
       if(votePlayer == matrix.matrixVoice[curRow]) {
           row = curRow;
           return;
       }
    }
    throw std::invalid_argument("Participant's voice is not correct");
}

void Mode::updateTotalPoints() {
    for (int i = 0; i < 3; ++i) {
        vectorTotalPoint[i] += matrix.matrixPoint[row][i];
    }
}

std::string Mode::pickingWinner() {
    int maxIndex = 0;
    for(int i = 0; i < strategyName.size(); ++i) {
        if(vectorTotalPoint[i] > vectorTotalPoint[maxIndex]) maxIndex = i;
    }
    return strategyName[maxIndex];
}