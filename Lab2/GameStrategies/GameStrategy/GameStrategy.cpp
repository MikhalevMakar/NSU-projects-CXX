#include "GameStrategy.h"

GameStrategy::GameStrategy(std::string nameStrategy, std::string configFolder) {
    configFolder += "/" + nameStrategy + ".txt";
    auto it = mapFile.find(configFolder);
    if(it != mapFile.end()) return;
    std::fstream* ptrConfigFile = new std::fstream(configFolder,std::fstream::in | std::fstream::out);
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