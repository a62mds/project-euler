#!/bin/bash

# Project Euler library test runner script.

# Define library name
LIBRARY_NAME=$1

# Test directory
TEST_DIRECTORY=".test"

# Return code
RETURN_CODE=0

# Check if library directory exists
if [ ! -d "$LIBRARY_NAME" ]; then
    echo "No library called $LIBRARY_NAME"
    exit 1
fi

# Change to library directory
cd "$LIBRARY_NAME" || exit

# Create test directory if it doesn't exist
if [ ! -d "$TEST_DIRECTORY" ]; then
    mkdir "$TEST_DIRECTORY"
fi

# Change to test directory
cd "$TEST_DIRECTORY" || exit

# Build tests with CMake
cmake -DENABLE_TESTS=ON ..

# Build tests
cmake --build .

# Run tests executable
./test-"$LIBRARY_NAME"

# Get return code
RETURN_CODE=$?

# Go back to original directory
cd "$OLDPWD" || exit

exit $RETURN_CODE
