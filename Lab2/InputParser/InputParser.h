// Created by Макар Михалёв on 20.10.2022.
#ifndef LAB2_INPUTPARSER_H
#define LAB2_INPUTPARSER_H

#include <boost/program_options.hpp>
#include <iostream>
#include <string>
#include <vector>

namespace po = boost::program_options;

class InputParser {
public:
    InputParser(int argc, char** argv);

private:
    po::variables_map vm;
    std::vector<std::string> strategyName;
    std::string modeLine;
    int countSteps;
    std::vector<std::string> configsLine;
    std::string matrixLine;
};

#endif //LAB2_INPUTPARSER_H
