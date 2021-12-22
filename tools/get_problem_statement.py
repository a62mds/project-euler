"""
Scrape the problem statement from https://projecteuler.net and save in a plain text file.

To do:
- Use the projecteuler.net/minimal=<PROBLEM_NUMBER> URL to get the problem statement HTML
- Write problem statement to a markdown file
  - markdownify?
"""
import argparse
from pathlib import Path
import requests
import sys
import traceback


TOOLS_DIR = Path(__file__).parent
ROOT_DIR = TOOLS_DIR.parent
PROBLEMS_DIR = ROOT_DIR / "problems"

MIN_PROBLEM_NUMBER: int = 1
MAX_PROBLEM_NUMBER: int = 765       # Should probably do this differently so this info doesn't need to be known


def main(args: argparse.Namespace) -> int:
    """
    Scrape the problem statement from the Project Euler website, create a new directory for the problem (if one does
    not already exist), and write the problem statement to a text file in the problem directory.
    """
    return_code: int = 0
    try:
        problem_number: int = args.problem_number
        problem_statement: str = get_problem_statement(problem_number)
        problem_name: str = f"problem-{problem_number:03d}"

        problem_dir: Path = PROBLEMS_DIR / problem_name
        problem_dir.mkdir(parents=True, exist_ok=True)
        problem_file: Path = (problem_dir / problem_name).with_suffix(".txt")

        with problem_file.open("w", encoding="utf-8") as problem_file_object:
            problem_file_object.write(f"Problem {problem_number}\n\n")
            problem_file_object.write(f"{problem_statement.rstrip()}\n")
    except Exception:
        print(traceback.format_exc())
        return_code = 1
    return return_code


def get_problem_statement(problem_number: int) -> str:
    """
    Scrape the statement for the specified problem from the Project Euler website and return as a string.
    """
    url: str = f"https://projecteuler.net/minimal={problem_number}"
    response: "requests.models.Response" = requests.get(url)
    return response.text


if __name__=="__main__":

    PARSER = argparse.ArgumentParser(description="Scrape the problem statement from https://projecteuler.net")
    PARSER.add_argument(
        "problem_number",
        type=int,
        choices=range(MIN_PROBLEM_NUMBER, MAX_PROBLEM_NUMBER + 1),
        help="Problem number"
    )
    ARGS: argparse.Namespace = PARSER.parse_args()

    RETURN_CODE: int = main(ARGS)

    sys.exit(RETURN_CODE)
