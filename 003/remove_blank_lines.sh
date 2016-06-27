#!/usr/bin/env bash

##
# one-liner that removes blank lines and lines containing only spaces from a
# file
##

# check that filename was specified
if [ "$#" -ne 1 ]; then
	echo "Please supply a filename"
	exit 2
fi

# check that file exists in directory
if ! [ -f "$1" ]; then
	echo "File $1 not found"
	exit 2
fi

# run sed to remove the blank lines
sed -i '/^ *$/d' "$1"
## M. Sullivan. June, 2016
