cmake_minimum_required (VERSION 3.12.0)
project(NIT_TDD)

find_package(GTest REQUIRED)

option(CODE_COVERAGE "Build with code coverage" OFF)
option(TESTING "Enable testing mode" OFF)

if(CODE_COVERAGE)
    if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
        message("Building with code coverage")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0 -fprofile-arcs -ftest-coverage")
        set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -lgcov --coverage")
    endif()
endif()


if(TESTING)
    message("Building with enabled testing mode")
    add_definitions(-DTESTING)
endif()

add_subdirectory(src)
add_subdirectory(test)
