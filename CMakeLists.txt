cmake_minimum_required(VERSION 3.12)

if (DEFINED ENV{TRAVIS_BUILD_NUMBER})
    project(helloworld VERSION 0.1.$ENV{TRAVIS_BUILD_NUMBER})
else ()
    project(helloworld VERSION 0.1.1)
endif ()

set(CONAN_DISABLE_CHECK_COMPILER ON)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

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
