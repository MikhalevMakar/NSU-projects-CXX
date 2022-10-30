//
// Created by Макар Михалёв on 29.10.2022.
//

#include "PercentageChoice.h"
PercentageChoice::PercentageChoice(std::string& configFile) {
    std::ifstream inputConfigFile(configFile);
    if(!inputConfigFile.is_open()) throw std::invalid_argument("ConfigFile is not open\n");

    char c;
    inputConfigFile.get(c);
    voice = static_cast<Voice>(c);

    std::getline(inputConfigFile, inputLine);
    std::string::size_type sz;
    percentageChoiceC = std::stod (inputLine, &sz);
}

Voice PercentageChoice::vote()  {
    return voice;
}

int PercentageChoice::voiceToNumTransl(Voice player) {
    return (player == COOPERATE) ? 1 : 0;
}

void PercentageChoice::update(Voice playerA, Voice playerB) {
    if(sumVote != 0) {
        cooperationRatio =
                cast_d(voiceToNumTransl(playerA) + voiceToNumTransl(playerB) + cooperationRatio) / cast_d(sumVote);
        voice = (cooperationRatio > percentageChoiceC) ? COOPERATE : DEFECT;
    }
    sumVote +=2;
}