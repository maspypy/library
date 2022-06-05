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
    \n// \u30CF\u30C3\u30B7\u30E5\u95A2\u6570 H : X -> long long \u3092\u6301\u305F\
    \u305B\u308B\r\n// [lb, rb) \u306E\u6700\u521D\u306E\u89E3\u3092\u304B\u3048\u3059\
    \r\n// \u306A\u3051\u308C\u3070 -1\r\ntemplate <typename Group, typename X>\r\n\
    ll discrete_log(Group::X a, Group::X b, function<ll(Group::X)> H, ll lb, ll ub)\
    \ {\r\n  if (lb >= ub) return -1;\r\n  {\r\n    ll n = lb;\r\n    X p = a;\r\n\
    \    X x = Group::unit();\r\n    while (n) {\r\n      if (n & 1) x = Group::op(x,\
    \ a);\r\n      p = Group::op(p, p);\r\n      n /= 2;\r\n    }\r\n    x = Group::inverse(x);\r\
    \n    b = Group::op(b, x);\r\n  }\r\n  ll LIM = ub - lb;\r\n\r\n  ll K = 1;\r\n\
    \  while (K * K < LIM) ++K;\r\n\r\n  static HashMapLL<int, 20> MP;\r\n  MP.reset();\r\
    \n\r\n  X p = Group::unit();\r\n  FOR(k, K + 1) {\r\n    auto key = H(p);\r\n\
    \    if (!MP.count(key)) MP[key] = k;\r\n    if (k != K) p = Group::op(p, a);\r\
    \n  }\r\n  p = Group::inverse(p);\r\n  FOR(k, K + 1) {\r\n    auto key = H(b);\r\
    \n    if (MP.count(key)) {\r\n      ll res = k * K + MP[key] + lb;\r\n      return\
    \ (res >= ub ? -1 : res);\r\n    }\r\n    b = Group::op(b, p);\r\n  }\r\n  return\
    \ -1;\r\n}\n"
  code: "// log_a b \u306E\u8A08\u7B97\r\n// \u30CF\u30C3\u30B7\u30E5\u95A2\u6570\
    \ H : X -> long long \u3092\u6301\u305F\u305B\u308B\r\n// [lb, rb) \u306E\u6700\
    \u521D\u306E\u89E3\u3092\u304B\u3048\u3059\r\n// \u306A\u3051\u308C\u3070 -1\r\
    \ntemplate <typename Group, typename X>\r\nll discrete_log(Group::X a, Group::X\
    \ b, function<ll(Group::X)> H, ll lb, ll ub) {\r\n  if (lb >= ub) return -1;\r\
    \n  {\r\n    ll n = lb;\r\n    X p = a;\r\n    X x = Group::unit();\r\n    while\
    \ (n) {\r\n      if (n & 1) x = Group::op(x, a);\r\n      p = Group::op(p, p);\r\
    \n      n /= 2;\r\n    }\r\n    x = Group::inverse(x);\r\n    b = Group::op(b,\
    \ x);\r\n  }\r\n  ll LIM = ub - lb;\r\n\r\n  ll K = 1;\r\n  while (K * K < LIM)\
    \ ++K;\r\n\r\n  static HashMapLL<int, 20> MP;\r\n  MP.reset();\r\n\r\n  X p =\
    \ Group::unit();\r\n  FOR(k, K + 1) {\r\n    auto key = H(p);\r\n    if (!MP.count(key))\
    \ MP[key] = k;\r\n    if (k != K) p = Group::op(p, a);\r\n  }\r\n  p = Group::inverse(p);\r\
    \n  FOR(k, K + 1) {\r\n    auto key = H(b);\r\n    if (MP.count(key)) {\r\n  \
    \    ll res = k * K + MP[key] + lb;\r\n      return (res >= ub ? -1 : res);\r\n\
    \    }\r\n    b = Group::op(b, p);\r\n  }\r\n  return -1;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: other/discrete_log.hpp
  requiredBy:
  - mod/mod_log.hpp
  timestamp: '2022-06-05 15:16:23+09:00'
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
