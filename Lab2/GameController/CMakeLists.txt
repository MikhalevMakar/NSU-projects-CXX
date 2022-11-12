add_library(GameController STATIC Game.h Game.cpp)

target_include_directories(GameController PUBLIC ${CMAKE_BINARY_DIR}/GameMatrix
                                                 ${CMAKE_BINARY_DIR}/InputParser
                                                 ${CMAKE_BINARY_DIR}/GameMode)


find_package(Boost COMPONENTS program_options)
set(BOOST_INCLUDE_LIBRARIES program_options)
set(BOOST_ENABLE_CMAKE ON)

target_link_libraries(GameMode PUBLIC GameMatrix
                                      InputParser
                                      GameMode)

target_include_directories(GameController PUBLIC Boost::program_options)

target_link_libraries(GameController PUBLIC Boost::program_options)

target_link_directories(GameController PUBLIC  ${CMAKE_BINARY_DIR}/GameMatrix
                                               ${CMAKE_BINARY_DIR}/InputParser
                                               ${CMAKE_BINARY_DIR}/GameMode)
