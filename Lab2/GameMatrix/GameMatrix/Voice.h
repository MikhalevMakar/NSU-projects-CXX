#ifndef PRISONERS_CHOICE_H
#define PRISONERS_CHOICE_H

enum Voice {
    COOPERATE = 'C',
    DEFECT = 'D'
};

enum StrategyName {
    ALWAYS_VOICE_C,
    ALWAYS_VOICE_D,
    RANDOM_VOICE
};

#endif