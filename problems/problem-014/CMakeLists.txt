cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(problem-014 VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add the executable
set(SOURCES
    problem-014/problem-014.cpp
)
add_executable(test-solution-to-problem-014 ${SOURCES})

# add the libraries
set(LIB_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/")
set(LIBS
    libmath
)
foreach(LIB "${LIBS}")
    if(WIN32)
        set(LIB_PATHS "${LIB_PATHS}" "${LIB_ROOT}/${LIB}/.build/Debug/${LIB}.lib")
    elseif(UNIX)
        set(LIB_PATHS "${LIB_PATHS}" "${LIB_ROOT}/${LIB}/.build/${LIB}.a")
    endif()
endforeach()
target_include_directories(test-solution-to-problem-014 PRIVATE "${LIB_ROOT}")
target_link_libraries(test-solution-to-problem-014 PRIVATE "${LIB_PATHS}")
