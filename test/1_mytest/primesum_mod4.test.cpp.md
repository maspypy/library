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
    \  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: nt/primetable.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n#include \"other/io.hpp\"\n#include \"nt/primesum_mod4.hpp\"\n\nvoid test_count()\
    \ {\n  ll LIM = 10000;\n  vc<int> A1(LIM), A3(LIM);\n  for (auto&& p: primetable(LIM))\n\
    \    if (p % 4 == 1) { A1[p]++; }\n  for (auto&& p: primetable(LIM))\n    if (p\
    \ % 4 == 3) { A3[p]++; }\n  A1 = cumsum<int>(A1, 0);\n  A3 = cumsum<int>(A3, 0);\n\
    \n  FOR(N, LIM) {\n    PrimeSum_Mod_4<int> X(N);\n    X.calc_count();\n    FOR(K,\
    \ 1, N + 10) { assert(X[N / K] == mp(A1[N / K], A3[N / K])); }\n  }\n}\n\nvoid\
    \ test_sum() {\n  ll LIM = 10000;\n  vc<int> A1(LIM), A3(LIM);\n  for (auto&&\
    \ p: primetable(LIM))\n    if (p % 4 == 1) { A1[p] += p; }\n  for (auto&& p: primetable(LIM))\n\
    \    if (p % 4 == 3) { A3[p] += p; }\n  A1 = cumsum<int>(A1, 0);\n  A3 = cumsum<int>(A3,\
    \ 0);\n\n  FOR(N, LIM) {\n    PrimeSum_Mod_4<int> X(N);\n    X.calc_sum();\n \
    \   FOR(K, 1, N + 10) { assert(X[N / K] == mp(A1[N / K], A3[N / K])); }\n  }\n\
    }\n\nvoid solve() {\n  int a, b;\n  cin >> a >> b;\n  cout << a + b << \"\\n\"\
    ;\n}\n\nsigned main() {\n  test_count();\n  test_sum();\n  solve();\n\n  return\
    \ 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/1_mytest/primesum_mod4.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/1_mytest/primesum_mod4.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/primesum_mod4.test.cpp
- /verify/test/1_mytest/primesum_mod4.test.cpp.html
title: test/1_mytest/primesum_mod4.test.cpp
---
