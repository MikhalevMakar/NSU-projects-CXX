cmake_minimum_required(VERSION 3.23)
project(Prison)

set(CMAKE_CXX_STANDARD 14)

add_executable(Prison main.cpp Game.h Game.cpp)

add_subdirectory(GameMatrix)
add_subdirectory(InputParser)
add_subdirectory(GameStrategies)
add_subdirectory(GameMode)

target_include_directories(Prison PUBLIC GameMatrix  InputParser GameStrategies GameMode)

target_link_libraries(Prison PUBLIC GameMatrix  InputParser GameStrategies GameMode)