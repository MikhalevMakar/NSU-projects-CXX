#ifndef PRISON_MODEDETAILED_H
#define PRISON_MODEDETAILED_H
#include <vector>
#include <string>

class ModeDetailed {
public:
    ModeDetailed() = default;
    ModeDetailed(std::vector<std::string> strategyName,
                 std::string modeLine,
                 std::vector<std::string> configsLine);
};


#endif
