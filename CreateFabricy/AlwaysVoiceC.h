//
// Created by Макар Михалёв on 22.10.2022.

#ifndef LAB2_ALWAYSVOICEC_H
#define LAB2_ALWAYSVOICEC_H

#include "StrategyObject.h"

class AlwaysVoiceC : public StrategyObject {
public:
      Voice vote() const override {
         return COOPERATE;
     }
     void update(Voice playerA, Voice playerB) const override {
     }

};

namespace StrategyFactoryRegistration {
    StrategyFactoryRegistrations<AlwaysVoiceC> _AlwaysVoiceC("AlwaysVoiceC");
}

#endif
