//
// Created by Макар Михалёв on 04.11.2022.
//
#include "BipolarDisorder.h"

BipolarDisorder::BipolarDisorder(std::string configFolder) : GameStrategy("BIPOLAR_DISORDER",
                                                                            configFolder) {
    it = mapFile.find(configsFile);

    while(!it->second->eof()) {
        it->second->get(c);
        inputLine += c;
    }
    inputLine.erase(inputLine.end()-1);
    disorderFrequency = std::stod(inputLine, &sz);
    voice = COOPERATE;
}

Voice BipolarDisorder::vote() {
    return voice;
}

void BipolarDisorder::update(Voice playerA, Voice playerB) {
    if(playerA == DEFECT || playerB == DEFECT) countD++;
    else countD = 0;
    if(disorderFrequency == countD) voice = DEFECT;
}
