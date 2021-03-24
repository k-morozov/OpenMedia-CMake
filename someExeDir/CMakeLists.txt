cmake_minimum_required(VERSION 3.12)

add_executable(someExe main.cpp)

set_target_properties(someExe PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        )

target_include_directories(someExe
        PRIVATE "${CMAKE_BINARY_DIR}"
        )

target_link_libraries(someExe PUBLIC someLib)