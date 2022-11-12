//
// Created by daniil on 15.10.22.
//

#ifndef PRISONERS_GAMESTRATEGY_H
#define PRISONERS_GAMESTRATEGY_H

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include "../StrategyFactory/StrategyFactoryRegistrations.h"
#include "Voice.h"

#define cast_d static_cast<double>

class GameStrategy {
public:
    GameStrategy() = default;
    void openFolder(std::string f, std::string nameStrategy);
    virtual void strategyDevelopment(std::string folder) = 0;
    virtual Voice vote()  = 0;
    virtual void update(Voice playerA, Voice playerB)  = 0;
    ~GameStrategy();
    int voiceToNumTransl(Voice player);
protected:
    std::map<std::string, std::fstream*>::iterator  it;
    std::map<std::string, std::fstream*> mapFile;
    int sumVote = 0;
    Voice voice;
    std::string inputLine;
    std::string::size_type sz;
    char c;
};

#endif