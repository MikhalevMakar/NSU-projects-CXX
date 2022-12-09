//
// Created by Макар Михалёв on 06.12.2022.
//

#ifndef LAB3_PARAMETERSWAVFILE_H
#define LAB3_PARAMETERSWAVFILE_H

struct WAVHeader {
    unsigned chunkID;
    unsigned  chunkSize;
    unsigned  format;
    unsigned subChunk1Id;
    unsigned  subChunk1Size;
    unsigned short audioFormat;
    unsigned short numberOfChannels;
    unsigned sampleRate;
    unsigned  byteRate;
    unsigned short blockAlign;
    unsigned short bitsPerSample;
};

enum ConstantParameters {
    RIFF = 0x52494646,
    WAVE = 0x57415645,
    FMT = 0x666d7420,
    DATA = 0x61746164,
    PCM = 1,
    AudioFormat = 1,
    SampleRate = 44100,
    BitsPerSample = 16,
    BlockAlign = BitsPerSample / 8,
    ByteRate = SampleRate*BlockAlign
};
#endif //LAB3_PARAMETERSWAVFILE_H
