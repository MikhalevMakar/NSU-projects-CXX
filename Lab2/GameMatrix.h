//
// Created by Макар Михалёв on 21.10.2022.
#ifndef LAB2_GAMEMATRIX_H
#define LAB2_GAMEMATRIX_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>

class GameMatrix {
public:
    GameMatrix();
    void allocMemory();
    GameMatrix(const char* tableMatrix);
private:
    std::vector<std::string> matrixVoice;
    std::vector<std::string> matrixPoint;
};


#endif //LAB2_GAMEMATRIX_H
