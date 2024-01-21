---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: linalg/implicit_matrix/pascal.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc285/tasks/abc285_Ex\"\n\n\
    #include \"my_template.hpp\"\n#include \"other/io.hpp\"\n\n#include \"mod/modint.hpp\"\
    \n#include \"poly/fps_pow.hpp\"\n#include \"linalg/implicit_matrix/pascal.hpp\"\
    \n\nusing mint = modint107;\n\nvoid solve() {\n  LL(N, K);\n  VEC(int, A, K);\n\
    \  vc<mint> f = {1, -1};\n  ll LIM = MAX(A);\n  f.resize(LIM + 1);\n  f = fps_pow_1<mint>(f,\
    \ -N);\n  vc<mint> dp(N + 1);\n  FOR(k, N + 1) {\n    mint x = 1;\n    FOR(i,\
    \ K) x *= f[A[i]];\n    dp[k] = x;\n    FOR(i, len(f) - 1) f[i + 1] -= f[i];\n\
    \  }\n  FOR(i, N + 1) dp[i] *= C<mint>(N, i);\n  dp = pascal<mint>(dp, true, true);\n\
    \  print(dp[0]);\n}\n\nsigned main() {\n  solve();\n  return 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: test_atcoder/abc285h.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test_atcoder/abc285h.test.cpp
layout: document
redirect_from:
- /verify/test_atcoder/abc285h.test.cpp
- /verify/test_atcoder/abc285h.test.cpp.html
title: test_atcoder/abc285h.test.cpp
---