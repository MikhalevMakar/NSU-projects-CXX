//
// Created by Макар Михалёв on 04.11.2022.
//

#ifndef LAB2_COLLECTIVESTRATEGY_H
#define LAB2_COLLECTIVESTRATEGY_H


#include "Factory.h"
#include <vector>

class CollectiveStrategy  : public GameStrategy {
public:
    CollectiveStrategy(std::string configFolder);
    Voice vote() override;
    void update(Voice playerA, Voice playerB) override;
private:
    std::vector<GameStrategy*> vectorGameStrategy;
    void ReadFromFile();
    std::string configsFile = "COLLECTIVE_STRATEGY";
};


#endif //LAB2_COLLECTIVESTRATEGY_H
