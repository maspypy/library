---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: seq/maxplus_convolution_concave.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n#include \"other/io.hpp\"\n#include \"random/base.hpp\"\n\n#include \"seq/maxplus_convolution_concave.hpp\"\
    \n\nconst int INF = numeric_limits<int>::max();\n\nvc<int> gen(int L, int N, int\
    \ R) {\n  vc<int> A(N);\n  FOR(i, N) A[i] = RNG(-100, 100);\n  sort(all(A));\n\
    \  reverse(all(A));\n  A = cumsum<int>(A);\n  FOR(L) A.insert(A.begin(), -INF);\n\
    \  FOR(R) A.insert(A.end(), -INF);\n  return A;\n}\n\nvc<int> naive(vc<int> A,\
    \ vc<int> B) {\n  int N = len(A), M = len(B);\n  vc<int> C(N + M - 1, -INF);\n\
    \  FOR(i, N) FOR(j, M) {\n    if (A[i] == -INF || B[j] == -INF) continue;\n  \
    \  chmax(C[i + j], A[i] + B[j]);\n  }\n  return C;\n}\n\nvoid test() {\n  FOR(a1,\
    \ 5) FOR(b1, 10) FOR(c1, 5) {\n    vc<int> A = gen(a1, b1, c1);\n    FOR(a2, 5)\
    \ FOR(b2, 10) FOR(c2, 5) {\n      vc<int> B = gen(a2, b2, c2);\n      assert(naive(A,\
    \ B) == maxplus_convolution_concave<int>(A, B, INF));\n    }\n  }\n}\n\nvoid solve()\
    \ {\n  LL(a, b);\n  print(a + b);\n}\n\nsigned main() {\n  cout << fixed << setprecision(15);\n\
    \n  test();\n  solve();\n\n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/mytest/maxplus_concave.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/mytest/maxplus_concave.test.cpp
layout: document
redirect_from:
- /verify/test/mytest/maxplus_concave.test.cpp
- /verify/test/mytest/maxplus_concave.test.cpp.html
title: test/mytest/maxplus_concave.test.cpp
---
