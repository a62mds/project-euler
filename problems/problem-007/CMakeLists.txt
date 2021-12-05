cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(problem-007 VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add the executable
set(SOURCES
    problem-007/Primes.cpp
    problem-007/problem-007.cpp
)
add_executable(test-solution-to-problem-007 ${SOURCES})

# copy the file with prime numbers to the executable directory
add_custom_command(
    TARGET test-solution-to-problem-007
    POST_BUILD
    COMMAND "${CMAKE_COMMAND}" -E copy_if_different "${CMAKE_SOURCE_DIR}/problem-007/primes" "${CMAKE_BINARY_DIR}/$<CONFIG>/"
)
