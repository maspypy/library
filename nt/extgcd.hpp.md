---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/3_yukicoder/1936.test.cpp
    title: test/3_yukicoder/1936.test.cpp
  - icon: ':x:'
    path: test/4_aoj/NTL_1_E.test.cpp
    title: test/4_aoj/NTL_1_E.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"nt/extgcd.hpp\"\n// {g,x,y}, ax+by=g\r\ntemplate <typename\
    \ T>\r\ntuple<T, T, T> extgcd(T a, T b) {\r\n  static_assert(is_same_v<T, int>\
    \ || is_same_v<T, ll>);\r\n  T x = 1, y = 0, x1 = 0, y1 = 1;\r\n  while (b !=\
    \ 0) {\r\n    T q = a / b;\r\n    swap(a %= b, b);\r\n    T X = x - q * x1, Y\
    \ = y - q * y1;\r\n    x = x1, y = y1, x1 = X, y1 = Y;\r\n  }\r\n  return {a,\
    \ x, y};\r\n}\r\n"
  code: "// {g,x,y}, ax+by=g\r\ntemplate <typename T>\r\ntuple<T, T, T> extgcd(T a,\
    \ T b) {\r\n  static_assert(is_same_v<T, int> || is_same_v<T, ll>);\r\n  T x =\
    \ 1, y = 0, x1 = 0, y1 = 1;\r\n  while (b != 0) {\r\n    T q = a / b;\r\n    swap(a\
    \ %= b, b);\r\n    T X = x - q * x1, Y = y - q * y1;\r\n    x = x1, y = y1, x1\
    \ = X, y1 = Y;\r\n  }\r\n  return {a, x, y};\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: nt/extgcd.hpp
  requiredBy: []
  timestamp: '2024-11-16 13:34:11+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/3_yukicoder/1936.test.cpp
  - test/4_aoj/NTL_1_E.test.cpp
documentation_of: nt/extgcd.hpp
layout: document
redirect_from:
- /library/nt/extgcd.hpp
- /library/nt/extgcd.hpp.html
title: nt/extgcd.hpp
---
