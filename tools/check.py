#!/usr/bin/env python3
"""Check the course, or fix what can be fixed automatically.

    python3 tools/check.py                    check everything
    python3 tools/check.py 03-control-flow    check one chapter (any folder works)
    python3 tools/check.py --fix [folder]     refresh the code and output blocks in lesson pages

The rules it enforces are written down in CONTRIBUTING.md.
Needs Python 3.9+, g++ (or $CXX), and rustc for the Rust chapter. Linux or macOS.
"""
from __future__ import annotations

import argparse
import atexit
import concurrent.futures as futures
import glob
import hashlib
import os
import re
import shutil
import signal
import subprocess
import sys
import time
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
BUILD = ROOT / "build" / "check" / str(os.getpid())      # one scratch folder per run, removed at exit
SOLUTIONS = ROOT / "solutions"

CXX = os.environ.get("CXX", "g++")
CXX_BASE = ["-std=c++20", "-Wall", "-Wextra", "-Wpedantic", "-fdiagnostics-color=never"]
CXX_SANITIZE = ["-g", "-fsanitize=address,undefined", "-fno-sanitize-recover=undefined",
                "-fno-omit-frame-pointer", "-D_GLIBCXX_ASSERTIONS"]
RUN_ENV = {"ASAN_OPTIONS": "detect_leaks=1", "UBSAN_OPTIONS": "print_stacktrace=0"}

CHAPTER_RE = re.compile(r"^\d\d-[a-z0-9]+(-[a-z0-9]+)*$")
DIR_RE = re.compile(r"^[a-z0-9]+([-_][a-z0-9]+)*$")
FILE_RE = re.compile(r"^[a-z0-9]+([-_.][a-z0-9]+)*$")
FILE_EXCEPTIONS = {"README.md", "Cargo.toml", "Cargo.lock", "CMakeLists.txt", "Makefile"}
WINDOWS_RESERVED = {"con", "prn", "aux", "nul"} | {f"com{i}" for i in range(1, 10)} | {f"lpt{i}" for i in range(1, 10)}
SOURCE_EXT = {".cpp", ".rs"}
DATA_EXT = {".txt", ".csv", ".dat"}

MAX_LESSON_WORDS = 400
MAX_SKETCH_LINES = 8
BANNED_PHRASES = [
    "delve", "embark", "journey", "realm", "tapestry", "happy coding", "in conclusion",
    "welcome to", "comprehensive guide", "dive into", "deep dive", "master the art",
    "intricacies", "important to note", "unleash", "seamless", "game-changer", "leverage",
    "utilize", "in today's", "ever-evolving", "cutting-edge",
]
EMOJI_RE = re.compile("[\U0001F000-\U0001FAFF☀-➿️‍]")
MARKER_RE = re.compile(r"^\s*<!--\s*(file|snippet|output|session|errors|no-output)\s*:\s*(.+?)\s*-->\s*$")
FENCE_RE = re.compile(r"^(\s*)(`{3,}|~{3,})(.*)$")
LINK_RE = re.compile(r"(?<!\!)\[[^\]\n]*\]\(([^)\s]+)(?:\s+\"[^\"]*\")?\)")
ADDRESS_RE = re.compile(r"0x[0-9a-fA-F]{4,}")
CAPTION_RE = re.compile(r"^\s*\*\*`([^`]+)`\*\*\s*$")       # **`hello.cpp`** above a file block

errors: list[str] = []
warnings: list[str] = []
args: argparse.Namespace


def rel(path: Path) -> str:
    try:
        return str(Path(path).resolve().relative_to(ROOT))
    except ValueError:
        return str(path)


def error(path, message: str) -> None:
    errors.append(f"{rel(path)}: {message}")


def warn(path, message: str) -> None:
    warnings.append(f"{rel(path)}: {message}")


def find_tool(name: str) -> str | None:
    found = shutil.which(name)
    if found:
        return found
    candidates = sorted(glob.glob(str(Path.home() / ".rustup" / "toolchains" / "*" / "bin" / name)))
    return candidates[-1] if candidates else None


RUSTC = find_tool("rustc")
CARGO = find_tool("cargo")


def run(cmd, cwd=None, stdin_path: Path | None = None, timeout: float = 120.0, env=None):
    """Run a command. Returns (exit code or None on timeout, stdout, stderr)."""
    full_env = dict(os.environ)
    full_env.update(env or {})
    stdin = open(stdin_path, "rb") if stdin_path else subprocess.DEVNULL
    try:
        done = subprocess.run(cmd, cwd=cwd, stdin=stdin, capture_output=True, timeout=timeout, env=full_env)
        return done.returncode, done.stdout.decode(errors="replace"), done.stderr.decode(errors="replace")
    except subprocess.TimeoutExpired as exc:
        out = (exc.stdout or b"").decode(errors="replace")
        return None, out, "timed out"
    finally:
        if stdin_path:
            stdin.close()


