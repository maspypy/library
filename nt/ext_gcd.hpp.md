---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"nt/ext_gcd.hpp\"\n// {g,x,y}, ax+by=g\r\ntemplate <typename\
    \ T>\r\ntuple<T, T, T> ext_gcd(T a, T b) {\r\n  static_assert(is_same_v<T, int>\
    \ || is_same_v<T, ll>);\r\n  T x = 1, y = 0, x1 = 0, y1 = 1;\r\n  while (b !=\
    \ 0) {\r\n    T q = a / b;\r\n    swap(a %= b, b);\r\n    T X = x - q * x1, Y\
    \ = y - q * y1;\r\n    x = x1, y = y1, x1 = X, y1 = Y;\r\n  }\r\n  return {a,\
    \ x, y};\r\n}\r\n\r\ntuple<ll, ll, ll, ll> farey_lr(ll a, ll b) {\r\n  assert(a\
    \ > 0 && b > 0);\r\n  /*\r\n  Farey \u6570\u5217\u3067\u3001a/b \u304C\u6700\u521D\
    \u306B\u73FE\u308C\u308B\u3068\u304D\u306E\u3001\u5DE6\u53F3\u3092\u6C42\u3081\
    \u308B\u3002\r\n  a/b = 19/12 \u2192 (x1/y1, x2/y2) = (11/7, 8/5) \u2192 (11,7,8,5)\
    \ \u3092\u8FD4\u3059\u3002\r\n  */\r\n  if (a == b) return {0, 1, 1, 0};\r\n \
    \ ll q = (a - 1) / b;\r\n  auto [x1, y1, x2, y2] = farey_lr(b, a - q * b);\r\n\
    \  return {q * x2 + y2, x2, q * x1 + y1, x1};\r\n}\r\n"
  code: "// {g,x,y}, ax+by=g\r\ntemplate <typename T>\r\ntuple<T, T, T> ext_gcd(T\
    \ a, T b) {\r\n  static_assert(is_same_v<T, int> || is_same_v<T, ll>);\r\n  T\
    \ x = 1, y = 0, x1 = 0, y1 = 1;\r\n  while (b != 0) {\r\n    T q = a / b;\r\n\
    \    swap(a %= b, b);\r\n    T X = x - q * x1, Y = y - q * y1;\r\n    x = x1,\
    \ y = y1, x1 = X, y1 = Y;\r\n  }\r\n  return {a, x, y};\r\n}\r\n\r\ntuple<ll,\
    \ ll, ll, ll> farey_lr(ll a, ll b) {\r\n  assert(a > 0 && b > 0);\r\n  /*\r\n\
    \  Farey \u6570\u5217\u3067\u3001a/b \u304C\u6700\u521D\u306B\u73FE\u308C\u308B\
    \u3068\u304D\u306E\u3001\u5DE6\u53F3\u3092\u6C42\u3081\u308B\u3002\r\n  a/b =\
    \ 19/12 \u2192 (x1/y1, x2/y2) = (11/7, 8/5) \u2192 (11,7,8,5) \u3092\u8FD4\u3059\
    \u3002\r\n  */\r\n  if (a == b) return {0, 1, 1, 0};\r\n  ll q = (a - 1) / b;\r\
    \n  auto [x1, y1, x2, y2] = farey_lr(b, a - q * b);\r\n  return {q * x2 + y2,\
    \ x2, q * x1 + y1, x1};\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: nt/ext_gcd.hpp
  requiredBy: []
  timestamp: '2026-08-17 08:30:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: nt/ext_gcd.hpp
layout: document
redirect_from:
- /library/nt/ext_gcd.hpp
- /library/nt/ext_gcd.hpp.html
title: nt/ext_gcd.hpp
---
