#!/usr/bin/env python3
"""Build the website version of the course with mdBook.

    python3 tools/build_site.py           build into build/site
    python3 tools/build_site.py --serve   build, then serve it at http://localhost:3000

The pages are the same Markdown files you read on GitHub. This script copies them to
build/site-src, writes the table of contents (SUMMARY.md) from the folder structure, and
runs mdBook. Install mdBook from https://github.com/rust-lang/mdBook/releases
"""
from __future__ import annotations

import re
import shutil
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
STAGE = ROOT / "build" / "site-src"
CHAPTER_RE = re.compile(r"^\d\d-[a-z0-9]+(-[a-z0-9]+)*$")
TOP_PAGES = ["README.md", "GLOSSARY.md", "INSTRUCTORS.md", "CONTRIBUTING.md"]
LINK_RE = re.compile(r"(?<!\!)(\[[^\]\n]*\])\(([^)\s]+)\)")


def repository_url() -> str:
    match = re.search(r'^git-repository-url\s*=\s*"([^"]+)"', (ROOT / "book.toml").read_text(), re.M)
    return match.group(1).rstrip("/") if match else ""


def title_of(page: Path) -> str:
    for line in page.read_text(encoding="utf-8").splitlines():
        if line.startswith("# "):
            return line[2:].strip()
    return page.parent.name


def course_folders() -> list[Path]:
    folders = [p for p in sorted(ROOT.iterdir()) if p.is_dir() and CHAPTER_RE.match(p.name)]
    return folders + [ROOT / name for name in ("appendix", "projects") if (ROOT / name).is_dir()]


def link_order(folder: Path) -> dict[str, int]:
    """The order in which a folder's README links to its sub-folders."""
    page = folder / "README.md"
    if not page.exists():
        return {}
    names = re.findall(r"\]\(([^)/\s#]+)(?:/|\)|#)", page.read_text(encoding="utf-8"))
    return {name: position for position, name in reversed(list(enumerate(names)))}


def pages_in(folder: Path) -> list[Path]:
    """Markdown pages below a folder in reading order: each folder's README first, then its
    sub-folders in the order the README lists them (exercises last), then by name."""
    def rank(parent: Path, name: str):
        if name == "README.md":
            return (0, 0, name)
        if name == "exercises":
            return (2, 0, name)
        return (1, link_order(parent).get(name, 10_000), name)

    def order(page: Path):
        parts = page.relative_to(folder).parts
        return [rank(folder.joinpath(*parts[:i]), part) for i, part in enumerate(parts)]

    pages = [p for p in folder.rglob("*.md") if "target" not in p.parts and "build" not in p.parts]
    return sorted(pages, key=order)


def rewrite_links(text: str, page: Path, repo: str) -> str:
    """Links to source files and folders go to GitHub; links between pages stay local."""
    def replace(match: re.Match) -> str:
        label, target = match.group(1), match.group(2)
        if re.match(r"^[a-z][a-z0-9+.-]*:", target) or target.startswith("#"):
            return match.group(0)
        path_part = target.split("#")[0]
        destination = (page.parent / path_part).resolve()
        if not destination.exists() or destination.suffix == ".md":
            return match.group(0)
        if destination.is_dir() and (destination / "README.md").exists():
            return f"{label}({path_part.rstrip('/')}/README.md)"
        kind = "tree" if destination.is_dir() else "blob"
        try:
            relative = destination.relative_to(ROOT)
        except ValueError:
            return match.group(0)
        return f"{label}({repo}/{kind}/main/{relative.as_posix()})" if repo else match.group(0)

    out, fenced = [], False
    for line in text.split("\n"):
        if line.lstrip().startswith("```"):
            fenced = not fenced
        out.append(line if fenced else LINK_RE.sub(replace, line))
    return "\n".join(out)


def main() -> int:
    repo = repository_url()
    if STAGE.exists():
        shutil.rmtree(STAGE)
    STAGE.mkdir(parents=True)

    staged: list[Path] = []
    for name in TOP_PAGES:
        if (ROOT / name).exists():
            staged.append(ROOT / name)
    for folder in course_folders():
        staged += pages_in(folder)
    for page in staged:
        target = STAGE / page.relative_to(ROOT)
        target.parent.mkdir(parents=True, exist_ok=True)
        target.write_text(rewrite_links(page.read_text(encoding="utf-8"), page, repo), encoding="utf-8")

    summary = ["# Summary", "", "[Start here](README.md)", "", "# The course", ""]
    for folder in course_folders():
        if folder.name == "appendix":
            summary += ["", "# More", ""]
        for page in pages_in(folder):
            relative = page.relative_to(ROOT)
            depth = len(relative.parts) - 2 + (0 if relative.name == "README.md" else 1)
            summary.append(f"{'    ' * depth}- [{title_of(page)}]({relative.as_posix()})")
    if (ROOT / "GLOSSARY.md").exists():
        summary.append("- [Glossary](GLOSSARY.md)")
    teachers = [(name, title) for name, title in (("INSTRUCTORS.md", "Teaching guide"),
                                                   ("CONTRIBUTING.md", "How this course is written"))
                if (ROOT / name).exists()]
    if teachers:
        summary += ["", "# For teachers", ""] + [f"- [{title}]({name})" for name, title in teachers]
    (STAGE / "SUMMARY.md").write_text("\n".join(summary) + "\n", encoding="utf-8")
    print(f"staged {len(staged)} pages in {STAGE.relative_to(ROOT)}")

    mdbook = shutil.which("mdbook")
    if not mdbook:
        print("mdbook is not installed, so the site was not built. See the top of this file.")
        return 1
    command = [mdbook, "serve" if "--serve" in sys.argv else "build", str(ROOT)]
    return subprocess.call(command)


if __name__ == "__main__":
    sys.exit(main())
