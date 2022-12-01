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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ds/fenwick.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_inversions_query\"\
    \n#include \"my_template.hpp\"\n#include \"other/io.hpp\"\n\n#include \"ds/fenwick.hpp\"\
    \n#include \"ds/query/rollback_mo.hpp\"\n\nvoid solve() {\n  LL(N, Q);\n  VEC(ll,\
    \ A, N);\n  vi key = A;\n  UNIQUE(key);\n\n  for (auto&& x: A) x = LB(key, x);\n\
    \  ll K = len(key);\n  FenwickTree<Monoid_Add<int>> bit(K);\n\n  Rollback_Mo mo;\n\
    \  vi ANS(Q);\n  FOR(Q) {\n    LL(L, R);\n    mo.add(L, R);\n  }\n\n  ll inv =\
    \ 0;\n  ll tinv = 0;\n  ll t = 0;\n  vc<int> history;\n  auto add_l = [&](int\
    \ i) -> void {\n    int x = A[i];\n    inv += bit.sum(x);\n    bit.add(x, +1);\n\
    \    history.eb(x);\n  };\n  auto add_r = [&](int i) -> void {\n    int x = A[i];\n\
    \    inv += bit.sum_all() - bit.sum(x + 1);\n    bit.add(x, +1);\n    history.eb(x);\n\
    \  };\n  auto rb = [&](int t) -> void {\n    while (len(history) > t) { bit.add(pick(history),\
    \ -1); }\n  };\n  auto reset = [&]() -> void {\n    rb(0);\n    inv = 0;\n  };\n\
    \  auto save = [&]() -> void {\n    t = len(history);\n    tinv = inv;\n  };\n\
    \  auto rollback = [&]() -> void {\n    rb(t);\n    inv = tinv;\n  };\n  auto\
    \ calc = [&](int i) -> void { ANS[i] = inv; };\n  mo.calc(add_l, add_r, reset,\
    \ save, rollback, calc);\n  for (auto&& x: ANS) print(x);\n}\n\nsigned main()\
    \ {\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n  cout << setprecision(15);\n\
    \n  solve();\n\n  return 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/library_checker/datastructure/static_range_inversions_mo2.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/datastructure/static_range_inversions_mo2.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/datastructure/static_range_inversions_mo2.test.cpp
- /verify/test/library_checker/datastructure/static_range_inversions_mo2.test.cpp.html
title: test/library_checker/datastructure/static_range_inversions_mo2.test.cpp
---
