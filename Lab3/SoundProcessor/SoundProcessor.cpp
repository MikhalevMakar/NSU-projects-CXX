//
// Created by Макар Михалёв on 05.12.2022.
//

#include "SoundProcessor.h"

SoundProcessor::SoundProcessor(int argc, char* argv[]) {
    ParseCommandLine parseCommandLine(argc, argv);
    ptrParseCommandLine = &parseCommandLine;

    ConfigurationFile configurationFile(ptrParseCommandLine->getConfigFile());
    ptrConfigurationFile = &configurationFile;

    createVectorInputFile();
    converterConversions();
}

void SoundProcessor::firstLaunchConverter() {
    ptrConfigurationFile->getNewInputLine();
    ptrService = Factory::get().orderService(ptrConfigurationFile->getNameConvertor());
    ptrConvertor = Factory::get().orderСonvertor(ptrConfigurationFile->getNameConvertor());
    WAV  beginWav(vectorInputFile[0],
                  ptrParseCommandLine->getOutputFile());
    ptrWAV = &beginWav;
    ptrService->linkConvertorAndWAV(ptrParseCommandLine,
                                    ptrConvertor,
                                    vectorInputFile,
                                    ptrConfigurationFile,
                                    ptrWAV);
}
void SoundProcessor::converterConversions() {
    firstLaunchConverter();
    vectorInputFile[0] = ptrParseCommandLine->getOutputFile();
    while(true) {
        ptrConfigurationFile->getNewInputLine();
        std::cout << ptrConfigurationFile->getNameConvertor() << "\n";
        if(ptrConfigurationFile->getNameConvertor().empty()) break;
        ptrService = Factory::get().orderService(ptrConfigurationFile->getNameConvertor());
        ptrConvertor = Factory::get().orderСonvertor(ptrConfigurationFile->getNameConvertor());

        WAV mainWAV(vectorInputFile[0],
                    ptrParseCommandLine->getOutputFile(),
                    0);

        ptrService->linkConvertorAndWAV(ptrParseCommandLine,
                                        ptrConvertor,
                                        vectorInputFile,
                                        ptrConfigurationFile,
                                        &mainWAV);
    }
}

void SoundProcessor::createVectorInputFile() {
    int size = ptrParseCommandLine->getInputFileSize();
    for(int i =0; i < size; ++i) {
        vectorInputFile.push_back(ptrParseCommandLine->getInputFile(i));
    }
}

