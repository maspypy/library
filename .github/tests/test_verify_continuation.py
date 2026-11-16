"""Offline regression tests for bounded reruns and per-file failure carryover."""
from __future__ import annotations

import contextlib
import datetime
import importlib.util
import io
import json
import os
import pathlib
import subprocess
import sys
import tempfile
import types
import unittest
from unittest import mock

HERE = pathlib.Path(__file__).resolve().parents[1]
SCRIPTS = HERE / "scripts"
ORIGIN = "a" * 40
TS = "2026-11-16 14:00:00 +0900"


def import_by_path(name: str, path: pathlib.Path):
    spec = importlib.util.spec_from_file_location(name, path)
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    return module


cont = import_by_path("verification_continuation_test", SCRIPTS / "continue_verify.py")
runner = import_by_path("verification_runner_continuation_test", SCRIPTS / "run_verify_shard.py")
tracer = import_by_path("verification_tracer_test", SCRIPTS / "verify_trace.py")


class Fixture(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        self.root = pathlib.Path(self.temp.name)

    @contextlib.contextmanager
    def working_dir(self):
        old = pathlib.Path.cwd()
        os.chdir(self.root)
        try:
            yield
        finally:
            os.chdir(old)

    def put_json(self, name, data):
        p = self.root / name
        p.parent.mkdir(parents=True, exist_ok=True)
        p.write_text(json.dumps(data) + "\n", encoding="utf-8")
        return p

    def previous(self, statuses: dict[str, str], *, round_number=0,
                 run_id=10, retry_target="both", blocked=None):
        self.make_test_sources(statuses)
        return self.put_json("previous.json", {
            "schema": 1, "origin_sha": ORIGIN, "run_id": run_id,
            "round": round_number, "statuses": statuses,
            "blocked": blocked or {"yukicoder": False, "other": False},
            "retry_target": retry_target,
        })

    def make_test_sources(self, statuses: dict[str, str]):
        for name in statuses:
            path = self.root / name
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_text("// fixture\n")

    def artifact(self, group: str, shard: int, statuses: dict[str, str],
                 *, attempts=0, rate=False, infra=False, exit_code=0):
        inp = self.root / "artifacts"
        inp.mkdir(exist_ok=True)
        self.put_json(f"artifacts/complete-{group}-{shard}.json", {
            "group": group, "shard": shard, "shards": 16,
            "selected_files": len(statuses), "verify_exit_code": exit_code,
            "rate_limited": rate, "infrastructure_error": infra,
            "attempted_files": attempts,
        })
        self.put_json(f"artifacts/states-{group}-{shard}.json", {
            "group": group, "shard": shard, "statuses": statuses,
        })
        self.put_json(f"artifacts/timestamps-{group}-{shard}.json", {})

    def artifact_round(self, statuses: dict[str, str], groups=("yukicoder", "other"),
                       *, attempted_groups=(), blocked_groups=(), infra_groups=()):
        self.make_test_sources(statuses)
        for group in groups:
            for shard in range(16):
                group_status = {name: value for name, value in statuses.items()
                                if cont.group_of(pathlib.Path(name)) == group and
                                cont.shard_of(pathlib.Path(name), 16) == shard}
                self.artifact(group, shard, group_status,
                              attempts=len(group_status) if group in attempted_groups else 0,
                              rate=bool(group_status) and group in blocked_groups,
                              infra=bool(group_status) and group in infra_groups,
                              exit_code=int("failed" in group_status.values()))

    def summarize(self, *, round_number=0, target="both", previous=None,
                  previous_run_id=0, run_id=10):
        args = types.SimpleNamespace(
            input_dir=self.root / "artifacts", output=self.root / "state.json",
            shards=16, origin_sha=ORIGIN, round=round_number,
            run_id=run_id, previous_run_id=previous_run_id, target=target,
            previous_state=previous)
        with self.working_dir(), contextlib.redirect_stdout(io.StringIO()):
            cont.summarize(args)
        return json.loads(args.output.read_text())


class ContinuationDecisionTests(Fixture):
    def test_failed_and_ignored_are_terminal_but_not_ac(self):
        y = "test/3_yukicoder/y.test.cpp"
        x = "test/2_library_checker/x.test.cpp"
        q = "test/2_library_checker/unfinished.test.cpp"
        self.artifact_round({y: "failed", x: "ac", q: "pending"},
                            attempted_groups=("yukicoder", "other"))
        state = self.summarize()
        self.assertEqual(state["statuses"][y], "failed")
        self.assertEqual(state["retry_target"], "other")
        self.assertEqual(state["round"], 0)

    def test_no_progress_is_not_retried(self):
        pending = "test/2_library_checker/a.test.cpp"
        previous = self.previous({pending: "pending"}, retry_target="other")
        self.artifact_round({pending: "pending"}, groups=("other",))
        now = self.summarize(round_number=1, target="other", previous=previous,
                             previous_run_id=10, run_id=11)
        self.assertEqual(now["retry_target"], "none")

    def test_only_pending_remaining_progress_triggers_retry(self):
        failed = "test/2_library_checker/wa.test.cpp"
        newly_done = "test/2_library_checker/now_ac.test.cpp"
        pending = "test/2_library_checker/unreached.test.cpp"
        previous = self.previous({failed: "failed", newly_done: "pending", pending: "pending"},
                                 retry_target="other")
        self.artifact_round({failed: "failed", newly_done: "ac", pending: "pending"},
                            groups=("other",), attempted_groups=("other",))
        current = self.summarize(round_number=1, target="other", previous=previous,
                                 previous_run_id=10, run_id=11)
        self.assertEqual(current["retry_target"], "other")
        self.assertEqual(current["statuses"][failed], "failed")
        self.assertEqual(current["round"], 1)

    def test_both_groups_resume_only_when_each_has_progress(self):
        a = "test/3_yukicoder/a.test.cpp"
        b = "test/2_library_checker/b.test.cpp"
        c = "test/2_library_checker/c.test.cpp"
        self.artifact_round({a: "pending", b: "pending", c: "ac"},
                            attempted_groups=("yukicoder", "other"))
        self.assertEqual(self.summarize()["retry_target"], "both")

    def test_rate_limit_blocks_yukicoder_but_not_other(self):
        a = "test/3_yukicoder/a.test.cpp"
        b = "test/2_library_checker/b.test.cpp"
        self.artifact_round({a: "pending", b: "pending"},
                            attempted_groups=("yukicoder", "other"),
                            blocked_groups=("yukicoder",))
        current = self.summarize()
        self.assertTrue(current["blocked"]["yukicoder"])
        self.assertEqual(current["retry_target"], "other")

    def test_infrastructure_error_prevents_auto_retry(self):
        a = "test/2_library_checker/a.test.cpp"
        self.artifact_round({a: "pending"}, attempted_groups=("other",),
                            infra_groups=("other",))
        self.assertEqual(self.summarize()["retry_target"], "none")

    def test_continuation_does_not_lose_unselected_group(self):
        yfail = "test/3_yukicoder/old-failure.test.cpp"
        ypending = "test/3_yukicoder/remaining.test.cpp"
        other = "test/2_library_checker/pending.test.cpp"
        prior = self.previous({yfail: "failed", ypending: "pending", other: "pending"},
                              retry_target="other", blocked={"yukicoder": True, "other": False})
        self.artifact_round({other: "ac"}, groups=("other",), attempted_groups=("other",))
        current = self.summarize(round_number=1, target="other", previous=prior,
                                 previous_run_id=10, run_id=11)
        self.assertEqual(current["statuses"][yfail], "failed")
        self.assertEqual(current["statuses"][ypending], "pending")
        self.assertTrue(current["blocked"]["yukicoder"])
        self.assertEqual(current["retry_target"], "none")

    def test_round_three_is_hard_cap(self):
        a = "test/2_library_checker/a.test.cpp"
        b = "test/2_library_checker/b.test.cpp"
        prior = self.previous({a: "pending", b: "pending"},
                              round_number=2, run_id=12, retry_target="other")
        self.artifact_round({a: "ac", b: "pending"}, groups=("other",),
                            attempted_groups=("other",))
        current = self.summarize(round_number=3, target="other", previous=prior,
                                 previous_run_id=12, run_id=13)
        self.assertEqual(current["retry_target"], "none")

    def test_reject_missing_owner_manifest_and_incomplete_status(self):
        a = "test/2_library_checker/a.test.cpp"
        self.artifact_round({a: "failed"})
        path = self.root / "artifacts" / "complete-other-15.json"
        path.unlink()
        with self.assertRaises(FileNotFoundError):
            self.summarize()
        self.artifact("other", 15, {})
        owner = cont.shard_of(pathlib.Path(a), 16)
        path = self.root / "artifacts" / f"states-other-{owner}.json"
        self.put_json(path.relative_to(self.root), {"group": "other", "shard": owner,
                                                    "statuses": {}})
        with self.assertRaisesRegex(ValueError, "statuses incomplete"):
            self.summarize()

    def test_statuses_are_not_counted_as_success_if_failed(self):
        a = "test/2_library_checker/a.test.cpp"
        path = self.previous({a: "failed"})
        with self.assertRaises(SystemExit) as err:
            with contextlib.redirect_stderr(io.StringIO()):
                cont.assert_final(types.SimpleNamespace(state=path))
        self.assertEqual(err.exception.code, 1)


class RunnerSkipTests(Fixture):
    def select_same_shard(self, n: int):
        selected = []
        for i in range(5000):
            p = pathlib.Path(f"test/2_library_checker/case_{i}.test.cpp")
            if runner.shard_of(p, 16) == 4:
                selected.append(p)
                if len(selected) == n:
                    return selected
        raise AssertionError("not enough fixture paths")

    def test_wa_wa_ac_pending_skips_only_existing_failed(self):
        fa, fb, ac, newer, latest = self.select_same_shard(5)
        for p in (fa, fb, ac, newer, latest):
            path = self.root / p
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_text("// test\n")
        timestamp_path = self.put_json(".verify-helper/timestamps.remote.json", {})

        def fake_verification_one(command, check, env):
            self.assertIn(str(fa), command)
            self.assertIn(str(fb), command)
            self.assertIn(str(ac), command)
            trace = pathlib.Path(env["VERIFY_TRACE_FILE"])
            with trace.open("w") as stream:
                for p, state in [(fa, "failed"), (fb, "failed"), (ac, "ac")]:
                    stream.write(json.dumps({"path": str(p), "status": state}) + "\n")
            timestamp_path.write_text(json.dumps({str(ac): TS}) + "\n")
            return types.SimpleNamespace(returncode=1)

        def fake_verification_two(command, check, env):
            self.assertNotIn(str(fa), command)
            self.assertNotIn(str(fb), command)
            self.assertIn(str(newer), command)
            self.assertIn(str(latest), command)
            trace = pathlib.Path(env["VERIFY_TRACE_FILE"])
            trace.write_text(json.dumps({"path": str(newer), "status": "ac"}) + "\n")
            timestamp_path.write_text(json.dumps({str(ac): TS, str(newer): TS}) + "\n")
            return types.SimpleNamespace(returncode=0)

        def run(round_num, action):
            args = ["run_verify_shard.py", "--group", "other", "--shard", "4",
                    "--shards", "16", "--output-dir", str(self.root / "artifacts"),
                    "--round", str(round_num), "--origin-sha", ORIGIN]
            if round_num:
                args += ["--previous-state", str(self.root / "previous.json"),
                         "--previous-run-id", "10"]
            with self.working_dir(), mock.patch.object(sys, "argv", args), \
                 mock.patch.object(runner, "pipeline_timestamp",
                                   return_value=datetime.datetime(2026, 11, 16,
                                           tzinfo=datetime.timezone.utc)), \
                 mock.patch.object(runner, "collect_yukicoder_testcases"), \
                 mock.patch.object(runner, "verification_environment", return_value={}), \
                 mock.patch.object(runner.subprocess, "run", side_effect=action):
                return runner.main()

        self.assertEqual(run(0, fake_verification_one), 1)
        first = json.loads((self.root / "artifacts/states-other-4.json").read_text())
        self.assertEqual(first["statuses"], {str(fa): "failed", str(fb): "failed",
                                             str(ac): "ac", str(newer): "pending",
                                             str(latest): "pending"})
        self.previous(first["statuses"])
        self.assertEqual(run(1, fake_verification_two), 1)
        second = json.loads((self.root / "artifacts/states-other-4.json").read_text())
        self.assertEqual(second["statuses"], {str(fa): "failed", str(fb): "failed",
                                              str(ac): "ac", str(newer): "ac",
                                              str(latest): "pending"})
        self.assertEqual(json.loads(timestamp_path.read_text()), {str(ac): TS, str(newer): TS})
        self.assertEqual(json.loads((self.root / "artifacts/complete-other-4.json").read_text())
                         ["attempted_files"], 1)

    def test_fresh_push_does_not_skip_known_failure(self):
        a = self.select_same_shard(1)[0]
        args = types.SimpleNamespace(round=0, previous_state=None, origin_sha="",
                                     previous_run_id=0)
        self.assertEqual(runner.prior_failures(args, [a]), {})


class GuardTests(Fixture):
    def test_git_changed_code_stops_continuation_but_timestamps_are_ignored(self):
        with self.working_dir():
            subprocess.check_call(["git", "init", "-q"])
            subprocess.check_call(["git", "config", "user.name", "Test"])
            subprocess.check_call(["git", "config", "user.email", "test@example.com"])
            p = pathlib.Path("code.cpp")
            p.write_text("int x;\n")
            subprocess.check_call(["git", "add", "code.cpp"])
            subprocess.check_call(["git", "commit", "-qm", "initial"])
            origin = subprocess.check_output(["git", "rev-parse", "HEAD"], text=True).strip()
            self.assertTrue(cont.unchanged_sources(origin))
            ts = pathlib.Path(".verify-helper/timestamps.remote.json")
            ts.parent.mkdir(parents=True)
            ts.write_text("{}\n")
            subprocess.check_call(["git", "add", str(ts)])
            subprocess.check_call(["git", "commit", "-qm", "timestamps"])
            self.assertTrue(cont.unchanged_sources(origin))
            p.write_text("int y;\n")
            subprocess.check_call(["git", "add", "code.cpp"])
            subprocess.check_call(["git", "commit", "-qm", "changed code"])
            self.assertFalse(cont.unchanged_sources(origin))

    def test_state_identity_wrong_run_or_round_is_rejected(self):
        state = json.loads(self.previous({"test/2_library_checker/a.test.cpp": "failed"}).read_text())
        with self.assertRaisesRegex(ValueError, "mismatched"):
            cont.validate_state(state, origin=ORIGIN, round_number=0, previous_run_id=11)
        with self.assertRaisesRegex(ValueError, "mismatched"):
            cont.validate_state(state, origin=ORIGIN, round_number=1, previous_run_id=10)

    def test_bad_target_and_source_prevent_prepare(self):
        path = self.previous({"test/2_library_checker/a.test.cpp": "failed"},
                             retry_target="other")
        args = types.SimpleNamespace(continuation=True, round=1, previous_run_id=10,
                                     origin_sha=ORIGIN, target="yukicoder", previous_state=path)
        with mock.patch.object(cont, "unchanged_sources", return_value=True):
            with self.assertRaisesRegex(ValueError, "target differs"):
                cont.prepare(args)
        args.target = "other"
        with mock.patch.object(cont, "unchanged_sources", return_value=False):
            with self.assertRaisesRegex(ValueError, "source tree changed"):
                cont.prepare(args)

    def test_dispatch_emits_one_bounded_workflow_dispatch(self):
        state = self.previous({"test/2_library_checker/a.test.cpp": "pending"},
                              retry_target="other")
        calls = []

        class Resp:
            status = 204
            def __init__(self, data=None): self.data = data or {}
            def __enter__(self): return self
            def __exit__(self, *args): return False
            def read(self): return json.dumps(self.data).encode()

        def urlopen(req, timeout):
            calls.append(req)
            if len(calls) == 1:
                return Resp({"commit": {"sha": "b" * 40}})
            return Resp()

        with mock.patch.object(cont, "unchanged_sources", return_value=True), \
             mock.patch.object(cont.subprocess, "check_output", return_value="b" * 40), \
             mock.patch.object(cont.urllib.request, "urlopen", side_effect=urlopen), \
             mock.patch.dict(os.environ, {"GITHUB_TOKEN": "fake-token", "GITHUB_REPOSITORY": "maspypy/library"}):
            with contextlib.redirect_stdout(io.StringIO()):
                cont.dispatch(types.SimpleNamespace(state=state, branch="main"))
        self.assertEqual(len(calls), 2)
        self.assertTrue(calls[1].full_url.endswith("/actions/workflows/verify.yml/dispatches"))
        payload = json.loads(calls[1].data)
        self.assertEqual(payload["inputs"]["round"], "1")
        self.assertEqual(payload["inputs"]["previous_run_id"], "10")
        self.assertEqual(payload["inputs"]["origin_sha"], ORIGIN)
        self.assertEqual(payload["inputs"]["target"], "other")
        self.assertEqual(payload["ref"], "main")

    def test_dispatch_noop_if_no_retry(self):
        state = self.previous({}, retry_target="none")
        with mock.patch.object(cont.urllib.request, "urlopen") as fn:
            cont.dispatch(types.SimpleNamespace(state=state, branch="main"))
            fn.assert_not_called()


class MergeTests(Fixture):
    def test_partial_merge_preserves_other_group_ac(self):
        other = "test/2_library_checker/a.test.cpp"
        yuki = "test/3_yukicoder/z.test.cpp"
        self.artifact_round({other: "ac"}, groups=("other",), attempted_groups=("other",))
        owner = cont.shard_of(pathlib.Path(other), 16)
        self.put_json(f"artifacts/timestamps-other-{owner}.json", {other: TS})
        self.put_json("baseline.json", {yuki: TS, other: "2023-01-01 00:00:00 +0000"})
        script = SCRIPTS / "merge_verify_timestamps.py"
        completed = subprocess.run([
            sys.executable, str(script), "--input-dir", str(self.root / "artifacts"),
            "--output", str(self.root / "merged.json"),
            "--baseline", str(self.root / "baseline.json"),
            "--shards", "16", "--groups", "other",
        ], capture_output=True, text=True)
        self.assertEqual(completed.returncode, 0, completed.stderr)
        self.assertEqual(json.loads((self.root / "merged.json").read_text()),
                         {yuki: TS, other: TS})

    def test_missing_source_status_cannot_appear_ac(self):
        missing = "test/2_library_checker/missing.test.cpp"
        current = "test/2_library_checker/ok.test.cpp"
        self.artifact_round({current: "ac"}, attempted_groups=("other",))
        self.make_test_sources({missing: "pending"})
        with self.assertRaisesRegex(ValueError, "state does not cover all"):
            self.summarize()


class TraceTests(Fixture):
    def test_trace_records_attempted_statuses(self):
        filename = self.root / "trace.jsonl"
        with mock.patch.dict(os.environ, {"VERIFY_TRACE_FILE": str(filename)}):
            tracer.record(pathlib.Path("test/foo.test.cpp"), "failed")
            tracer.record(pathlib.Path("test/bar.test.cpp"), "ignored")
        self.assertEqual([json.loads(x)["status"] for x in filename.read_text().splitlines()],
                         ["failed", "ignored"])

    def test_instrumented_verifier_uses_existing_upstream_verification(self):
        file = self.root / "trace.jsonl"
        package = types.ModuleType("onlinejudge_verify")
        package.__path__ = []
        module_main = types.ModuleType("onlinejudge_verify.main")
        module_verify = types.ModuleType("onlinejudge_verify.verify")
        observed = []

        def fake_verify_file(path, **kwargs):
            observed.append((str(path), kwargs))
            if path.name == "a.test.cpp": return False
            if path.name == "b.test.cpp": return True
            return None

        def fake_main(args):
            for name in ("a.test.cpp", "b.test.cpp", "c.test.cpp"):
                module_verify.verify_file(pathlib.Path(name), jobs=2)
            self.assertEqual(args, ["run", "-j", "2"])

        module_verify.verify_file = fake_verify_file
        module_main.main = fake_main
        package.main = module_main
        package.verify = module_verify
        with mock.patch.dict(sys.modules, {
            "onlinejudge_verify": package, "onlinejudge_verify.main": module_main,
            "onlinejudge_verify.verify": module_verify,
        }), mock.patch.dict(os.environ, {"VERIFY_TRACE_FILE": str(file)}), \
             mock.patch.object(sys, "argv", ["verify_trace.py", "run", "-j", "2"]):
            tracer.main()
        self.assertEqual(len(observed), 3)
        states = [json.loads(line)["status"] for line in file.read_text().splitlines()]
        self.assertEqual(states, ["failed", "ac", "ignored"])


if __name__ == "__main__":
    unittest.main()
