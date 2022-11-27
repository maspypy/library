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
  bundledCode: "#line 2 \"alg/monoid/add_array.hpp\"\n\r\ntemplate <typename E, int\
    \ K>\r\nstruct Group_Add_Array {\r\n  using value_type = array<E, K>;\r\n  using\
    \ X = value_type;\r\n  static X op(X x, X y) {\r\n    X z;\r\n    FOR(i, K) z[i]\
    \ = x[i] + y[i];\r\n    return z;\r\n  }\r\n  static X unit() { return X{}; }\r\
    \n  static constexpr bool commute = 1;\r\n};\r\n"
  code: "#pragma once\r\n\r\ntemplate <typename E, int K>\r\nstruct Group_Add_Array\
    \ {\r\n  using value_type = array<E, K>;\r\n  using X = value_type;\r\n  static\
    \ X op(X x, X y) {\r\n    X z;\r\n    FOR(i, K) z[i] = x[i] + y[i];\r\n    return\
    \ z;\r\n  }\r\n  static X unit() { return X{}; }\r\n  static constexpr bool commute\
    \ = 1;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid/add_array.hpp
  requiredBy: []
  timestamp: '2022-11-27 13:59:16+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: alg/monoid/add_array.hpp
layout: document
redirect_from:
- /library/alg/monoid/add_array.hpp
- /library/alg/monoid/add_array.hpp.html
title: alg/monoid/add_array.hpp
---
