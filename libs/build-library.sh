#!/bin/bash

# Project Euler library build script.

# Define library name
LIBRARY_NAME=$1

# Build directory
BUILD_DIRECTORY=".build"

# Return code
RETURN_CODE=0

# Check if library directory exists
if [ ! -d "$LIBRARY_NAME" ]; then
    echo "No library called $LIBRARY_NAME"
    exit 1
fi

# Change to library directory
cd "$LIBRARY_NAME" || exit

# Create build directory if it doesn't exist
if [ ! -d "$BUILD_DIRECTORY" ]; then
    mkdir "$BUILD_DIRECTORY"
fi

# Change to build directory
cd "$BUILD_DIRECTORY" || exit

# Run CMake to generate build files
cmake ..

# Build library
cmake --build .

# Get return code
RETURN_CODE=$?

# Go back to original directory
cd "$OLDPWD" || exit

exit $RETURN_CODE
