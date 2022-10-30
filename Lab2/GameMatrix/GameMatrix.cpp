#include "GameMatrix.h"

void GameMatrix::allocMemory() {
    matrixVoice.resize(8);
    matrixPoint.resize(8);
    for(int i = 0; i < 8; ++i) {
        matrixVoice[i].resize(3);
        matrixPoint[i].resize(3);
    }
}

GameMatrix::GameMatrix() {
    allocMemory();
    matrixVoice[0] = "CCC";
    matrixVoice[1] = "CCD";
    matrixVoice[2] = "CDC";
    matrixVoice[3] = "DCC";
    matrixVoice[4] = "CDD";
    matrixVoice[5] = "DCD";
    matrixVoice[6] = "DDC";
    matrixVoice[7] = "DDD";
    matrixPoint = { {7, 7, 7},
                    {3, 3, 9},
                    {3, 9, 3},
                    {9, 3, 3},
                    {0, 5, 5},
                    {5, 0, 5},
                    {5, 5, 0},
                    {1, 1, 1} };
}

void GameMatrix::updateGivenGameMatrix(std::string& tableMatrix) {
    std::ifstream fileMatrix(tableMatrix);

    if(!fileMatrix.is_open()) throw std::invalid_argument("file is not open");

    char* currReadLine = new char[n];

    for(int i =0; !fileMatrix.eof(); ++i) {
        fileMatrix.read(currReadLine, n);
        matrixVoice[i] = currReadLine;
        fileMatrix.read(currReadLine, n);
        matrixPoint[i][0] = std::atoi(&currReadLine[0]) / 100;
        matrixPoint[i][1] = std::atoi(&currReadLine[1]) / 10;
        matrixPoint[i][2] = std::atoi(&currReadLine[2]);
        fileMatrix.get(tab);
    }
    delete[] currReadLine;
}