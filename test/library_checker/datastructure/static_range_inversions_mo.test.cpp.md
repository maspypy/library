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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ds/fenwick/fenwick.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_inversions_query\"\
    \r\n#include \"my_template.hpp\"\r\n#include \"other/io.hpp\"\r\n\r\n#include\
    \ \"ds/fenwick/fenwick.hpp\"\r\n#include \"ds/offline_query/mo.hpp\"\r\n\r\nvoid\
    \ solve() {\r\n  LL(N, Q);\r\n  VEC(ll, A, N);\r\n  vi key = A;\r\n  UNIQUE(key);\r\
    \n\r\n  for (auto&& x: A) x = LB(key, x);\r\n  ll K = len(key);\r\n  FenwickTree<Monoid_Add<int>>\
    \ bit(K);\r\n\r\n  Mo mo;\r\n  vi ANS(Q);\r\n  FOR(Q) {\r\n    LL(L, R);\r\n \
    \   mo.add(L, R);\r\n  }\r\n\r\n  ll inv = 0;\r\n  auto add_l = [&](int i) ->\
    \ void {\r\n    int x = A[i];\r\n    inv += bit.sum(x);\r\n    bit.add(x, +1);\r\
    \n  };\r\n  auto rm_l = [&](int i) -> void {\r\n    int x = A[i];\r\n    bit.add(x,\
    \ -1);\r\n    inv -= bit.sum(x);\r\n  };\r\n  auto add_r = [&](int i) -> void\
    \ {\r\n    int x = A[i];\r\n    inv += bit.sum_all() - bit.sum(x + 1);\r\n   \
    \ bit.add(x, +1);\r\n  };\r\n  auto rm_r = [&](int i) -> void {\r\n    int x =\
    \ A[i];\r\n    bit.add(x, -1);\r\n    inv -= bit.sum_all() - bit.sum(x + 1);\r\
    \n  };\r\n  auto calc = [&](int i) -> void { ANS[i] = inv; };\r\n  mo.calc(add_l,\
    \ add_r, rm_l, rm_r, calc);\r\n  for (auto&& x: ANS) print(x);\r\n}\r\n\r\nsigned\
    \ main() {\r\n  cin.tie(nullptr);\r\n  ios::sync_with_stdio(false);\r\n  cout\
    \ << setprecision(15);\r\n\r\n  solve();\r\n\r\n  return 0;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: true
  path: test/library_checker/datastructure/static_range_inversions_mo.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/datastructure/static_range_inversions_mo.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/datastructure/static_range_inversions_mo.test.cpp
- /verify/test/library_checker/datastructure/static_range_inversions_mo.test.cpp.html
title: test/library_checker/datastructure/static_range_inversions_mo.test.cpp
---