def run_session(cmd, lines, cwd, env=None, timeout: float = 20.0, quiet: float = 0.4):
    """Run a program on a pseudo-terminal, typing `lines` whenever it waits for input.

    Returns (exit code or None, transcript, unused input lines).
    """
    import pty
    import select

    full_env = dict(os.environ)
    full_env.update(env or {})
    full_env["TERM"] = "dumb"
    pid, fd = pty.fork()
    if pid == 0:
        try:
            os.chdir(cwd)
            os.execvpe(cmd[0], cmd, full_env)
        finally:
            os._exit(127)
    out = bytearray()
    pending = list(lines)
    sent_eof = False
    status = None
    start = time.time()
    while True:
        if time.time() - start > timeout:
            os.kill(pid, signal.SIGKILL)
            os.waitpid(pid, 0)
            os.close(fd)
            return None, out.decode(errors="replace").replace("\r\n", "\n"), pending
        ready, _, _ = select.select([fd], [], [], quiet)
        if ready:
            try:
                data = os.read(fd, 65536)
            except OSError:
                data = b""
            if not data:
                break
            out += data
            continue
        done_pid, done_status = os.waitpid(pid, os.WNOHANG)
        if done_pid:
            status = done_status
            break
        if not out and time.time() - start < 3.0:
            continue                                   # give the program time to print its first prompt
        if pending:
            os.write(fd, (pending.pop(0) + "\n").encode())
        elif not sent_eof:
            os.write(fd, b"\x04")
            sent_eof = True
    if status is None:
        _, status = os.waitpid(pid, 0)
    os.close(fd)
    text = out.decode(errors="replace").replace("\r\n", "\n")
    return os.waitstatus_to_exitcode(status), text, pending


def normalize(text: str) -> str:
    """Make two outputs comparable: ignore trailing spaces, trailing blank lines and memory addresses."""
    lines = [ADDRESS_RE.sub("0xADDR", line.rstrip()) for line in text.replace("\r\n", "\n").split("\n")]
    while lines and not lines[-1]:
        lines.pop()
    return "\n".join(lines)


# --------------------------------------------------------------------------- programs

class Program:
    """One runnable example: a single source file, or a folder of sources built together."""

    def __init__(self, folder: Path, name: str, sources: list[Path], lang: str):
        self.folder = folder
        self.name = name
        self.sources = sources
        self.lang = lang                      # cpp | rs | cargo
        stem = name
        self.kind = "nocompile" if stem.endswith("_nocompile") else "bug" if stem.endswith("_bug") else "normal"
        digest = hashlib.sha1(f"{rel(folder)}/{name}".encode()).hexdigest()[:12]
        self.out_dir = BUILD / "bin" / digest
        self.exe = self.out_dir / "program"
        self.built: bool | None = None
        self.diagnostics = ""

    def sidecar(self, ext: str) -> Path | None:
        path = self.folder / f"{self.name}{ext}"
        return path if path.exists() else None

    def compile_command(self, strict: bool, sanitize: bool) -> tuple[list[str], Path]:
        """Returns (command, working directory)."""
        if self.lang == "cpp":
            cmd = [CXX, *CXX_BASE]
            if strict:
                cmd.append("-Werror")
            if sanitize:
                cmd += CXX_SANITIZE
            base = self.folder if len(self.sources) == 1 else self.sources[0].parent.parent
            cmd += [str(s.relative_to(base)) for s in self.sources] + ["-o", str(self.exe)]
            return cmd, base
        if self.lang == "rs":
            cmd = [RUSTC or "rustc", "--edition", "2024", "--color", "never"]
            if strict:
                cmd += ["-D", "warnings"]
            cmd += [self.sources[0].name, "-o", str(self.exe)]
            return cmd, self.folder
        manifest = self.sources[0]
        cmd = [CARGO or "cargo", "build", "--quiet", "--offline", "--color", "never",
               "--manifest-path", str(manifest), "--target-dir", str(self.out_dir / "target")]
        return cmd, self.folder

    def build(self) -> bool:
        if self.built is not None:
            return self.built
        if self.lang in ("rs", "cargo") and not (RUSTC and CARGO):
            self.built = False
            self.diagnostics = "Rust toolchain not found"
            return False
        self.out_dir.mkdir(parents=True, exist_ok=True)
        strict = self.kind == "normal"
        sanitize = self.kind == "normal" and self.lang == "cpp" and not args.no_sanitize
        cmd, cwd = self.compile_command(strict, sanitize)
        env = None
        if self.lang == "cargo":                           # cargo looks for rustc on PATH
            env = {"PATH": str(Path(CARGO).parent) + os.pathsep + os.environ.get("PATH", "")}
        code, _, stderr = run(cmd, cwd=cwd, timeout=300, env=env)
        self.diagnostics = tidy_diagnostics(stderr)
        self.built = code == 0
        if self.built and self.lang == "cargo":
            match = re.search(r'^name\s*=\s*"([^"]+)"', self.sources[0].read_text(), re.M)
            binary = self.out_dir / "target" / "debug" / (match.group(1) if match else self.name)
            if binary.exists():
                shutil.copy2(binary, self.exe)
            else:
                self.built = False
                self.diagnostics = f"cargo did not produce {binary.name}"
        return self.built

    def run_dir(self) -> Path:
        """A scratch folder holding copies of the lesson's data files, so runs never write into the repo."""
        digest = hashlib.sha1(rel(self.folder).encode()).hexdigest()[:12]
        target = BUILD / "run" / digest
        target.mkdir(parents=True, exist_ok=True)
        for item in self.folder.iterdir():
            if item.is_file() and item.suffix in DATA_EXT:
                shutil.copy2(item, target / item.name)
        return target

    def arguments(self) -> list[str]:
        side = self.sidecar(".args")
        return side.read_text().split() if side else []

    def expected_exit(self) -> int:
        side = self.sidecar(".exitcode")
        return int(side.read_text().strip()) if side else 0

    def execute(self):
        """Run with the sidecar input (not echoed). Returns (exit code, stdout, stderr)."""
        return run([str(self.exe), *self.arguments()], cwd=self.run_dir(), stdin_path=self.sidecar(".in"),
                   timeout=20, env=RUN_ENV)

    def session(self):
        """Run like a person at a terminal would. Returns (exit code, transcript, unused lines)."""
        side = self.sidecar(".in")
        lines = side.read_text().splitlines() if side else []
        return run_session([str(self.exe), *self.arguments()], lines, self.run_dir(), env=RUN_ENV)


