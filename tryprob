#!/usr/bin/env bash

##
# Script for setting up the basic files needed for solving a problem from 
# http://projecteuler.net.
#
# Creates directory for the solution files and uses a Python script to scrape 
# the problem statement from the website and store it in a text file in the 
# new directory. Also creates a blank main.cpp and Makefile.
##

# check that a problem number has been supplied
if ! [[ "$1" =~ ^[0-9]+$ ]]; then
	echo "Please supply a problem number in the range [1,556]"
	exit 2
fi

# check that problem number supplied is valid
if ! [ "$1" -ge 1 -a "$1" -le 556 ]; then
	echo "Please supply a problem number in the range [1,556]"
	exit 2
fi

# pad problem number with zeros and store in new variable $PROBLEM
printf -v PROBLEM "%03d" $1

# create directory name from variable $PROBLEM
PROBDIR="./$PROBLEM"

if [ -d "$PROBDIR" ]; then
	cd "$PROBDIR"
else
	mkdir "$PROBDIR"
	# run python script to scrape problem statement from project euler website
	pybin/get_problem_statement.py $1
	cd "$PROBDIR"
	touch main.cpp
	touch Makefile
fi

## M. Sullivan. June, 2016
