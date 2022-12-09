//
// Created by Макар Михалёв on 25.11.2022.
//

#ifndef SOUNDPROCESSOR__ParseCommandLine_H
#define SOUNDPROCESSOR__ParseCommandLine_H

#include <boost/program_options.hpp>
#include "../IncludeLibs.h"

namespace po = boost::program_options;

struct ParseCommandLine {
    ParseCommandLine() = default;
    ParseCommandLine(int argc, char* argv[]);
    std::string getOutputFile();
    std::string getConfigFile();
    std::string getInputFile(int index);
    int getInputFileSize();
private:
    std::vector<std::string> input;
    std::string output;
    std::string config;
private:
    po::variables_map vm;
};

#endif //SOUNDPROCESSOR__ParseCommandLine_H
