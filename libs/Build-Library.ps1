<#
.Synopsis
   Project Euler library build script.
.DESCRIPTION
   Builds the library.
.EXAMPLE
   .\Build-Library.ps1 <LIBRARY>
.INPUTS
   The name of the library to be built and run.
.OUTPUTS
   Static library files.
.NOTES
   Version 1.0
#>
Param(
    [Parameter(Mandatory=$true)][String]$LIBRARY_NAME
)

[String]$BUILD_DIRECTORY = ".build"
[Int32]$RETURN_CODE = 0

Try {
    If (!(Test-Path "$LIBRARY_NAME")) {
        Write-Error "No library called $LIBRARY_NAME"
        Exit 1
    }
    Set-Location "$LIBRARY_NAME"
    If (!(Test-Path "$BUILD_DIRECTORY")) {
        New-Item -Type directory "$BUILD_DIRECTORY"
    }
    Set-Location "$BUILD_DIRECTORY"
    cmake ..
    cmake --build .
} Catch {
    Write-Error $Error[0]
    $RETURN_CODE = 1
} Finally {
    Set-Location $PSScriptRoot
}

Exit $RETURN_CODE
