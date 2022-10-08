cmake_minimum_required(VERSION 3.23)
project(Bigint_GTest)

set(CMAKE_CXX_STANDARD 14)

add_executable(Bigint_GTest BigInt.cpp BigInt.h test.cpp)
include(FetchContent)

FetchContent_Declare(
        googletest
        # Specify the commit you depend on and update it regularly.
        URL https://github.com/google/googletest/archive/58d77fa8070e8cec2dc1ed015d66b454c8d78850.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)
target_link_libraries(Bigint_GTest  gtest_main)