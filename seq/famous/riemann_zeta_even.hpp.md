---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/1357.test.cpp
    title: test/yukicoder/1357.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"seq/famous/riemann_zeta_even.hpp\"\n// 2 \u4EE5\u4E0A N\
    \ \u4EE5\u4E0B\u306E\u5076\u6570\u306B\u5BFE\u3057\u3066, zeta(n) = c pi^n \u3068\
    \u306A\u308B c\n// [0,0,1/6,0,1/90,...]\ntemplate <typename mint>\nvc<mint> riemann_zeta_even(int\
    \ N) {\n  auto B = bernoulli_number<mint>(N);\n  mint pow = inv<mint>(4);\n  FOR(n,\
    \ N + 1) {\n    pow += pow;\n    if (n <= 1 || n & 1) {\n      B[n] = 0;\n   \
    \   continue;\n    }\n    B[n] *= fact_inv<mint>(n);\n    B[n] *= pow;\n    if\
    \ (!(n & 2)) B[n] = -B[n];\n  }\n  return B;\n}\n"
  code: "// 2 \u4EE5\u4E0A N \u4EE5\u4E0B\u306E\u5076\u6570\u306B\u5BFE\u3057\u3066\
    , zeta(n) = c pi^n \u3068\u306A\u308B c\n// [0,0,1/6,0,1/90,...]\ntemplate <typename\
    \ mint>\nvc<mint> riemann_zeta_even(int N) {\n  auto B = bernoulli_number<mint>(N);\n\
    \  mint pow = inv<mint>(4);\n  FOR(n, N + 1) {\n    pow += pow;\n    if (n <=\
    \ 1 || n & 1) {\n      B[n] = 0;\n      continue;\n    }\n    B[n] *= fact_inv<mint>(n);\n\
    \    B[n] *= pow;\n    if (!(n & 2)) B[n] = -B[n];\n  }\n  return B;\n}"
  dependsOn: []
  isVerificationFile: false
  path: seq/famous/riemann_zeta_even.hpp
  requiredBy: []
  timestamp: '2023-11-21 19:20:30+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/1357.test.cpp
documentation_of: seq/famous/riemann_zeta_even.hpp
layout: document
redirect_from:
- /library/seq/famous/riemann_zeta_even.hpp
- /library/seq/famous/riemann_zeta_even.hpp.html
title: seq/famous/riemann_zeta_even.hpp
---
