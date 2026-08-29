---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: alg/acted_monoid/maxidx_add.hpp
    title: alg/acted_monoid/maxidx_add.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/1_mytest/maxidx_add.test.cpp
    title: test/1_mytest/maxidx_add.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/529.test.cpp
    title: test/3_yukicoder/529.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"alg/monoid/maxidx.hpp\"\n\ntemplate <typename T, bool tie_is_left\
    \ = true>\nstruct Monoid_MaxIdx {\n  using value_type = pair<T, int>;\n  using\
    \ X = value_type;\n  static X op(X x, X y) {\n    if (x.fi > y.fi) return x;\n\
    \    if (x.fi < y.fi) return y;\n    if (x.se > y.se) swap(x, y);\n    return\
    \ (tie_is_left ? x : y);\n  }\n  static constexpr X unit() { return {-infty<T>,\
    \ -1}; }\n  static constexpr bool commute = true;\n};\n"
  code: "\ntemplate <typename T, bool tie_is_left = true>\nstruct Monoid_MaxIdx {\n\
    \  using value_type = pair<T, int>;\n  using X = value_type;\n  static X op(X\
    \ x, X y) {\n    if (x.fi > y.fi) return x;\n    if (x.fi < y.fi) return y;\n\
    \    if (x.se > y.se) swap(x, y);\n    return (tie_is_left ? x : y);\n  }\n  static\
    \ constexpr X unit() { return {-infty<T>, -1}; }\n  static constexpr bool commute\
    \ = true;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid/maxidx.hpp
  requiredBy:
  - alg/acted_monoid/maxidx_add.hpp
  timestamp: '2026-08-17 08:30:43+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/1_mytest/maxidx_add.test.cpp
  - test/3_yukicoder/529.test.cpp
documentation_of: alg/monoid/maxidx.hpp
layout: document
redirect_from:
- /library/alg/monoid/maxidx.hpp
- /library/alg/monoid/maxidx.hpp.html
title: alg/monoid/maxidx.hpp
---
