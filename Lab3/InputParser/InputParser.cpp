//
// Created by Макар Михалёв on 25.11.2022.
#include "InputParser.h"

InputParser::InputParser(int argc, char** argv) {
    po::options_description desc("Generate parameters");
    desc.add_options()
            ("help, h", "All options_description")
            ("configFile, c", po::value<std::string>(&config),  "Show parameter file --configFile=[config.txt] Extension: txt")
            ("output, o", po::value<std::string> (&output), "--output=[output.wav] Extension: wav")
            ("input, i", po::value< std::vector<std::string> >(&input), "--input=inputNumber, when Number = 1, 2, 3... | Extension: wav")
            ;

    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);

    if(vm.count("help")) {
        std::cout << desc;
        throw ("call --help\n");
    }
}