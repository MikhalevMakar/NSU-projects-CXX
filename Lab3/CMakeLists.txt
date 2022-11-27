cmake_minimum_required(VERSION 3.23)
project(Lab3)

set(CMAKE_CXX_STANDARD 14)

add_executable(Lab3 main.cpp WAV/WAV.cpp WAV/WAV.h)

add_subdirectory(InputParser)
target_include_directories(Lab3 PUBLIC InputParser)

target_link_libraries(Lab3 PUBLIC InputParser)