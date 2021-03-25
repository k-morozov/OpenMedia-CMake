cmake_minimum_required(VERSION 3.12)

set(APP_TEST someNameForTests)

#set(BUILD_SHARED_LIBS ON)

project(${APP_TEST})

set(CMAKE_CXX_STANDARD 17)

set(SOURCES_APP ${CMAKE_SOURCE_DIR}/someLibDir/someLib.cpp)
set(SOURCES_TESTS main.cpp test.cpp)

add_executable(${APP_TEST}
        ${SOURCES_TESTS}
        ${SOURCES_APP}
)

include_directories(${CONAN_INCLUDE_DIRS_GTEST})

target_link_libraries(${APP_TEST} ${CONAN_LIBS_GTEST})

target_compile_options(${APP_TEST} PRIVATE
        -Wall
        -Wextra
        -Wpedantic
        -Werror
)

add_test(NAME ${APP_TEST} COMMAND $<TARGET_FILE:${APP_TEST}>)
