---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/mytest/QOJ5445.test.cpp
    title: test/mytest/QOJ5445.test.cpp
  - icon: ':x:'
    path: test/yukicoder/184.test.cpp
    title: test/yukicoder/184.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"alg/monoid/xor_basis.hpp\"\n\r\ntemplate <typename E>\r\n\
    struct Monoid_XorBasis {\r\n  using value_type = vector<E>;\r\n  using VECT_SP\
    \ = value_type;\r\n\r\n  // \u7834\u58CA\u7684\u306B\u5909\u66F4\u3059\u308B\r\
    \n  static bool add_element(VECT_SP& x, E v) {\r\n    for (auto&& e: x) {\r\n\
    \      if (e == 0 || v == 0) break;\r\n      chmin(v, v ^ e);\r\n    }\r\n   \
    \ if (v) {\r\n      x.eb(v);\r\n      return true;\r\n    }\r\n    return false;\r\
    \n  }\r\n\r\n  static VECT_SP op(VECT_SP x, VECT_SP y) {\r\n    if (len(x) < len(y))\
    \ swap(x, y);\r\n    for (auto v: y) { add_element(x, v); }\r\n    return x;\r\
    \n  }\r\n\r\n  static bool isin(E v, const VECT_SP& V) {\r\n    for (auto&& w:\
    \ V) { chmin(v, v ^ w); }\r\n    return v == 0;\r\n  }\r\n\r\n  static E get_max(const\
    \ VECT_SP& V, E xor_val = 0) {\r\n    E res = xor_val;\r\n    for (auto&& x: V)\
    \ chmax(res, res ^ x);\r\n    return res;\r\n  }\r\n\r\n  static E get_min(const\
    \ VECT_SP& V, E xor_val = 0) {\r\n    E res = xor_val;\r\n    for (auto&& x: V)\
    \ chmin(res, res ^ x);\r\n    return res;\r\n  }\r\n  static constexpr VECT_SP\
    \ unit() { return VECT_SP{}; };\r\n  static constexpr bool commute = true;\r\n\
    };\r\n"
  code: "\r\ntemplate <typename E>\r\nstruct Monoid_XorBasis {\r\n  using value_type\
    \ = vector<E>;\r\n  using VECT_SP = value_type;\r\n\r\n  // \u7834\u58CA\u7684\
    \u306B\u5909\u66F4\u3059\u308B\r\n  static bool add_element(VECT_SP& x, E v) {\r\
    \n    for (auto&& e: x) {\r\n      if (e == 0 || v == 0) break;\r\n      chmin(v,\
    \ v ^ e);\r\n    }\r\n    if (v) {\r\n      x.eb(v);\r\n      return true;\r\n\
    \    }\r\n    return false;\r\n  }\r\n\r\n  static VECT_SP op(VECT_SP x, VECT_SP\
    \ y) {\r\n    if (len(x) < len(y)) swap(x, y);\r\n    for (auto v: y) { add_element(x,\
    \ v); }\r\n    return x;\r\n  }\r\n\r\n  static bool isin(E v, const VECT_SP&\
    \ V) {\r\n    for (auto&& w: V) { chmin(v, v ^ w); }\r\n    return v == 0;\r\n\
    \  }\r\n\r\n  static E get_max(const VECT_SP& V, E xor_val = 0) {\r\n    E res\
    \ = xor_val;\r\n    for (auto&& x: V) chmax(res, res ^ x);\r\n    return res;\r\
    \n  }\r\n\r\n  static E get_min(const VECT_SP& V, E xor_val = 0) {\r\n    E res\
    \ = xor_val;\r\n    for (auto&& x: V) chmin(res, res ^ x);\r\n    return res;\r\
    \n  }\r\n  static constexpr VECT_SP unit() { return VECT_SP{}; };\r\n  static\
    \ constexpr bool commute = true;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid/xor_basis.hpp
  requiredBy: []
  timestamp: '2023-02-02 04:23:44+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/184.test.cpp
  - test/mytest/QOJ5445.test.cpp
documentation_of: alg/monoid/xor_basis.hpp
layout: document
redirect_from:
- /library/alg/monoid/xor_basis.hpp
- /library/alg/monoid/xor_basis.hpp.html
title: alg/monoid/xor_basis.hpp
---
