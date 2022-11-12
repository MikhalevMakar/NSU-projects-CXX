add_library(GameMode STATIC Mode/Mode.h
                            Mode/Mode.cpp
                            ModeFast/ModeFast.h
                            ModeFast/ModeFast.cpp
                            ModeDetailed/ModeDetailed.h
                            ModeDetailed/ModeDetailed.cpp
                            ModeTournament/ModeTournament.h
                            ModeTournament/ModeTournament.cpp)

target_link_libraries(GameMode PUBLIC GameMatrix
                                      InputParser
                                      GameStrategies
                                      StrategyFactory)

target_include_directories(GameMode PUBLIC ${CMAKE_BINARY_DIR}/GameMatrix
                                           ${CMAKE_BINARY_DIR}/GameStrategies
                                           ${CMAKE_BINARY_DIR}/StrategyFactory)

target_link_directories(GameMode PUBLIC ${CMAKE_BINARY_DIR}/GameMatrix
                                        ${CMAKE_BINARY_DIR}/GameStrategies
                                        ${CMAKE_BINARY_DIR}/StrategyFactory)
