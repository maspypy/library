"""Offline tests for the CI yukicoder downloader shim (no network)."""
from __future__ import annotations

import hashlib
import importlib.util
import os
import pathlib
import stat
import subprocess
import sys
import tempfile
import unittest

ROOT = pathlib.Path(__file__).resolve().parents[2]
SHIM = ROOT / ".github/scripts/oj"
RUNNER = ROOT / ".github/scripts/run_verify_shard.py"
FAKE_OJ = '''#!/usr/bin/env python3
import os
import pathlib
import sys
args = sys.argv[1:]
count_file = pathlib.Path(os.environ['FAKE_OJ_COUNT'])
n = int(count_file.read_text()) + 1 if count_file.exists() else 1
count_file.write_text(str(n))
mode = os.environ['FAKE_OJ_MODE']
if args[0] != 'download' or mode == 'passthrough':
    print('PASSTHROUGH', args)
    sys.exit(7)
i = args.index('-d') + 1
dest = pathlib.Path(args[i]); dest.mkdir(parents=True, exist_ok=True)
if mode == 'permanent_429' or (mode == 'once_429' and n == 1):
    (dest / 'orphan.in').write_text('partial')
    print('[NETWORK] 429 Too Many Requests')
    print('[ERROR] 429 Client Error: Too Many Requests for url: https://yukicoder.me/problems/no/1/testcase.zip')
    sys.exit(1)
if mode == 'invalid_success':
    (dest / 'orphan.in').write_text('partial')
    sys.exit(0)
if mode == 'other_failure':
    print('[ERROR] 403 Forbidden')
    sys.exit(1)
(dest / 'example.in').write_text('1\\n')
(dest / 'example.out').write_text('2\\n')
print('download successful')
sys.exit(0)
'''


def load_runner():
    spec = importlib.util.spec_from_file_location("verify_shard_under_test", RUNNER)
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    return module


