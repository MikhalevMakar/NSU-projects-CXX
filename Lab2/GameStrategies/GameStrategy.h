//
// Created by daniil on 15.10.22.
//

#ifndef PRISONERS_GAMESTRATEGY_H
#define PRISONERS_GAMESTRATEGY_H

#include "Voice.h"
#include <iostream>
#include <string>
class GameStrategy {
public:
    virtual Voice vote() = 0;
    virtual void update(Voice playerA, Voice playerB) = 0;
    virtual ~GameStrategy() = default;
};

#endif