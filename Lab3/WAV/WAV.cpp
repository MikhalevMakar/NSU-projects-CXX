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

void WAV::findDataIntoFileAndWriteWAV(std::function<void()> variableFunction) {
    while(findData.size() != 4) {
        istreamFileWAV.read((char*)&readByte, sizeof(readByte));
        variableFunction();
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

void WAV::checkChunkAndWrite() {
    istreamFileWAV.read((char*)&wavHeader, sizeof(wavHeader));
    ostreamOutputWAV.write((char *) &wavHeader, sizeof(wavHeader));
    InverseToBigEndian(wavHeader.chunkID);
    InverseToBigEndian(wavHeader.format);
    InverseToBigEndian(wavHeader.subChunk1Id);

    if(ConstantParameters::RIFF != wavHeader.chunkID ||
       ConstantParameters::WAVE != wavHeader.format ||
       ConstantParameters::FMT != wavHeader.subChunk1Id) {
        throw std::invalid_argument("Wrong four character code file\n");
    }

    //if(wavHeader.audioFormat != ConstantParameters::AudioFormat) throw std::invalid_argument("Wrong AudioFormat\n"); //to do
    //if(wavHeader.numberOfChannels != ConstantParameters::PCM) throw std::invalid_argument("Wrong PCM\n");
    //if(wavHeader.sampleRate != ConstantParameters::SampleRate) throw std::invalid_argument("Wrong SampleRate\n");
    //if(wavHeader.bitsPerSample != ConstantParameters::BitsPerSample) throw std::invalid_argument("Wrong BitsPerSample\n");
    //if(wavHeader.blockAlign != ConstantParameters::BlockAlign) throw std::invalid_argument("Wrong BlockAlign\n");
    //if(wavHeader.byteRate != ConstantParameters::ByteRate) throw std::invalid_argument("Wrong ByteRate\n");
}

void WAV::openFile(std::string nameInputWAV, std::string outputFile) {
    pathWAV = pathWAV + nameInputWAV + ".wav";
    istreamFileWAV.open(pathWAV);

    outputPath = outputPath + outputFile + ".wav";
    ostreamOutputWAV.open(outputPath);

    if (!istreamFileWAV.is_open() || !ostreamOutputWAV.is_open()) {
        throw std::invalid_argument("WAV File is not open\n");
    }
}

WAV::WAV(std::string nameInputWAV, std::string outputFile) {
    openFile(nameInputWAV, outputFile);
    checkChunkAndWrite();

    auto writeToFile = [=](){
        ostreamOutputWAV.write((char*)&(readByte), sizeof(readByte));
    };
    findDataIntoFileAndWriteWAV(writeToFile);
}

WAV::WAV(std::string nameInputWAV) {
    outputPath = outputPath + nameInputWAV + ".wav";
    istreamFileWAV.open(outputPath);
    if (!istreamFileWAV.is_open()) {
        throw std::invalid_argument("WAV File is not open\n");
    }

    istreamFileWAV.seekg(sizeof(WAVHeader), std::ios::cur);

    std::function<void()> sizeSkipInformation;
    sizeSkipInformation = []() {};
    findDataIntoFileAndWriteWAV(sizeSkipInformation); //to do
}


bool WAV::readNewSample(uint16_tArray& bufferSample) {
    istreamFileWAV.read((char*)&bufferSample, sizeof(bufferSample));
    return istreamFileWAV.gcount();
}

void WAV::seekIntroFile(int countSeek) {
    istreamFileWAV.seekg(ConstantParameters::SampleRate*countSeek*sizeof(uint16_t), std::ios::cur);
}

void WAV::imageOverwrite(uint16_tArray bufferSample) {
    istreamFileWAV.seekg(istreamFileWAV.gcount()*(-1), std::ios::cur);
    istreamFileWAV.write((char*)&bufferSample, sizeof(bufferSample));
}

void WAV::fileOverWritten(int rightTime, uint16_tArray bufferSample) {
    for(int i = 0; i < rightTime; ++i) {
        if(istreamFileWAV.eof()) throw std::invalid_argument("Not correct file\n");
        istreamFileWAV.read((char*)&bufferSample, sizeof(bufferSample));
        ostreamOutputWAV.write((char*)&bufferSample, sizeof(bufferSample));
    }
}

void WAV::writeSample(uint16_tArray bufferSample) {
    ostreamOutputWAV.write((char*)&bufferSample, sizeof(bufferSample)); //to do
}

void WAV::writeLastPart(uint16_tArray bufferSample) {
    while(!istreamFileWAV.eof()) {
        istreamFileWAV.read((char*)&bufferSample, sizeof(bufferSample));
        ostreamOutputWAV.write((char*)&bufferSample, sizeof(bufferSample));
    }
}

WAV::~WAV() {
    istreamFileWAV.close();
    ostreamOutputWAV.close();
}
