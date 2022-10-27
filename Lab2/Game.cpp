// Created by Макар Михалёв on 23.10.2022.
#include "Game.h"

Game::Game(int argc, char** argv) {
    InputParser inputParser(argc, argv);
    std::cout<<inputParser.modeLine;
    RandomVoice v;

    if(inputParser.modeLine == "detailed")  ModeDetailed(inputParser.strategyName,
                                                         inputParser.modeLine,
                                                         inputParser.configsLine);
    else if(inputParser.modeLine == "fast") std::cout << "fast";
    else if(inputParser.modeLine == "tournament") std::cout << "tournament";

}
