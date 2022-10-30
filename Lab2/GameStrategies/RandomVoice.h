//
// Created by Макар Михалёв on 22.10.2022.

#ifndef LAB2_RANDOMVOICE_H
#define LAB2_RANDOMVOICE_H

#include "GameStrategy.h"

class RandomVoice : public GameStrategy {
public:
    RandomVoice() =default;
    Voice vote() override;
    void update(Voice playerA, Voice playerB) override;
    ~RandomVoice() override = default;
};


#endif
