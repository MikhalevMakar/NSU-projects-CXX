//
// Created by Макар Михалёв on 03.12.2022.
//

#include "Mix.h"
#include <iomanip>

void Mix::isCorrectArgFile(std::string& inputFileArg1, std::string& inputFileArg2) {
    if(inputFileArg1.size() < 2) {
        throw std::invalid_argument("not enough arguments\n");
    }
    if(inputFileArg1[0] != '$') {
        throw std::invalid_argument("not correct symbol - character expected : $\n");
    }

    inputFileArg1.erase(inputFileArg1.begin());

    if(!is_number(inputFileArg1)) {
        throw std::invalid_argument("is not digit numberFile\n");
    }

    if(!is_number(inputFileArg2)) {
        throw std::invalid_argument("is not digit beginTime\n");
    }
}

void Mix::readArg(ConfigurationFile* ptrConfigurationFile) {
    if (ptrConfigurationFile->getParametersSize() != 2) {
        throw std::invalid_argument("incorrect number of arguments in Mix");
    }

    isCorrectArgFile(ptrConfigurationFile->getParameter(index), ptrConfigurationFile->getParameter(index+1));
    numberFile = static_cast<int>(std::atoi(ptrConfigurationFile->getParameter(index).c_str()));
    timeFrom = static_cast<int>(std::atoi(ptrConfigurationFile->getParameter(index+1).c_str()));
}

void Mix::changingSamples(uint16_tArray& buffer1,
                          uint16_tArray& buffer2) {
    for(int i = 0; i < ConstantParameters::SampleRate; ++i) {
        buffer1[i] = buffer2[i];
    }
}

int Mix:: getEndingTime() {
    throw std::invalid_argument("No such option\n");
    return EXIT_FAILURE;
}

int Mix::getBeginningTime() {
    return timeFrom;
}

int Mix::getNumberFile() {
    return numberFile;
}
