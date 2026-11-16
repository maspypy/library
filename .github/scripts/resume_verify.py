"""Schedule-side reader and duplicate-run guard. No waiting on runners."""
import io
import json
import os
import pathlib
import types
import urllib.request
from urllib.parse import quote
import zipfile


def api(path, binary=False):
    base = os.environ.get("GITHUB_API_URL", "https://api.github.com").rstrip("/")
    req = urllib.request.Request(
        f"{base}/repos/{os.environ['GITHUB_REPOSITORY']}/{path}",
        headers={"Accept": "application/vnd.github+json"})
    # Artifact downloads redirect to signed storage URLs. Do not forward
    # the repository token to the redirect host.
    req.add_unredirected_header("Authorization", f"Bearer {os.environ['GITHUB_TOKEN']}")
    with urllib.request.urlopen(req, timeout=30) as response:
        raw = response.read()
    return raw if binary else json.loads(raw)


def runs():
    branch = quote(os.environ["GITHUB_REF_NAME"], safe="")
    return sorted(api(f"actions/workflows/verify.yml/runs?branch={branch}&per_page=100")[
        "workflow_runs"], key=lambda r: r["run_number"], reverse=True)


def check_predecessor(previous, current=0):
    history = runs()
    if current:
        here = next((r for r in history if r["id"] == current), None)
        if here is None or here.get("run_attempt", 1) != 1:
            raise ValueError("missing current run or manual rerun")
        history = [r for r in history if r["run_number"] < here["run_number"]]
    if not history or history[0]["id"] != previous or history[0].get("run_attempt", 1) != 1:
        raise ValueError("conflicting run or duplicate continuation")


def main():
    from continue_verify import dispatch, validate_state
    history = runs()
    if not history:
        return
    run = history[0]
    if (run["status"] != "completed" or run.get("run_attempt", 1) != 1 or
            run.get("conclusion") not in ("success", "failure")):
        return
    artifacts = api(f"actions/runs/{run['id']}/artifacts?per_page=100")["artifacts"]
    candidates = [a for a in artifacts if a["name"] == "verify-continuation-state" and not a["expired"]]
    if len(candidates) != 1:
        return
    raw = api(f"actions/artifacts/{candidates[0]['id']}/zip", binary=True)
    with zipfile.ZipFile(io.BytesIO(raw)) as archive:
        member = archive.getinfo("verification-state.json")
        if member.file_size > 10_000_000:
            raise ValueError("oversized state artifact")
        state = json.loads(archive.read(member))
    validate_state(state, origin=state["origin_sha"], round_number=state["round"],
                   previous_run_id=run["id"])
    path = pathlib.Path(".verify-helper/resume-state.json")
    path.parent.mkdir(exist_ok=True)
    path.write_text(json.dumps(state), encoding="utf-8")
    dispatch(types.SimpleNamespace(state=path, branch=os.environ["GITHUB_REF_NAME"]))


if __name__ == "__main__":
    main()
