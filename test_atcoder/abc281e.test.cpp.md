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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ds/my_multiset.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc281/tasks/abc281_e\"\n#include\
    \ \"my_template.hpp\"\n#include \"other/io.hpp\"\n\n#include \"ds/my_multiset.hpp\"\
    \n\nvoid solve() {\n  LL(N, M, K);\n  My_Multiset<int, ll> X;\n  VEC(ll, A, N);\n\
    \  FOR(i, M) X.insert(A[i]);\n  vi ANS;\n  FOR(i, M, N + 1) {\n    ANS.eb(X.get_kth(K).se);\n\
    \    if (i == N) break;\n    X.insert(A[i]), X.erase(A[i - M]);\n  }\n  print(ANS);\n\
    }\n\nsigned main() {\n  solve();\n  return 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: test_atcoder/abc281e.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test_atcoder/abc281e.test.cpp
layout: document
redirect_from:
- /verify/test_atcoder/abc281e.test.cpp
- /verify/test_atcoder/abc281e.test.cpp.html
title: test_atcoder/abc281e.test.cpp
---
