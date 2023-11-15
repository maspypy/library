---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test_atcoder/abc200f.test.cpp
    title: test_atcoder/abc200f.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"alg/monoid_pow.hpp\"\ntemplate <typename Monoid>\ntypename\
    \ Monoid::X monoid_pow(typename Monoid::X x, u64 exp) {\n  using X = typename\
    \ Monoid::X;\n  assert(exp >= 0);\n  X res = Monoid::unit();\n  while (exp) {\n\
    \    if (exp & 1) res = Monoid::op(res, x);\n    x = Monoid::op(x, x);\n    exp\
    \ >>= 1;\n  }\n  return res;\n}\n"
  code: "template <typename Monoid>\ntypename Monoid::X monoid_pow(typename Monoid::X\
    \ x, u64 exp) {\n  using X = typename Monoid::X;\n  assert(exp >= 0);\n  X res\
    \ = Monoid::unit();\n  while (exp) {\n    if (exp & 1) res = Monoid::op(res, x);\n\
    \    x = Monoid::op(x, x);\n    exp >>= 1;\n  }\n  return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid_pow.hpp
  requiredBy: []
  timestamp: '2023-04-14 22:06:45+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test_atcoder/abc200f.test.cpp
documentation_of: alg/monoid_pow.hpp
layout: document
redirect_from:
- /library/alg/monoid_pow.hpp
- /library/alg/monoid_pow.hpp.html
title: alg/monoid_pow.hpp
---
