---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  [Previous line repeated 3 more times]\n  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: mod/barret.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    my_template.hpp\"\n#include \"other/io.hpp\"\n#include \"random/base.hpp\"\n#include\
    \ \"linalg/implicit_matrix/vandermonde.hpp\"\n\ntemplate <typename mint>\nvc<mint>\
    \ naive(vc<mint> f, vc<mint> A, bool transpose) {\n  assert(len(f) == len(A));\n\
    \  int N = len(f);\n  vc<mint> g(N);\n  if (!transpose) { FOR(i, N) FOR(j, N)\
    \ g[i] += A[i].pow(j) * f[j]; }\n  if (transpose) { FOR(i, N) FOR(j, N) g[i] +=\
    \ A[j].pow(i) * f[j]; }\n  return g;\n}\n\nusing mint = modint998;\nvc<mint> gen(int\
    \ n) {\n  vc<mint> f(n);\n  set<mint> ss;\n  FOR(i, n) {\n    while (1) {\n  \
    \    mint x = RNG(-100, 100);\n      if (ss.count(x)) continue;\n      ss.insert(x);\n\
    \      f[i] = x;\n      break;\n    }\n  }\n  return f;\n}\n\nvoid test() {\n\
    \  FOR(t, 2) {\n    FOR(n, 100) {\n      auto f = gen(n), A = gen(n);\n      auto\
    \ g = vandermonde<mint>(f, A, t, 0);\n      auto g1 = naive(f, A, t);\n      assert(g\
    \ == g1);\n      auto f1 = vandermonde<mint>(g, A, t, 1);\n      assert(f == f1);\n\
    \    }\n  }\n}\n\nvoid solve() {\n  LL(a, b);\n  print(a + b);\n}\n\nsigned main()\
    \ {\n  test();\n  solve();\n  return 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/mytest/vandermonde.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/mytest/vandermonde.test.cpp
layout: document
redirect_from:
- /verify/test/mytest/vandermonde.test.cpp
- /verify/test/mytest/vandermonde.test.cpp.html
title: test/mytest/vandermonde.test.cpp
---
