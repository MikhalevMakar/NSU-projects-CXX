//
// Created by Макар Михалёв on 22.10.2022.

#ifndef LAB2_ALWAYSVOICED_H
#define LAB2_ALWAYSVOICED_H

#include "../GameStrategy/GameStrategy.h"

class AlwaysVoiceD : public GameStrategy {
public:
    AlwaysVoiceD() = default;
    Voice vote() override;
    void update(Voice playerA, Voice playerB) override;
    void strategyDevelopment(std::string folder) override;
    ~AlwaysVoiceD()  = default;
};

namespace StrategyFactoryRegistration {
    StrategyFactoryRegistrations<AlwaysVoiceD> _AlwaysVoiceD("ALWAYS_VOICE_D");
}

#endif
