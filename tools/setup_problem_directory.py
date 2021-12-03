"""
Set up a skeleton directory for creating a problem solution.

Eventually, this will be language-dependent, but for now it is assumed that all solutions will be written in C++.
"""
import argparse
from pathlib import Path
import sys
import traceback

from jinja2 import Environment, FileSystemLoader, Template


TOOLS_DIR = Path(__file__).resolve().parent
ROOT_DIR = TOOLS_DIR.parent
PROBLEMS_DIR = ROOT_DIR / "problems"
TEMPLATE_DIR = TOOLS_DIR / "templates"

MIN_PROBLEM_NUMBER: int = 1
MAX_PROBLEM_NUMBER: int = 765       # Should probably do this differently so this info doesn't need to be known

PROBLEM_NAME_TEMPLATE: str = "problem-xxx"


def main(args: argparse.Namespace) -> int:
    """
    
    """
    return_code: int = 0
    try:
        problem_number: int = args.problem_number
        problem_name: str = f"problem-{problem_number:03d}"

        problem_dir: Path = PROBLEMS_DIR / problem_name
        problem_dir.mkdir(parents=True, exist_ok=True)

        for template_path in filter(lambda p: p.is_file(), TEMPLATE_DIR.glob("**/*")):
            relative_template_path = template_path.relative_to(TEMPLATE_DIR)
            relative_render_path = Path(
                *(p.replace(PROBLEM_NAME_TEMPLATE, problem_name) for p in relative_template_path.parts)
            )
            render_path = (problem_dir / relative_render_path).with_suffix("")      # Strip the .j2

            if render_path.is_file():
                print(f"Not overwriting existing file {render_path}")
                continue

            # The trim_blocks and lstrip_blocks args remove extraneous whitespace when creating successive lines from a for
            # loop. See https://jinja2docs.readthedocs.io/en/stable/templates.html?highlight=trim_blocks#whitespace-control
            # for details
            template_env = Environment(
                loader=FileSystemLoader(template_path.parent),
                trim_blocks=True,
                lstrip_blocks=True
            )

            template: Template = template_env.get_template(template_path.name)
            rendered_template: str = template.render(problem_name=problem_name)

            print(f"Writing rendered template to {render_path}")
            render_path.parent.mkdir(parents=True, exist_ok=True)
            with render_path.open(mode="w") as render_file:
                render_file.write(rendered_template)
    except Exception:
        print(traceback.format_exc())
        return_code = 1
    return return_code


if __name__ == "__main__":

    PARSER = argparse.ArgumentParser(description="Set up a skeleton directory for creating a problem solution")
    PARSER.add_argument(
        "problem_number",
        type=int,
        choices=range(MIN_PROBLEM_NUMBER, MAX_PROBLEM_NUMBER + 1),
        help="Problem number"
    )
    ARGS: argparse.Namespace = PARSER.parse_args()

    RETURN_CODE: int = main(ARGS)

    sys.exit(RETURN_CODE)