"""Offline regression tests for standalone dispatch and compiler results."""
import contextlib
import importlib.util
import json
import os
import pathlib
import shutil
import sys
import tempfile
import types
import unittest
from unittest import mock

SCRIPT = pathlib.Path(__file__).resolve().parents[1] / "scripts/verify_trace.py"
spec = importlib.util.spec_from_file_location("verify_standalone_test", SCRIPT)
tracer = importlib.util.module_from_spec(spec)
spec.loader.exec_module(tracer)


class StandaloneTests(unittest.TestCase):
    def setUp(self):
        stack = contextlib.ExitStack()
        self.addCleanup(stack.close)
        self.root = pathlib.Path(stack.enter_context(tempfile.TemporaryDirectory()))
        old = pathlib.Path.cwd()
        stack.callback(os.chdir, old)
        os.chdir(self.root)
        self.path = tracer.STANDALONE_ROOT / "example.test.cpp"
        self.path.parent.mkdir(parents=True)
        stack.enter_context(mock.patch.dict(os.environ, {
            "VERIFY_TRACE_FILE": str(self.root / "trace.jsonl"),
            "AI_TEST_TIMEOUT": "120", "AI_TEST_COMPILE_TIMEOUT": "120",
        }))

    def environment(self, *flags):
        return types.SimpleNamespace(
            CXX="g++", CXXFLAGS=["-std=c++17", "-DNDEBUG", *flags],
            get_execute_command=lambda path, *, basedir, tempdir: [str(tempdir / "a.out")],
        )

    def verify(self, source, *envs):
        if not shutil.which("g++") or not shutil.which("timeout"):
            self.skipTest("requires g++ and GNU timeout")
        self.path.write_text(source)
        with mock.patch.object(tracer, "cpp_environments", return_value=list(envs)):
            return tracer.verify_standalone(self.path)

    def test_success_both_environments_no_input(self):
        with mock.patch.object(tracer, "run_bounded", wraps=tracer.run_bounded) as run:
            self.assertTrue(self.verify(
                '#include <cstdio>\nint main(){return getchar()==EOF?0:1;}\n',
                self.environment(), self.environment("-DSECOND")))
            self.assertEqual(run.call_count, 4)

    def test_assertions_still_enabled(self):
        self.assertFalse(self.verify(
            '#include <cassert>\nint main(){assert(false);}\n', self.environment()))

    def test_second_environment_failure(self):
        self.assertFalse(self.verify('''int main(){
#ifdef SECOND
return 1;
#else
return 0;
#endif
}''', self.environment(), self.environment("-DSECOND")))

    def test_compile_failure(self):
        self.assertFalse(self.verify("not valid C++\n", self.environment()))

    def test_execution_timeout(self):
        with mock.patch.dict(os.environ, {"AI_TEST_TIMEOUT": "1"}):
            self.assertFalse(self.verify(
                '#include <unistd.h>\nint main(){sleep(20);}\n', self.environment()))

    def test_compile_timeout(self):
        if not shutil.which("timeout"):
            self.skipTest("requires GNU timeout")
        with mock.patch.dict(os.environ, {"AI_TEST_COMPILE_TIMEOUT": "1"}):
            env = self.environment()
            # A script that never gets as far as creating an executable.
            compiler = self.root / "compiler"
            compiler.write_text("#!/bin/sh\nsleep 20\n")
            compiler.chmod(0o755)
            env.CXX = compiler
            self.path.write_text("int main(){}\n")
            with mock.patch.object(tracer, "cpp_environments", return_value=[env]):
                self.assertFalse(tracer.verify_standalone(self.path))

    def test_invalid_timeout(self):
        with mock.patch.dict(os.environ, {"AI_TEST_TIMEOUT": "0"}):
            with self.assertRaises(ValueError):
                tracer.verify_standalone(self.path)

    def test_path_detection(self):
        self.assertTrue(tracer.is_standalone(self.path))
        self.assertTrue(tracer.is_standalone(self.path.resolve()))
        self.assertFalse(tracer.is_standalone(pathlib.Path("test/1_mytest/a.test.cpp")))
        self.assertFalse(tracer.is_standalone(pathlib.Path("test/5_ai_generated_test_other/a.test.cpp")))

    def test_trace_routing_and_failed_status(self):
        pkg = types.ModuleType("onlinejudge_verify")
        cli = types.ModuleType("onlinejudge_verify.main")
        verifier = types.ModuleType("onlinejudge_verify.verify")
        original = mock.Mock(return_value=True)
        verifier.verify_file = original
        pkg.main = cli
        pkg.verify = verifier
        ordinary = pathlib.Path("test/1_mytest/a.test.cpp")
        other_ai = self.path.with_name("failure.test.cpp")
        def call_cli(args):
            self.assertTrue(verifier.verify_file(ordinary, tle=60))
            self.assertTrue(verifier.verify_file(self.path, tle=60))
            self.assertFalse(verifier.verify_file(other_ai, tle=60))
        cli.main = call_cli
        with mock.patch.dict(sys.modules, {
            "onlinejudge_verify": pkg, "onlinejudge_verify.main": cli,
            "onlinejudge_verify.verify": verifier,
        }), mock.patch.object(tracer, "verify_standalone", side_effect=[True, False]) as run:
            tracer.main()
        original.assert_called_once_with(ordinary, tle=60)
        self.assertEqual(run.call_args_list, [mock.call(self.path), mock.call(other_ai)])
        entries = [json.loads(line) for line in (self.root / "trace.jsonl").read_text().splitlines()]
        self.assertEqual(entries, [{"path": p.as_posix(), "status": s} for p, s in
            [(ordinary, "ac"), (self.path, "ac"), (other_ai, "failed")]])

    def test_empty_environment_is_not_success(self):
        pkg = types.ModuleType("onlinejudge_verify")
        languages = types.ModuleType("onlinejudge_verify.languages")
        registry = types.ModuleType("onlinejudge_verify.languages.list")
        registry.get = mock.Mock(return_value=types.SimpleNamespace(
            list_environments=mock.Mock(return_value=[])))
        pkg.languages = languages
        languages.list = registry
        with mock.patch.dict(sys.modules, {
            "onlinejudge_verify": pkg, "onlinejudge_verify.languages": languages,
            "onlinejudge_verify.languages.list": registry,
        }):
            with self.assertRaisesRegex(RuntimeError, "no configured compiler"):
                tracer.verify_standalone(self.path)


if __name__ == "__main__":
    unittest.main()
