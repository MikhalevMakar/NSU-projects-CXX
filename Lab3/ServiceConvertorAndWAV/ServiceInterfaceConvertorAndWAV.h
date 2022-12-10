//
// Created by Макар Михалёв on 30.11.2022.
//

#ifndef LAB3_SERVICEINTERFACECONVERTORANDWAV_H
#define LAB3_SERVICEINTERFACECONVERTORANDWAV_H

#include "../IncludeLibs.h"
#include "WAV.h"
#include "Convertor.h"
#include "ParseCommandLine.h"
#include "ConfigurationFile.h"
#include "Factory.h"

class ServiceInterfaceConvertorAndWAV {
public:
    ServiceInterfaceConvertorAndWAV() = default;

    virtual void firstLaunchConvertorAndWAV(ParseCommandLine* ptrParseCommandLine,
                                            Convertor* ptrConvertor,
                                            std::vector<std::string> vectorInputFile,
                                            ConfigurationFile* ptrConfigurationFile,
                                            WAV* ptrWAV) = 0;

    virtual void linkConvertorAndWAV(ParseCommandLine* ptrParseCommandLine,
                                     Convertor* ptrConvertor,
                                     std::vector<std::string> vectorInputFile,
                                     ConfigurationFile* ptrConfigurationFile,
                                     WAV* ptrWAV) = 0;

    ~ServiceInterfaceConvertorAndWAV() = default;

protected:
    uint16_tArray bufferSample1, bufferSample2;
    int tmpCnt = 0;
    bool firstLaunch = true;
};

#endif