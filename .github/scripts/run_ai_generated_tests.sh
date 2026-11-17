#!/usr/bin/env bash
# Standalone assert-based tests, not oj-verify-helper problems.
# Run from the repository root: bash .github/scripts/run_ai_generated_tests.sh
set -euo pipefail

TEST_ROOT="${1:-test/5_ai_generated_test}"
CXX="${CXX:-g++}"
TEST_TIMEOUT="${AI_TEST_TIMEOUT:-120}"

if [[ ! -d "$TEST_ROOT" ]]; then
  echo "::error::Test directory missing: $TEST_ROOT" >&2
  exit 1
fi

mapfile -d '' -t tests < <(find "$TEST_ROOT" -type f -name '*.test.cpp' -print0 | sort -z)
if (( ${#tests[@]} == 0 )); then
  echo "::error::No *.test.cpp found under $TEST_ROOT" >&2
  exit 1
fi

work_dir="$(mktemp -d "${TMPDIR:-/tmp}/maspy-ai-tests.XXXXXX")"
trap 'rm -rf -- "$work_dir"' EXIT

fails=0
index=0
for source in "${tests[@]}"; do
  exe="$work_dir/test-$index"
  echo "::group::${source}"
  echo "[compile] $source"
  if "$CXX" -std=c++17 -O2 -Wall -g -mavx2 -mpopcnt -I. "$source" -o "$exe"; then
    echo "[run] $source (timeout: ${TEST_TIMEOUT}s)"
    if timeout --kill-after=5s "${TEST_TIMEOUT}s" "$exe" < /dev/null; then
      echo "[PASS] $source"
    else
      code=$?
      echo "::error file=${source}::Test exited with code ${code}" >&2
      fails=$((fails + 1))
    fi
  else
    code=$?
    echo "::error file=${source}::Compilation failed with code ${code}" >&2
    fails=$((fails + 1))
  fi
  echo "::endgroup::"
  index=$((index + 1))
done

echo "AI-generated tests: $((index - fails))/$index passed"
if (( fails > 0 )); then
  exit 1
fi
