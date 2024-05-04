cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(Math VERSION 1.1)
set(CMAKE_STATIC_LIBRARY_PREFIX "")

option(ENABLE_TESTS "Enable tests" OFF)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add the library
set(HEADERS
    Matrix.h
    NaturalNumbers.h
    PrimeNumbers.h
)
set(SOURCES
    NaturalNumbers.cpp
    PrimeNumbers.cpp
)
add_library(libmath "${SOURCES}" "${HEADERS}")

if(${ENABLE_TESTS})
    set(TEST_SOURCES
        Math.test.cpp
        Matrix.test.cpp
        NaturalNumbers.test.cpp
        PrimeNumbers.test.cpp
    )
    add_executable(test-libmath "${TEST_SOURCES}")
    target_include_directories(test-libmath PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../external/doctest/doctest/")
    target_link_libraries(test-libmath PRIVATE libmath)
endif()
