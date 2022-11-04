#ifndef CREATE_FABRICY_H
#define CREATE_FABRICY_H

enum Voice {
    COOPERATE = 'C',
    DEFECT = 'D'
};

enum StrategyName {
    ALWAYS_VOICE_C,
    ALWAYS_VOICE_D,
    RANDOM_VOICE,
    PERCENTAGE_CHOICE
};

#endif