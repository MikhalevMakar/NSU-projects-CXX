// Created by Макар Михалёв on 21.10.2022.
#ifndef LAB2_GAMEMATRIX_H
#define LAB2_GAMEMATRIX_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "Voice.h"

class GameMatrix {
public:
    GameMatrix();
    void allocMemory();
    GameMatrix(std::string& tableMatrix);
    void updateScorePointMatrix(Voice VoiceA,
                                Voice VoiceB,
                                Voice VoiceC);
private:
    std::vector<std::string> matrixVoice;
    std::vector<std::string> matrixPoint;
    std::vector<std::string> ScorePointMatrix;
};


#endif
