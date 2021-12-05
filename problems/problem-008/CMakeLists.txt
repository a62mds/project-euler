cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(problem-008 VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add the executable
set(SOURCES
    problem-008/problem-008.cpp
)
add_executable(test-solution-to-problem-008 ${SOURCES})

# copy the file containing the 1000 digit number to the executable directory
add_custom_command(
    TARGET test-solution-to-problem-008
    POST_BUILD
    COMMAND "${CMAKE_COMMAND}" -E copy_if_different "${CMAKE_SOURCE_DIR}/problem-008.txt" "${CMAKE_BINARY_DIR}/$<CONFIG>/"
)
