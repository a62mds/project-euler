cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(Math VERSION 1.0)

option(ENABLE_TESTS "Enable tests" OFF)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add the library
set(HEADERS
    NaturalNumbers.h
    Primes.h
)
set(SOURCES
    NaturalNumbers.cpp
    Primes.cpp
)
add_library(libmath "${SOURCES}" "${HEADERS}")

if(${ENABLE_TESTS})
    set(TEST_SOURCES
        Math.test.cpp
        NaturalNumbers.test.cpp
        Primes.test.cpp
    )
    add_executable(test-libmath "${TEST_SOURCES}")
    target_include_directories(test-libmath PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../external/doctest/doctest/")
    target_link_libraries(test-libmath PRIVATE libmath)
endif()
