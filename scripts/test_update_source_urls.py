#!/usr/bin/env python3
"""Regression tests for scripts/update_source_urls.py."""

import importlib.util
import subprocess
import tempfile
import unittest
from pathlib import Path


SCRIPT = Path(__file__).with_name("update_source_urls.py")
spec = importlib.util.spec_from_file_location("update_source_urls", SCRIPT)
module = importlib.util.module_from_spec(spec)
assert spec.loader is not None
spec.loader.exec_module(module)


class UpdateSourceUrlsTest(unittest.TestCase):
    def setUp(self):
        self.temporary_directory = tempfile.TemporaryDirectory()
        self.root = Path(self.temporary_directory.name)
        subprocess.run(["git", "init", "-q", str(self.root)], check=True)

    def tearDown(self):
        self.temporary_directory.cleanup()

    def write_and_track(self, relative_path: str, content: bytes) -> Path:
        path = self.root / relative_path
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_bytes(content)
        subprocess.run(["git", "-C", str(self.root), "add", relative_path], check=True)
        return path

    def test_insert_repair_and_idempotence(self):
        header = self.write_and_track("dir/a b.hpp", b"#pragma once\nint x;\n")
        self.assertEqual(module.update(self.root, check=True), 1)
        self.assertEqual(module.update(self.root, check=False), 0)
        expected = b"// Source: https://github.com/maspypy/library/blob/main/dir/a%20b.hpp\n#pragma once\nint x;\n"
        self.assertEqual(header.read_bytes(), expected)
        self.assertEqual(module.update(self.root, check=True), 0)

        header.write_bytes(b"// Source: https://example.invalid/old.hpp\n#pragma once\n")
        self.assertEqual(module.update(self.root, check=False), 0)
        self.assertTrue(header.read_bytes().startswith(b"// Source: https://github.com/maspypy/library/blob/main/dir/a%20b.hpp\n"))

    def test_moves_source_line_before_existing_comment_and_normalizes_crlf(self):
        header = self.write_and_track("a.hpp", b"/* note */\r\n// Source: stale\r\nint x;\r\n")
        self.assertEqual(module.update(self.root, check=False), 0)
        self.assertEqual(
            header.read_bytes(),
            b"// Source: https://github.com/maspypy/library/blob/main/a.hpp\n/* note */\nint x;\n",
        )


if __name__ == "__main__":
    unittest.main()
