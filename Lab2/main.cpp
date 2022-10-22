#include <iostream>
#include "InputParser/InputParser.h"
#include "GameMatrix.h"

int main(int argc, char** argv) {
    try {

        InputParser ip(argc, argv);
        //GameMatrix m("fileMatrix.txt");
    } catch (std::invalid_argument const& ex) {
        std::cout << ex.what() << '\n';
    }


   return 0;
}
