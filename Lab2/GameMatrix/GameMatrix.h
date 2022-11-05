// Created by Макар Михалёв on 21.10.2022.
#ifndef LAB2_GAMEMATRIX_H
#define LAB2_GAMEMATRIX_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "Voice.h"
#include <cstdlib>

class GameMatrix {
public:
    GameMatrix();
    void allocMemory();
    void updateGivenGameMatrix(std::string tableMatrix);
    std::vector<std::string> matrixVoice;
    std::vector< std::vector<int> > matrixPoint;
private:
    int n = 3;
    char tab;
};

#endif
