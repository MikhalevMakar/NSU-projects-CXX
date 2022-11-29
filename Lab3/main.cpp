#include <iostream>
#include "InputParser.h"
#include "IncludeLibs.h"
#include "WAV.h"

int main(int argc, char** argv) {
    try {
        //InputParser inputParser(argc, argv);
        WAV wav("district_four");


    } catch (std::invalid_argument const& ex) {
        std::cout << ex.what() << '\n';
    }

    return 0;
}
