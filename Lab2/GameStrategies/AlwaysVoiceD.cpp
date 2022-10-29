//
// Created by Макар Михалёв on 22.10.2022.
//

#include "AlwaysVoiceD.h"
Voice AlwaysVoiceD::vote()  {
    return DEFECT;
}

bool AlwaysVoiceD::isApplicable(StrategyName name)  {
    return name == ALWAYS_VOICE_D;
}

void AlwaysVoiceD::update(Voice playerA, Voice playerB) {

}