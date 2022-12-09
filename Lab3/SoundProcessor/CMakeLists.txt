add_library(SoundProcessor STATIC SoundProcessor.h
                                  SoundProcessor.cpp)

target_link_libraries(SoundProcessor PUBLIC WAV
                                            Convertor
                                            ParseCommandLine
                                            ConfigurationFile
                                            ServiceConvertorAndWAV)

target_include_directories(SoundProcessor PUBLIC ${CMAKE_SOURCE_DIR}/WAV
                                                 ${CMAKE_SOURCE_DIR}/Convertor
                                                 ${CMAKE_SOURCE_DIR}/ParseCommandLine
                                                 ${CMAKE_SOURCE_DIR}/ConfigurationFile
                                                 ${CMAKE_SOURCE_DIR}/ServiceConvertorAndWAV)

target_link_directories(SoundProcessor PUBLIC ${CMAKE_BINARY_DIR}/WAV
                                              ${CMAKE_BINARY_DIR}/Convertor
                                              ${CMAKE_BINARY_DIR}/ParseCommandLine
                                              ${CMAKE_BINARY_DIR}/ConfigurationFile
                                              ${CMAKE_BINARY_DIR}/ServiceConvertorAndWAV)