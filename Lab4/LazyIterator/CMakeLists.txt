add_library(LazyIterator STATIC include/LazyIterator.h
        src/LazyIterator.cpp)

target_link_libraries(LazyIterator PUBLIC IncludeLibs
        CSVParser)

target_include_directories(LazyIterator PUBLIC ${CMAKE_SOURCE_DIR}/IncludeLibs
                                               ${CMAKE_SOURCE_DIR}/CSVParser)

target_link_directories(LazyIterator PUBLIC ${CMAKE_BINARY_DIR}/IncludeLibs
                                            ${CMAKE_SOURCE_DIR}/CSVParser)