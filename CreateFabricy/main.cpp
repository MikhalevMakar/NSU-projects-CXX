#include <iostream>
#include "StrategyObject.h"
#include "StrategyFactory.h"
#include "StrategyFactoryRegistrations.h"
#include "AlwaysVoiceC.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    StrategyFactoryRegistration::StrategyFactoryRegistrations<AlwaysVoiceC>  a("AlwaysVoiceC");
    return 0;
}