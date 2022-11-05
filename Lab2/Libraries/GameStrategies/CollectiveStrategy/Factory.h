#ifndef PRISONERS_STRATEGYFACTORY_H
#define PRISONERS_STRATEGYFACTORY_H

#include <map>
#include "../GameStrategy/GameStrategy.h"
#include "../AlwaysVoiceC/AlwaysVoiceC.h"
#include "../AlwaysVoiceD/AlwaysVoiceD.h"
#include "../RandomVoice/RandomVoice.h"
#include "GameMatrix.h"
#include "../PercentageChoice/PercentageChoice.h"
#include "../ViewOpponentsActions/ViewOpponentsActions.h"
#include "../BipolarDisorder/BipolarDisorder.h"
#include <string>

class Factory {
public:
    Factory() = default;
    Factory(std::string& _configsLine);
    GameStrategy* createStrategy(std::string strategyName);
    ~Factory() = default;

private:
    std::string configsLine;
};

#endif