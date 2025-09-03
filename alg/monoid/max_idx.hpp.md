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
  bundledCode: "#line 2 \"alg/monoid/max_idx.hpp\"\n\r\ntemplate <typename T, bool\
    \ tie_is_left = true>\r\nstruct Monoid_Max_Idx {\r\n  using value_type = pair<T,\
    \ int>;\r\n  using X = value_type;\r\n  static X op(X x, X y) {\r\n    if (x.fi\
    \ > y.fi) return x;\r\n    if (x.fi < y.fi) return y;\r\n    if (x.se > y.se)\
    \ swap(x, y);\r\n    return (tie_is_left ? x : y);\r\n  }\r\n  static constexpr\
    \ X unit() { return {-infty<T>, -1}; }\r\n  static constexpr bool commute = true;\r\
    \n};\r\n"
  code: "#pragma once\r\n\r\ntemplate <typename T, bool tie_is_left = true>\r\nstruct\
    \ Monoid_Max_Idx {\r\n  using value_type = pair<T, int>;\r\n  using X = value_type;\r\
    \n  static X op(X x, X y) {\r\n    if (x.fi > y.fi) return x;\r\n    if (x.fi\
    \ < y.fi) return y;\r\n    if (x.se > y.se) swap(x, y);\r\n    return (tie_is_left\
    \ ? x : y);\r\n  }\r\n  static constexpr X unit() { return {-infty<T>, -1}; }\r\
    \n  static constexpr bool commute = true;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid/max_idx.hpp
  requiredBy:
  - alg/acted_monoid/maxidx_add.hpp
  timestamp: '2023-02-01 23:31:55+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/3_yukicoder/529.test.cpp
  - test/1_mytest/maxidx_add.test.cpp
documentation_of: alg/monoid/max_idx.hpp
layout: document
redirect_from:
- /library/alg/monoid/max_idx.hpp
- /library/alg/monoid/max_idx.hpp.html
title: alg/monoid/max_idx.hpp
---
