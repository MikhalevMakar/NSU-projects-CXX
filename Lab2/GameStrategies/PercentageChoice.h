//
// Created by Макар Михалёв on 29.10.2022.
//

#ifndef LAB2_STRATEGYPERCENTAGECHOICE_H
#define LAB2_STRATEGYPERCENTAGECHOICE_H

#include <fstream>
#include "GameStrategy.h"
#include "GameMatrix.h"

#define cast_d static_cast<double>

class PercentageChoice : public GameStrategy {
public:
    PercentageChoice(std::string& configFile);
    Voice vote() override;
    void update(Voice playerA, Voice playerB) override;
    int voiceToNumTransl(Voice player);
private:
    std::ofstream* ptrOutputConfigFile;
    Voice voice = COOPERATE;
    double cooperationRatio = 0;
    int sumVote = 0;
    GameMatrix matrix;
    double percentageChoiceC;
    std::string inputLine;
    int indexInputLine = 0;
};


#endif
