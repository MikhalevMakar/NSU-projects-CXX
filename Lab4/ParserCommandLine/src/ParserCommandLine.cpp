//
// Created by Макар Михалёв on 23.12.2022.
//

#include "../include/ParserCommandLine.h"

ParserCommandLine::ParserCommandLine(int argc, char* argv[]) {
    po::options_description desc("Generate parameters");
    std::string lineRowDelim;
    desc.add_options()
            ("help, h", "All options_description")
            ("countOffset, o", po::value<int>(&countOffset), "--count=countOffset")
            ("row, r", po::value<char>(&columnDelim), "--row=columnDelim")
            ("column, c", po::value<std::string>(&lineRowDelim), "--column=rowDelim")
            ("shielding, s", po::value<char>(&shielding), "--shielding=shielding");
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);
    if (vm.count("help")) {
        std::cout << desc;
        throw std::invalid_argument("call --help\n");
    }

    if(lineRowDelim == "\n") rowDelim = '\n';
    else if(lineRowDelim == "\a") rowDelim = '\a';
    else if(lineRowDelim == "\t") rowDelim = '\t';
    else if(lineRowDelim == "\v") rowDelim = '\v';
//    else rowDelim = static_cast<char>(lineRowDelim);
}

char ParserCommandLine::getColumnDelim() {
    return columnDelim;
}

char ParserCommandLine::getRowDelim() {
    return rowDelim;
}

char ParserCommandLine::getShielding() {
    return shielding;
}

int ParserCommandLine::getCountOffset() {
    return countOffset;
}