---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: alg/acted_monoid/minmax_add.hpp
    title: alg/acted_monoid/minmax_add.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/1_mytest/minmax_add.test.cpp
    title: test/1_mytest/minmax_add.test.cpp
  - icon: ':x:'
    path: test/4_aoj/ITP2_3_B.test.cpp
    title: test/4_aoj/ITP2_3_B.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"alg/monoid/minmax.hpp\"\n\ntemplate <class X>\nstruct Monoid_MinMax\
    \ {\n  using P = pair<X, X>;\n  using value_type = P;\n  static constexpr P op(const\
    \ P x, const P y) noexcept {\n    return {min(x.fi, y.fi), max(x.se, y.se)};\n\
    \  }\n  static constexpr P from_element(const X x) { return {x, x}; }\n  static\
    \ constexpr P unit() { return {infty<X>, -infty<X>}; }\n  static constexpr bool\
    \ commute = true;\n};\n"
  code: "\ntemplate <class X>\nstruct Monoid_MinMax {\n  using P = pair<X, X>;\n \
    \ using value_type = P;\n  static constexpr P op(const P x, const P y) noexcept\
    \ {\n    return {min(x.fi, y.fi), max(x.se, y.se)};\n  }\n  static constexpr P\
    \ from_element(const X x) { return {x, x}; }\n  static constexpr P unit() { return\
    \ {infty<X>, -infty<X>}; }\n  static constexpr bool commute = true;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid/minmax.hpp
  requiredBy:
  - alg/acted_monoid/minmax_add.hpp
  timestamp: '2026-08-16 04:03:00+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/1_mytest/minmax_add.test.cpp
  - test/4_aoj/ITP2_3_B.test.cpp
documentation_of: alg/monoid/minmax.hpp
layout: document
redirect_from:
- /library/alg/monoid/minmax.hpp
- /library/alg/monoid/minmax.hpp.html
title: alg/monoid/minmax.hpp
---
