#ifndef PRISONERS_STRATEGYFACTORY_H
#define PRISONERS_STRATEGYFACTORY_H

#include <map>
#include "GameStrategy.h"
#include "AlwaysVoiceC.h"
#include "AlwaysVoiceD.h"
#include "RandomVoice.h"
#include "GameMatrix.h"
#include "PercentageChoice.h"
#include <string>

class StrategyFactory {
public:
    StrategyFactory() = default;
    GameStrategy* createStrategy(std::string strategyName, std::vector<std::string>& configsLine);
    ~StrategyFactory() = default;
    void clearConfigFile();
    int indexConfigsLine = 0;
};

#endif