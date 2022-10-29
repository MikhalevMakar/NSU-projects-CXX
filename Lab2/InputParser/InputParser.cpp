#include "InputParser.h"

InputParser::InputParser(int argc, char** argv) {
    po::options_description desc("Generate parameters");
    desc.add_options()
            ("help, h", "All options_description")
            ("nameStrategy, n", po::value<std::vector<std::string>  >(&strategyName), "Show --strategy={ALWAYS_VOICE_C|ALWAYS_VOICE_D|RANDOM_VOICE|name4|name5|name6|")
            ("mode, m", po::value<std::string>(&modeLine),  "Show --mode=[detailed|fast|tournament]")
            ("steps, s", po::value<int>(&countSteps)->default_value(3), "Show --steps=<n>")
            ("configs, c", po::value<std::vector <std::string> >(&configsLine), "Show --configs=[dirname1|dirname2|dirname3 .txt")
            ("gameMatrix, g", po::value<std::string>(&matrixLine), "Show --matrix[matrix.txt] .txt")
            ;

    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);

    if(vm.count("help")) {
        std::cout << desc;
        throw ("call --help\n");
    }
    else if(countSteps <= 0) {
        throw std::invalid_argument("The game didn't start because the number of steps wasn't allowed\n");
    }
    else if(modeLine != "detailed" && modeLine != "fast" && modeLine != "tournament") {
        throw std::invalid_argument("This strategy isn't present");
    }
}