---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ds/query/range_mex_query.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n#include \"other/io.hpp\"\n#include \"random/base.hpp\"\n\n#include \"ds/query/range_mex_query.hpp\"\
    \n\npair<vc<int>, vc<pi>> gen(int N, int LIM, int Q) {\n  vc<int> A(N);\n  FOR(i,\
    \ N) { A[i] = RNG(0, LIM); }\n  vc<pi> query;\n  FOR(q, Q) {\n    int l = RNG(0,\
    \ N);\n    int r = RNG(l, N + 1);\n    query.eb(l, r);\n  }\n  return {A, query};\n\
    }\n\nvc<int> naive(vc<int> A, vc<pi> query, int begin) {\n  vc<int> ANS;\n  for\
    \ (auto&& [l, r]: query) {\n    int mex = begin;\n    while (1) {\n      bool\
    \ ok = 1;\n      FOR(i, l, r) if (A[i] == mex) ok = 0;\n      if (ok) break;\n\
    \      ++mex;\n    }\n    ANS.eb(mex);\n  }\n  return ANS;\n}\n\nvoid test_0()\
    \ {\n  FOR(N, 1, 10) FOR(LIM, 1, 20) FOR(Q, 1, 20) {\n    auto [A, query] = gen(N,\
    \ LIM, Q);\n    RangeMexQuery<0, int> X(A);\n    for (auto&& [l, r]: query) X.add(l,\
    \ r);\n    assert(naive(A, query, 0) == X.calc());\n  }\n}\n\nvoid test_1() {\n\
    \  FOR(N, 1, 10) FOR(LIM, 1, 20) FOR(Q, 1, 20) {\n    auto [A, query] = gen(N,\
    \ LIM, Q);\n    for (auto&& x: A) ++x;\n    RangeMexQuery<1, int> X(A);\n    for\
    \ (auto&& [l, r]: query) X.add(l, r);\n    assert(naive(A, query, 1) == X.calc());\n\
    \  }\n}\n\nvoid solve() {\n  LL(a, b);\n  print(a + b);\n}\n\nsigned main() {\n\
    \  cout << fixed << setprecision(15);\n\n  test_0();\n  test_1();\n  solve();\n\
    \n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/mytest/range_mex.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/mytest/range_mex.test.cpp
layout: document
redirect_from:
- /verify/test/mytest/range_mex.test.cpp
- /verify/test/mytest/range_mex.test.cpp.html
title: test/mytest/range_mex.test.cpp
---
