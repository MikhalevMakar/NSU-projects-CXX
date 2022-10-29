//
// Created by daniil on 15.10.22.
//

#ifndef PRISONERS_GAMESTRATEGY_H
#define PRISONERS_GAMESTRATEGY_H

#include "Voice.h"
#include <iostream>


class GameStrategy {
public:
    virtual Voice vote() = 0;
    virtual void update(Voice playerA, Voice playerB) = 0;
    virtual bool isApplicable(StrategyName name) = 0;
    virtual ~GameStrategy() = default;
};

#endif