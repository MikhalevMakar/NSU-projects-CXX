#include "GameStrategy.h"

void GameStrategy::openFolder(std::string f, std::string nameStrategy) {
    f += "/" + nameStrategy + ".txt";
    auto it = mapFile.find(f);
    if(it != mapFile.end()) return;
    std::fstream* ptrConfigFile = new std::fstream(f, std::fstream::in | std::fstream::out);
    if(!ptrConfigFile->is_open())
        throw std::invalid_argument("ConfigFile is not open\n");

    mapFile.emplace(nameStrategy, ptrConfigFile);
}

GameStrategy::~GameStrategy() {
    for(auto it : mapFile) {
        it.second->close();
    }
}

int GameStrategy::voiceToNumTransl(Voice player) {
    return (player == COOPERATE) ? 1 : 0;
}