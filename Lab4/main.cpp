#include "include/CSVParser.h"
#include "include/IncludeLibs.h"
#include "include/LazyIterator.h"

int main() {
    std::string path = "../FolderCSV/test.csv";
    std::fstream ptrFile(path);


//    for (std::tuple<int, int>& rs : parser) {
//        std::cout << rs << std::endl;
//    }


//    for(LazyIterator<int, int> it = parser.begin(); it != parser.end(); ++it) {
//
//    }
    CSVParser<int, int> parser(&ptrFile);
      LazyIterator<int, int> it;
      it = parser.begin();

      //if(it != parser.end()) { }
//    LazyIterator<int, int> it1;
//    it1 = parser.begin();

    std::ifstream ptrFFile(path);
    std::tuple  <std::string, int> t;
    ptrFFile >> t;
    std::cout << t;
    ptrFFile >> t;
    std::cout << t;

    return 0;
}