def tidy_diagnostics(text: str) -> str:
    """Compiler messages without machine-specific noise."""
    text = re.sub(r"/tmp/cc\w+\.o", "program.o", text)
    text = re.sub(r"/usr/bin/ld: ", "ld: ", text)
    text = text.replace(str(ROOT) + "/", "")
    return text.strip("\n")


_programs: dict[Path, dict[str, Program]] = {}


def discover_programs(folder: Path) -> dict[str, Program]:
    folder = folder.resolve()
    if folder in _programs:
        return _programs[folder]
    programs: dict[str, Program] = {}
    _programs[folder] = programs
    for item in sorted(folder.iterdir()):
        if item.name.startswith("."):
            continue
        if item.is_file() and item.suffix in SOURCE_EXT:
            programs[item.stem] = Program(folder, item.stem, [item], item.suffix[1:])
        elif item.is_dir() and item.name not in ("tests", "starter", "exercises") and not is_exercise(item):
            if (item / "Cargo.toml").exists():
                programs[item.name] = Program(folder, item.name, [item / "Cargo.toml"], "cargo")
            else:
                sources = sorted(item.glob("*.cpp"))
                if sources and not (item / "README.md").exists():
                    programs[item.name] = Program(folder, item.name, sources, "cpp")
    return programs


# --------------------------------------------------------------------------- course layout

def chapter_dirs() -> list[Path]:
    found = [p for p in sorted(ROOT.iterdir()) if p.is_dir() and CHAPTER_RE.match(p.name)]
    for extra in ("appendix", "projects"):
        if (ROOT / extra).is_dir():
            found.append(ROOT / extra)
    return found


def is_exercise(folder: Path) -> bool:
    return any((folder / name).exists() for name in ("exercise.cpp", "exercise.rs", "prediction.txt", "starter"))


def in_scope(path: Path) -> bool:
    path = path.resolve()
    return any(path == scope or scope in path.parents or path in scope.parents for scope in args.scope)


def markdown_files() -> list[Path]:
    """Every tracked-looking Markdown file in the course (build output and solutions excluded)."""
    result = []
    for path in sorted(ROOT.rglob("*.md")):
        parts = path.relative_to(ROOT).parts
        if parts[0] in ("solutions", ".git", "node_modules") or "target" in parts or "build" in parts:
            continue
        if any(part.startswith(".") and part != ".github" for part in parts):
            continue
        result.append(path)
    return result


# --------------------------------------------------------------------------- lesson pages

def split_blocks(lines: list[str]):
    """Yield (start, end, info) for each fenced block; `start` and `end` are the fence line indexes."""
    index = 0
    while index < len(lines):
        match = FENCE_RE.match(lines[index])
        if match:
            fence = match.group(2)
            closing = re.compile(r"^\s*" + re.escape(fence[0]) + "{" + str(len(fence)) + r",}\s*$")
            end = index + 1
            while end < len(lines) and not closing.match(lines[end]):
                end += 1
            yield index, min(end, len(lines) - 1), match.group(3).strip()
            index = end + 1
        else:
            index += 1


def prose_of(lines: list[str]) -> str:
    """The text a student actually reads: no code blocks, no HTML comments, no link targets."""
    keep = [True] * len(lines)
    for start, end, _ in split_blocks(lines):
        for i in range(start, end + 1):
            keep[i] = False
    text = "\n".join(line for line, k in zip(lines, keep) if k and not CAPTION_RE.match(line))
    text = re.sub(r"<!--.*?-->", " ", text, flags=re.S)
    text = re.sub(r"\]\([^)]*\)", "]", text)
    return text


