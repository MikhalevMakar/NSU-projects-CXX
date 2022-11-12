// Created by Макар Михалёв on 22.10.2022.

#include "RandomVoice.h"
Voice RandomVoice::vote()  {
    return (rand() % 2) ? COOPERATE : DEFECT;
}

void RandomVoice::update(Voice playerA, Voice playerB) { }

void RandomVoice::strategyDevelopment(std::string folder) { }