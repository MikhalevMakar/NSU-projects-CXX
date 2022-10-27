#include "StrategyFactory.h"

 GameStrategy* StrategyFactory::createStrategy(StrategyName strategyName,
                                    const std::string &configPath,
                                    const GameMatrix &gameMatrix) {
     switch (strategyName) {
         case ALWAYS_VOICE_C:
             return new AlwaysVoiceD();
         case ALWAYS_VOICE_D:
             return new AlwaysVoiceD();
         case RANDOM_VOICE:
             return new RandomVoice();
     }
     throw std::invalid_argument("no such StrategyName\n");
 }
