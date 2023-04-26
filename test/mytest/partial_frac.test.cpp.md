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
    \  [Previous line repeated 1 more time]\n  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: mod/barret.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n#include \"other/io.hpp\"\n#include \"random/base.hpp\"\n#include \"poly/sum_of_rationals.hpp\"\
    \n#include \"poly/partial_frac_decomposition.hpp\"\n\nusing mint = modint998;\n\
    using poly = vc<mint>;\n\nvc<mint> gen(int n) {\n  vc<mint> f(n);\n  set<mint>\
    \ ss;\n  FOR(i, n) {\n    while (1) {\n      mint x = RNG(-100, 100);\n      if\
    \ (ss.count(x)) continue;\n      ss.insert(x);\n      f[i] = x;\n      break;\n\
    \    }\n  }\n  return f;\n}\n\nvoid check(poly f, vc<mint> A) {\n  int m = len(A);\n\
    \  auto B = partial_frac_decomposition<mint>(f, A);\n  assert(len(B) == m);\n\
    \  vc<pair<poly, poly>> dat;\n  FOR(i, m) {\n    poly F = {B[i]};\n    poly G\
    \ = {-A[i], mint(1)};\n    dat.eb(F, G);\n  }\n  auto [p, q] = sum_of_rationals<mint>(dat);\n\
    \  while (len(p) && p.back() == mint(0)) p.pop_back();\n  while (len(f) && f.back()\
    \ == mint(0)) f.pop_back();\n  assert(p == f);\n}\n\nvoid test() {\n  FOR(n, 50)\
    \ FOR(m, n, 50) {\n    poly f = gen(n), A = gen(m);\n    check(f, A);\n  }\n}\n\
    \nvoid solve() {\n  LL(a, b);\n  print(a + b);\n}\n\nsigned main() {\n  test();\n\
    \  solve();\n  return 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/mytest/partial_frac.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/mytest/partial_frac.test.cpp
layout: document
redirect_from:
- /verify/test/mytest/partial_frac.test.cpp
- /verify/test/mytest/partial_frac.test.cpp.html
title: test/mytest/partial_frac.test.cpp
---