def check_page(page: Path, fix: bool) -> None:
    folder = page.parent
    original = page.read_text(encoding="utf-8")
    lines = original.split("\n")
    programs = discover_programs(folder) if not is_exercise(folder) else {}
    blocks = list(split_blocks(lines))
    block_at = {start: (start, end, info) for start, end, info in blocks}
    shown: set[str] = set()
    with_output: set[str] = set()
    marked_blocks: set[int] = set()
    replacements: list[tuple[int, int, list[str]]] = []

    def block_after(line_index: int):
        nxt = line_index + 1
        while nxt < len(lines) and not lines[nxt].strip():
            nxt += 1
        return block_at.get(nxt)

    def program_for(name: str) -> Program | None:
        stem = name[:-4] if name.endswith(".cpp") else name[:-3] if name.endswith(".rs") else name
        program = programs.get(stem)
        if program is None:
            error(page, f"line {i + 1}: no program '{name}' in this folder")
        return program

    for i, line in enumerate(lines):
        match = MARKER_RE.match(line)
        if not match:
            continue
        kind, target = match.group(1), match.group(2)
        words = target.split()
        name, flags = words[0], words[1:]
        if kind == "no-output":
            with_output.add(Path(name).stem)
            continue
        block = block_after(i)
        if block is None:
            error(page, f"line {i + 1}: '{kind}: {target}' must be followed by a fenced block")
            continue
        start, end, _ = block
        marked_blocks.add(start)
        indent = FENCE_RE.match(lines[start]).group(1)
        current = [l[len(indent):] if l.startswith(indent) else l for l in lines[start + 1:end]]
        wanted: list[str] | None = None

        if kind in ("file", "snippet"):
            source = folder / name
            if not source.is_file():
                error(page, f"line {i + 1}: file '{name}' does not exist")
                continue
            shown.add(Path(name).parts[0] if len(Path(name).parts) > 1 else Path(name).stem)
            content = source.read_text(encoding="utf-8").rstrip("\n").split("\n")
            if kind == "file":
                wanted = content
            else:
                have = {" ".join(l.split()) for l in content}
                missing = [l for l in current if l.strip() and " ".join(l.split()) not in have]
                if missing:
                    error(page, f"line {i + 1}: snippet line not found in {name}: {missing[0].strip()!r}")
        elif kind in ("output", "session"):
            program = program_for(name)
            if program is None:
                continue
            with_output.add(program.name)
            if program.kind != "normal":
                error(page, f"line {i + 1}: '{kind}' needs a program that runs correctly; {name} is a {program.kind} demo")
                continue
            if not program.build():
                continue                                   # reported by check_programs
            if kind == "output":
                code, out, _ = program.execute()
                unused: list[str] = []
            else:
                code, out, unused = program.session()
            if code != program.expected_exit():
                continue                                   # reported by check_programs
            if unused:
                error(page, f"line {i + 1}: {program.name}.in has {len(unused)} line(s) the program never reads")
            fresh = normalize_display(out)
            if "unchecked" in flags and any(l.strip() for l in current):
                wanted = None
            elif normalize("\n".join(current)) != normalize("\n".join(fresh)):
                wanted = fresh
        elif kind == "errors":
            program = program_for(name)
            if program is None:
                continue
            with_output.add(program.name)
            if program.kind == "normal":
                error(page, f"line {i + 1}: 'errors' is for *_nocompile and *_bug programs")
                continue
            program.build()
            fresh = program.diagnostics.split("\n") if program.diagnostics else []
            shown_lines = [l for l in current if l.strip()]
            if not shown_lines:
                wanted = fresh or None
                if wanted is None:
                    error(page, f"line {i + 1}: {name} produced no compiler messages")
            elif fresh and " ".join(shown_lines[0].split()) != " ".join(next(l for l in fresh if l.strip()).split()):
                warn(page, f"line {start + 1}: the compiler's message for {name} has changed since this block "
                           f"was filled. Empty the block and run --fix to refresh it")

        if wanted is not None and wanted != current:
            if fix:
                replacements.append((start, end, [indent + l if l else l for l in wanted]))
            else:
                what = "differs from the file" if kind == "file" else "is out of date"
                error(page, f"line {start + 1}: block for '{kind}: {target}' {what} (run: python3 tools/check.py --fix {rel(folder)})")

    # A reader cannot see the markers, so every whole-file block gets a visible caption.
    captions: list[tuple[int, str]] = []
    for i, line in enumerate(lines):
        match = MARKER_RE.match(line)
        if not match or match.group(1) != "file":
            continue
        name = match.group(2).split()[0]
        above = i - 1
        while above >= 0 and not lines[above].strip():
            above -= 1
        caption = CAPTION_RE.match(lines[above]) if above >= 0 else None
        if caption and caption.group(1) == name:
            continue
        if fix:
            captions.append((i, name))
        else:
            error(page, f"line {i + 1}: put the caption **`{name}`** on the line above the marker "
                        f"(run: python3 tools/check.py --fix {rel(folder)})")

    if replacements or captions:
        for start, end, new in sorted(replacements, reverse=True):
            lines[start + 1:end] = new
        for i, name in sorted(captions, reverse=True):
            indent = re.match(r"^(\s*)", lines[i]).group(1)
            insert = [indent + f"**`{name}`**"]
            if i > 0 and lines[i - 1].strip():
                insert = [""] + insert
            lines[i:i] = insert
        page.write_text("\n".join(lines), encoding="utf-8")
        print(f"fixed  {rel(page)}")
        lines = page.read_text(encoding="utf-8").split("\n")
        blocks = list(split_blocks(lines))
        marked_blocks = set()
        for i, line in enumerate(lines):
            if MARKER_RE.match(line) and MARKER_RE.match(line).group(1) != "no-output":
                nxt = i + 1
                while nxt < len(lines) and not lines[nxt].strip():
                    nxt += 1
                marked_blocks.add(nxt)

    # Code that is not taken from a file must be a short sketch, never a whole program.
    for start, end, info in blocks:
        if start in marked_blocks or info.split(" ")[0] not in ("cpp", "c++", "rust", "rs"):
            continue
        body = lines[start + 1:end]
        if len(body) > MAX_SKETCH_LINES:
            error(page, f"line {start + 1}: code block of {len(body)} lines is not taken from a file "
                        f"(put it in a file and use <!-- file: ... -->, or keep sketches to {MAX_SKETCH_LINES} lines)")
        if any(re.search(r"\b(int|fn)\s+main\s*\(", l) for l in body):
            error(page, f"line {start + 1}: a complete program must come from a file (<!-- file: ... -->)")

    for start, end, info in blocks:
        if info.split(" ")[0] in ("sh", "bash", "zsh", "shell", "console"):
            for offset, command in enumerate(lines[start + 1:end]):
                if re.search(r"\S\s+#\s", command):
                    error(page, f"line {start + 2 + offset}: no comment after a command: the default shell on "
                                f"macOS does not ignore it when the line is pasted. Explain in the text instead")

    text = "\n".join(lines)
    if programs:
        for name, program in programs.items():
            mentioned = name in shown or re.search(r"\b" + re.escape(name) + r"\b", text)
            if not mentioned:
                error(page, f"{name} is in this folder but the page never shows or mentions it")
            if program.kind == "normal" and name not in with_output:
                error(page, f"{name} runs, but the page does not show its output "
                            f"(add <!-- output: {name} --> or <!-- session: {name} -->)")
    lint_page(page, lines)


