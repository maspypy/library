---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: dp/longest_increasing_subsequence.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/longest_increasing_subsequence\"\
    \n#include \"my_template.hpp\"\n#include \"other/io.hpp\"\n\n#include \"dp/longest_increasing_subsequence.hpp\"\
    \n\nvoid solve() {\n  LL(N);\n  VEC(int, A, N);\n  auto dp = longest_increasing_subsequence(A);\n\
    \  ll n = MAX(dp);\n  ll x = MAX(A) + 1;\n  vc<int> I;\n  FOR_R(i, N) {\n    if\
    \ (dp[i] == n && A[i] < x) {\n      I.eb(i);\n      --n;\n      x = A[i];\n  \
    \  }\n  }\n  reverse(all(I));\n  print(len(I));\n  print(I);\n}\n\nsigned main()\
    \ {\n  cout << fixed << setprecision(15);\n\n  ll T = 1;\n  // LL(T);\n  FOR(T)\
    \ solve();\n\n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/library_checker/math/longest_increasing_subsequence.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/math/longest_increasing_subsequence.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/math/longest_increasing_subsequence.test.cpp
- /verify/test/library_checker/math/longest_increasing_subsequence.test.cpp.html
title: test/library_checker/math/longest_increasing_subsequence.test.cpp
---
