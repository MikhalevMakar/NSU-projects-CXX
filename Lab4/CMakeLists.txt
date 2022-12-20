cmake_minimum_required(VERSION 3.23)
project(Lab4)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lab4 main.cpp)

add_subdirectory(PrintTuple)
add_subdirectory(IncludeLibs)
add_subdirectory(CSVParser)

target_include_directories(Lab4 PUBLIC PrintTuple
                                       IncludeLibs
                                       CSVParser)

target_link_libraries(Lab4 PUBLIC PrintTuple
                                   IncludeLibs
                                   CSVParser)