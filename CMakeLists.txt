cmake_minimum_required (VERSION 3.12.0)
project(NIT_TDD)

find_package(GTest REQUIRED)

option(CODE_COVERAGE "Build with code coverage" OFF)
option(CODE_TESTING "Build with GoogleTests" ON)

if(CODE_COVERAGE)
    if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
        message("Building with code coverage")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0 -fprofile-arcs -ftest-coverage")
        set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -lgcov --coverage")
    endif()
endif()

add_subdirectory(src)

if(CODE_TESTING)
    message(STATUS "Defining CODE_TESTING globally")
    add_definitions(-DCODE_TESTING)
    add_subdirectory(test)
endif()
