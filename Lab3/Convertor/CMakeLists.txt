add_library(Convertor STATIC  Convertor.h
                              Convertor.cpp)

target_link_libraries(Convertor PUBLIC ConfigurationFile WAV Factory)

target_include_directories(Convertor PUBLIC ${CMAKE_SOURCE_DIR}/ConfigurationFile
                                            ${CMAKE_SOURCE_DIR}/WAV
                                            ${CMAKE_SOURCE_DIR}/Factory)

target_link_directories(Convertor PUBLIC ${CMAKE_BINARY_DIR}/ConfigurationFile
                                         ${CMAKE_BINARY_DIR}/WAV
                                         ${CMAKE_BINARY_DIR}/Factory)