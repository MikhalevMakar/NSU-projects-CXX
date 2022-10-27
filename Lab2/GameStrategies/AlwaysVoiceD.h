//
// Created by Макар Михалёв on 22.10.2022.

#ifndef LAB2_ALWAYSVOICED_H
#define LAB2_ALWAYSVOICED_H
#include "GameStrategy.h"

class AlwaysVoiceD : public GameStrategy {
public:
     Voice vote() override;
     void update(Voice playerA, Voice playerB) override;
     bool isApplicable(StrategyName name) override;
     ~AlwaysVoiceD() override = default;
};


#endif //LAB2_ALWAYSVOICED_H
