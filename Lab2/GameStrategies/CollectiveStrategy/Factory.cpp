#include "Factory.h"

Factory::Factory(std::string& _configsLine) {
    configsLine = _configsLine;
}

GameStrategy* Factory::createStrategy(std::string strategyName) {
    if(strategyName == "ALWAYS_VOICE_C") {
        return new AlwaysVoiceC();
    }
    else if(strategyName == "ALWAYS_VOICE_D") {
        return new AlwaysVoiceD();
    }
    else if(strategyName == "RANDOM_VOICE") {
        return new RandomVoice();
    }
    else if(strategyName == "PERCENTAGE_CHOICE") {
        return new PercentageChoice(configsLine);
    }
    else if(strategyName == "VIEW_OPPONENTS_ACTIONS") {
        return new ViewOpponentsActions(configsLine);
    }
    else if(strategyName == "BIPOLAR_DISORDER")  {
        return new BipolarDisorder(configsLine);
    }

    throw std::invalid_argument("No such StrategyName\n");
}