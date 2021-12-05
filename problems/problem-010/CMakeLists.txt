cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(problem-010 VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add the executable
set(SOURCES
    problem-010/Primes.cpp
    problem-010/problem-010.cpp
)
add_executable(test-solution-to-problem-010 ${SOURCES})

# copy the file with prime numbers to the executable directory
add_custom_command(
    TARGET test-solution-to-problem-010
    POST_BUILD
    COMMAND "${CMAKE_COMMAND}" -E copy_if_different "${CMAKE_SOURCE_DIR}/problem-010/primes" "${CMAKE_BINARY_DIR}/$<CONFIG>/"
)
