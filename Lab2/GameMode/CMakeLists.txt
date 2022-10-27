add_library(GameMode STATIC GameMode.h
                            ModeDetailed.h
                            ModeDetailed.cpp)

target_include_directories(GameMode PUBLIC ${CMAKE_BINARY_DIR}/GameMatrix
                                           ${CMAKE_BINARY_DIR}/InputParser)

target_link_directories(GameMode PUBLIC ${CMAKE_BINARY_DIR}/GameMatrix
                                        ${CMAKE_BINARY_DIR}/InputParser)
