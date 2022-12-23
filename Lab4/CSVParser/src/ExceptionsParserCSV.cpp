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
                                       size_t column) : ExceptionsParserCSV(exceptionsDATA,
                                                                            row,
                                                                            column,
                                                                            "Data in file is not correct\n") {}

ExceptionsFilePermission::ExceptionsFilePermission(size_t row,
                                                   size_t column) :ExceptionsParserCSV(exceptionsFile,
                                                                                       row,
                                                                                       column,
                                                                                       "Not correct file\n") {}

ExceptionsReadThread::ExceptionsReadThread(size_t row,
                                           size_t column) : ExceptionsParserCSV(exceptionsFilePermission,
                                                                                row,
                                                                                column,
                                                                                "Data stream was not read => empty\n") {}

int ExceptionsParserCSV::getReturnCode() {
    return returnCode;
}

std::ostream& operator<<(std::ostream& output, const ExceptionsParserCSV& ex) {
    std::cout << ex.what();
    return  output;
}

