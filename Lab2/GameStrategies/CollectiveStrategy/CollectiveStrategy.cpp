//
// Created by Макар Михалёв on 04.11.2022.
//

#include "CollectiveStrategy.h"

void CollectiveStrategy::ReadFromFile() {
    c = 'c';
    while(c != '\n' && c != ' ' && !it->second->eof()) {
        it->second->get(c);
        inputLine += c;
    }
    inputLine.erase(inputLine.end()-1);
}

CollectiveStrategy::CollectiveStrategy(std::string configFolder) : GameStrategy("COLLECTIVE_STRATEGY",
                                                                                 configFolder){
      Factory factory = configsFile;
      voice = DEFECT;
      it = mapFile.find(configsFile);
      ReadFromFile();
      GameStrategy* firstStrategy = factory.createStrategy(inputLine);
      inputLine.clear();
      ReadFromFile();
      GameStrategy* secondStrategy = factory.createStrategy(inputLine);
      vectorGameStrategy.push_back(firstStrategy);
      vectorGameStrategy.push_back(secondStrategy);
}

Voice CollectiveStrategy::vote() {
    return voice;
}

void CollectiveStrategy::update(Voice playerA, Voice playerB) {
    if (playerA == playerB) {
        voice =  vectorGameStrategy[0]->vote();
        vectorGameStrategy[0]->update(playerA, playerB);
    } else {
        voice =  vectorGameStrategy[1]->vote();
        vectorGameStrategy[1]->update(playerA, playerB);
    }
}
