//
// Created by daniil on 15.10.22.
//

#ifndef PRISONERS_GAMESTRATEGY_H
#define PRISONERS_GAMESTRATEGY_H

#include "Voice.h"
#include <iostream>
#include <string>
#include <map>
#include <fstream>

#define cast_d static_cast<double>

class GameStrategy {
public:
    GameStrategy() = default;
    GameStrategy(std::string nameStrategy, std::string configFolder);
    virtual Voice vote() = 0;
    virtual void update(Voice playerA, Voice playerB) = 0;
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