//
// Created by Макар Михалёв on 04.11.2022.
//

#ifndef CREATEFABRICY_STRATEGYOBJECT_H
#define CREATEFABRICY_STRATEGYOBJECT_H

#include "StrategyFactoryRegistrations.h"
#include "Voice.h"

class StrategyObject {
public:
    virtual Voice vote() const  = 0;
    virtual void update(Voice playerA, Voice playerB) const = 0;
};

#endif