//
// Created by Макар Михалёв on 30.10.2022.
//

#ifndef LAB2_TOTALVIEWOPPONENTSACTIONS_H
#define LAB2_TOTALVIEWOPPONENTSACTIONS_H

#include "../GameStrategy/GameStrategy.h"
#include "../GameMatrix/GameMatrix.h"

class ViewOpponentsActions : public GameStrategy {
public:
    ViewOpponentsActions() = default;
    void strategyDevelopment(std::string folder) override;
    Voice vote() override;
    void update(Voice playerA, Voice playerB) override;
    Voice voiceDefinition(double player);
    void decisionMakingStrategy(Voice first, Voice second);
private:
    std::string configsFile = "VIEW_OPPONENTS_ACTIONS";

    int firstPlayer, secondPlayer;
    GameMatrix matrix;
};

namespace StrategyFactoryRegistration {
    StrategyFactoryRegistrations<ViewOpponentsActions> _ViewOpponentsActions("VIEW_OPPONENTS_ACTIONS");
}

#endif //LAB2_TOTALVIEWOPPONENTSACTIONS_H
