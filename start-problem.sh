#!/bin/bash

# Set up directory for implementing solution to a problem.
#
# Usage: ./start-problem.sh PROBLEM_NUMBER
#
# Arguments:
#   PROBLEM_NUMBER: Valid Project Euler problem number.
#
# Outputs:
#   Solution implementation directory with skeleton files.

# Exit on any error
set -e

PROBLEM_NUMBER=$1
RETURN_CODE=0

pushd tools > /dev/null 2>&1

if [ ! -f "Pipfile.lock" ]; then pipenv install; fi

# Run Python scripts
pipenv run python get_problem_statement.py $PROBLEM_NUMBER || { echo "Failed to get problem statement for problem $PROBLEM_NUMBER"; exit 1; }
pipenv run python setup_problem_directory.py $PROBLEM_NUMBER || { echo "Failed to set up problem directory for problem $PROBLEM_NUMBER"; exit 1; }

popd > /dev/null 2>&1

exit $RETURN_CODE
