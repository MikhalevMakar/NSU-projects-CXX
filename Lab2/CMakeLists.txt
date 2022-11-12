cmake_minimum_required(VERSION 3.23)
project(Lab2)

set(CMAKE_CXX_STANDARD 14)

add_executable(Lab2  main.cpp
                     GameStrategies/AlwaysVoiceC/AlwaysVoiceC.h
                     GameStrategies/AlwaysVoiceC/AlwaysVoiceC.cpp
                     GameStrategies/AlwaysVoiceD/AlwaysVoiceD.h
                     GameStrategies/AlwaysVoiceD/AlwaysVoiceD.cpp
                     GameStrategies/RandomVoice/RandomVoice.h
        	     GameStrategies/RandomVoice/RandomVoice.cpp
        	     GameStrategies/PercentageChoice/PercentageChoice.h
        	     GameStrategies/PercentageChoice/PercentageChoice.cpp
        	     GameStrategies/GameStrategy/GameStrategy.h
                     GameStrategies/GameStrategy/GameStrategy.cpp
        	     GameStrategies/ViewOpponentsActions/ViewOpponentsActions.cpp
        	     GameStrategies/ViewOpponentsActions/ViewOpponentsActions.h
        	     GameStrategies/BipolarDisorder/BipolarDisorder.h
        	     GameStrategies/BipolarDisorder/BipolarDisorder.cpp)

add_subdirectory(GameMatrix)
add_subdirectory(InputParser)
add_subdirectory(GameMode)
add_subdirectory(GameController)
#add_subdirectory(GameStrategies)
add_subdirectory(StrategyFactory)

include(FetchContent)
FetchContent_Declare(
        googletest
        # Specify the commit you depend on and update it regularly.
        URL https://github.com/google/googletest/archive/58d77fa8070e8cec2dc1ed015d66b454c8d78850.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)
#InputParser
target_include_directories(Lab2 PUBLIC  GameController GameMatrix InputParser  StrategyFactory GameMode)

target_link_libraries(Lab2 PUBLIC gtest_main)

target_link_libraries(Lab2 PUBLIC  GameController GameMatrix InputParser  StrategyFactory GameMode)