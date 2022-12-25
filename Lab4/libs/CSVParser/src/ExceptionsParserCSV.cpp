#include "include/ExceptionsParserCSV.h"

ExceptionsParserCSV::ExceptionsParserCSV(int returnCode_,
                                         size_t row,
                                         size_t column,
                                         const std::string messageError) : std::runtime_error
                                         (messageError + "ROW: " + std::to_string(row) + "\tCOLUMN: " +
                                          std::to_string(column) ) {
    returnCode = returnCode_;
}

ErrorInputFileData::ErrorInputFileData(size_t row,
                                       size_t column) : ExceptionsParserCSV(EXCEPTIONS_DATA,
                                                                            row,
                                                                            column,
                                                                            "Data in file is not correct\n") {}

ExceptionsFilePermission::ExceptionsFilePermission(size_t row,
                                                   size_t column) :ExceptionsParserCSV(EXCEPTIONS_FILE,
                                                                                       row,
                                                                                       column,
                                                                                       "Not correct file\n") {}

ExceptionsReadThread::ExceptionsReadThread(size_t row,
                                           size_t column) : ExceptionsParserCSV(EXCEPTIONS_COMMAND_LINE,
                                                                                row,
                                                                                column,
                                                                                "Data stream was not read => empty\n") {}


ExceptionsCommandLine::ExceptionsCommandLine(size_t row,
                                             size_t column): ExceptionsParserCSV(EXCEPTIONS_FILE_PERMISSION,
                                                                                 row,
                                                                                 column,
                                                                                 "Bad input in command line\n") {}

int ExceptionsParserCSV::getReturnCode() {
    return returnCode;
}

std::ostream& operator<<(std::ostream& output, const ExceptionsParserCSV& ex) {
    std::cout << ex.what();
    return  output;
}

