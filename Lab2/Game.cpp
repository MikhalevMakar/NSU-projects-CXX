// Created by Макар Михалёв on 23.10.2022.
#include "Game.h"

Game::Game(int argc, char** argv) {
    InputParser inputParser(argc, argv);

    if(inputParser.modeLine == "detailed")
                                            ModeDetailed(inputParser.countSteps,
                                                         inputParser.strategyName,
                                                         inputParser.configsLine);
    else if(inputParser.modeLine == "fast")
                                            ModeFast(inputParser.countSteps,
                                                     inputParser.strategyName,
                                                     inputParser.configsLine);
    else if(inputParser.modeLine == "tournament")
                                            ModeTournament(inputParser.countSteps,
                                                           inputParser.strategyName,
                                                           inputParser.configsLine);
}
