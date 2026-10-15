---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://github.com/maspypy/library/blob/main/other/solve_hukumenzan.hpp
  bundledCode: "#line 1 \"other/solve_hukumenzan.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/other/solve_hukumenzan.hpp\n\
    // a + b = c \u3092\u89E3\u304F\nvc<tuple<ll, ll, ll>> solve_hukumenzan(string\
    \ A, string B, string C) {\n  using T = tuple<ll, ll, ll>;\n  vc<T> res;\n  vc<char>\
    \ v;\n  for (auto&& x: A + B + C) v.eb(x);\n  UNIQUE(v);\n  if (len(v) > 10) return\
    \ res;\n  vc<int> I(10);\n  iota(all(I), 0);\n  do {\n    map<char, int> MP;\n\
    \    FOR(i, len(v)) MP[v[i]] = I[i];\n    if (MP[A[0]] == 0) continue;\n    if\
    \ (MP[B[0]] == 0) continue;\n    if (MP[C[0]] == 0) continue;\n    ll a = 0, b\
    \ = 0, c = 0;\n    for (auto&& x: A) a = 10 * a + MP[x];\n    for (auto&& x: B)\
    \ b = 10 * b + MP[x];\n    for (auto&& x: C) c = 10 * c + MP[x];\n    if (a +\
    \ b == c) res.eb(a, b, c);\n  } while (next_permutation(all(I)));\n  return res;\n\
    }\n"
  code: "// Source: https://github.com/maspypy/library/blob/main/other/solve_hukumenzan.hpp\n\
    // a + b = c \u3092\u89E3\u304F\nvc<tuple<ll, ll, ll>> solve_hukumenzan(string\
    \ A, string B, string C) {\n  using T = tuple<ll, ll, ll>;\n  vc<T> res;\n  vc<char>\
    \ v;\n  for (auto&& x: A + B + C) v.eb(x);\n  UNIQUE(v);\n  if (len(v) > 10) return\
    \ res;\n  vc<int> I(10);\n  iota(all(I), 0);\n  do {\n    map<char, int> MP;\n\
    \    FOR(i, len(v)) MP[v[i]] = I[i];\n    if (MP[A[0]] == 0) continue;\n    if\
    \ (MP[B[0]] == 0) continue;\n    if (MP[C[0]] == 0) continue;\n    ll a = 0, b\
    \ = 0, c = 0;\n    for (auto&& x: A) a = 10 * a + MP[x];\n    for (auto&& x: B)\
    \ b = 10 * b + MP[x];\n    for (auto&& x: C) c = 10 * c + MP[x];\n    if (a +\
    \ b == c) res.eb(a, b, c);\n  } while (next_permutation(all(I)));\n  return res;\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: other/solve_hukumenzan.hpp
  requiredBy: []
  timestamp: '2026-10-15 19:54:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: other/solve_hukumenzan.hpp
layout: document
redirect_from:
- /library/other/solve_hukumenzan.hpp
- /library/other/solve_hukumenzan.hpp.html
title: other/solve_hukumenzan.hpp
---
