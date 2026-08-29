---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: alg/acted_monoid/minidx_add.hpp
    title: alg/acted_monoid/minidx_add.hpp
  - icon: ':x:'
    path: geo/manhattan_nns.hpp
    title: geo/manhattan_nns.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/1_mytest/manhattan_nns.test.cpp
    title: test/1_mytest/manhattan_nns.test.cpp
  - icon: ':x:'
    path: test/1_mytest/minidx_add.test.cpp
    title: test/1_mytest/minidx_add.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/2361.test.cpp
    title: test/3_yukicoder/2361.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/2897.test.cpp
    title: test/3_yukicoder/2897.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"alg/monoid/minidx.hpp\"\n\ntemplate <typename T, bool tie_is_left\
    \ = true>\nstruct Monoid_MinIdx {\n  using value_type = pair<T, int>;\n  using\
    \ X = value_type;\n  static constexpr bool is_small(const X& x, const X& y) {\n\
    \    if (x.fi < y.fi) return true;\n    if (x.fi > y.fi) return false;\n    return\
    \ (tie_is_left ? (x.se < y.se) : (x.se >= y.se));\n  }\n  static X op(X x, X y)\
    \ { return (is_small(x, y) ? x : y); }\n  static constexpr X unit() { return {infty<T>,\
    \ -1}; }\n  static constexpr bool commute = true;\n};\n"
  code: "\ntemplate <typename T, bool tie_is_left = true>\nstruct Monoid_MinIdx {\n\
    \  using value_type = pair<T, int>;\n  using X = value_type;\n  static constexpr\
    \ bool is_small(const X& x, const X& y) {\n    if (x.fi < y.fi) return true;\n\
    \    if (x.fi > y.fi) return false;\n    return (tie_is_left ? (x.se < y.se) :\
    \ (x.se >= y.se));\n  }\n  static X op(X x, X y) { return (is_small(x, y) ? x\
    \ : y); }\n  static constexpr X unit() { return {infty<T>, -1}; }\n  static constexpr\
    \ bool commute = true;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid/minidx.hpp
  requiredBy:
  - geo/manhattan_nns.hpp
  - alg/acted_monoid/minidx_add.hpp
  timestamp: '2026-08-17 08:30:43+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/1_mytest/manhattan_nns.test.cpp
  - test/1_mytest/minidx_add.test.cpp
  - test/3_yukicoder/2361.test.cpp
  - test/3_yukicoder/2897.test.cpp
documentation_of: alg/monoid/minidx.hpp
layout: document
redirect_from:
- /library/alg/monoid/minidx.hpp
- /library/alg/monoid/minidx.hpp.html
title: alg/monoid/minidx.hpp
---
