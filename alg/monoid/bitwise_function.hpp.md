---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/3_yukicoder/2498.test.cpp
    title: test/3_yukicoder/2498.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/bitwise_function.hpp\"\n\n// composition of bitwise\
    \ operation\n// 0 -> a, -1 -> b\ntemplate <typename UINT>\nstruct Bitwise_Function\
    \ {\n  static_assert(is_same_v<UINT, u32> || is_same_v<UINT, u64>);\n  using value_type\
    \ = pair<UINT, UINT>;\n  using X = value_type;\n  static X op(X x, X y) { return\
    \ {eval(y, x.fi), eval(y, x.se)}; }\n  static UINT eval(X f, UINT x) { return\
    \ (f.fi & (~x)) | (f.se & x); }\n  static X func_or(UINT x) { return {x, UINT(-1)};\
    \ }\n  static X func_and(UINT x) { return {0, x}; }\n  static X func_xor(UINT\
    \ x) { return {x, UINT(-1) ^ x}; }\n  static constexpr X unit() { return {UINT(0),\
    \ UINT(-1)}; }\n  static constexpr bool commute = 0;\n};\n"
  code: "#pragma once\n\n// composition of bitwise operation\n// 0 -> a, -1 -> b\n\
    template <typename UINT>\nstruct Bitwise_Function {\n  static_assert(is_same_v<UINT,\
    \ u32> || is_same_v<UINT, u64>);\n  using value_type = pair<UINT, UINT>;\n  using\
    \ X = value_type;\n  static X op(X x, X y) { return {eval(y, x.fi), eval(y, x.se)};\
    \ }\n  static UINT eval(X f, UINT x) { return (f.fi & (~x)) | (f.se & x); }\n\
    \  static X func_or(UINT x) { return {x, UINT(-1)}; }\n  static X func_and(UINT\
    \ x) { return {0, x}; }\n  static X func_xor(UINT x) { return {x, UINT(-1) ^ x};\
    \ }\n  static constexpr X unit() { return {UINT(0), UINT(-1)}; }\n  static constexpr\
    \ bool commute = 0;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid/bitwise_function.hpp
  requiredBy: []
  timestamp: '2023-11-08 21:49:23+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/3_yukicoder/2498.test.cpp
documentation_of: alg/monoid/bitwise_function.hpp
layout: document
redirect_from:
- /library/alg/monoid/bitwise_function.hpp
- /library/alg/monoid/bitwise_function.hpp.html
title: alg/monoid/bitwise_function.hpp
---
