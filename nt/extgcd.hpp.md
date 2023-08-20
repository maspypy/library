---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/NTL_1_E.test.cpp
    title: test/aoj/NTL_1_E.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1936.test.cpp
    title: test/yukicoder/1936.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"nt/extgcd.hpp\"\ntuple<ll, ll, ll, ll> Farey_lr(ll a, ll\
    \ b) {\r\n  assert(a > 0 && b > 0);\r\n  /*\r\n  Farey \u6570\u5217\u3067\u3001\
    a/b \u304C\u6700\u521D\u306B\u73FE\u308C\u308B\u3068\u304D\u306E\u3001\u5DE6\u53F3\
    \u3092\u6C42\u3081\u308B\u3002\r\n  a/b = 19/12 \u2192 (x1/y1, x2/y2) = (11/7,\
    \ 8/5) \u2192 (11,7,8,5) \u3092\u8FD4\u3059\u3002\r\n  */\r\n  if (a == b) return\
    \ {0, 1, 1, 0};\r\n  ll q = (a - 1) / b;\r\n  auto [x1, y1, x2, y2] = Farey_lr(b,\
    \ a - q * b);\r\n  return {q * x2 + y2, x2, q * x1 + y1, x1};\r\n}\r\n\r\ntuple<ll,\
    \ ll, ll> extgcd(ll a, ll b) {\r\n  // ax + by = d \u306E\u6700\u5C0F\u89E3 (x,\
    \ y, d) \u3092\u8FD4\u3059\u3002\r\n  // (|x|+|y|, x) \u306B\u95A2\u3059\u308B\
    \u8F9E\u66F8\u9806\u6700\u5C0F\u3068\u3059\u308B\u3002\r\n  auto [x1, y1, x2,\
    \ y2] = Farey_lr(a, b);\r\n  tie(x1, y1) = mp(y1, -x1);\r\n  tie(x2, y2) = mp(-y2,\
    \ x2);\r\n  ll g = a * x1 + b * y1;\r\n\r\n  pi key1 = mp(abs(x1) + abs(y1), x1);\r\
    \n  pi key2 = mp(abs(x2) + abs(y2), x2);\r\n  return (key1 < key2 ? mt(x1, y1,\
    \ g) : mt(x2, y2, g));\r\n}\r\n"
  code: "tuple<ll, ll, ll, ll> Farey_lr(ll a, ll b) {\r\n  assert(a > 0 && b > 0);\r\
    \n  /*\r\n  Farey \u6570\u5217\u3067\u3001a/b \u304C\u6700\u521D\u306B\u73FE\u308C\
    \u308B\u3068\u304D\u306E\u3001\u5DE6\u53F3\u3092\u6C42\u3081\u308B\u3002\r\n \
    \ a/b = 19/12 \u2192 (x1/y1, x2/y2) = (11/7, 8/5) \u2192 (11,7,8,5) \u3092\u8FD4\
    \u3059\u3002\r\n  */\r\n  if (a == b) return {0, 1, 1, 0};\r\n  ll q = (a - 1)\
    \ / b;\r\n  auto [x1, y1, x2, y2] = Farey_lr(b, a - q * b);\r\n  return {q * x2\
    \ + y2, x2, q * x1 + y1, x1};\r\n}\r\n\r\ntuple<ll, ll, ll> extgcd(ll a, ll b)\
    \ {\r\n  // ax + by = d \u306E\u6700\u5C0F\u89E3 (x, y, d) \u3092\u8FD4\u3059\u3002\
    \r\n  // (|x|+|y|, x) \u306B\u95A2\u3059\u308B\u8F9E\u66F8\u9806\u6700\u5C0F\u3068\
    \u3059\u308B\u3002\r\n  auto [x1, y1, x2, y2] = Farey_lr(a, b);\r\n  tie(x1, y1)\
    \ = mp(y1, -x1);\r\n  tie(x2, y2) = mp(-y2, x2);\r\n  ll g = a * x1 + b * y1;\r\
    \n\r\n  pi key1 = mp(abs(x1) + abs(y1), x1);\r\n  pi key2 = mp(abs(x2) + abs(y2),\
    \ x2);\r\n  return (key1 < key2 ? mt(x1, y1, g) : mt(x2, y2, g));\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: nt/extgcd.hpp
  requiredBy: []
  timestamp: '2022-04-16 04:26:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/NTL_1_E.test.cpp
  - test/yukicoder/1936.test.cpp
documentation_of: nt/extgcd.hpp
layout: document
redirect_from:
- /library/nt/extgcd.hpp
- /library/nt/extgcd.hpp.html
title: nt/extgcd.hpp
---
