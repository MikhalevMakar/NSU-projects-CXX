#include "IncludeLibs.h"
#include "SoundProcessor.h"
#include "WAV.h"
int main(int argc, char* argv[]) {
    try {
        SoundProcessor soundProcessor(argc, argv);
    } catch(std::invalid_argument const& ex) {
        std::cout << ex.what() << '\n';
    }
    return 0;
}
