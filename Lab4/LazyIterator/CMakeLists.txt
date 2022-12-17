add_library(LazyIterator STATIC include/LazyIterator.h
        src/LazyIterator.cpp)

target_link_libraries(LazyIterator PUBLIC IncludeLibs)

target_include_directories(LazyIterator PUBLIC ${CMAKE_SOURCE_DIR}/IncludeLibs)

target_link_directories(LazyIterator PUBLIC ${CMAKE_BINARY_DIR}/IncludeLibs)