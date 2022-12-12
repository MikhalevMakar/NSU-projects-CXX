cmake_minimum_required(VERSION 3.23)
project(Lab4)

set(CMAKE_CXX_STANDARD 17)

add_executable(Lab4 main.cpp CSVParse/CSVParse.cpp CSVParse/CSVParse.h)
