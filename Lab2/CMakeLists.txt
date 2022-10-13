cmake_minimum_required(VERSION 3.23)
project(Lab2)

set(CMAKE_CXX_STANDARD 14)

find_package(Boost 1.78.0 COMPONENTS filesystem program_options)

set(SOURCE_FILES
        EApplication.cpp
        EApplication.h
        main.cpp)


#include_directories(${Boost_INCLUDE_DIRS})
add_executable(Lab2 ${SOURCE_FILES})
target_link_libraries(Lab2 ${Boost_LIBRARIES})