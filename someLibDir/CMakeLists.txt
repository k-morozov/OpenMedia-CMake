cmake_minimum_required(VERSION 3.12)

add_library(someLib STATIC someLib.cpp)

set_target_properties(someLib PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)

target_include_directories(someLib PUBLIC ${CMAKE_SOURCE_DIR})
