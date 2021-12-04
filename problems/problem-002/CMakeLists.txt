cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(problem-002 VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add the executable
set(SOURCES
    problem-002/problem-002.cpp
)
add_executable(test-solution-to-problem-002 ${SOURCES})
