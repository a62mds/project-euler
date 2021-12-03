cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(problem-001 VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add the executable
set(SOURCES
    problem-001/problem-001.cpp
)
add_executable(test-solution-001 ${SOURCES})
