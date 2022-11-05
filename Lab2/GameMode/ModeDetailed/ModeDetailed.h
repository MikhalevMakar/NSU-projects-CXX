#ifndef PRISON_MODEDETAILED_H
#define PRISON_MODEDETAILED_H

#include "../Mode/Mode.h"
class ModeDetailed : public Mode {
public:
    ModeDetailed(int _countSteps,
                 std::vector<std::string> _strategyName,
                 std::string _configsLine,
                 std::string _matrixLine);
    void gameModeStart() override;
    void printGame() override;
private:
    std::string key;
    std::string ret = "return";
};

#endif