add_library(CSVParser STATIC include/CSVParser.h
                             include/ExceptionsParserCSV.h
                             src/ExceptionsParserCSV.cpp)

target_include_directories(CSVParser PUBLIC ${CMAKE_SOURCE_DIR}/IncludeLibs
                                            ${CMAKE_SOURCE_DIR}/PrintTuple)

target_link_directories(CSVParser PUBLIC ${CMAKE_BINARY_DIR}/IncludeLibs
                                         ${CMAKE_BINARY_DIR}/PrintTuple)

target_link_libraries(CSVParser   IncludeLibs
                                  PrintTuple)
#include(FetchContent)
#
#FetchContent_Declare(
#        googletest
#        # Specify the commit you depend on and update it regularly.
#        URL https://github.com/google/googletest/archive/58d77fa8070e8cec2dc1ed015d66b454c8d78850.zip
#)
## For Windows: Prevent overriding the parent project's compiler/linker settings
#set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
#
#FetchContent_MakeAvailable(googletest)
#target_link_libraries(CSVParser  gtest_main IncludeLibs
#        PrintTuple)