def normalize_display(out: str) -> list[str]:
    lines = [l.rstrip() for l in out.replace("\r\n", "\n").split("\n")]
    while lines and not lines[-1]:
        lines.pop()
    return lines


def page_role(page: Path) -> str:
    parts = page.relative_to(ROOT).parts
    if len(parts) == 3 and CHAPTER_RE.match(parts[0]) and parts[1] != "exercises" and parts[2] == "README.md":
        return "lesson"
    if len(parts) == 2 and CHAPTER_RE.match(parts[0]) and parts[1] == "README.md":
        return "chapter"
    return "other"


def lint_page(page: Path, lines: list[str]) -> None:
    prose = prose_of(lines)
    lower = prose.lower()
    for phrase in BANNED_PHRASES:
        if re.search(r"\b" + re.escape(phrase), lower):
            error(page, f"filler phrase '{phrase}': say it plainly")
    if EMOJI_RE.search("\n".join(lines)):
        error(page, "no emoji or decorative symbols: use words")
    if re.search(r"^#+\s*(conclusion|introduction|overview)\s*$", prose, re.I | re.M):
        error(page, "no 'Conclusion', 'Introduction' or 'Overview' headings: start with the point, end when done")
    if not lines or not lines[0].startswith("# "):
        error(page, "the first line must be the title: '# Title'")
    role = page_role(page)
    if role == "lesson":
        words = len(re.findall(r"[A-Za-z0-9][A-Za-z0-9'’+#:_.-]*", prose))
        if words > MAX_LESSON_WORDS:
            error(page, f"{words} words of text; the limit for a lesson is {MAX_LESSON_WORDS}. Cut, or split the lesson")
        if "**Goal:**" not in prose:
            error(page, "missing the '> **Goal:** ...' line under the title")
        chapter = page.relative_to(ROOT).parts[0]
        if not chapter.startswith("00-") and not re.search(r"^## Try it", prose, re.M):
            error(page, "missing a '## Try it' section")
        if not re.search(r"^\*\*Next:\*\*", prose, re.M):
            error(page, "missing the '**Next:** [..](..)' line at the end")


# --------------------------------------------------------------------------- programs in lessons

