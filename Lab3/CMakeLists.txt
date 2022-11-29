cmake_minimum_required(VERSION 3.23)
project(Lab3)

set(CMAKE_CXX_STANDARD 14)

add_executable(Lab3 main.cpp IncludeLibs.h)

add_subdirectory(InputParser)
add_subdirectory(WAV)

target_include_directories(Lab3 PUBLIC InputParser WAV)

target_link_libraries(Lab3 PUBLIC InputParser WAV)