//
// Created by Макар Михалёв on 06.12.2022.
//

#include "ServiceMuteAndWAV.h"

void ServiceMuteAndWAV::linkConvertorAndWAV(ParseCommandLine* ptrParseCommandLine,
                                            Convertor* ptrConvertor,
                                            std::vector<std::string> vectorInputFile,
                                            ConfigurationFile* ptrConfigurationFile,
                                            WAV* ptrWAV)  {

    ptrConvertor->readArg(ptrConfigurationFile);
    ptrWAV->fileOverWritten(ptrConvertor->getBeginningTime(), bufferSample1);

    tmpCnt = ptrConvertor->getBeginningTime();

    while(ptrWAV->readNewSample(bufferSample1)) {
        if(++tmpCnt >= ptrConvertor->getEndingTime()) break;
        ptrConvertor->changingSamples(bufferSample1,
                                      bufferSample2);
        ptrWAV->writeSample(bufferSample1);
    }
    ptrWAV->writeLastPart(bufferSample1);
}

