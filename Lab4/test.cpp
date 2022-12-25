#include <gtest/gtest.h>
#include "include/CSVParser.h"
#include "include/IncludeLibs.h"
#include "include/ExceptionsParserCSV.h"


using TypeCSVParsresIntString = CSVParser<int, std::string>;
using TypeCSVParsresIntStringBoolChar = CSVParser<float, std::string, bool, char>;

TEST(testCSVParser, testOutputTuple) {
    std::string path = "../FolderCSV/test1.csv";
    std::ifstream ptrFile(path);
    std::ostringstream output;
    CSVParser<std::string, int> csvParser(&ptrFile, 3);
    for (auto tuple : csvParser)
        output << tuple << std::endl;

    std::ostringstream print_again;
    for (auto tuple : csvParser)
        print_again << tuple << std::endl;
    EXPECT_EQ(output.str(), print_again.str());
    ptrFile.close();
}


TEST(testCSVParser, testErorrInputDataFile) {
    std::string path = "../FolderCSV/testError.csv";
    std::ifstream ptrFile(path);
    TypeCSVParsresIntString csvParser(&ptrFile, 0);

    EXPECT_THROW({
        for(auto tuple : csvParser)
            std::cout << tuple << std::endl;
        }, ErrorInputFileData);
}

TEST(testCSVParser, testCheckPrintTuple) {
    std::string path = "../FolderCSV/test2.csv";
    std::ifstream ptrFile(path);
    EXPECT_NO_THROW({
        TypeCSVParsresIntString csvParser(&ptrFile, 0);
        for (const auto &tuple: csvParser)
            std::cout << tuple;
    });
    ptrFile.close();
}

TEST(testCSVParser, testBadNameFile) {
    std::string path = "../FolderCSV/testBad.csv";
    std::ifstream ptrFile(path);
    EXPECT_THROW({TypeCSVParsresIntString csvParser(&ptrFile, 0);}, std::fstream::failure);
}

TEST(testCSVParser, TestShielding) {
    std::string path = "../FolderCSV/test3.csv";
    std::ifstream ptrFile(path);
    std::ostringstream output;
    TypeCSVParsresIntStringBoolChar csvParser(&ptrFile, 0, ',', '\n', '"');
    for (const auto &tuple : csvParser)
        std::cout << tuple << std::endl;
    ptrFile.close();
}

int main(int argc, char ** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}