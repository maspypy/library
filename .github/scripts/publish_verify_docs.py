"""Publish verified docs on push and workflow_dispatch, on an isolated runner."""
import argparse
import logging
import os
import pathlib
import subprocess


def publish(jobs: int) -> None:
    if jobs <= 0:
        raise ValueError("jobs must be positive")
    if os.environ.get("GITHUB_EVENT_NAME") not in ("push", "workflow_dispatch"):
        raise ValueError("unsupported documentation event")
    branch = os.environ.get("DEFAULT_BRANCH")
    if not branch or os.environ.get("GITHUB_REF") != f"refs/heads/{branch}":
        raise ValueError("documentation can only be published from the default branch")
    # The helper silently skips publishing without GH_PAT. Fail explicitly:
    # a GITHUB_TOKEN push alone does not trigger the Pages branch build.
    if not os.environ.get("GH_PAT"):
        raise ValueError("GH_PAT is required to trigger the GitHub Pages build")
    verified_sha = os.environ.get("VERIFIED_SHA")
    head = subprocess.check_output(["git", "rev-parse", "HEAD"], text=True).strip()
    if not verified_sha or head != verified_sha:
        raise ValueError("checkout does not match the finalized verification commit")

    import onlinejudge_verify.config as config
    import onlinejudge_verify.documentation.main as documentation
    import onlinejudge_verify.main as helper
    import onlinejudge_verify.marker as marker

    config.set_config_path(pathlib.Path(config.default_config_path))
    marker.get_verification_marker(jobs=jobs)
    helper.generate_gitignore()
    # Do not use the CLI's push-only gate or its checkout of the mutable branch.
    # Keep the verified checkout until generation finishes, then publish via PAT.
    os.environ["GITHUB_SHA"] = verified_sha
    documentation.main(jobs=jobs)
    helper.push_documents_to_gh_pages(src_dir=pathlib.Path(".verify-helper/markdown"))


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("-j", "--jobs", type=int, default=1)
    args = parser.parse_args()
    logging.basicConfig(level=logging.INFO)
    publish(args.jobs)
