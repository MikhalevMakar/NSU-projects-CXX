//
// Created by Макар Михалёв on 27.11.2022.
//
#include "WAV.h"

void WAV::InverseToBigEndian(unsigned& value) {
    unsigned b0 = (value & 0x000000ff) << 24u;
    unsigned b1 = (value & 0x0000ff00) << 8u;
    unsigned b2 = (value & 0x00ff0000) >> 8u;
    unsigned b3 = (value & 0xff000000) >> 24u;
    value = b0 | b1 | b2 | b3;
}

void WAV::findDataIntoFileWAV(std::fstream* ptrFileWAV) {
    while(findData.size() != 4) {
        ptrFileWAV->read((char*)&readByte, sizeof(readByte));
        if((findData.size() == 0 && readByte ==  'd') ||
           (findData.size() == 1 && readByte ==  'a') ||
           (findData.size() == 2 && readByte ==  't') ||
           (findData.size() == 3 && readByte ==  'a')) {
            findData += readByte;
        } else {
            findData.clear();
        }
    }
}

void WAV::checkChunk(std::fstream* ptrFileWAV) {
    ptrFileWAV->read((char*)&wavHeader, sizeof(wavHeader));

    if(constantParameters.RIFF != wavHeader.chunkID) {
        //throw std::invalid_argument("Wrong four character code file\n");
    }

    std::cout << findData << "\n";
    char d;
    ptrFileWAV->read((char*)&d, sizeof(char));
    std::cout << (int) d << "\n";
    ptrFileWAV->read((char*)&d, sizeof(char));
    std::cout << (int) d << "\n";
    ptrFileWAV->read((char*)&d, sizeof(char));
    std::cout << (int) d << "\n";
}

WAV::WAV(std::string nameInputWAV) {
    pathWAV += "/" + nameInputWAV + ".wav";

    std::fstream* ptrFileWAV = new std::fstream(pathWAV, std::fstream::in | std::fstream::out);
    if (!ptrFileWAV->is_open()) {
        throw std::invalid_argument("ConfigFile is not open\n");
    }

    checkChunk(ptrFileWAV);
}