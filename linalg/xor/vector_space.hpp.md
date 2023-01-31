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
  bundledCode: "#line 1 \"linalg/xor/vector_space.hpp\"\n\nstruct Monoid_XorBasis\
    \ {\n  using value_type = ARR;\n  using VECT_SP = value_type;\n  // \u7834\u58CA\
    \u7684\u306B\u5909\u66F4\u3059\u308B\u3002\n  static inline bool add_element(VECT_SP&\
    \ x, u64 v) {\n    for (auto&& e: x) {\n      if (v == 0) break;\n      if (e\
    \ == 0) {\n        e = v; // v \u3092\u8FFD\u52A0\n        return true;\n    \
    \  }\n      chmin(v, v ^ e);\n    }\n    return false;\n  }\n\n  static u64 get_max(const\
    \ VECT_SP& V) {\n    u64 res = 0;\n    for (auto&& x: V) chmax(res, res ^ x);\n\
    \    return res;\n  }\n  static constexpr VECT_SP unit() { return VECT_SP(); };\n\
    \  static constexpr bool commute = true;\n};\n"
  code: "\nstruct Monoid_XorBasis {\n  using value_type = ARR;\n  using VECT_SP =\
    \ value_type;\n  // \u7834\u58CA\u7684\u306B\u5909\u66F4\u3059\u308B\u3002\n \
    \ static inline bool add_element(VECT_SP& x, u64 v) {\n    for (auto&& e: x) {\n\
    \      if (v == 0) break;\n      if (e == 0) {\n        e = v; // v \u3092\u8FFD\
    \u52A0\n        return true;\n      }\n      chmin(v, v ^ e);\n    }\n    return\
    \ false;\n  }\n\n  static u64 get_max(const VECT_SP& V) {\n    u64 res = 0;\n\
    \    for (auto&& x: V) chmax(res, res ^ x);\n    return res;\n  }\n  static constexpr\
    \ VECT_SP unit() { return VECT_SP(); };\n  static constexpr bool commute = true;\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: linalg/xor/vector_space.hpp
  requiredBy: []
  timestamp: '2023-01-31 19:52:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: linalg/xor/vector_space.hpp
layout: document
redirect_from:
- /library/linalg/xor/vector_space.hpp
- /library/linalg/xor/vector_space.hpp.html
title: linalg/xor/vector_space.hpp
---
