---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: mod/mod_log.hpp
    title: mod/mod_log.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/math/discrete_logarithm_mod.test.cpp
    title: test/library_checker/math/discrete_logarithm_mod.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"other/discrete_log.hpp\"\n// log_a b \u306E\u8A08\u7B97\r\
    \n// \u300C*\u300D \u304C\u5B9A\u7FA9\u3055\u308C\u305F\u30AF\u30E9\u30B9\u3001\
    \u30CF\u30C3\u30B7\u30E5\u95A2\u6570 H \u3092\u6301\u305F\u305B\u308B\r\n// lb\
    \ \u4EE5\u4E0A\u306E\u89E3\u3092\u304B\u3048\u3059\r\ntemplate <typename X>\r\n\
    ll discrete_log(X a, X b, ll LIM, function<ll(X)> H, int lb = 0) {\r\n  {\r\n\
    \    int n = lb;\r\n    X p = a;\r\n    while (n) {\r\n      if (n & 1) b /= p;\r\
    \n      p *= p;\r\n      n /= 2;\r\n    }\r\n  }\r\n\r\n  ll K = 1;\r\n  while\
    \ (K * K < LIM) ++K;\r\n\r\n  unordered_map<ll, int> MP;\r\n  MP.reserve(K + 1);\r\
    \n  X p = 1;\r\n  FOR(k, K + 1) {\r\n    auto key = H(p);\r\n    if (!MP.count(key))\
    \ MP[key] = k;\r\n    if (k != K) p = p * a;\r\n  }\r\n  p = X(1) / p;\r\n  FOR(k,\
    \ K + 1) {\r\n    auto key = H(b);\r\n    if (MP.count(key)) return k * K + MP[key]\
    \ + lb;\r\n    b *= p;\r\n  }\r\n  return -1;\r\n}\r\n"
  code: "// log_a b \u306E\u8A08\u7B97\r\n// \u300C*\u300D \u304C\u5B9A\u7FA9\u3055\
    \u308C\u305F\u30AF\u30E9\u30B9\u3001\u30CF\u30C3\u30B7\u30E5\u95A2\u6570 H \u3092\
    \u6301\u305F\u305B\u308B\r\n// lb \u4EE5\u4E0A\u306E\u89E3\u3092\u304B\u3048\u3059\
    \r\ntemplate <typename X>\r\nll discrete_log(X a, X b, ll LIM, function<ll(X)>\
    \ H, int lb = 0) {\r\n  {\r\n    int n = lb;\r\n    X p = a;\r\n    while (n)\
    \ {\r\n      if (n & 1) b /= p;\r\n      p *= p;\r\n      n /= 2;\r\n    }\r\n\
    \  }\r\n\r\n  ll K = 1;\r\n  while (K * K < LIM) ++K;\r\n\r\n  unordered_map<ll,\
    \ int> MP;\r\n  MP.reserve(K + 1);\r\n  X p = 1;\r\n  FOR(k, K + 1) {\r\n    auto\
    \ key = H(p);\r\n    if (!MP.count(key)) MP[key] = k;\r\n    if (k != K) p = p\
    \ * a;\r\n  }\r\n  p = X(1) / p;\r\n  FOR(k, K + 1) {\r\n    auto key = H(b);\r\
    \n    if (MP.count(key)) return k * K + MP[key] + lb;\r\n    b *= p;\r\n  }\r\n\
    \  return -1;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: other/discrete_log.hpp
  requiredBy:
  - mod/mod_log.hpp
  timestamp: '2022-04-16 04:26:49+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library_checker/math/discrete_logarithm_mod.test.cpp
documentation_of: other/discrete_log.hpp
layout: document
redirect_from:
- /library/other/discrete_log.hpp
- /library/other/discrete_log.hpp.html
title: other/discrete_log.hpp
---
