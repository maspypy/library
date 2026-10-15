#!/usr/bin/env python3
"""Keep per-header source URLs in sync with their paths in this repository."""

from __future__ import annotations

import argparse
import subprocess
import sys
from pathlib import Path
from urllib.parse import quote


REPOSITORY_URL = "https://github.com/maspypy/library"
SOURCE_PREFIX = "// Source: "


def tracked_headers(root: Path) -> list[Path]:
    """Return every tracked .hpp file, including files in normally ignored paths."""
    result = subprocess.run(
        ["git", "-C", str(root), "ls-files", "-z", "--", "*.hpp"],
        check=True,
        stdout=subprocess.PIPE,
    )
    return [root / name for name in result.stdout.decode("utf-8").split("\0") if name]


def expected_source_line(root: Path, path: Path) -> bytes:
    relative_path = path.relative_to(root).as_posix()
    url_path = quote(relative_path, safe="/-._~")
    return f"{SOURCE_PREFIX}{REPOSITORY_URL}/blob/main/{url_path}".encode("ascii")


def normalized_content(root: Path, path: Path) -> bytes:
    content = path.read_bytes().replace(b"\r\n", b"\n")
    bom = b"\xef\xbb\xbf" if content.startswith(b"\xef\xbb\xbf") else b""
    if bom:
        content = content[len(bom) :]

    # Header files use LF by repository policy (see .gitattributes).
    lines = content.splitlines(keepends=True)
    source_line = expected_source_line(root, path) + b"\n"

    # A Source line is a reserved, top-of-file metadata line.  Normalizing all
    # such lines in the leading comment/blank block also repairs an old header
    # placed after a comment block without touching source citations in code.
    header_end = 0
    for line in lines:
        bare = line.rstrip(b"\r\n")
        if bare == b"" or bare.startswith(b"//") or bare.startswith(b"/*") or bare.startswith(b"*") or bare.startswith(b"*/"):
            header_end += 1
        else:
            break
    leading = [
        line
        for line in lines[:header_end]
        if not line.rstrip(b"\r\n").startswith(SOURCE_PREFIX.encode("ascii"))
    ]
    return bom + source_line + b"".join(leading + lines[header_end:])


def update(root: Path, check: bool) -> int:
    changed: list[Path] = []
    for path in tracked_headers(root):
        normalized = normalized_content(root, path)
        if path.read_bytes() != normalized:
            changed.append(path)
            if not check:
                path.write_bytes(normalized)

    if changed:
        for path in changed:
            print(path.relative_to(root).as_posix())
        if check:
            print("Source URL headers are missing or stale. Run: python scripts/update_source_urls.py", file=sys.stderr)
            return 1
    return 0


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--check", action="store_true", help="report stale headers without changing files")
    parser.add_argument("--root", type=Path, default=Path(__file__).resolve().parents[1], help="repository root")
    args = parser.parse_args()
    return update(args.root.resolve(), args.check)


if __name__ == "__main__":
    raise SystemExit(main())
