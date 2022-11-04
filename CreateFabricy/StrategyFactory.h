//
// Created by Макар Михалёв on 04.11.2022.
//

#ifndef CREATEFABRICY_STRATEGYFACTORY_H
#define CREATEFABRICY_STRATEGYFACTORY_H

#include <iostream>
#include <string>
#include <unordered_map>

class StrategyObject;
typedef StrategyObject*(*StrategyInstanceGenerator)();

class StrategyFactory {
public:
    static StrategyFactory& get();
    StrategyObject* orderStrategy(std::string  typeName);
    bool registerGenerator(std::string  typeName, const StrategyInstanceGenerator& funcCreate);

    StrategyFactory() = default;

    ~StrategyFactory() = default;
    std::unordered_map<std::string, StrategyInstanceGenerator> s_generators;
};


#endif