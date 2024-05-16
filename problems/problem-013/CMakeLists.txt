cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(problem-013 VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add the executable
set(SOURCES
    problem-013/problem-013.cpp
)
add_executable(test-solution-to-problem-013 ${SOURCES})

# add the libraries
set(LIB_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/")
target_include_directories(test-solution-to-problem-013 PRIVATE "${LIB_ROOT}")

# copy the problem statement to the test directory
add_custom_command(
    TARGET test-solution-to-problem-013
    POST_BUILD
    COMMAND "${CMAKE_COMMAND}" -E copy_if_different "${CMAKE_SOURCE_DIR}/problem-013.html" "${CMAKE_BINARY_DIR}/$<CONFIG>/"
)
