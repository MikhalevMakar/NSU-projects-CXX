//
// Created by Макар Михалёв on 22.10.2022.
//

#include "AlwaysVoiceC.h"
Voice AlwaysVoiceC::vote()  {
    return COOPERATE;
}

void AlwaysVoiceC::update(Voice playerA, Voice playerB)  {

}
bool AlwaysVoiceC::isApplicable(StrategyName name)  {
    return name == ALWAYS_VOICE_C;
}