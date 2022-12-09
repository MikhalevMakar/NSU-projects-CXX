//
// Created by Макар Михалёв on 29.11.2022.
//

#include "ConfigurationFile.h"

ConfigurationFile::ConfigurationFile(std::string nameConfigFile) {
    pathFile = "../" + pathFile + "/" + nameConfigFile + ".txt";
    streamFileWAV.open(pathFile);
    if (!streamFileWAV.is_open()) {
        throw std::invalid_argument("Config File is not open\n");
    }
}

ConfigurationFile::ConfigurationFile(const ConfigurationFile& other) {
    nameConvertor = other.getNameConvertor();
    int size = other.getParametersSize();

    for(int i = 0; i < size; ++i) {
        parameters[i] = other.getParameter(i);
    }
}

ConfigurationFile& ConfigurationFile::operator=(const ConfigurationFile& other) {
    nameConvertor = other.getNameConvertor();
    int size = other.getParametersSize();

    for(int i = 0; i < size; ++i) {
        parameters[i] = other.getParameter(i);
    }
}

void ConfigurationFile::skipComment() {
    do {
        streamFileWAV.read((char*)&readByte, sizeof(readByte));
    } while(readByte != '\n');
}

void ConfigurationFile::getNewInputLine() {
    clearParameters();
    streamFileWAV >> readByte;
    if(readByte == '#') skipComment();
    else streamFileWAV.seekg(-1, std::ios::cur);
    streamFileWAV >> nameConvertor;

    std::string currentParameter;
    while(streamFileWAV >> currentParameter) {
        if(currentParameter == "#") {
            streamFileWAV.seekg(-1, std::ios::cur);
            break;
        }
        parameters.push_back(currentParameter);
    }
}

std::string ConfigurationFile::getNameConvertor() {
    return nameConvertor;
}

int ConfigurationFile::getParametersSize() {
    return parameters.size();
}

std::string& ConfigurationFile::getParameter(int index) {
    return parameters[index];
}

void ConfigurationFile::clearParameters() {
    parameters.clear();
    nameConvertor.clear();
}

std::string ConfigurationFile::getNameConvertor() const {
    return nameConvertor;
}

int ConfigurationFile::getParametersSize() const {
    return parameters.size();
}

std::string ConfigurationFile::getParameter(int index) const {
    return parameters[index];
}
