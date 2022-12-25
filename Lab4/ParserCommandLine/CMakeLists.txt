add_library(ParserCommandLine STATIC include/ParserCommandLine.h
                                     src/ParserCommandLine.cpp)

find_package(Boost COMPONENTS program_options)
set(BOOST_INCLUDE_LIBRARIES program_options)
set(BOOST_ENABLE_CMAKE ON)

include_directories(${BOOST_INCLUDE_LIBRARIES})

target_include_directories(ParserCommandLine PUBLIC ${CMAKE_SOURCE_DIR}/IncludeLibs)

target_link_libraries(ParserCommandLine PUBLIC Boost::program_options
                                               ${CMAKE_BINARY_DIR}/IncludeLibs)
