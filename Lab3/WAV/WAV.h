//
// Created by Макар Михалёв on 27.11.2022.
//

#ifndef LAB3_WAV_H
#define LAB3_WAV_H

#include "../IncludeLibs.h"

class WAV {
public:
    WAV(std::string nameInputWAV);
    void checkChunk(std::fstream* ptrFileWAV);
private:
    struct WAVHeader {
        unsigned  chunkID;
        unsigned  chunkSize;
        unsigned format;
        unsigned subChunk1Id;
        unsigned  subChunk1Size;
        unsigned short audioFormat; //
        unsigned short numberOfChannels; //
        unsigned sampleRate; //
        unsigned  byteRate;
        unsigned short blockAlign;
        unsigned short bitsPerSample; //
    };

    struct  ConstantParameters {
        unsigned RIFF = 0x52494646;
        unsigned WAVE = 0x57415645;
        unsigned FMT = 0x666d7420;
        unsigned DATA = 0x61746164;
        short PCM = 1;
    };

    WAVHeader wavHeader;

    std::string pathWAV = "FolderWAV";
    ConstantParameters constantParameters;
private:
    void InverseToBigEndian(unsigned& value);
};

#endif//LAB3_WAV_H
//46 46 49 52
//52 49 46 46
//52 49 46 46