"""Regression for docs rewriting the checkout before continuation state upload."""
import copy
import pathlib
import subprocess
import sys
import tempfile
import unittest
import yaml

WORKFLOW = pathlib.Path(__file__).resolve().parents[1] / "workflows/verify.yml"


def validate_layout(workflow):
    jobs = workflow["jobs"]
    finalize = jobs["finalize"]
    steps = finalize["steps"]
    assert not any("oj-verify docs" in s.get("run", "") or "publish_verify_docs.py" in s.get("run", "") for s in steps)
    upload = next(i for i, s in enumerate(steps) if s.get("id") == "state")
    commit = next(i for i, s in enumerate(steps) if s.get("id") == "commit")
    dispatch = next(i for i, s in enumerate(steps) if "continue_verify.py dispatch" in s.get("run", ""))
    verdict = next(i for i, s in enumerate(steps) if "continue_verify.py assert-final" in s.get("run", ""))
    assert commit < upload < dispatch < verdict
    assert steps[upload]["with"]["if-no-files-found"] == "error"
    assert steps[upload]["with"]["include-hidden-files"] == "true"
    assert finalize["outputs"]["state_saved"] == "${{ steps.state.outcome == 'success' }}"
    assert finalize["outputs"]["verified_sha"] == "${{ steps.commit.outputs.sha }}"
    assert 'echo "sha=$(git rev-parse HEAD)" >> "$GITHUB_OUTPUT"' in steps[commit]["run"]
    docs = jobs["documentation"]
    assert docs["needs"] == "finalize"
    assert docs["if"] == "always() && needs.finalize.outputs.state_saved == 'true' && github.ref == format('refs/heads/{0}', github.event.repository.default_branch)"
    checkout = next(s for s in docs["steps"] if s.get("uses", "").startswith("actions/checkout@"))
    assert checkout["with"]["ref"] == "${{ needs.finalize.outputs.verified_sha }}"
    publish = next(s for s in docs["steps"] if "publish_verify_docs.py" in s.get("run", ""))
    assert publish["env"]["DEFAULT_BRANCH"] == "${{ github.event.repository.default_branch }}"
    assert publish["env"]["VERIFIED_SHA"] == "${{ needs.finalize.outputs.verified_sha }}"
    assert publish["env"]["GH_PAT"] == "${{ secrets.GH_PAT }}"


class DocumentationIsolationTests(unittest.TestCase):
    def setUp(self):
        self.workflow = yaml.load(WORKFLOW.read_text(encoding="utf-8"), Loader=yaml.BaseLoader)

    def test_workflow_isolates_docs_and_preserves_commit_state_dispatch_verdict_order(self):
        validate_layout(self.workflow)

    def test_reject_original_docs_before_upload_bug(self):
        broken = copy.deepcopy(self.workflow)
        steps = broken["jobs"]["finalize"]["steps"]
        index = next(i for i,s in enumerate(steps) if s.get("id") == "state")
        steps.insert(index, {"run": 'oj-verify docs -j "$VERIFY_JOBS"'})
        with self.assertRaises(AssertionError):
            validate_layout(broken)

    def test_reject_docs_using_mutable_branch(self):
        broken = copy.deepcopy(self.workflow)
        broken["jobs"]["documentation"]["steps"][0]["with"]["ref"] = "main"
        with self.assertRaises(AssertionError):
            validate_layout(broken)

    def test_reject_docs_skipped_on_expected_failed_verdict(self):
        broken = copy.deepcopy(self.workflow)
        broken["jobs"]["documentation"]["if"] = "success()"
        with self.assertRaises(AssertionError):
            validate_layout(broken)

    def test_docs_checkout_rewrite_cannot_destroy_finalizer_state_or_scripts(self):
        with tempfile.TemporaryDirectory() as temp:
            root = pathlib.Path(temp)
            final = root / "finalize"
            docs = root / "documentation"
            for checkout in (final, docs):
                (checkout / ".verify-helper").mkdir(parents=True)
                (checkout / ".github/scripts").mkdir(parents=True)
                (checkout / ".verify-helper/verification-state.json").write_text('{"retry_target":"all"}')
                (checkout / ".github/scripts/continue_verify.py").write_text("print('continuation intact')")
            # Emulate the destructive side effect seen in the real docs logs.
            program = "import pathlib,shutil; shutil.rmtree('.verify-helper'); shutil.rmtree('.github'); pathlib.Path('index.html').write_text('docs')"
            subprocess.run([sys.executable, "-c", program], cwd=docs, check=True)
            self.assertFalse((docs / ".verify-helper/verification-state.json").exists())
            self.assertEqual((final / ".verify-helper/verification-state.json").read_text(), '{"retry_target":"all"}')
            result = subprocess.run([sys.executable, ".github/scripts/continue_verify.py"],
                                    cwd=final, check=True, text=True, capture_output=True)
            self.assertIn("continuation intact", result.stdout)


if __name__ == "__main__":
    unittest.main()
