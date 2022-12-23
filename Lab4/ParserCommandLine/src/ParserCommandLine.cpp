//
// Created by Макар Михалёв on 23.12.2022.
//

#include "../include/ParserCommandLine.h"
ParserCommandLine::ParserCommandLine((int argc, char* argv[]) {
    po::options_description desc("Generate parameters");
    std::string tmp;
    desc.add_options()
            ("help, h", "All options_description")
            ("countOffset, o", po::value<char>(&columnDelim), "--count=countOffset")
            ("row, r", po::value<char>(&columnDelim), "--row=columnDelim")
            ("column, c", po::value<char>(&rowDelim), "--column=rowDelim")
            ("shielding, s", po::value<char>(&shielding), "--shielding=shielding")
            ;
    try {
        po::store(po::parse_command_line(argc, argv, desc), vm);
        po::notify(vm);
        if(vm.count("help")) {
            std::cout << desc;
            throw std::invalid_argument("call --help\n");
        }
    } catch(po::error &e) {
        throw Exceptions(BAD_ARGS, e.what());
    }

    switch(shielding) {
        case '\\n' : shielding = '\n'; break;
    }
//    if (tmp == "\\n")
//        lines_separator = '\n';
//    else
//        std::istringstream(tmp) >> lines_separator;
}