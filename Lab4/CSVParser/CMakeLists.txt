add_library(CSVParser STATIC include/CSVParser.h
        src/CSVParser.cpp)


target_link_libraries(CSVParser PUBLIC IncludeLibs
                                       LazyIterator)

target_include_directories(CSVParser PUBLIC ${CMAKE_SOURCE_DIR}/IncludeLibs
                                            ${CMAKE_SOURCE_DIR}/LazyIterator)

target_link_directories(CSVParser PUBLIC ${CMAKE_BINARY_DIR}/IncludeLibs
                                         ${CMAKE_BINARY_DIR}/LazyIterator)