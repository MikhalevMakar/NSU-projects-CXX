//
// Created by Макар Михалёв on 22.10.2022.
//

#include "AlwaysVoiceD.h"
Voice AlwaysVoiceD::vote()  {
    return DEFECT;
}

void AlwaysVoiceD::update(Voice playerA, Voice playerB)  {

}
bool AlwaysVoiceD::isApplicable(StrategyName name)  {
    return name == ALWAYS_VOICE_D;
}