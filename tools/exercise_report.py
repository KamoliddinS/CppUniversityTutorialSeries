#!/usr/bin/env python3
"""Turn the results of `ctest --output-junit` into a short Markdown table.

    python3 tools/exercise_report.py build/results.xml
"""
import sys
import xml.etree.ElementTree as ET


def main() -> int:
    if len(sys.argv) != 2:
        print(__doc__)
        return 2
    try:
        root = ET.parse(sys.argv[1]).getroot()
    except (OSError, ET.ParseError) as problem:
        print(f"No results to show ({problem}).")
        return 0

    tasks: dict[str, list[bool]] = {}
    for case in root.iter("testcase"):
        task = case.get("name", "").split(".")[0]
        passed = case.find("failure") is None and case.find("error") is None and case.get("status") == "run"
        tasks.setdefault(task, []).append(passed)

    done = sum(1 for results in tasks.values() if all(results))
    print("## Exercise results\n")
    print(f"**{done} of {len(tasks)}** exercises pass.\n")
    print("| Exercise | Result |")
    print("|----------|--------|")
    for task in sorted(tasks):
        results = tasks[task]
        if all(results):
            verdict = "passed"
        elif not results[0]:
            verdict = "does not build yet" if len(results) > 1 and not any(results) else "not yet"
        else:
            verdict = f"not yet ({sum(results) - 1} of {len(results) - 1} checks)"
        print(f"| `{task}` | {verdict} |")
    return 0


if __name__ == "__main__":
    sys.exit(main())
