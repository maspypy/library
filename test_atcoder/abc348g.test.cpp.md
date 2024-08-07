---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: convex/maxplus_convolution.hpp
    title: convex/maxplus_convolution.hpp
  - icon: ':question:'
    path: convex/monotone_minima.hpp
    title: convex/monotone_minima.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':question:'
    path: other/io.hpp
    title: other/io.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc348/tasks/abc348_g
    links:
    - https://atcoder.jp/contests/abc348/tasks/abc348_g
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 289, in update\n    uncommented_lines = get_uncommented_code(path, iquotes=self.iquotes,\
    \ compiler=self.compiler).splitlines(keepends=True)\n                        ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 195, in get_uncommented_code\n    code = _get_uncommented_code(path.resolve(),\
    \ iquotes_options=tuple(iquotes_options), compiler=compiler)\n           ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 188, in _get_uncommented_code\n    return subprocess.check_output(command)\n\
    \           ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/subprocess.py\"\
    , line 466, in check_output\n    return run(*popenargs, stdout=PIPE, timeout=timeout,\
    \ check=True,\n           ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/subprocess.py\"\
    , line 571, in run\n    raise CalledProcessError(retcode, process.args,\nsubprocess.CalledProcessError:\
    \ Command '['g++', '-x', 'c++', '-I', '/home/runner/work/library/library', '-fpreprocessed',\
    \ '-dD', '-E', '/home/runner/work/library/library/other/io.hpp']' returned non-zero\
    \ exit status 1.\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc348/tasks/abc348_g\"\n#include\
    \ \"my_template.hpp\"\n#include \"other/io.hpp\"\n\n#include \"convex/maxplus_convolution.hpp\"\
    \n\nvoid solve() {\n  LL(N);\n  vi A(N), B(N);\n  FOR(i, N) read(A[i], B[i]);\n\
    \n  auto I = argsort(B);\n  A = rearrange(A, I);\n  B = rearrange(B, I);\n\n \
    \ auto dfs = [&](auto &dfs, int L, int R) -> pair<vi, vi> {\n    if (R == L +\
    \ 1) {\n      vi X = {0, A[L]};\n      vi Y = {-infty<ll>, A[L] - B[L]};\n   \
    \   return {X, Y};\n    }\n    int M = (L + R) / 2;\n    auto [X1, Y1] = dfs(dfs,\
    \ L, M);\n    auto [X2, Y2] = dfs(dfs, M, R);\n\n    ll n = R - L;\n    vi X(n\
    \ + 1, -infty<ll>);\n    vi Y(n + 1, -infty<ll>);\n    // \u53F3\u5074\u304C\u7A7A\
    \n    FOR(i, len(X1)) chmax(X[i], X1[i]);\n    FOR(i, len(Y1)) chmax(Y[i], Y1[i]);\n\
    \n    vi P = maxplus_convolution<ll, true, true>(X1, X2);\n    vi Q = maxplus_convolution<ll,\
    \ true, false>(X1, Y2);\n    FOR(i, len(P)) chmax(X[i], P[i]);\n    FOR(i, len(Q))\
    \ chmax(Y[i], Q[i]);\n    // vi R = maxplus_convolution<ll, true, true>(Y1, X2);\n\
    \    return {X, Y};\n  };\n\n  auto [X, Y] = dfs(dfs, 0, N);\n  FOR(i, 1, N +\
    \ 1) print(Y[i]);\n}\n\nsigned main() {\n  int T = 1;\n  // INT(T);\n  FOR(T)\
    \ solve();\n  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - convex/maxplus_convolution.hpp
  - convex/monotone_minima.hpp
  isVerificationFile: true
  path: test_atcoder/abc348g.test.cpp
  requiredBy: []
  timestamp: '2024-08-07 16:19:15+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test_atcoder/abc348g.test.cpp
layout: document
redirect_from:
- /verify/test_atcoder/abc348g.test.cpp
- /verify/test_atcoder/abc348g.test.cpp.html
title: test_atcoder/abc348g.test.cpp
---
