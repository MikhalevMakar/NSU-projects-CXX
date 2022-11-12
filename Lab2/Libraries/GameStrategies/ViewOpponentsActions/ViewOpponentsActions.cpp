//
// Created by Макар Михалёв on 30.10.2022.
//

#include "ViewOpponentsActions.h"

void ViewOpponentsActions::strategyDevelopment(std::string folder) {
    openFolder(folder, "VIEW_OPPONENTS_ACTIONS");
    it = mapFile.find(configsFile);
    it->second->get(c);
    voice = static_cast<Voice>(c);
}

Voice ViewOpponentsActions::vote() {
    return voice;
}

void ViewOpponentsActions::decisionMakingStrategy(Voice first, Voice second) {
    int maxPoint = 0;
    for(int i = 0; i < 8; ++i)
        if (maxPoint < matrix.matrixPoint[i][2])
            if (matrix.matrixVoice[i][0] == first &&
                matrix.matrixVoice[i][1] == second) {
                maxPoint = matrix.matrixPoint[i][2];
                voice = static_cast<Voice>(matrix.matrixVoice[i][2]);

            }
}

Voice ViewOpponentsActions::voiceDefinition(double player) {
    return (player > 0.5) ? DEFECT : COOPERATE;
}

void ViewOpponentsActions::update(Voice playerA, Voice playerB)  {
    sumVote++;
        firstPlayer += voiceToNumTransl(playerA);
        secondPlayer += voiceToNumTransl(playerB);
        decisionMakingStrategy(voiceDefinition(cast_d(firstPlayer/sumVote)),
                               voiceDefinition(cast_d(secondPlayer/sumVote)));

}
