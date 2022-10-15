cmake_minimum_required(VERSION 3.23)
project(Lab2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)

find_package(Boost COMPONENTS program_options)
add_executable(Lab2 main.cpp)

if(NOT Boost_FOUND)
    include(FetchContent)
    FetchContent_Declare(
            Boost
            GIT_REPOSITORY https://github.com/boostorg/boost.git

        )
    FetchContent_MakeAvailable(Boost)
endif()


target_include_directories(Lab2 PUBLIC ${Boost_INCLUDE_DIR})
target_link_libraries(Lab2 PUBLIC ${Boost_LIBRARIES})