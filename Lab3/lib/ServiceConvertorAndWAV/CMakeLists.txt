add_library(ServiceConvertorAndWAV STATIC ServiceInterfaceConvertorAndWAV.h
                                          ServiceInterfaceConvertorAndWAV.cpp)

target_link_libraries(ServiceConvertorAndWAV PUBLIC WAV
                                                    Convertor
                                                    ParseCommandLine
                                                    ConfigurationFile
                                                    Factory)

target_include_directories(ServiceConvertorAndWAV PUBLIC ${CMAKE_SOURCE_DIR}/WAV
                                                         ${CMAKE_SOURCE_DIR}/Convertor
                                                         ${CMAKE_SOURCE_DIR}/ParseCommandLine
                                                         ${CMAKE_SOURCE_DIR}/ConfigurationFile
                                                         ${CMAKE_SOURCE_DIR}/Factory)

target_link_directories(ServiceConvertorAndWAV PUBLIC ${CMAKE_BINARY_DIR}/WAV
                                                      ${CMAKE_BINARY_DIR}/Convertor
                                                      ${CMAKE_BINARY_DIR}/ParseCommandLine
                                                      ${CMAKE_BINARY_DIR}/ConfigurationFile$
                                                      ${CMAKE_SOURCE_DIR}/Factory)