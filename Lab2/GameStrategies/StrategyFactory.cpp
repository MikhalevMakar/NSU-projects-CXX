#include "StrategyFactory.h"

 GameStrategy* StrategyFactory::createStrategy(std::string strategyName) {
    if(strategyName == "ALWAYS_VOICE_C") {
        return new AlwaysVoiceC();
    }
    else if(strategyName == "ALWAYS_VOICE_D") {
        return new AlwaysVoiceD();
    }
    else if(strategyName == "RANDOM_VOICE") {
        return new RandomVoice();
    }
    throw std::invalid_argument("No such StrategyName\n");
 }
