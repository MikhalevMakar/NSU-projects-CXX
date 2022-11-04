cmake_minimum_required(VERSION 3.23)
project(CreateFabricy)

set(CMAKE_CXX_STANDARD 14)

add_executable(CreateFabricy main.cpp StrategyObject.h StrategyFactoryRegistrations.h AlwaysVoiceC.cpp AlwaysVoiceC.h StrategyFactory.h StrategyFactory.cpp Voice.h )
