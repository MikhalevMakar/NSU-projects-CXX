cmake_minimum_required(VERSION 3.23)
project(Lab2)

set(CMAKE_CXX_STANDARD 14)

find_package(Boost COMPONENTS filesystem program_options)

message("Boost not found")
message("Installing Boost")
include(FetchContent)
FetchContent_Declare(
        Boost
        GIT_REPOSITORY https://github.com/boostorg/boost.git
        GIT_TAG boost-1.74.0
)

FetchContent_MakeAvailable(Boost)

add_executable(Lab2 EApplication.h EApplication.cpp main.cpp)
target_link_libraries(Lab2 PUBLIC ${Boost_LIBRARIES})



