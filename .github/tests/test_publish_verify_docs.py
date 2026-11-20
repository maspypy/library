"""Exercise the real helper's publication entry point without network writes."""
import contextlib
import importlib.util
import os
import pathlib
import tempfile
import unittest
from unittest import mock

import onlinejudge_verify.config as config
import onlinejudge_verify.documentation.main as documentation
import onlinejudge_verify.main as helper
import onlinejudge_verify.marker as marker

SCRIPT = pathlib.Path(__file__).resolve().parents[1] / "scripts/publish_verify_docs.py"
spec = importlib.util.spec_from_file_location("publish_verify_docs_test", SCRIPT)
publisher = importlib.util.module_from_spec(spec)
spec.loader.exec_module(publisher)
SHA = "a" * 40


class PublishDocsTests(unittest.TestCase):
    def setUp(self):
        self.stack = contextlib.ExitStack()
        self.addCleanup(self.stack.close)
        self.stack.enter_context(mock.patch.dict(os.environ, {
            "GITHUB_ACTION": "test", "GITHUB_EVENT_NAME": "workflow_dispatch",
            "DEFAULT_BRANCH": "main", "GITHUB_REF": "refs/heads/main",
            "VERIFIED_SHA": SHA, "GITHUB_SHA": "b" * 40,
            "GITHUB_TOKEN": "test-token", "GH_PAT": "test-pat",
        }, clear=True))
        self.stack.enter_context(mock.patch.object(publisher.subprocess, "check_output", return_value=SHA + "\n"))
        self.stack.enter_context(mock.patch.object(config, "set_config_path"))
        self.stack.enter_context(mock.patch.object(marker, "get_verification_marker"))
        self.stack.enter_context(mock.patch.object(helper, "generate_gitignore"))
        self.generate = self.stack.enter_context(mock.patch.object(documentation, "main"))
        self.push = self.stack.enter_context(mock.patch.object(helper, "push_documents_to_gh_pages"))

    def test_push_and_dispatch_both_publish_generated_docs(self):
        for event in ("push", "workflow_dispatch"):
            with self.subTest(event=event), tempfile.TemporaryDirectory() as tmp:
                with mock.patch.dict(os.environ, {"GITHUB_EVENT_NAME": event}):
                    artifact = pathlib.Path(tmp) / "generated"
                    self.generate.side_effect = lambda **kw: artifact.write_text(SHA)
                    def publish(**kw):
                        self.assertEqual(artifact.read_text(), SHA)
                        self.assertEqual(kw["src_dir"], pathlib.Path(".verify-helper/markdown"))
                        self.assertEqual(os.environ["GITHUB_SHA"], SHA)
                        self.assertEqual(os.environ["GITHUB_EVENT_NAME"], event)
                    self.push.side_effect = publish
                    publisher.publish(2)
                    self.generate.assert_called_once_with(jobs=2)
                    self.push.assert_called_once()
                    self.generate.reset_mock()
                    self.push.reset_mock()

    def test_original_helper_skips_dispatch(self):
        helper.subcommand_docs(jobs=2)
        self.generate.assert_not_called()
        self.push.assert_not_called()

    def test_untrusted_contexts_and_missing_pat_fail_before_generation(self):
        for override in ({"GITHUB_EVENT_NAME": "pull_request"},
                         {"GITHUB_REF": "refs/heads/feature"},
                         {"DEFAULT_BRANCH": ""}, {"GH_PAT": ""},
                         {"VERIFIED_SHA": "c" * 40}):
            with self.subTest(override=override), mock.patch.dict(os.environ, override):
                with self.assertRaises(ValueError):
                    publisher.publish(2)
                self.generate.assert_not_called()
                self.push.assert_not_called()

    def test_generation_failure_does_not_publish(self):
        self.generate.side_effect = RuntimeError("generation failed")
        with self.assertRaisesRegex(RuntimeError, "generation failed"):
            publisher.publish(2)
        self.push.assert_not_called()

    def test_push_failure_is_not_reported_as_success(self):
        self.push.side_effect = RuntimeError("push failed")
        with self.assertRaisesRegex(RuntimeError, "push failed"):
            publisher.publish(2)


if __name__ == "__main__":
    unittest.main()
