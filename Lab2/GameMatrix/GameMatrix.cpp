#include "GameMatrix.h"
void GameMatrix::allocMemory() {
    matrixVoice.resize(8);
    matrixPoint.resize(8);
    for(int i = 0; i < 8; ++i) {
        matrixVoice[i].resize(6);
        matrixPoint[i].resize(6);
    }
}
GameMatrix::GameMatrix() {
    allocMemory();
    matrixVoice[0] = "CCC";
    matrixPoint[0] = "777";

    matrixVoice[1] = "CCD";
    matrixPoint[1] = "339";

    matrixVoice[2] = "CDC";
    matrixPoint[2] = "393";

    matrixVoice[3] = "DCC";
    matrixPoint[3] = "933";

    matrixVoice[4] = "CDD";
    matrixPoint[4] = "055";

    matrixVoice[5] = "DCD";
    matrixPoint[5] = "505";

    matrixVoice[6] = "DDC";
    matrixPoint[6] = "550";

    matrixVoice[7] = "DDD";
    matrixPoint[7] = "111";
}

GameMatrix::GameMatrix(std::string& tableMatrix) {
    allocMemory();
    std::ifstream fileMatrix("fileMatrix.txt");

    if(!fileMatrix.is_open()) throw std::invalid_argument("file is not open");
    int n = 3;
    char* currReadLine = new char[n+1];
    for(int i =0; !fileMatrix.eof(); ++i) {
        fileMatrix.read(currReadLine, n);
        matrixVoice[i] = currReadLine;
        fileMatrix.read(currReadLine, n);
        matrixPoint[i] = currReadLine;
    }
    delete[] currReadLine;
}