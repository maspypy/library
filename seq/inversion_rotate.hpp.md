---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/1838.test.cpp
    title: test/yukicoder/1838.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"seq/inversion_rotate.hpp\"\n\n// i \u756A\u76EE\uFF1AA_i\
    \ \u304C\u5148\u982D\u306B\u306A\u308B\u3088\u3046\u306B rotate \u3057\u305F\u3068\
    \u304D\u306E\u8EE2\u5012\u6570\ntemplate <typename T>\nvi inversion_rotate(vc<T>&\
    \ A, bool SMALL = false) {\n  const int N = len(A);\n  if (!SMALL) {\n    auto\
    \ key = A;\n    UNIQUE(key);\n    for (auto&& x: A) x = LB(key, x);\n  }\n  ll\
    \ K = MAX(A) + 1;\n  ll ANS = 0;\n  FenwickTree<Group_Add<int>> bit(K);\n  for\
    \ (auto&& x: A) {\n    ANS += bit.sum(x + 1, K);\n    bit.add(x, 1);\n  }\n  vi\
    \ res(N);\n  FOR(i, N) {\n    res[i] = ANS;\n    ll x = A[i];\n    ANS = ANS +\
    \ bit.prod(x + 1, K) - bit.sum(x);\n  }\n  return res;\n}\n"
  code: "\n// i \u756A\u76EE\uFF1AA_i \u304C\u5148\u982D\u306B\u306A\u308B\u3088\u3046\
    \u306B rotate \u3057\u305F\u3068\u304D\u306E\u8EE2\u5012\u6570\ntemplate <typename\
    \ T>\nvi inversion_rotate(vc<T>& A, bool SMALL = false) {\n  const int N = len(A);\n\
    \  if (!SMALL) {\n    auto key = A;\n    UNIQUE(key);\n    for (auto&& x: A) x\
    \ = LB(key, x);\n  }\n  ll K = MAX(A) + 1;\n  ll ANS = 0;\n  FenwickTree<Group_Add<int>>\
    \ bit(K);\n  for (auto&& x: A) {\n    ANS += bit.sum(x + 1, K);\n    bit.add(x,\
    \ 1);\n  }\n  vi res(N);\n  FOR(i, N) {\n    res[i] = ANS;\n    ll x = A[i];\n\
    \    ANS = ANS + bit.prod(x + 1, K) - bit.sum(x);\n  }\n  return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: seq/inversion_rotate.hpp
  requiredBy: []
  timestamp: '2022-10-21 18:52:33+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/1838.test.cpp
documentation_of: seq/inversion_rotate.hpp
layout: document
redirect_from:
- /library/seq/inversion_rotate.hpp
- /library/seq/inversion_rotate.hpp.html
title: seq/inversion_rotate.hpp
---
