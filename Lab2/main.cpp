#include <iostream>
#include "GameController/Game.h"
int main(int argc, char** argv) {
    try {
        Game game(argc, argv);
    } catch (std::invalid_argument const& ex) {
        std::cout << ex.what() << '\n';
    }
    return 0;
}