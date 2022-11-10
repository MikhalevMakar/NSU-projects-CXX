cmake_minimum_required(VERSION 3.23)
project(CreateFabricy)

set(CMAKE_CXX_STANDARD 14)

add_executable(CreateFabricy main.cpp
               StrategyFactoryRegistrations.h
               AlwaysVoiceC.cpp
               AlwaysVoiceC.h
               GameStrategy.h
               GameStrategy.cpp
               StrategyFactory.cpp
               StrategyFactory.h
               Voice.h
               BipolarDisorder.h
               BipolarDisorder.cpp
        )
