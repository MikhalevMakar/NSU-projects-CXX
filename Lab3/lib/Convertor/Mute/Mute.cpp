//
// Created by Макар Михалёв on 02.12.2022.
//

#include "Mute.h"

void Mute::readArg(ConfigurationFile* ptrConfigurationFile) {
    if (ptrConfigurationFile->getParametersSize() != 2) {
        throw std::invalid_argument("incorrect number of arguments in Mute");
    }

    if(!is_number(ptrConfigurationFile->getParameter(index++)) ||
       !is_number(ptrConfigurationFile->getParameter(index--))) {
        throw std::invalid_argument("is not digit numberFile\n");
    }

    timeFrom = static_cast<int>(std::atoi(ptrConfigurationFile->getParameter(index++).c_str()));

    timeEnd = static_cast<int>(std::atoi(ptrConfigurationFile->getParameter(index).c_str()));
}

void Mute::changingSamples(uint16_tArray& buffer1,
                           uint16_tArray& buffer2) {
    buffer1.fill(0);
}

int Mute:: getEndingTime() {
    return timeEnd;
}

int Mute::getBeginningTime() {
    return timeFrom;
}

int Mute::getNumberFile() {
    throw std::invalid_argument("No such option\n");
    return 0;
}