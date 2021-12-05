cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(problem-484 VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add the executable
set(SOURCES
    problem-484/Primes.cpp
    problem-484/problem-484.cpp
)
add_executable(test-solution-to-problem-484 ${SOURCES})

# copy the file with prime numbers to the executable directory
add_custom_command(
    TARGET test-solution-to-problem-484
    POST_BUILD
    COMMAND "${CMAKE_COMMAND}" -E copy_if_different "${CMAKE_SOURCE_DIR}/problem-484/primes" "${CMAKE_BINARY_DIR}/$<CONFIG>/"
)
