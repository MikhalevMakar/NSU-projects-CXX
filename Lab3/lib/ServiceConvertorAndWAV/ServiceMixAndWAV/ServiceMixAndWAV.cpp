//
// Created by Макар Михалёв on 06.12.2022.
//

#include "ServiceMixAndWAV.h"

void ServiceMixAndWAV::firstLaunchConvertorAndWAV(ParseCommandLine *ptrParseCommandLine,
                                                  Convertor *ptrConvertor,
                                                  std::vector<std::string> vectorInputFile,
                                                  ConfigurationFile *ptrConfigurationFile,
                                                  WAV *ptrWAV) {
    ptrConvertor->readArg(ptrConfigurationFile);
    tmpCnt = ptrConvertor->getBeginningTime();
    ptrWAV->fileOverWritten(tmpCnt, bufferSample1);
    WAV supportWAV(vectorInputFile[ptrConvertor->getNumberFile()]);
    supportWAV.seekIntroFile(tmpCnt);
    while(ptrWAV->readNewSample(bufferSample1) && supportWAV.readNewSample(bufferSample2)) {
        ptrConvertor->changingSamples(bufferSample1,
                                      bufferSample2);
        ptrWAV->writeSample(bufferSample1);
    }
    ptrWAV->writeLastPart(bufferSample1);
}

void ServiceMixAndWAV::linkConvertorAndWAV(ParseCommandLine* ptrParseCommandLine,
                                           Convertor* ptrConvertor,
                                           std::vector<std::string> vectorInputFile,
                                           ConfigurationFile* ptrConfigurationFile,
                                           WAV* ptrWAV) {
    ptrConvertor->readArg(ptrConfigurationFile);
    tmpCnt = ptrConvertor->getBeginningTime();
    ptrWAV->seekIntroFile(tmpCnt);
    WAV supportWAV(vectorInputFile[ptrConvertor->getNumberFile()]);
    supportWAV.seekIntroFile(tmpCnt);
    while(ptrWAV->readNewSample(bufferSample1) && supportWAV.readNewSample(bufferSample2)) {
        ptrConvertor->changingSamples(bufferSample1,
                                      bufferSample2);
        ptrWAV->imageOverwrite(bufferSample1);
    }
}
