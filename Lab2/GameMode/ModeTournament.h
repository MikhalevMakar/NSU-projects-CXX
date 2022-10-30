//
// Created by Макар Михалёв on 29.10.2022.
//

#ifndef LAB2_MODETOURNAMENT_H
#define LAB2_MODETOURNAMENT_H
#include "Mode.h"

class ModeTournament : public Mode {
public:
    ModeTournament(int _countSteps,
                   std::vector<std::string> _strategyName,
                   std::vector<std::string> _configsLine,
                   std::string _matrixLine);
    void gameModeStart() override;
    bool threePlayerGeneration();
    void supportMessageClient();
    void printGame() override;
    void printCurrentGameResults();
    void updateTotalPoints(int value);
private:
    int player1 = 0,
        player2 = 1,
        player3 = 1,
        step = 0;
};


#endif //LAB2_MODETOURNAMENT_H
