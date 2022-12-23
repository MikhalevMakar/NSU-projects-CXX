#include "include/CSVParser.h"
#include "include/IncludeLibs.h"

int main(int argc, char* argv[]) {
    try {
        std::string path = "../FolderCSV/test1.csv";
        std::ifstream ptrFile(path);
        CSVParser<std::string, int> parser(&ptrFile, 0);

        for(auto it = parser.begin(); it != parser.end(); ++it) {
             std::cout << *it;
       }

        std::string path2 = "../FolderCSV/test2.csv";
        std::ifstream ptrFile2(path2);
        CSVParser<int, bool> parser2(&ptrFile2, 0);
        for(auto it2 = parser2.begin(); it2 != parser2.end(); ++it2) {
            std::cout << *it2;
        }
    } catch (ExceptionsParserCSV& ex) {
        std::cerr << ex;
        return ex.getReturnCode();
    }


    return 0;
}

