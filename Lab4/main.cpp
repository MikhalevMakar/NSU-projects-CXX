#include "include/CSVParser.h"
#include "include/IncludeLibs.h"


int main() {
    std::string path = "../FolderCSV/test.csv";
    std::fstream ptrFile(path);
    CSVParser<char, int> parser(&ptrFile);

    //for (std::tuple<int, int>& rs : parser) {
        //std::cout << rs << std::endl;
    //}
    std::ifstream ptrFFile(path);
    std::tuple  <char, int> t;
    ptrFFile >> t;



    //get<1>(t) = {""};
    //std::cout << t;
    return 0;
}

