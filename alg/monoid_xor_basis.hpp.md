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
  bundledCode: "#line 1 \"alg/monoid_xor_basis.hpp\"\ntemplate <typename INT, int\
    \ LOG>\r\nstruct Monoid_XorBasis {\r\n  using value_type = array<INT, LOG>;\r\n\
    \  using X = value_type;\r\n  static void add_element(X& x, INT v) {\r\n    int\
    \ n = 0;\r\n    for (auto&& e: x) {\r\n      if (e == 0 || v == 0) break;\r\n\
    \      ++n;\r\n      chmin(v, v ^ e);\r\n    }\r\n    if (v) x[n] = v;\r\n  }\r\
    \n\r\n  static X op(const X& x, const X& y) {\r\n    X z = x;\r\n    int n = 0;\r\
    \n    while (n < LOG && z[n]) ++n;\r\n    for (auto v: y) { add_element(z, v);\
    \ }\r\n    return z;\r\n  }\r\n  static INT get_max(const X& x) {\r\n    INT res\
    \ = 0;\r\n    for (auto&& a: x) chmax(res, res ^ a);\r\n    return res;\r\n  }\r\
    \n  static constexpr X unit() { return X{}; };\r\n  static constexpr bool commute\
    \ = true;\r\n};\r\n"
  code: "template <typename INT, int LOG>\r\nstruct Monoid_XorBasis {\r\n  using value_type\
    \ = array<INT, LOG>;\r\n  using X = value_type;\r\n  static void add_element(X&\
    \ x, INT v) {\r\n    int n = 0;\r\n    for (auto&& e: x) {\r\n      if (e == 0\
    \ || v == 0) break;\r\n      ++n;\r\n      chmin(v, v ^ e);\r\n    }\r\n    if\
    \ (v) x[n] = v;\r\n  }\r\n\r\n  static X op(const X& x, const X& y) {\r\n    X\
    \ z = x;\r\n    int n = 0;\r\n    while (n < LOG && z[n]) ++n;\r\n    for (auto\
    \ v: y) { add_element(z, v); }\r\n    return z;\r\n  }\r\n  static INT get_max(const\
    \ X& x) {\r\n    INT res = 0;\r\n    for (auto&& a: x) chmax(res, res ^ a);\r\n\
    \    return res;\r\n  }\r\n  static constexpr X unit() { return X{}; };\r\n  static\
    \ constexpr bool commute = true;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid_xor_basis.hpp
  requiredBy: []
  timestamp: '2022-04-16 04:26:49+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: alg/monoid_xor_basis.hpp
layout: document
redirect_from:
- /library/alg/monoid_xor_basis.hpp
- /library/alg/monoid_xor_basis.hpp.html
title: alg/monoid_xor_basis.hpp
---
