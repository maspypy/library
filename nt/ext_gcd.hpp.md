---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1936.test.cpp
    title: test/3_yukicoder/1936.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://github.com/maspypy/library/blob/main/nt/ext_gcd.hpp
  bundledCode: "#line 1 \"nt/ext_gcd.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/nt/ext_gcd.hpp\n\
    // {g,x,y}, ax+by=g\ntemplate <typename T>\ntuple<T, T, T> ext_gcd(T a, T b) {\n\
    \  static_assert(is_same_v<T, int> || is_same_v<T, ll>);\n  T x = 1, y = 0, x1\
    \ = 0, y1 = 1;\n  while (b != 0) {\n    T q = a / b;\n    swap(a %= b, b);\n \
    \   T X = x - q * x1, Y = y - q * y1;\n    x = x1, y = y1, x1 = X, y1 = Y;\n \
    \ }\n  return {a, x, y};\n}\n\ntuple<ll, ll, ll, ll> farey_lr(ll a, ll b) {\n\
    \  assert(a > 0 && b > 0);\n  /*\n  Farey \u6570\u5217\u3067\u3001a/b \u304C\u6700\
    \u521D\u306B\u73FE\u308C\u308B\u3068\u304D\u306E\u3001\u5DE6\u53F3\u3092\u6C42\
    \u3081\u308B\u3002\n  a/b = 19/12 \u2192 (x1/y1, x2/y2) = (11/7, 8/5) \u2192 (11,7,8,5)\
    \ \u3092\u8FD4\u3059\u3002\n  */\n  if (a == b) return {0, 1, 1, 0};\n  ll q =\
    \ (a - 1) / b;\n  auto [x1, y1, x2, y2] = farey_lr(b, a - q * b);\n  return {q\
    \ * x2 + y2, x2, q * x1 + y1, x1};\n}\n"
  code: "// Source: https://github.com/maspypy/library/blob/main/nt/ext_gcd.hpp\n\
    // {g,x,y}, ax+by=g\ntemplate <typename T>\ntuple<T, T, T> ext_gcd(T a, T b) {\n\
    \  static_assert(is_same_v<T, int> || is_same_v<T, ll>);\n  T x = 1, y = 0, x1\
    \ = 0, y1 = 1;\n  while (b != 0) {\n    T q = a / b;\n    swap(a %= b, b);\n \
    \   T X = x - q * x1, Y = y - q * y1;\n    x = x1, y = y1, x1 = X, y1 = Y;\n \
    \ }\n  return {a, x, y};\n}\n\ntuple<ll, ll, ll, ll> farey_lr(ll a, ll b) {\n\
    \  assert(a > 0 && b > 0);\n  /*\n  Farey \u6570\u5217\u3067\u3001a/b \u304C\u6700\
    \u521D\u306B\u73FE\u308C\u308B\u3068\u304D\u306E\u3001\u5DE6\u53F3\u3092\u6C42\
    \u3081\u308B\u3002\n  a/b = 19/12 \u2192 (x1/y1, x2/y2) = (11/7, 8/5) \u2192 (11,7,8,5)\
    \ \u3092\u8FD4\u3059\u3002\n  */\n  if (a == b) return {0, 1, 1, 0};\n  ll q =\
    \ (a - 1) / b;\n  auto [x1, y1, x2, y2] = farey_lr(b, a - q * b);\n  return {q\
    \ * x2 + y2, x2, q * x1 + y1, x1};\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: nt/ext_gcd.hpp
  requiredBy: []
  timestamp: '2026-10-15 19:54:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/3_yukicoder/1936.test.cpp
documentation_of: nt/ext_gcd.hpp
layout: document
redirect_from:
- /library/nt/ext_gcd.hpp
- /library/nt/ext_gcd.hpp.html
title: nt/ext_gcd.hpp
---
