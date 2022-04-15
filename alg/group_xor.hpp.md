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
  bundledCode: "#line 1 \"alg/group_xor.hpp\"\ntemplate <typename T = long long>\r\
    \nstruct Group_Xor {\r\n  using value_type = T;\r\n  using X = value_type;\r\n\
    \  static X op(X x, X y) { return x ^ y; }\r\n  static constexpr X inverse(const\
    \ X &x) noexcept { return x; }\r\n  static constexpr X power(const X &x, ll n)\
    \ noexcept {\r\n    return (n & 1 ? x : 0);\r\n  }\r\n  static constexpr X unit(){return\
    \ X(0)};\r\n  static constexpr bool commute = true;\r\n};\r\n"
  code: "template <typename T = long long>\r\nstruct Group_Xor {\r\n  using value_type\
    \ = T;\r\n  using X = value_type;\r\n  static X op(X x, X y) { return x ^ y; }\r\
    \n  static constexpr X inverse(const X &x) noexcept { return x; }\r\n  static\
    \ constexpr X power(const X &x, ll n) noexcept {\r\n    return (n & 1 ? x : 0);\r\
    \n  }\r\n  static constexpr X unit(){return X(0)};\r\n  static constexpr bool\
    \ commute = true;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/group_xor.hpp
  requiredBy: []
  timestamp: '2022-04-16 04:26:49+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: alg/group_xor.hpp
layout: document
redirect_from:
- /library/alg/group_xor.hpp
- /library/alg/group_xor.hpp.html
title: alg/group_xor.hpp
---
