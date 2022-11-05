add_library(GameMode STATIC Mode/Mode.h
        Mode/Mode.cpp
        ModeFast/ModeFast.h
        ModeFast/ModeFast.cpp
        ModeDetailed/ModeDetailed.h
        ModeDetailed/ModeDetailed.cpp
        ModeTournament/ModeTournament.h
        ModeTournament/ModeTournament.cpp)

target_include_directories(GameMode PUBLIC ${CMAKE_BINARY_DIR}/GameMatrix
                                           ${CMAKE_BINARY_DIR}/InputParser
                                           ${CMAKE_BINARY_DIR}/GameStrategies)

target_link_directories(GameMode PUBLIC ${CMAKE_BINARY_DIR}/GameMatrix
                                        ${CMAKE_BINARY_DIR}/InputParser
                                        ${CMAKE_BINARY_DIR}/GameStrategies)
