//
// Created by Макар Михалёв on 29.11.2022.
//

#ifndef LAB3_CONFIGURATIONFILE_H
#define LAB3_CONFIGURATIONFILE_H

#include "../IncludeLibs.h"

class ConfigurationFile {
public:
    ConfigurationFile() = default;
    ConfigurationFile(std::string nameConfigFile);
    ConfigurationFile(const ConfigurationFile&);

    void getNewInputLine() const;
    std::string getNameConvertor() const;
    int getParametersSize() const;
    std::string getParameter(int index) const;

    void getNewInputLine();
    std::string getNameConvertor();
    int getParametersSize();
    std::string& getParameter(int index);
    ConfigurationFile& operator=(const ConfigurationFile&);
    ~ConfigurationFile() = default;
private:
    void clearParameters();
    void skipComment();
    std::ifstream streamFileWAV;
    std::string nameConvertor;
    std::vector<std::string> parameters;
    std::string pathFile = "ConfigurationFolder";
    std::string folderOutput = "FolderOutput";
    char readByte;
};

#endif //LAB3_CONFIGURATIONFILE_H
