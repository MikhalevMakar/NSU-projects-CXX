#include "include/CSVParser.h"
#include "include/IncludeLibs.h"
#include "include/ParserCommandLine.h"

int main(int argc, char* argv[]) {
    try {
        ParserCommandLine parserCommandLine(argc, argv);

        std::string path = "../FolderCSV/test1.csv";
        std::ifstream ptrFile(path);
        std::cout << "FirstFIle\n";
        CSVParser<std::string, int> parser(&ptrFile,
                                           parserCommandLine.getCountOffset(),
                                           parserCommandLine.getColumnDelim(),
                                           parserCommandLine.getRowDelim(),
                                           parserCommandLine.getShielding());
        for(auto it = parser.begin(); it != parser.end(); ++it) {
             std::cout << *it;
        }
    } catch (ExceptionsParserCSV& ex) {
        std::cerr << ex;
        return ex.getReturnCode();
    }
    return 0;
}

