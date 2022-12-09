//
// Created by Макар Михалёв on 27.11.2022.
//

#ifndef LAB3_WAV_H
#define LAB3_WAV_H

#include "../IncludeLibs.h"
#include "ParametersWAVFile.h"

typedef   std::array<uint16_t , ConstantParameters::SampleRate> uint16_tArray;

class WAV {
public:
    WAV() = default;
    WAV(std::string nameInputWAV,
        std::string outputFile);
    WAV(std::string nameInputWAV,
        std::string outputFile,
        int count);
    bool readNewSample(uint16_tArray bufferSample);
    void writeSample(const uint16_tArray bufferSample);
    void writeLastPart(uint16_tArray bufferSample);
    void seekIntroFile();
    void fileOverWritten(int rightTime, uint16_tArray bufferSample);
    int getBufferSampleValue(int index);
    ~WAV();
private:
    void openFile(std::string nameInputWAV, std::string outputFile);
    WAVHeader wavHeader;
    std::string pathWAV = "../FolderWAV/";
    std::string outputPath = "../FolderOutput/";
    std::ifstream istreamFileWAV;
    std::fstream ostreamOutputWAV;
    void InverseToBigEndian(unsigned& value);
    void checkChunkAndWrite();
    void findDataIntoFileAndWriteWAV(std::function<void()> variableFunction);
    char readByte;
    std::string findData;
};

#endif//LAB3_WAV_H
