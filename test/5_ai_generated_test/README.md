# AI-generated standalone regression tests

Place standalone C++17 programs as `*.test.cpp` in this directory or its
subdirectories. Each program must have `int main()` (or `signed main()`),
perform its own assertions, read no standard input, and exit 0 on success.

CI runs every matching file on push, pull_request, and manual dispatch. An
uncaught exception, failed assertion, nonzero exit, compilation failure, or
per-test timeout fails the workflow. Tests use `-std=c++17 -O2 -Wall -g -mavx2
-mpopcnt -I.` without `-DNDEBUG`. The per-test timeout defaults to 120 seconds.

Local run from the library repository root:

    bash .github/scripts/run_ai_generated_tests.sh

Use deterministic random seeds. This test suite is separate from the existing
`test/**/*.test.cpp` online-judge-verify-helper pipeline.
