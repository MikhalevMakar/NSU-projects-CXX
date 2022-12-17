#include "include/CSVParser.h"
#include "include/IncludeLibs.h"


int main() {
    std::string path = "../FolderCSV/test.csv";
    std::fstream ptrFile(path);
    CSVParser<int> parser(&ptrFile);

    //for (std::tuple<int, int>& rs : parser) {
        //std::cout << rs << std::endl;
    //}
    std::ifstream ptrFFile(path);
    std::tuple  <int> t;
    ptrFFile >> t;
//    ptrFFile >> t;
//    ptrFFile >> t;
    std::string a = "Makar";
    get<0>(t) = {1};
    get<1>(t) = {""};
    std::cout << t;
    return 0;
}

