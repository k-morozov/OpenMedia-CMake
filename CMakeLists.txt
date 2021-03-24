cmake_minimum_required(VERSION 3.12)

if (DEFINED ENV{TRAVIS_BUILD_NUMBER})
    project(helloworld VERSION 0.8.$ENV{TRAVIS_BUILD_NUMBER})
else ()
    project(helloworld VERSION 0.8.1)
endif ()

set(CONAN_DISABLE_CHECK_COMPILER ON)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

include(CTest)
enable_testing()

include_directories(someLibDir)
include_directories(${CMAKE_SOURCE_DIR})
add_subdirectory(someLibDir)

add_subdirectory(someExeDir)


add_subdirectory(someTests)
