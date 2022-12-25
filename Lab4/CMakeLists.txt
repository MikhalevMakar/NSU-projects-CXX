cmake_minimum_required(VERSION 3.23)
project(Lab4)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lab4 main.cpp)

add_subdirectory(PrintTuple)
add_subdirectory(IncludeLibs)
add_subdirectory(CSVParser)
add_subdirectory(ParserCommandLine)

target_include_directories(Lab4 PUBLIC PrintTuple
                                       IncludeLibs
                                       CSVParser
                                       ParserCommandLine)


include(FetchContent)

FetchContent_Declare(
        googletest
        # Specify the commit you depend on and update it regularly.
        URL https://github.com/google/googletest/archive/58d77fa8070e8cec2dc1ed015d66b454c8d78850.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

target_link_libraries(Lab4  gtest_main PrintTuple
                                       IncludeLibs
                                       CSVParser
                                       ParserCommandLine)