class ShimTests(unittest.TestCase):
    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.addCleanup(self.tmp.cleanup)
        self.root = pathlib.Path(self.tmp.name)
        self.fake = self.root / "fake_oj"
        self.fake.write_text(FAKE_OJ)
        self.fake.chmod(self.fake.stat().st_mode | stat.S_IXUSR)
        if os.name == "nt":
            script = self.fake
            self.fake = self.root / "fake_oj.cmd"
            self.fake.write_text(f'@"{sys.executable}" "{script}" %*\n')
        self.dest = self.root / "cache" / "hash" / "test"
        self.count = self.root / "count"
        self.circuit = self.root / "circuit.block"
        self.env = os.environ.copy()
        self.env.update({
            "VERIFY_REAL_OJ": str(self.fake),
            "VERIFY_YUKICODER_CIRCUIT": str(self.circuit),
            "VERIFY_YUKICODER_RETRY_SECONDS": "0,0",
            "FAKE_OJ_COUNT": str(self.count),
            "FAKE_OJ_MODE": "success",
        })

    def invoke(self, *argv):
        args = ("download", "--system", "-d", str(self.dest), "--silent",
                "https://yukicoder.me/problems/no/1") if not argv else argv
        return subprocess.run(
            [sys.executable, str(SHIM), *args],
            env=self.env, cwd=self.root,
            capture_output=True, text=True, check=False,
        )

    def count_calls(self):
        return int(self.count.read_text()) if self.count.exists() else 0

    def test_success_is_atomic(self):
        result = self.invoke()
        self.assertEqual(result.returncode, 0, result.stderr)
        self.assertEqual(self.count_calls(), 1)
        self.assertTrue((self.dest / "example.in").exists())
        self.assertTrue((self.dest / "example.out").exists())
        self.assertFalse(list(self.dest.parent.glob(".test.partial-*")))

    def test_429_then_success_retries_and_discards_partial(self):
        self.env["FAKE_OJ_MODE"] = "once_429"
        result = self.invoke()
        self.assertEqual(result.returncode, 0, result.stderr)
        self.assertEqual(self.count_calls(), 2)
        self.assertFalse((self.dest / "orphan.in").exists())
        self.assertTrue((self.dest / "example.out").exists())
        self.assertGreater(float(self.circuit.read_text()), 0)

    def test_429_persistent_opens_circuit(self):
        self.env["FAKE_OJ_MODE"] = "permanent_429"
        first = self.invoke()
        self.assertEqual(first.returncode, 75, first.stderr)
        self.assertEqual(self.count_calls(), 3)
        self.assertTrue(self.circuit.exists())
        self.assertFalse(self.dest.exists())
        second = self.invoke()
        self.assertEqual(second.returncode, 75)
        self.assertEqual(self.count_calls(), 3)

    def test_other_error_does_not_retry_or_poison_cache(self):
        self.env["FAKE_OJ_MODE"] = "other_failure"
        result = self.invoke()
        self.assertEqual(result.returncode, 1)
        self.assertEqual(self.count_calls(), 1)
        self.assertFalse(self.dest.exists())

    def test_empty_output_is_not_cached_even_on_success(self):
        self.env["FAKE_OJ_MODE"] = "invalid_success"
        result = self.invoke()
        self.assertEqual(result.returncode, 1)
        self.assertFalse(self.dest.exists())

    def test_replaces_old_incomplete_directory(self):
        self.dest.mkdir(parents=True)
        (self.dest / "orphan.in").write_text("old partial data")
        result = self.invoke()
        self.assertEqual(result.returncode, 0)
        self.assertFalse((self.dest / "orphan.in").exists())
        self.assertTrue((self.dest / "example.out").exists())

    def test_oj_test_is_forwarded_verbatim(self):
        result = self.invoke("test", "-d", "foo")
        self.assertEqual(result.returncode, 7)
        self.assertEqual(self.count_calls(), 1)
        self.assertIn("PASSTHROUGH", result.stdout)

    def test_non_yukicoder_download_is_forwarded(self):
        self.env["FAKE_OJ_MODE"] = "passthrough"
        result = self.invoke("download", "-d", str(self.dest),
                             "https://judge.yosupo.jp/problem/foo")
        self.assertEqual(result.returncode, 7)
        self.assertEqual(self.count_calls(), 1)
        self.assertFalse(self.dest.exists())

    def test_invalid_legacy_cache_is_removed(self):
        mod = load_runner()
        source = self.root / "test/3_yukicoder/123.test.cpp"
        source.parent.mkdir(parents=True)
        url = "https://yukicoder.me/problems/no/123"
        source.write_text(f'#define PROBLEM "{url}"\n')
        target = self.root / ".verify-helper/cache" / hashlib.md5(
            url.encode()).hexdigest() / "test"
        target.mkdir(parents=True)
        (target / "orphan.in").write_text("partial")
        old_cwd = pathlib.Path.cwd()
        try:
            os.chdir(self.root)
            mod.remove_incomplete_yukicoder_caches([
                pathlib.Path("test/3_yukicoder/123.test.cpp")])
        finally:
            os.chdir(old_cwd)
        self.assertFalse(target.exists())

    def test_valid_legacy_cache_is_kept(self):
        mod = load_runner()
        source = self.root / "test/3_yukicoder/123.test.cpp"
        source.parent.mkdir(parents=True)
        url = "https://yukicoder.me/problems/no/123"
        source.write_text(f'#define PROBLEM "{url}"\n')
        target = self.root / ".verify-helper/cache" / hashlib.md5(
            url.encode()).hexdigest() / "test"
        target.mkdir(parents=True)
        (target / "sample.in").write_text("1")
        (target / "sample.out").write_text("2")
        old_cwd = pathlib.Path.cwd()
        try:
            os.chdir(self.root)
            mod.remove_incomplete_yukicoder_caches([
                pathlib.Path("test/3_yukicoder/123.test.cpp")])
        finally:
            os.chdir(old_cwd)
        self.assertTrue(target.exists())

    def test_successful_download_is_collected_without_verify_timestamp(self):
        mod = load_runner()
        source = self.root / "test/3_yukicoder/123.test.cpp"
        source.parent.mkdir(parents=True)
        url = "https://yukicoder.me/problems/no/123"
        source.write_text(f'#define PROBLEM "{url}"\n')
        target = self.root / ".verify-helper/cache" / hashlib.md5(
            url.encode()).hexdigest() / "test"
        target.mkdir(parents=True)
        (target / "sample.in").write_text("1")
        (target / "sample.out").write_text("2")
        (target / ".download-complete").write_text("ok\n")
        old_cwd = pathlib.Path.cwd()
        try:
            os.chdir(self.root)
            mod.collect_yukicoder_testcases([
                pathlib.Path("test/3_yukicoder/123.test.cpp")])
        finally:
            os.chdir(old_cwd)
        saved = self.root / ".verify-helper/testcases" / hashlib.md5(
            url.encode()).hexdigest() / "test"
        self.assertEqual((saved / "sample.out").read_text(), "2")
        self.assertTrue((saved / ".download-complete").is_file())

    def test_corrupt_saved_testcases_can_be_repaired(self):
        mod = load_runner()
        source = self.root / "test/3_yukicoder/123.test.cpp"
        source.parent.mkdir(parents=True)
        url = "https://yukicoder.me/problems/no/123"
        source.write_text(f'#define PROBLEM "{url}"\n')
        checksum = hashlib.md5(url.encode()).hexdigest()
        current = self.root / ".verify-helper/cache" / checksum / "test"
        current.mkdir(parents=True)
        (current / "sample.in").write_text("1")
        (current / "sample.out").write_text("2")
        (current / ".download-complete").write_text("ok\n")
        saved = self.root / ".verify-helper/testcases" / checksum / "test"
        saved.mkdir(parents=True)
        (saved / "incomplete.in").write_text("partial")
        old_cwd = pathlib.Path.cwd()
        try:
            os.chdir(self.root)
            mod.collect_yukicoder_testcases([
                pathlib.Path("test/3_yukicoder/123.test.cpp")])
        finally:
            os.chdir(old_cwd)
        self.assertFalse((saved / "incomplete.in").exists())
        self.assertEqual((saved / "sample.out").read_text(), "2")

    def test_ci_orchestration_change_does_not_force_full_reverify(self):
        mod = load_runner()
        self.assertNotIn(".github/scripts/oj", mod.PIPELINE_FILES)
        self.assertNotIn(".github/scripts/run_verify_shard.py", mod.PIPELINE_FILES)


if __name__ == "__main__":
    unittest.main()