def check_programs(folder: Path) -> None:
    programs = discover_programs(folder)
    if not programs:
        return
    with futures.ThreadPoolExecutor(max_workers=args.jobs) as pool:
        list(pool.map(lambda p: p.build(), programs.values()))
    for program in programs.values():
        where = folder / program.name
        if program.lang in ("rs", "cargo") and not (RUSTC and CARGO):
            warn(where, "skipped: Rust toolchain not found")
            continue
        if program.kind == "nocompile":
            if program.built:
                error(where, "is named *_nocompile but compiles without errors")
            continue
        if not program.built:
            first = program.diagnostics.split("\n")
            error(where, "does not compile cleanly (warnings count as errors):\n    " + "\n    ".join(first[:12]))
            continue
        if program.kind == "bug":
            continue
        code, out, err = program.execute()
        want = program.expected_exit()
        if code is None:
            error(where, "did not finish within 20 s (does it wait for input that is not in the .in file?)")
        elif code != want:
            tail = "\n    ".join((err or out).strip().split("\n")[-12:])
            error(where, f"exited with code {code}, expected {want}:\n    {tail}")


# --------------------------------------------------------------------------- exercises

def build_sources(sources: list[Path], exe: Path, strict: bool) -> tuple[bool, str]:
    exe.parent.mkdir(parents=True, exist_ok=True)
    if sources[0].suffix == ".rs":
        if not RUSTC:
            return False, "Rust toolchain not found"
        cmd = [RUSTC, "--edition", "2024", "--color", "never", "--test", sources[0].name, "-o", str(exe)]
        if strict:
            cmd[5:5] = ["-D", "warnings"]
        code, _, stderr = run(cmd, cwd=sources[0].parent, timeout=300)
        return code == 0, tidy_diagnostics(stderr)
    cmd = [CXX, *CXX_BASE]
    if strict:
        cmd.append("-Werror")
        if not args.no_sanitize:
            cmd += CXX_SANITIZE
    cmd += [s.name for s in sources] + ["-o", str(exe)]
    code, _, stderr = run(cmd, cwd=sources[0].parent, timeout=300)
    return code == 0, tidy_diagnostics(stderr)


def build_program_file(source: Path, exe: Path) -> tuple[bool, str]:
    """Build one ordinary program (not a test binary), warnings as errors."""
    if source.suffix != ".rs":
        return build_sources([source], exe, strict=True)
    if not RUSTC:
        return False, "Rust toolchain not found"
    exe.parent.mkdir(parents=True, exist_ok=True)
    code, _, stderr = run([RUSTC, "--edition", "2024", "--color", "never", "-D", "warnings",
                           source.name, "-o", str(exe)], cwd=source.parent, timeout=300)
    return code == 0, tidy_diagnostics(stderr)


def run_tests(exe: Path, tests: Path, data_from: Path) -> list[str]:
    """Run an exercise program against its tests. Returns one message per failed case.

    A test case is tests/NAME.out (the expected output) with an optional tests/NAME.in (what is typed).
    Without a tests folder the program checks itself: it must exit with code 0.
    """
    failures = []
    for item in data_from.iterdir():
        if item.is_file() and item.suffix in DATA_EXT and item.name != "prediction.txt":
            shutil.copy2(item, exe.parent / item.name)
    cases = sorted(tests.glob("*.out")) if tests.is_dir() else []
    if not cases:
        code, out, err = run([str(exe)], cwd=exe.parent, timeout=20, env=RUN_ENV)
        if code != 0:
            failures.append(f"exit code {code}: " + " | ".join((out + err).strip().split("\n")[-3:]))
        return failures
    for case in cases:
        expected = case.read_text(encoding="utf-8")
        typed = case.with_suffix(".in")
        code, out, err = run([str(exe)], cwd=exe.parent, stdin_path=typed if typed.exists() else None,
                             timeout=20, env=RUN_ENV)
        if code != 0:
            failures.append(f"{case.name}: exit code {code}: " + " | ".join(err.strip().split("\n")[-3:]))
        elif normalize(out) != normalize(expected):
            failures.append(f"{case.name}: the output differs from what is expected")
    return failures


