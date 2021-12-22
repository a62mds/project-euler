<#
.Synopsis
   Set up directory for implementing solution to a problem.
.DESCRIPTION
   Use the Python tools in the `tools` directory to scrape the problem statement from the Project Euler website and
   render the implementation file templates.
.EXAMPLE
   .\Start-Problem.ps1 PROBLEM_NUMBER
.INPUTS
   PROBLEM_NUMBER
     Valid Project Euler problem number.
.OUTPUTS
   Solution implementation directory with skeleton files.
.NOTES
   Version 2.0
#>
Param(
    [Parameter(Mandatory=$true)][Int32]$PROBLEM_NUMBER
)

[Int32]$RETURN_CODE = 0

Try {
    Set-Location tools
    pipenv run python get_problem_statement.py $PROBLEM_NUMBER
    If ($LastExitCode -ne 0) {
       Throw "Failed to get problem statement for problem $PROBLEM_NUMBER"
    }
    pipenv run python setup_problem_directory.py $PROBLEM_NUMBER
} Catch {
    Write-Error $Error[0]
    $RETURN_CODE = 1
} Finally {
    Set-Location $PSScriptRoot
}

Exit $RETURN_CODE
