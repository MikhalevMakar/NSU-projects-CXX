//
// Created by Макар Михалёв on 25.11.2022.
//

#ifndef SOUNDPROCESSOR__INPUTPARSER_H
#define SOUNDPROCESSOR__INPUTPARSER_H

#include <boost/program_options.hpp>
#include <iostream>
#include <string>
#include "map"

namespace po = boost::program_options;

struct InputParser {
    InputParser() = default;
    InputParser(int argc, char** argv);
    std::vector<std::string> input;
    std::string output;
    std::string config;
private:
    po::variables_map vm;
};

#endif //SOUNDPROCESSOR__INPUTPARSER_H
