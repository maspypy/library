---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1641.test.cpp
    title: test/yukicoder/1641.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1790.test.cpp
    title: test/yukicoder/1790.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"alg/monoid/xor.hpp\"\ntemplate <typename T = long long>\r\
    \nstruct Monoid_Xor {\r\n  using value_type = T;\r\n  using X = value_type;\r\n\
    \  static X op(X x, X y) { return x ^ y; }\r\n  static constexpr X inverse(const\
    \ X &x) noexcept { return x; }\r\n  static constexpr X power(const X &x, ll n)\
    \ noexcept {\r\n    return (n & 1 ? x : 0);\r\n  }\r\n  static constexpr X unit(){return\
    \ X(0);};\r\n  static constexpr bool commute = true;\r\n};\r\n"
  code: "template <typename T = long long>\r\nstruct Monoid_Xor {\r\n  using value_type\
    \ = T;\r\n  using X = value_type;\r\n  static X op(X x, X y) { return x ^ y; }\r\
    \n  static constexpr X inverse(const X &x) noexcept { return x; }\r\n  static\
    \ constexpr X power(const X &x, ll n) noexcept {\r\n    return (n & 1 ? x : 0);\r\
    \n  }\r\n  static constexpr X unit(){return X(0);};\r\n  static constexpr bool\
    \ commute = true;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid/xor.hpp
  requiredBy: []
  timestamp: '2022-11-27 14:09:58+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/1641.test.cpp
  - test/yukicoder/1790.test.cpp
documentation_of: alg/monoid/xor.hpp
layout: document
redirect_from:
- /library/alg/monoid/xor.hpp
- /library/alg/monoid/xor.hpp.html
title: alg/monoid/xor.hpp
---
