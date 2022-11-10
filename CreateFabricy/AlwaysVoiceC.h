//
// Created by Макар Михалёв on 22.10.2022.

#ifndef LAB2_ALWAYSVOICEC_H
#define LAB2_ALWAYSVOICEC_H


#include "GameStrategy.h"

class AlwaysVoiceC : public GameStrategy {
public:
      Voice vote()   override {
         return COOPERATE;
     }
     void update(Voice playerA, Voice playerB)  override {

      }

     void Print() override {
          std::cout << "AlwaysVoiceC\n" << std::endl;
      }
};

namespace StrategyFactoryRegistration {
    StrategyFactoryRegistrations<AlwaysVoiceC> _AlwaysVoiceC("AlwaysVoiceC");
}

#endif
