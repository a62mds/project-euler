cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(Functional VERSION 1.0)

option(ENABLE_TESTS "Enable tests" OFF)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add the header-only library
add_library(libfunctional INTERFACE)

if(${ENABLE_TESTS})
    set(TEST_SOURCES
        Functional.test.cpp
        Filter.test.cpp
        Map.test.cpp
        Reduce.test.cpp
    )
    add_executable(test-libfunctional "${TEST_SOURCES}")
    target_include_directories(test-libfunctional PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../external/doctest/doctest/")
    target_link_libraries(test-libfunctional PRIVATE libfunctional)
endif()
