//
// Created by Макар Михалёв on 04.11.2022.
//

#ifndef LAB2_BIPOLARDISORDER_H
#define LAB2_BIPOLARDISORDER_H


#include "GameStrategy.h"

class BipolarDisorder : public GameStrategy {
public:
    BipolarDisorder() {

    }
    BipolarDisorder(std::string configFolder);
    Voice vote()  override;
    void update(Voice playerA, Voice playerB) override;
    void Print() override {
        std::cout << "BipolarDisorder\n";
    }

private:
    int disorderFrequency = 0;
    int countD = 0;
    std::string configsFile = "BIPOLAR_DISORDER";
};


namespace StrategyFactoryRegistration {
    StrategyFactoryRegistrations<BipolarDisorder> _BipolarDisorder("BipolarDisorder");
}

#endif
