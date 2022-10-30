#include "Mode.h"

Mode::Mode(int _countSteps,
           std::vector<std::string>  _strategyName,
           std::vector<std::string> _configsLine,
           std::string _matrixLine) : countSteps(_countSteps),
                                      strategyName(_strategyName),
                                      configsLine(_configsLine),
                                      matrixLine(_matrixLine) {
    vectorTotalPoint.resize(strategyName.size());

    if(!matrixLine.empty()) {
        matrix.updateGivenGameMatrix(matrixLine);
    }
}

void Mode::CreatePlayers() {
    for(int i = 0; i < 3; ++i) {
        vectorPlayers.push_back(strategyFactory.createStrategy(strategyName[i], configsLine));
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

void Mode::updateStrategy() {
    for(int i = 0; i < strategyName.size(); ++i) {
        if( strategyName[i] != "ALWAYS_VOICE_C" ||
            strategyName[i] != "ALWAYS_VOICE_D" ||
            strategyName[i] !=  "RANDOM_VOICE") {
            vectorPlayers[i]->update((Voice)(votePlayer[(i+1)%3]),
                                     (Voice)(votePlayer[(i+2)%3]));
        }
    }
}