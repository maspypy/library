---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test_atcoder/abc198d.test.cpp
    title: test_atcoder/abc198d.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"other/solve_hukumenzan.hpp\"\n// a + b = c \u3092\u89E3\u304F\
    \r\nvc<tuple<ll, ll, ll>> solve_hukumenzan(string A, string B, string C) {\r\n\
    \  using T = tuple<ll, ll, ll>;\r\n  vc<T> res;\r\n  vc<char> v;\r\n  for (auto&&\
    \ x: A + B + C) v.eb(x);\r\n  UNIQUE(v);\r\n  if (len(v) > 10) return res;\r\n\
    \  vc<int> I(10);\r\n  iota(all(I), 0);\r\n  do {\r\n    map<char, int> MP;\r\n\
    \    FOR(i, len(v)) MP[v[i]] = I[i];\r\n    if (MP[A[0]] == 0) continue;\r\n \
    \   if (MP[B[0]] == 0) continue;\r\n    if (MP[C[0]] == 0) continue;\r\n    ll\
    \ a = 0, b = 0, c = 0;\r\n    for (auto&& x: A) a = 10 * a + MP[x];\r\n    for\
    \ (auto&& x: B) b = 10 * b + MP[x];\r\n    for (auto&& x: C) c = 10 * c + MP[x];\r\
    \n    if (a + b == c) res.eb(a, b, c);\r\n  } while (next_permutation(all(I)));\r\
    \n  return res;\r\n}\n"
  code: "// a + b = c \u3092\u89E3\u304F\r\nvc<tuple<ll, ll, ll>> solve_hukumenzan(string\
    \ A, string B, string C) {\r\n  using T = tuple<ll, ll, ll>;\r\n  vc<T> res;\r\
    \n  vc<char> v;\r\n  for (auto&& x: A + B + C) v.eb(x);\r\n  UNIQUE(v);\r\n  if\
    \ (len(v) > 10) return res;\r\n  vc<int> I(10);\r\n  iota(all(I), 0);\r\n  do\
    \ {\r\n    map<char, int> MP;\r\n    FOR(i, len(v)) MP[v[i]] = I[i];\r\n    if\
    \ (MP[A[0]] == 0) continue;\r\n    if (MP[B[0]] == 0) continue;\r\n    if (MP[C[0]]\
    \ == 0) continue;\r\n    ll a = 0, b = 0, c = 0;\r\n    for (auto&& x: A) a =\
    \ 10 * a + MP[x];\r\n    for (auto&& x: B) b = 10 * b + MP[x];\r\n    for (auto&&\
    \ x: C) c = 10 * c + MP[x];\r\n    if (a + b == c) res.eb(a, b, c);\r\n  } while\
    \ (next_permutation(all(I)));\r\n  return res;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: other/solve_hukumenzan.hpp
  requiredBy: []
  timestamp: '2022-08-27 04:53:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test_atcoder/abc198d.test.cpp
documentation_of: other/solve_hukumenzan.hpp
layout: document
redirect_from:
- /library/other/solve_hukumenzan.hpp
- /library/other/solve_hukumenzan.hpp.html
title: other/solve_hukumenzan.hpp
---
