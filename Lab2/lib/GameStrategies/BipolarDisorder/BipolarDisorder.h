//
// Created by Макар Михалёв on 04.11.2022.
//

#ifndef LAB2_BIPOLARDISORDER_H
#define LAB2_BIPOLARDISORDER_H
#include "../GameStrategy/GameStrategy.h"

class BipolarDisorder : public GameStrategy {
public:
    BipolarDisorder() = default;
    Voice vote() override;
    void update(Voice playerA, Voice playerB) override;
    void strategyDevelopment(std::string folder) override;
private:
    int disorderFrequency = 0;
    int countD = 0;
    std::string configsFile = "BIPOLAR_DISORDER";
};

namespace StrategyFactoryRegistration {
    StrategyFactoryRegistrations<BipolarDisorder> _BipolarDisorder("BIPOLAR_DISORDER");
}

#endif //LAB2_BIPOLARDISORDER_H
