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
#include "../CollectiveStrategy/CollectiveStrategy.h"
#include <string>

class StrategyFactory {
public:
    StrategyFactory() = default;
    StrategyFactory(std::string& _configsLine);
    GameStrategy* createStrategy(std::string strategyName);
    ~StrategyFactory() = default;
private:
    std::string configsLine;
};

#endif