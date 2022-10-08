cmake_minimum_required(VERSION 3.23)
project(FirstTestProject)

set(CMAKE_CXX_STANDARD 14)

add_executable(FirstTestProject main.cpp)

add_subdirectory(dirModule1)
add_subdirectory(dirModule2)
add_subdirectory(dirModule3)

target_include_directories(FirstTestProject PRIVATE module1  module2 module3)

target_link_libraries(FirstTestProject PRIVATE dirModule1 dirModule2 dirModule3)
