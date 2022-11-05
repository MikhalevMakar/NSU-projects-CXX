//
// Created by Макар Михалёв on 29.10.2022.
//

#ifndef LAB2_STRATEGYPERCENTAGECHOICE_H
#define LAB2_STRATEGYPERCENTAGECHOICE_H

#include <fstream>
#include "../GameStrategy/GameStrategy.h"
#include "GameMatrix.h"


class PercentageChoice : public GameStrategy {
public:
    PercentageChoice(std::string configFile);
    Voice vote() override;
    void update(Voice playerA, Voice playerB) override;
private:
    std::string configsFile = "PERCENTAGE_CHOICE";
    std::ofstream* ptrOutputConfigFile;
    double cooperationRatio = 0;
    GameMatrix matrix;
    double percentageChoiceC;
    int indexInputLine = 0;
};


#endif
