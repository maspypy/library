"""Offline regression tests for independent yukicoder/other verify shards."""
from __future__ import annotations

import importlib.util
import datetime
import json
import os
import pathlib
import subprocess
import sys
import tempfile
import unittest
from unittest import mock

ROOT = pathlib.Path(__file__).resolve().parents[2]
SCRIPTS = ROOT / ".github" / "scripts"
MERGE_PROGRAM = SCRIPTS / "merge_verify_timestamps.py"
TIMESTAMP = "2026-11-16 14:00:00 +0900"
STALE = "2024-01-01 00:00:00 +0000"


def module_at(name: str, path: pathlib.Path):
    spec = importlib.util.spec_from_file_location(name, path)
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    return module


runner = module_at("verify_runner_groups", SCRIPTS / "run_verify_shard.py")
merger = module_at("verify_merge_groups", MERGE_PROGRAM)


class GroupTests(unittest.TestCase):
    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.addCleanup(self.tmp.cleanup)
        self.root = pathlib.Path(self.tmp.name)

    def test_each_file_belongs_to_one_group_and_original_shard(self):
        paths = [
            pathlib.Path("test/3_yukicoder/1242.test.cpp"),
            pathlib.Path("test/3_yukicoder/1036_3.test.cpp"),
            pathlib.Path("test/2_library_checker/foo.test.cpp"),
            pathlib.Path("test/4_aoj/bar.test.cpp"),
            pathlib.Path("test/1_mytest/baz.test.cpp"),
        ]
        for path in paths:
            group = "yukicoder" if path.parts[1] == "3_yukicoder" else "other"
            self.assertEqual(runner.group_of(path), group)
            self.assertEqual(merger.group_of(path), "all")
            self.assertEqual(runner.shard_of(path, 16), merger.shard_of(path, 16))
            owners = [
                (g, i) for g in ("all",) for i in range(16)
                if merger.group_of(path) == g and runner.shard_of(path, 16) == i
            ]
            self.assertEqual(owners, [("all", runner.shard_of(path, 16))])

    def test_group_specific_shard_outputs_do_not_collide(self):
        old_cwd = pathlib.Path.cwd()
        try:
            os.chdir(self.root)
            data = self.root / ".verify-helper" / "timestamps.remote.json"
            data.parent.mkdir(parents=True)
            data.write_text("{}")
            runner.write_outputs(self.root / "artifacts", "yukicoder", 0, 16, [], 0)
            runner.write_outputs(self.root / "artifacts", "other", 0, 16, [], 1)
        finally:
            os.chdir(old_cwd)
        directory = self.root / "artifacts"
        self.assertEqual(len(list(directory.iterdir())), 6)
        self.assertEqual(json.loads((directory / "complete-other-0.json").read_text())["group"], "other")
        self.assertEqual(json.loads((directory / "complete-yukicoder-0.json").read_text())["verify_exit_code"], 0)

    def artifacts(self):
        inp = self.root / "artifacts"
        inp.mkdir()
        for group in ("all",):
            for shard in range(16):
                (inp / f"complete-{group}-{shard}.json").write_text(json.dumps({
                    "group": group, "shard": shard, "shards": 16,
                    "selected_files": 1, "verify_exit_code": 0,
                }))
                # All shards see stale snapshots; only the owner is authoritative.
                timestamps = {p.as_posix(): STALE for p in self.paths}
                for p in self.paths:
                    if merger.group_of(p) == group and runner.shard_of(p, 16) == shard:
                        if p != self.failed:
                            timestamps[p.as_posix()] = TIMESTAMP
                        else:
                            del timestamps[p.as_posix()]
                (inp / f"timestamps-{group}-{shard}.json").write_text(json.dumps(timestamps))
        return inp

    def run_merge(self):
        return subprocess.run([
            sys.executable, str(MERGE_PROGRAM),
            "--input-dir", str(self.root / "artifacts"),
            "--output", str(self.root / "merged.json"),
            "--shards", "16", "--groups", "all",
        ], capture_output=True, text=True, check=False)

    def prepare(self):
        self.paths = [
            pathlib.Path("test/3_yukicoder/1242.test.cpp"),
            pathlib.Path("test/3_yukicoder/2361.test.cpp"),
            pathlib.Path("test/2_library_checker/range_sum.test.cpp"),
            pathlib.Path("test/4_aoj/hello.test.cpp"),
        ]
        self.failed = self.paths[0]
        return self.artifacts()

    def test_merge_uses_only_group_and_shard_owner(self):
        self.prepare()
        r = self.run_merge()
        self.assertEqual(r.returncode, 0, r.stderr)
        results = json.loads((self.root / "merged.json").read_text())
        self.assertNotIn(self.failed.as_posix(), results)
        self.assertEqual(set(results), {p.as_posix() for p in self.paths if p != self.failed})
        self.assertTrue(all(v == TIMESTAMP for v in results.values()))

    def test_merge_rejects_missing_group_shard(self):
        inp = self.prepare()
        (inp / "complete-all-15.json").unlink()
        r = self.run_merge()
        self.assertNotEqual(r.returncode, 0)
        self.assertIn("missing shard output", r.stderr)

    def test_merge_rejects_wrong_group(self):
        inp = self.prepare()
        p = inp / "complete-all-15.json"
        contents = json.loads(p.read_text())
        contents["group"] = "yukicoder"
        p.write_text(json.dumps(contents))
        r = self.run_merge()
        self.assertNotEqual(r.returncode, 0)
        self.assertIn("invalid completion manifest", r.stderr)

    def test_merge_rejects_invalid_owner_timestamp(self):
        inp = self.prepare()
        test = self.paths[1]
        group = merger.group_of(test)
        shard = runner.shard_of(test, 16)
        p = inp / f"timestamps-{group}-{shard}.json"
        contents = json.loads(p.read_text())
        contents[test.as_posix()] = "invalid"
        p.write_text(json.dumps(contents))
        r = self.run_merge()
        self.assertNotEqual(r.returncode, 0)
        self.assertIn("invalid timestamp", r.stderr)


if __name__ == "__main__":
    unittest.main()
