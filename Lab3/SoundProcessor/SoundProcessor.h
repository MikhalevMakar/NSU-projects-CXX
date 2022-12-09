//
// Created by Макар Михалёв on 05.12.2022.
//

#ifndef LAB3_SOUNDPROCESSOR_H
#define LAB3_SOUNDPROCESSOR_H

#include "Convertor.h"
#include "ParseCommandLine.h"
#include "ConfigurationFile.h"
#include "ServiceInterfaceConvertorAndWAV.h"
#include "../IncludeLibs.h"

class SoundProcessor {
public:
    SoundProcessor() = default;
    SoundProcessor(int argc, char* argv[]);
    void converterConversions();
    void createVectorInputFile();
    ~SoundProcessor() = default;
private:
    void firstLaunchConverter();
    bool firstLaunch = true;
    int count;
    ParseCommandLine* ptrParseCommandLine;
    ConfigurationFile* ptrConfigurationFile;
    ServiceInterfaceConvertorAndWAV* ptrService;
    Convertor* ptrConvertor;
    WAV* ptrWAV;
    int index = 0;
    std::vector<std::string> vectorInputFile;
};


#endif //LAB3_SOUNDPROCESSOR_H
