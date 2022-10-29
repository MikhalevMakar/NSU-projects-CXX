add_library(GameMode STATIC Mode.h
                            Mode.cpp
                            ModeFast.h
                            ModeFast.cpp
                            ModeDetailed.h
                            ModeDetailed.cpp
                            ModeTournament.h
                            ModeTournament.cpp)

target_include_directories(GameMode PUBLIC ${CMAKE_BINARY_DIR}/GameMatrix
                                           ${CMAKE_BINARY_DIR}/InputParser
                                           ${CMAKE_BINARY_DIR}/GameStrategies)

target_link_directories(GameMode PUBLIC ${CMAKE_BINARY_DIR}/GameMatrix
                                        ${CMAKE_BINARY_DIR}/InputParser
                                        ${CMAKE_BINARY_DIR}/GameStrategies)
