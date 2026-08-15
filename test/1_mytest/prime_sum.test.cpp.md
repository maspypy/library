---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: nt/primetable.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n\n#include \"nt/primesum.hpp\"\n#include \"nt/primetable.hpp\"\n#include \"\
    mod/modint.hpp\"\n\nvoid test_count() {\n  vc<int> A(1000);\n  for (auto&& p:\
    \ primetable(1000)) { A[p]++; }\n  A = cumsum<int>(A, 0);\n\n  FOR(N, 1000) {\n\
    \    PrimeSum<int> X(N);\n    X.calc_count();\n    FOR(K, 1, N + 10) { assert(X[N\
    \ / K] == A[N / K]); }\n  }\n\n  vc<ll> TEN(13);\n  TEN[0] = 1;\n  FOR(i, 12)\
    \ TEN[i + 1] = TEN[i] * 10;\n\n  ll N = TEN[12];\n  PrimeSum<ll> X(N);\n  X.calc_count();\n\
    \  assert(X[TEN[0]] == 0);\n  assert(X[TEN[1]] == 4);\n  assert(X[TEN[2]] == 25);\n\
    \  assert(X[TEN[3]] == 168);\n  assert(X[TEN[4]] == 1229);\n  assert(X[TEN[5]]\
    \ == 9592);\n  assert(X[TEN[6]] == 78498);\n  assert(X[TEN[7]] == 664579);\n \
    \ assert(X[TEN[8]] == 5761455);\n  assert(X[TEN[9]] == 50847534);\n  assert(X[TEN[10]]\
    \ == 455052511);\n  assert(X[TEN[11]] == 4118054813);\n  assert(X[TEN[12]] ==\
    \ 37607912018);\n}\n\nvoid test_sum() {\n  vc<int> A(1000);\n  for (auto&& p:\
    \ primetable(1000)) { A[p] += p; }\n  A = cumsum<int>(A, 0);\n\n  FOR(N, 1000)\
    \ {\n    PrimeSum<int> X(N);\n    X.calc_sum();\n    FOR(K, 1, N + 10) { assert(X[N\
    \ / K] == A[N / K]); }\n  }\n\n  vc<ll> TEN(13);\n  TEN[0] = 1;\n  FOR(i, 12)\
    \ TEN[i + 1] = TEN[i] * 10;\n\n  using mint = modint998;\n  ll N = TEN[12];\n\
    \  PrimeSum<mint> X(N);\n  X.calc_sum();\n\n  auto f = [&](string S) -> mint {\n\
    \    mint x = 0;\n    for (auto&& s: S) { x = x * mint(10) + mint(s - '0'); }\n\
    \    return x;\n  };\n\n  assert(X[TEN[0]] == f(\"0\"));\n  assert(X[TEN[1]] ==\
    \ f(\"17\"));\n  assert(X[TEN[2]] == f(\"1060\"));\n  assert(X[TEN[3]] == f(\"\
    76127\"));\n  assert(X[TEN[4]] == f(\"5736396\"));\n  assert(X[TEN[5]] == f(\"\
    454396537\"));\n  assert(X[TEN[6]] == f(\"37550402023\"));\n  assert(X[TEN[7]]\
    \ == f(\"3203324994356\"));\n  assert(X[TEN[8]] == f(\"279209790387276\"));\n\
    \  assert(X[TEN[9]] == f(\"24739512092254535\"));\n  assert(X[TEN[10]] == f(\"\
    2220822432581729238\"));\n  assert(X[TEN[11]] == f(\"201467077743744681014\"));\n\
    \  assert(X[TEN[12]] == f(\"18435588552550705911377\"));\n}\n\nvoid solve() {\n\
    \  int a, b;\n  cin >> a >> b;\n  cout << a + b << \"\\n\";\n}\n\nsigned main()\
    \ {\n  cout << fixed << setprecision(15);\n\n  test_count();\n  test_sum();\n\
    \  solve();\n\n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/1_mytest/prime_sum.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/1_mytest/prime_sum.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/prime_sum.test.cpp
- /verify/test/1_mytest/prime_sum.test.cpp.html
title: test/1_mytest/prime_sum.test.cpp
---
