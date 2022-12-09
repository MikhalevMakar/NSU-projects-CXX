//
// Created by Макар Михалёв on 09.12.2022.
//

#include "Quick.h"

void Quick::readArg(ConfigurationFile* ptrConfigurationFile) {
    if (ptrConfigurationFile->getParametersSize() != 3) {
        throw std::invalid_argument("incorrect number of arguments in Mute");
    }

    if(!is_number(ptrConfigurationFile->getParameter(index)) ||
       !is_number(ptrConfigurationFile->getParameter(index+1)) ||
       !is_number(ptrConfigurationFile->getParameter(index+2))) {
        throw std::invalid_argument("is not digit numberFile\n");
    }

    timeFrom = static_cast<int>(std::atoi(ptrConfigurationFile->getParameter(index).c_str()));

    timeEnd = static_cast<int>(std::atoi(ptrConfigurationFile->getParameter(index+1).c_str()));

    valueQuick = static_cast<int>(std::atoi(ptrConfigurationFile->getParameter(index+2).c_str()));
}

void Quick::changingSamples(uint16_tArray& buffer1,
                           uint16_tArray& buffer2) {
    length = ConstantParameters::SampleRate / valueQuick;
    for (long i = 0; i < length; ++i)
        buffer1[i] = buffer1[i * 2];
    for (long i = length; i < 2*length; ++i)
        buffer1[i] = buffer2[i * 2];
}

int Quick:: getEndingTime() {
    return timeEnd;
}

int Quick::getBeginningTime() {
    return timeFrom;
}

int Quick::getNumberFile() {
    throw std::invalid_argument("No such option\n");
    return 0;
}