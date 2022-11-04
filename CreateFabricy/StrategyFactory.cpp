//
// Created by Макар Михалёв on 04.11.2022.
//

#include "StrategyFactory.h"

StrategyFactory& StrategyFactory::get() {
    static StrategyFactory instance;
    return instance;
}

StrategyObject* StrategyFactory::orderStrategy(std::string typeName) {
    auto it = s_generators.find(typeName);
    if (it != s_generators.end())
        return it->second();
    return nullptr;
}

bool StrategyFactory::registerGenerator(std::string typeName, const StrategyInstanceGenerator& funcCreate) {
    return s_generators.insert(std::make_pair(typeName, funcCreate)).second;
}


