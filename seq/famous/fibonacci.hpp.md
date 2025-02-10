---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/303.test.cpp
    title: test/3_yukicoder/303.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"seq/famous/fibonacci.hpp\"\n// 0, 1, 1, 2, 3, 5, ...\ntemplate\
    \ <typename mint>\nmint fibonacci(ll N) {\n  using P = pair<mint, mint>;\n  P\
    \ f = {0, 1}, res = {1, 0};\n  while (N) {\n    auto& [a, b] = f;\n    auto& [c,\
    \ d] = res;\n    if (N & 1) { res = {a * c + b * d, b * c + (a + b) * d}; }\n\
    \    f = {a * a + b * b, b * (a + a + b)};\n    N >>= 1;\n  }\n  return res.se;\n\
    }\n"
  code: "// 0, 1, 1, 2, 3, 5, ...\ntemplate <typename mint>\nmint fibonacci(ll N)\
    \ {\n  using P = pair<mint, mint>;\n  P f = {0, 1}, res = {1, 0};\n  while (N)\
    \ {\n    auto& [a, b] = f;\n    auto& [c, d] = res;\n    if (N & 1) { res = {a\
    \ * c + b * d, b * c + (a + b) * d}; }\n    f = {a * a + b * b, b * (a + a + b)};\n\
    \    N >>= 1;\n  }\n  return res.se;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: seq/famous/fibonacci.hpp
  requiredBy: []
  timestamp: '2023-02-28 19:11:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/3_yukicoder/303.test.cpp
documentation_of: seq/famous/fibonacci.hpp
layout: document
redirect_from:
- /library/seq/famous/fibonacci.hpp
- /library/seq/famous/fibonacci.hpp.html
title: seq/famous/fibonacci.hpp
---
