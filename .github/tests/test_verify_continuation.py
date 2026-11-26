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
                 run_id=10, retry_target="all", blocked=None):
        self.make_test_sources(statuses)
        return self.put_json("previous.json", {
            "schema": 2, "origin_sha": ORIGIN, "run_id": run_id,
            "round": round_number, "statuses": statuses,
            "blocked": blocked or {"all": False},
            "retry_target": retry_target, "last_429": 1000 if "rate_limited" in statuses.values() else 0,
            "not_before": 5200 if "rate_limited" in statuses.values() and "pending" not in statuses.values() else 0,
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
            "attempted_files": attempts, "last_429": 1000 if rate else 0,
        })
        self.put_json(f"artifacts/states-{group}-{shard}.json", {
            "group": group, "shard": shard, "statuses": statuses,
        })
        self.put_json(f"artifacts/timestamps-{group}-{shard}.json", {})

    def artifact_round(self, statuses: dict[str, str], groups=("all",),
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



class Decisions(Fixture):
    def check(self, statuses, old=None, round_number=0, infra=False):
        previous = self.previous(old, round_number=round_number-1) if old else None
        self.artifact_round(statuses, attempted_groups=("all",),
                            blocked_groups=("all",) if "rate_limited" in statuses.values() else (),
                            infra_groups=("all",) if infra else ())
        return self.summarize(round_number=round_number, target="all",
                              previous=previous, previous_run_id=10 if old else 0)

    def test_standalone_paths_participate_in_continuation(self):
        statuses = {"test/a.test.cpp": "ac",
                    "test/5_ai_generated_test/a.test.cpp": "pending",
                    "test/5_ai_generated_test/b.test.cpp": "failed"}
        state = self.check(statuses)
        self.assertEqual(state["statuses"], statuses)
        updated = dict(statuses, **{"test/5_ai_generated_test/a.test.cpp": "ac"})
        state = self.check(updated, statuses, 1)
        self.assertEqual(state["statuses"], updated)
        self.assertEqual(state["retry_target"], "none")

    def test_missing_standalone_status_is_rejected(self):
        self.artifact_round({"test/a.test.cpp": "ac"})
        self.make_test_sources({"test/5_ai_generated_test/a.test.cpp": "pending"})
        with self.assertRaisesRegex(ValueError, "state does not cover all test sources"):
            self.summarize()

    def test_pending_immediate_failed_preserved(self):
        r = self.check({"test/a.test.cpp":"failed", "test/b.test.cpp":"pending"})
        self.assertEqual((r["retry_target"], r["not_before"]), ("all",0))

    def test_429_only_waits_70_minutes(self):
        r = self.check({"test/3_yukicoder/a.test.cpp":"rate_limited"})
        self.assertEqual((r["retry_target"], r["not_before"]), ("all",5200))

    def test_mixed_pending_does_not_wait(self):
        r = self.check({"test/a.test.cpp":"pending", "test/3_yukicoder/a.test.cpp":"rate_limited"})
        self.assertEqual((r["retry_target"],r["not_before"]),("all",0))

    def test_no_progress_stops_including_repeated_429(self):
        for value in ("pending","rate_limited"):
            states={"test/a.test.cpp":value}
            self.assertEqual(self.check(states, states, 1)["retry_target"],"none")

    def test_progress_then_delayed(self):
        old={"test/a.test.cpp":"pending","test/b.test.cpp":"rate_limited"}
        r=self.check({**old,"test/a.test.cpp":"ac"},old,1)
        self.assertEqual((r["retry_target"],r["not_before"]),("all",5200))

    def test_cap_infrastructure_and_no_attempt_stop(self):
        old={"test/a.test.cpp":"pending","test/b.test.cpp":"pending"}
        self.assertEqual(self.check({**old,"test/a.test.cpp":"ac"},old,3)["retry_target"],"none")
        self.assertEqual(self.check(old,infra=True)["retry_target"],"none")
        self.assertEqual(self.check(old)["retry_target"],"none")

    def test_terminal_regression_rejected(self):
        with self.assertRaisesRegex(ValueError,"regressed"):
            self.check({"test/a.test.cpp":"pending"},{"test/a.test.cpp":"failed"},1)

    def test_missing_manifest_rejected(self):
        self.artifact_round({"test/a.test.cpp":"ac"})
        (self.root/"artifacts/complete-all-15.json").unlink()
        with self.assertRaises(FileNotFoundError):
            self.summarize()

    def test_wrong_identity_rejected(self):
        state=json.loads(self.previous({"test/a.test.cpp":"failed"}).read_text())
        with self.assertRaises(ValueError):
            cont.validate_state(state,origin=ORIGIN,round_number=0,previous_run_id=11)

    def test_rate_limited_is_not_success(self):
        path=self.previous({"test/a.test.cpp":"rate_limited"})
        with self.assertRaises(SystemExit):
            cont.assert_final(types.SimpleNamespace(state=path))

    def test_normal_push_rechecks_failure(self):
        args=types.SimpleNamespace(round=0,previous_state=None)
        self.assertEqual(runner.prior_failures(args,[pathlib.Path("test/a.test.cpp")]),{})

    def test_continuation_skip_failed_and_cooldown(self):
        states={"test/a.test.cpp":"failed","test/b.test.cpp":"rate_limited","test/c.test.cpp":"pending"}
        args=types.SimpleNamespace(round=1,previous_state=self.previous(states),
                                  origin_sha=ORIGIN,previous_run_id=10)
        with mock.patch.object(runner.time,"time",return_value=5199):
            self.assertEqual(set(runner.prior_failures(args,list(map(pathlib.Path,states)))),
                             {"test/a.test.cpp","test/b.test.cpp"})
        with mock.patch.object(runner.time,"time",return_value=5200):
            self.assertEqual(set(runner.prior_failures(args,list(map(pathlib.Path,states)))),{"test/a.test.cpp"})

class ScheduleTests(Fixture):
    def setUp(self):
        super().setUp()
        import resume_verify
        self.resume=resume_verify

    def test_duplicate_and_new_push_stop(self):
        history=[dict(id=12,run_number=12),dict(id=11,run_number=11),dict(id=10,run_number=10)]
        with mock.patch.object(self.resume,"runs",return_value=history):
            self.resume.check_predecessor(10,current=11)
            with self.assertRaises(ValueError):
                self.resume.check_predecessor(10,current=12)
            with self.assertRaises(ValueError):
                self.resume.check_predecessor(10)

    def test_manual_rerun_stops(self):
        with mock.patch.object(self.resume,"runs",return_value=[dict(id=10,run_number=10,run_attempt=2)]):
            with self.assertRaises(ValueError):
                self.resume.check_predecessor(10)

    def test_due_boundary_and_dispatch_payload(self):
        path=self.previous({"test/a.test.cpp":"rate_limited"})
        requests=[]
        class Response:
            status=204
            def __enter__(self): return self
            def __exit__(self,*args): pass
            def read(self): return json.dumps({"commit":{"sha":"b"*40}}).encode()
        def request(req,timeout):
            requests.append(req)
            return Response()
        args=types.SimpleNamespace(state=path,branch="main")
        with mock.patch.object(cont,"unchanged_sources",return_value=True), \
             mock.patch.object(self.resume,"check_predecessor"), \
             mock.patch.object(cont.subprocess,"check_output",return_value="b"*40), \
             mock.patch.object(cont.urllib.request,"urlopen",side_effect=request), \
             mock.patch.dict(os.environ,{"GITHUB_TOKEN":"test","GITHUB_REPOSITORY":"test/repo"}):
            with mock.patch.object(cont.time,"time",return_value=5199):
                cont.dispatch(args)
            self.assertEqual(requests,[])
            with mock.patch.object(cont.time,"time",return_value=5200):
                cont.dispatch(args)
            self.assertEqual(len(requests),2)
            payload=json.loads(requests[1].data)
            self.assertEqual(payload["inputs"]["round"],"1")
            self.assertEqual(payload["inputs"]["previous_run_id"],"10")

    def test_running_or_cancelled_run_not_resumed(self):
        for status,conclusion in (("in_progress",None),("completed","cancelled")):
            with mock.patch.object(self.resume,"runs",return_value=[dict(id=10,status=status,conclusion=conclusion)]), \
                 mock.patch.object(self.resume,"api") as api:
                self.resume.main()
                api.assert_not_called()
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
            self.assertIn(fa.as_posix(), command)
            self.assertIn(fb.as_posix(), command)
            self.assertIn(ac.as_posix(), command)
            trace = pathlib.Path(env["VERIFY_TRACE_FILE"])
            with trace.open("w") as stream:
                for p, state in [(fa, "failed"), (fb, "failed"), (ac, "ac")]:
                    stream.write(json.dumps({"path": p.as_posix(), "status": state}) + "\n")
            timestamp_path.write_text(json.dumps({ac.as_posix(): TS}) + "\n")
            return types.SimpleNamespace(returncode=1)

        def fake_verification_two(command, check, env):
            self.assertNotIn(fa.as_posix(), command)
            self.assertNotIn(fb.as_posix(), command)
            self.assertIn(newer.as_posix(), command)
            self.assertIn(latest.as_posix(), command)
            trace = pathlib.Path(env["VERIFY_TRACE_FILE"])
            trace.write_text(json.dumps({"path": newer.as_posix(), "status": "ac"}) + "\n")
            timestamp_path.write_text(json.dumps({ac.as_posix(): TS, newer.as_posix(): TS}) + "\n")
            return types.SimpleNamespace(returncode=0)

        def run(round_num, action):
            args = ["run_verify_shard.py", "--group", "all", "--shard", "4",
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
        first = json.loads((self.root / "artifacts/states-all-4.json").read_text())
        self.assertEqual(first["statuses"], {fa.as_posix(): "failed", fb.as_posix(): "failed",
                                             ac.as_posix(): "ac", newer.as_posix(): "pending",
                                             latest.as_posix(): "pending"})
        self.previous(first["statuses"])
        self.assertEqual(run(1, fake_verification_two), 1)
        second = json.loads((self.root / "artifacts/states-all-4.json").read_text())
        self.assertEqual(second["statuses"], {fa.as_posix(): "failed", fb.as_posix(): "failed",
                                              ac.as_posix(): "ac", newer.as_posix(): "ac",
                                              latest.as_posix(): "pending"})
        self.assertEqual(json.loads(timestamp_path.read_text()), {ac.as_posix(): TS, newer.as_posix(): TS})
        self.assertEqual(json.loads((self.root / "artifacts/complete-all-4.json").read_text())
                         ["attempted_files"], 1)

    def test_fresh_push_does_not_skip_known_failure(self):
        a = self.select_same_shard(1)[0]
        args = types.SimpleNamespace(round=0, previous_state=None, origin_sha="",
                                     previous_run_id=0)
        self.assertEqual(runner.prior_failures(args, [a]), {})



class ShardOutputGuardTests(Fixture):
    def check(self, result):
        args = cont.parser().parse_args([
            "check-shards", "--input-dir", str(self.root / "artifacts"),
            "--shards", "16", "--job-result", result,
        ])
        args.func(args)

    def test_no_shards_reports_job_result_and_all_missing_outputs(self):
        with self.assertRaisesRegex(RuntimeError, "verify_all result='failure'") as ctx:
            self.check("failure")
        self.assertIn("missing shard outputs (48)", str(ctx.exception))
        self.assertIn("complete-all-0.json", str(ctx.exception))
        self.assertIn("timestamps-all-15.json", str(ctx.exception))

    def test_complete_outputs_allow_success_and_test_failure(self):
        self.artifact_round({})
        self.check("success")
        self.check("failure")

    def test_partial_upload_is_rejected_even_if_jobs_succeeded(self):
        self.artifact_round({})
        (self.root / "artifacts/states-all-7.json").unlink()
        with self.assertRaisesRegex(RuntimeError, r"missing shard outputs \(1\): states-all-7.json"):
            self.check("success")

    def test_skipped_or_cancelled_jobs_cannot_publish_state(self):
        self.artifact_round({})
        for result in ("skipped", "cancelled", ""):
            with self.subTest(result=result), self.assertRaises(RuntimeError):
                self.check(result)


class SourceGuardTests(Fixture):
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



class TraceIsolationTests(Fixture):
    def test_429_does_not_mask_other_wa_or_block_other_ac(self):
        package=types.ModuleType("onlinejudge_verify")
        package.__path__=[]
        verifier=types.ModuleType("onlinejudge_verify.verify")
        cli=types.ModuleType("onlinejudge_verify.main")
        def verify(path,**kwargs):
            if path.name=="limited.test.cpp":
                pathlib.Path(os.environ["VERIFY_RATE_FILE"]).write_text("429")
                return False
            return path.name=="ok.test.cpp"
        verifier.verify_file=verify
        def main(args):
            for n in ("limited","wa","ok"):
                verifier.verify_file(pathlib.Path(f"test/{n}.test.cpp"))
        cli.main=main
        package.main=cli
        package.verify=verifier
        trace=self.root/"trace"
        with mock.patch.dict(sys.modules,{"onlinejudge_verify":package,
            "onlinejudge_verify.verify":verifier,"onlinejudge_verify.main":cli}), \
            mock.patch.dict(os.environ,{"VERIFY_TRACE_FILE":str(trace)}):
            tracer.main()
        self.assertEqual(list(runner.read_trace(trace).values()),["rate_limited","failed","ac"])

    def test_trace_exception_is_infrastructure_error(self):
        package=types.ModuleType("onlinejudge_verify")
        package.__path__=[]
        verifier=types.ModuleType("onlinejudge_verify.verify")
        cli=types.ModuleType("onlinejudge_verify.main")
        verifier.verify_file=mock.Mock(side_effect=RuntimeError("broken helper"))
        cli.main=lambda args: verifier.verify_file(pathlib.Path("test/a.test.cpp"))
        package.main=cli
        package.verify=verifier
        trace=self.root/"trace"
        with mock.patch.dict(sys.modules,{"onlinejudge_verify":package,
            "onlinejudge_verify.verify":verifier,"onlinejudge_verify.main":cli}), \
            mock.patch.dict(os.environ,{"VERIFY_TRACE_FILE":str(trace)}):
            with self.assertRaises(RuntimeError):
                tracer.main()
        self.assertEqual(runner.read_trace(trace),{"test/a.test.cpp":"error"})

class ArtifactResumeTests(Fixture):
    def test_schedule_reads_real_zip_and_dispatches(self):
        import resume_verify as resume
        import zipfile
        state=json.loads(self.previous({"test/a.test.cpp":"rate_limited"}).read_text())
        buffer=io.BytesIO()
        with zipfile.ZipFile(buffer,"w") as z:
            z.writestr("verification-state.json",json.dumps(state))
        with self.working_dir(), \
             mock.patch.object(resume,"runs",return_value=[dict(id=10,status="completed",conclusion="failure")]), \
             mock.patch.object(resume,"api",side_effect=[
                 {"artifacts":[{"id":5,"name":"verify-continuation-state","expired":False}]},buffer.getvalue()]), \
             mock.patch.dict(os.environ,{"GITHUB_REF_NAME":"main"}), \
             mock.patch("continue_verify.dispatch") as dispatch:
            resume.main()
            self.assertEqual(json.loads(dispatch.call_args.args[0].state.read_text()),state)

    def test_schedule_missing_artifact_does_not_dispatch(self):
        import resume_verify as resume
        with mock.patch.object(resume,"runs",return_value=[dict(id=10,status="completed",conclusion="failure")]), \
             mock.patch.object(resume,"api",return_value={"artifacts":[]}), \
             mock.patch("continue_verify.dispatch") as dispatch:
            resume.main()
            dispatch.assert_not_called()

if __name__ == "__main__":
    unittest.main()
