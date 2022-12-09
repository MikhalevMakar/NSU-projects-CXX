//
// Created by Макар Михалёв on 30.11.2022.
//

#ifndef LAB3_CONVERTOR_H
#define LAB3_CONVERTOR_H

#include "ConfigurationFile.h"
#include "FactoryRegistration.h"
#include "WAV.h"
#include "../IncludeLibs.h"

class Convertor {
public:
    Convertor() = default;
    virtual int getBeginningTime() = 0;
    virtual void changingSamples(uint16_tArray& buffer1,
                                 uint16_tArray& buffer2) = 0;
    virtual int getNumberFile() = 0;
    virtual void readArg(ConfigurationFile* ptrConfigurationFile) = 0;
    virtual int getEndingTime() = 0;
    bool is_number(const std::string& s);
    ~Convertor() = default;
protected:
    int timeFrom, index = 0;
};


#endif //LAB3_CONVERTOR_H
