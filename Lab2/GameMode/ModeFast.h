//
// Created by Макар Михалёв on 29.10.2022.
//

#ifndef LAB2_MODEFAST_H
#define LAB2_MODEFAST_H

#include "Mode.h"

class ModeFast : public Mode {
public:

    ModeFast(int _countSteps,
             std::vector<std::string> _strategyName,
             std::vector<std::string> _configsLine);
    void gameModeStart() override;
    void printGame() override;
private:

};

#endif