def check_exercise(folder: Path) -> None:
    digest = hashlib.sha1(rel(folder).encode()).hexdigest()[:12]
    work = BUILD / "exercises" / digest
    tests = folder / "tests"
    if tests.is_dir():
        for case in sorted(tests.glob("*.in")):
            if not case.with_suffix(".out").exists():
                error(case, "has no matching .out file")
        if not list(tests.glob("*.out")):
            error(tests, "has no *.out files")

    prediction = folder / "prediction.txt"
    if prediction.exists():                                 # "predict the output" exercise
        program = next((p for p in (folder / "program.cpp", folder / "program.rs") if p.exists()), None)
        if program is None:
            error(folder, "a prediction exercise needs program.cpp (or program.rs) next to prediction.txt")
            return
        ok, diag = build_program_file(program, work / "program")
        if not ok:
            error(program, "does not compile cleanly:\n    " + "\n    ".join(diag.split("\n")[:10]))
            return
        for item in folder.iterdir():
            if item.is_file() and item.suffix in DATA_EXT and item.name != "prediction.txt":
                shutil.copy2(item, work / item.name)
        code, out, _ = run([str(work / "program")], cwd=work, timeout=20, env=RUN_ENV)
        if code != 0:
            error(program, f"exited with code {code}")
        elif normalize(out) == normalize(prediction.read_text(encoding="utf-8")):
            error(prediction, "already contains the right answer; the student must write it")
        return

    starter_dir = folder / "starter"
    if starter_dir.is_dir():
        sources = sorted(starter_dir.glob("*.cpp"))
    else:
        sources = [p for p in (folder / "exercise.cpp", folder / "exercise.rs") if p.exists()]
    if not sources:
        error(folder, "no exercise.cpp, exercise.rs, starter/ or prediction.txt")
        return
    head = "\n".join(sources[0].read_text(encoding="utf-8").split("\n")[:6]).lower()
    broken_on_purpose = "does not compile" in head
    ok, diag = build_sources(sources, work / "starter", strict=False)
    if broken_on_purpose:
        if ok:
            error(sources[0], "says it does not compile, but it does")
    elif not ok:
        error(sources[0], "starter does not compile (if that is the exercise, say 'does not compile' "
                          "in the first comment):\n    " + "\n    ".join(diag.split("\n")[:10]))
    elif not run_tests(work / "starter", tests, sources[0].parent):
        error(folder, "the starter already passes every test; there is nothing left to do")

    if not SOLUTIONS.is_dir():
        return
    solution_dir = SOLUTIONS / folder.relative_to(ROOT)
    solution = sorted(solution_dir.glob("*.cpp")) or sorted(solution_dir.glob("*.rs")) if solution_dir.is_dir() else []
    if not solution:
        error(folder, f"no solution in solutions/{rel(folder)}/")
        return
    ok, diag = build_sources(solution, work / "solution", strict=True)
    if not ok:
        error(solution[0], "solution does not compile cleanly:\n    " + "\n    ".join(diag.split("\n")[:12]))
        return
    for failure in run_tests(work / "solution", tests, sources[0].parent):
        error(solution[0], "solution fails: " + failure)


# --------------------------------------------------------------------------- links, names, glossary

def heading_slugs(page: Path) -> set[str]:
    slugs = set()
    lines = page.read_text(encoding="utf-8").split("\n")
    fenced = set()
    for start, end, _ in split_blocks(lines):
        fenced.update(range(start, end + 1))
    for i, line in enumerate(lines):
        if i in fenced or not line.startswith("#"):
            continue
        title = re.sub(r"^#+\s*", "", line).strip().lower()
        title = re.sub(r"[`*_]", "", title)
        slug = re.sub(r"[^\w\- ]", "", title).replace(" ", "-")
        slugs.add(slug)
    return slugs


def exists_exactly(path: Path) -> bool:
    """Like Path.exists(), but case-sensitive on every operating system."""
    try:
        parts = path.resolve().relative_to(ROOT).parts
    except ValueError:
        return path.exists()
    current = ROOT
    for part in parts:
        try:
            if part not in os.listdir(current):
                return False
        except (NotADirectoryError, FileNotFoundError):
            return False
        current = current / part
    return True


def check_links(page: Path) -> None:
    lines = page.read_text(encoding="utf-8").split("\n")
    fenced = set()
    for start, end, _ in split_blocks(lines):
        fenced.update(range(start, end + 1))
    for i, line in enumerate(lines):
        if i in fenced:
            continue
        for target in LINK_RE.findall(re.sub(r"`[^`]*`", "", line)):
            if re.match(r"^[a-z][a-z0-9+.-]*:", target):
                continue
            path_part, _, anchor = target.partition("#")
            destination = page if not path_part else (page.parent / path_part)
            if not exists_exactly(destination):
                outside = ROOT not in args.scope and not in_scope(destination)
                (warn if outside else error)(page, f"line {i + 1}: broken link '{target}'")
                continue
            if anchor and destination.is_dir():
                destination = destination / "README.md"
            if anchor and destination.suffix == ".md" and destination.is_file():
                if anchor.lower() not in heading_slugs(destination):
                    error(page, f"line {i + 1}: no heading '#{anchor}' in {rel(destination)}")


def check_names() -> None:
    for chapter in chapter_dirs():
        if not in_scope(chapter):
            continue
        for path in sorted(chapter.rglob("*")):
            parts = path.relative_to(ROOT).parts
            if "target" in parts or "build" in parts or any(p.startswith(".") for p in parts):
                continue
            name = path.name
            if name.lower().split(".")[0] in WINDOWS_RESERVED:
                error(path, "this name is reserved on Windows")
            if path.is_dir():
                if not DIR_RE.match(name):
                    error(path, "folder names use lowercase letters, digits and hyphens only")
            else:
                if name not in FILE_EXCEPTIONS and not FILE_RE.match(name):
                    error(path, "file names use lowercase letters, digits, '_', '-' and '.' only")
                if path.stat().st_size == 0:
                    error(path, "empty file")


