cmake_minimum_required(VERSION 3.12)

option(SOME_CHECK "enable some check" OFF)

if (DEFINED ENV{TRAVIS_BUILD_NUMBER})
    project(helloworld VERSION 0.1.$ENV{TRAVIS_BUILD_NUMBER})
else ()
    project(helloworld VERSION 0.1.1)
endif ()

set(CONAN_DISABLE_CHECK_COMPILER ON)

if (${SOME_CHECK})
    message("start some check")
else()
    message("skip some check")
endif ()

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    message("Debug type building")
else ()
    message("Release type building")
endif ()

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

include(${CMAKE_SOURCE_DIR}/cmake/ProjectWarnings.cmake)
add_library(project_warnings INTERFACE)
enable_warnings(project_warnings)

include(CTest)
enable_testing()

include_directories(someLibDir)

add_subdirectory(someLibDir)

add_subdirectory(someExeDir)


add_subdirectory(someTests)

if (NOT WIN32)
    set(CPACK_GENERATOR DEB)
    set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
    set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
    set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
    set(CPACK_PACKAGE_CONTACT examplet@openmedia.co)
    set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS ON)
    include(CPack)
endif()
