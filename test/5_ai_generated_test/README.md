# AI-generated standalone regression tests

Place standalone C++17 programs as `*.test.cpp` in this directory or its
subdirectories. Each program must have `int main()` (or `signed main()`),
perform its own assertions, read no standard input, and exit 0 on success.

The main `verify` workflow runs these tests on push and manual dispatch, using
its configured expanded and shrunk C++17 compiler environments. Each binary
runs once with no input; no `PROBLEM` URL or online judge is needed. Assertions
are enabled. A compile error, nonzero exit, or timeout fails verification.
Compilation and execution each default to 120 seconds per environment
(`AI_TEST_COMPILE_TIMEOUT` and `AI_TEST_TIMEOUT`, in positive integer seconds).
The normal dependency timestamps, continuation, and documentation generation
apply. Fork pull requests retain the read-only standalone fallback.

Local run from the library repository root:

    bash .github/scripts/run_ai_generated_tests.sh

Use deterministic random seeds. The local command uses the original standalone
compiler path; CI additionally checks both configured submission pipelines.
