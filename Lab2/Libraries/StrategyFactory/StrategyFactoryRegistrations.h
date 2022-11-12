//
// Created by Макар Михалёв on 04.11.2022.
//
#ifndef CREATEFABRICY_STRATEGYFACTORYREGISTRATIONS_H
#define CREATEFABRICY_STRATEGYFACTORYREGISTRATIONS_H

#include "StrategyFactory.h"

namespace StrategyFactoryRegistration {
    template <typename T>
    class StrategyFactoryRegistrations {
    public:
        StrategyFactoryRegistrations(std::string  id) {
            StrategyFactory::get().registerGenerator(
                    id,
                    []() {
                        return static_cast<GameStrategy*>(new T());
                    });
        }
    };
}
#endif