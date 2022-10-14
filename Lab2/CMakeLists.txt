cmake_minimum_required(VERSION 3.23)
project(Lab2)

set(CMAKE_CXX_STANDARD 14)

find_package(Boost COMPONENTS filesystem program_options)
include_directories(boost_1_78_0/boost)
set(Lab2
        EApplication.cpp
        EApplication.h
        main.cpp)

add_executable(Lab2 EApplication.h EApplication.cpp main.cpp)
target_link_libraries(Lab2 ${Boost_LIBRARIES})