def glossary_text() -> str:
    entries = []
    for chapter in chapter_dirs():
        page = chapter / "README.md"
        if not page.exists():
            continue
        lines = page.read_text(encoding="utf-8").split("\n")
        title = lines[0].lstrip("# ").strip() if lines else chapter.name
        inside = False
        for line in lines:
            if line.startswith("## "):
                inside = line.strip().lower() == "## key terms"
                continue
            if inside and line.startswith("|"):
                cells = [c.strip().replace("\x00", "\\|")
                         for c in line.strip().replace("\\|", "\x00").strip("|").split("|")]
                if len(cells) >= 2 and cells[0].lower() != "term" and not set(cells[0]) <= set("-: "):
                    entries.append((re.sub(r"[`*]", "", cells[0]).lower(), cells[0], cells[1], title, chapter.name))
    out = ["# Glossary", "",
           "Every key term from the chapters, in one place. This page is generated from the",
           "\"Key terms\" tables: edit those, then run `python3 tools/check.py --fix`.", "",
           "| Term | Meaning | Chapter |", "|------|---------|---------|"]
    for _, term, meaning, title, folder in sorted(entries):
        out.append(f"| {term} | {meaning} | [{title}]({folder}/README.md) |")
    return "\n".join(out) + "\n"


def check_glossary(fix: bool) -> None:
    page = ROOT / "GLOSSARY.md"
    fresh = glossary_text()
    current = page.read_text(encoding="utf-8") if page.exists() else ""
    if fresh != current:
        if fix:
            page.write_text(fresh, encoding="utf-8")
            print("fixed  GLOSSARY.md")
        else:
            error(page, "is out of date (run: python3 tools/check.py --fix)")


def check_chapter_index(chapter: Path) -> None:
    page = chapter / "README.md"
    if not page.exists():
        error(chapter, "chapter has no README.md")
        return
    text = page.read_text(encoding="utf-8")
    for sub in sorted(chapter.iterdir()):
        if sub.is_dir() and (sub / "README.md").exists() and f"({sub.name}/README.md)" not in text:
            error(page, f"does not link to {sub.name}/README.md")
    exercises = chapter / "exercises"
    if exercises.is_dir():
        index = exercises / "README.md"
        listing = index.read_text(encoding="utf-8") if index.exists() else ""
        if not index.exists():
            error(exercises, "has no README.md")
        for sub in sorted(exercises.iterdir()):
            if sub.is_dir() and sub.name not in listing:
                error(index, f"does not mention {sub.name}")


# --------------------------------------------------------------------------- main

def main() -> int:
    global args
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument("paths", nargs="*", help="folders to check (default: the whole course)")
    parser.add_argument("--fix", action="store_true", help="rewrite code/output blocks and the glossary")
    parser.add_argument("--no-sanitize", action="store_true", help="skip the sanitizers (faster, checks less)")
    parser.add_argument("--jobs", type=int, default=min(8, os.cpu_count() or 2))
    args = parser.parse_args()
    args.scope = [Path(p).resolve() for p in args.paths] or [ROOT]
    atexit.register(shutil.rmtree, BUILD, ignore_errors=True)
    for scope in args.scope:
        if not scope.exists():
            print(f"no such folder: {scope}", file=sys.stderr)
            return 2

    lesson_folders: list[Path] = []
    exercise_folders: list[Path] = []
    for chapter in chapter_dirs():
        if not in_scope(chapter):
            continue
        check_chapter_index(chapter)
        for folder in sorted(p for p in chapter.rglob("*") if p.is_dir()):
            parts = folder.relative_to(ROOT).parts
            if "target" in parts or "tests" in parts or "starter" in parts or not in_scope(folder):
                continue
            if is_exercise(folder):
                exercise_folders.append(folder)
            elif (folder / "README.md").exists() and "exercises" not in parts:
                lesson_folders.append(folder)

    for folder in lesson_folders:
        check_programs(folder)
    with futures.ThreadPoolExecutor(max_workers=args.jobs) as pool:
        list(pool.map(check_exercise, exercise_folders))
    for page in markdown_files():
        if in_scope(page):
            if page.name != "CONTRIBUTING.md":
                check_page(page, args.fix)
            check_links(page)
    check_names()
    if ROOT in args.scope:
        check_glossary(args.fix)

    for message in warnings:
        print("warning:", message)
    for message in errors:
        print("ERROR:", message)
    count = len(lesson_folders), len(exercise_folders)
    if errors:
        print(f"\n{len(errors)} problem(s) in {count[0]} lesson(s) and {count[1]} exercise(s).")
        return 1
    note = "" if SOLUTIONS.is_dir() else " (no solutions/ folder: exercise solutions were not checked)"
    print(f"OK: {count[0]} lesson(s) and {count[1]} exercise(s) checked{note}.")
    return 0


if __name__ == "__main__":
    sys.exit(main())
