#include <iostream>
#include "GameStrategy.h"
#include "StrategyFactory.h"


int main() {
    std::cout << "Hello, World!" << std::endl;
    GameStrategy* temp = StrategyFactory::get().orderStrategy("AlwaysVoiceC");
    temp->Print();
    GameStrategy* e = StrategyFactory::get().orderStrategy("BipolarDisorder");
    e->Print();
    return 0;
}