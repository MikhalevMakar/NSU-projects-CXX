// Created by Макар Михалёв on 23.10.2022

#ifndef PRISON_GAME_H
#define PRISON_GAME_H

#include "AlwaysVoiceC.h"
#include "AlwaysVoiceD.h"
#include "RandomVoice.h"
#include "GameMatrix.h"
#include "InputParser.h"
#include "Voice.h"
#include "ModeDetailed.h"
#include "ModeFast.h"
#include "ModeTournament.h"

class Game {
public:
     Game(int argc, char** argv);
     //virtual Voice vote() = 0;
    // virtual void update(Voice playerA, Voice playerB) = 0;
    // bool isApplicable(StrategyName name) = 0;
     //~GameStrategy() = default;
 };

#endif
