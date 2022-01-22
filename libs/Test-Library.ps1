<#
.Synopsis
   Project Euler library test runner script.
.DESCRIPTION
   Builds the test project and runs the executable produced.
.EXAMPLE
   .\Test-Library.ps1 <LIBRARY>
.INPUTS
   The name of the library whose tests are to be built and run.
.OUTPUTS
   Results of the test run.
.NOTES
   Version 1.0
#>
Param(
    [Parameter(Mandatory=$true)][String]$LIBRARY_NAME
)

[String]$TEST_DIRECTORY = ".test"
[Int32]$RETURN_CODE = 0

Try {
    If (!(Test-Path "$LIBRARY_NAME")) {
        Write-Error "No library called $LIBRARY_NAME"
        Exit 1
    }
    Set-Location "$LIBRARY_NAME"
    If (!(Test-Path "$TEST_DIRECTORY")) {
        New-Item -Type directory "$TEST_DIRECTORY"
    }
    Set-Location "$TEST_DIRECTORY"
    cmake -DENABLE_TESTS=ON ..
    cmake --build .
    Set-Location Debug
    & ".\test-$LIBRARY_NAME.exe"
} Catch {
    Write-Error $Error[0]
    $RETURN_CODE = 1
} Finally {
    Set-Location $PSScriptRoot
}

Exit $RETURN_CODE
