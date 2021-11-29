"""
Scrape the problem statement from https://projecteuler.net and save in a plain text file.
"""
import argparse
from pathlib import Path
import sys
import traceback
from urllib.request import urlopen

from bs4 import BeautifulSoup


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

        problem_dir: Path = PROBLEMS_DIR / f"{problem_number:03d}"
        problem_dir.mkdir(parents=True, exist_ok=True)
        problem_file: Path = problem_dir / f"problem-{problem_number:03d}.txt"

        with problem_file.open("w", encoding="utf-8") as problem_file_object:
            problem_file_object.write(f"Problem {problem_number}\n")
            problem_file_object.write(problem_statement)
    except Exception:
        print(traceback.format_exc())
        return_code = 1
    return return_code


def get_problem_statement(problem_number: int) -> str:
    """
    Scrape the statement for the specified problem from the Project Euler website and return as a string.
    """
    url: str = f"https://projecteuler.net/problem={problem_number}"
    soup = BeautifulSoup(urlopen(url).read(),"lxml")
    return soup.find_all("div", {"class" : "problem_content"})[0].text


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
