//
// Created by Макар Михалёв on 29.10.2022.

#include "PercentageChoice.h"
PercentageChoice::PercentageChoice(std::string configFolder) : GameStrategy("PERCENTAGE_CHOICE",
                                                                            configFolder) {
    it = mapFile.find(configsFile);
    it->second->get(c);
    voice = static_cast<Voice>(c);

    while(!it->second->eof()) {
        it->second->get(c);
        inputLine += c;
    }
    inputLine.erase(inputLine.end()-1);
    percentageChoiceC = std::stod(inputLine, &sz);
}

Voice PercentageChoice::vote()  {
    return voice;
}

void PercentageChoice::update(Voice playerA, Voice playerB) {
    if(sumVote != 0) {
        cooperationRatio =
                cast_d(voiceToNumTransl(playerA) + voiceToNumTransl(playerB) + cooperationRatio) / cast_d(sumVote);
        voice = (cooperationRatio > percentageChoiceC) ? COOPERATE : DEFECT;
    }
    sumVote +=2;
}
