cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(problem-003 VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add the executable
set(SOURCES
    problem-003/problem-003.cpp
)
add_executable(test-solution-to-problem-003 ${SOURCES})

# add the libraries
set(LIB_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/")
set(LIBS
    libmath
)
foreach(LIB "${LIBS}")
    set(LIB_PATHS "${LIB_PATHS}" "${LIB_ROOT}/${LIB}/.build/Debug/${LIB}.lib")
endforeach()
target_include_directories(test-solution-to-problem-003 PRIVATE "${LIB_ROOT}")
target_link_libraries(test-solution-to-problem-003 PRIVATE "${LIB_PATHS}")
