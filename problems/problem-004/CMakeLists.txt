cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(problem-004 VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add the executable
set(SOURCES
    problem-004/problem-004.cpp
)
add_executable(test-solution-to-problem-004 ${SOURCES})
