cmake_minimum_required(VERSION 3.23)
project(Lab3)

set(CMAKE_CXX_STANDARD 14)

add_executable(main.cpp IncludeLibs.h
                             Convertor/Mute.h
                             Convertor/Mute.cpp
                             Convertor/Mix.h
                             Convertor/Mix.cpp
                             Convertor/Quick.cpp
                             Convertor/Quick.h
                             ServiceConvertorAndWAV/ServiceMixAndWAV.cpp
                             ServiceConvertorAndWAV/ServiceMixAndWAV.h
                             ServiceConvertorAndWAV/ServiceMuteAndWAV.cpp
                             ServiceConvertorAndWAV/ServiceMuteAndWAV.h
                             ServiceConvertorAndWAV/ServiceQuickAndWAV.cpp
                             ServiceConvertorAndWAV/ServiceQuickAndWAV.h ServiceConvertorAndWAV/ServiceBackgroundAndWAV.cpp ServiceConvertorAndWAV/ServiceBackgroundAndWAV.h Convertor/BackGround.cpp Convertor/BackGround.h)

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