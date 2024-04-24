# Project Euler Solutions

## Overview

Solutions to [Project Euler](https://projecteuler.net/) problems along with some convenience scripts to automate setting up the prerequisites for implementing the solutions using C++.

## Prerequisites

- PowerShell or bash
- Python 3.9+
- Pipenv
- CMake 3.10+

## Usage

To start working on a problem, run the following:

- PowerShell:

```powershell
.\Start-Problem.ps1 PROBLEM_NUMBER
```

- bash:

```shell
./start-problem.sh PROBLEM_NUMBER
```

where `PROBLEM_NUMBER` is a valid problem number (1, 2, ..., 765 as of 2021-12-02). This will create a new directory
in the `problems` directory complete with:

- A text file containing the problem statement;
- A placeholder `.cpp` file in which the solution will be implemented;
- A `CMakeLists.txt` file for building an executable from the `.cpp` file.
