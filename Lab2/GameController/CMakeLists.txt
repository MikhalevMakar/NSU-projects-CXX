add_library(GameController STATIC GameController.h GameController.cpp)


target_include_directories(GameController PUBLIC ${CMAKE_BINARY_DIR}/GameMatrix
        ${CMAKE_BINARY_DIR}/InputParser
        ${CMAKE_BINARY_DIR}/GameStrategies)

target_link_directories(GameController PUBLIC  ${CMAKE_BINARY_DIR}/InputParser
                                                ${CMAKE_BINARY_DIR}/GameMode)
