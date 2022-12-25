add_library(PrintTuple STATIC include/PrintTuple.h
        src/LazyIterator.cpp)

target_link_libraries(PrintTuple PUBLIC IncludeLibs
                                        CSVParser)

target_include_directories(PrintTuple PUBLIC ${CMAKE_SOURCE_DIR}/IncludeLibs
                                               ${CMAKE_SOURCE_DIR}/CSVParser)

target_link_directories(PrintTuple PUBLIC ${CMAKE_BINARY_DIR}/IncludeLibs
                                          ${CMAKE_SOURCE_DIR}/CSVParser)