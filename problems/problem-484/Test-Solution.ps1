<#
.Synopsis
   Test the implementation of the solution.
.DESCRIPTION
   Use CMake to create build files and build executable of the solution implementation, then run the executable.
.EXAMPLE
   .\Test-Solution.ps1
.INPUTS
   N/A
.OUTPUTS
   Solution written to console.
.NOTES
   Generated from template version 1.0
#>

[String]$BUILD_DIRECTORY = ".build"
[Int32]$RETURN_CODE = 0

Try {
    If (!(Test-Path .build)) {
        New-Item -Type Directory "$BUILD_DIRECTORY"
    }
    Set-Location "$BUILD_DIRECTORY"
    cmake ..
    cmake --build .

    Set-Location Debug
    .\test-solution-to-problem-484.exe
} Catch {
    Write-Error $Error[0]
    $RETURN_CODE = 1
} Finally {
    Set-Location $PSScriptRoot
}

Exit $RETURN_CODE
