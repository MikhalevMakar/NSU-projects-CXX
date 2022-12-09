cmake_minimum_required(VERSION 3.23)
project(Lab3)

set(CMAKE_CXX_STANDARD 14)

add_executable(Lab3 main.cpp IncludeLibs.h
                             Convertor/Mute.h
                             Convertor/Mute.cpp
                             Convertor/Mix.h
                             Convertor/Mix.cpp
                             ServiceConvertorAndWAV/ServiceMixAndWAV.cpp
                             ServiceConvertorAndWAV/ServiceMixAndWAV.h
                             ServiceConvertorAndWAV/ServiceMuteAndWAV.cpp
                             ServiceConvertorAndWAV/ServiceMuteAndWAV.h)

add_subdirectory(WAV)
add_subdirectory(ParseCommandLine)
add_subdirectory(ConfigurationFile)
add_subdirectory(ServiceConvertorAndWAV)
add_subdirectory(Convertor)
add_subdirectory(SoundProcessor)
add_subdirectory(Factory)

target_include_directories(Lab3 PUBLIC ParseCommandLine
                                       ConfigurationFile
                                       ServiceConvertorAndWAV
                                       Convertor
                                       WAV
                                       SoundProcessor
                                       Factory)

target_link_libraries(Lab3 PUBLIC ParseCommandLine
                                  ConfigurationFile
                                  ServiceConvertorAndWAV
                                  Convertor
                                  WAV
                                  SoundProcessor
                                  Factory)