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
  bundledCode: "#line 2 \"alg/monoid/power_sums.hpp\"\n\r\n// 0 \u4E57\u548C\u304B\
    \u3089 K-1 \u4E57\u548C\u307E\u3067\r\ntemplate <typename mint, int K>\r\nstruct\
    \ Group_power_sums {\r\n  using value_type = vc<mint>;\r\n  using X = value_type;\r\
    \n  static X op(X x, X y) {\r\n    vc<mint> z(K);\r\n    FOR(i, K) z[i] = x[i]\
    \ + y[i];\r\n    return z;\r\n  }\r\n  static X from_element(mint x) {\r\n   \
    \ vc<mint> a(K);\r\n    a[0] = 1;\r\n    FOR(i, K - 1) a[i + 1] = a[i] * x;\r\n\
    \  }\r\n  static X unit() { return vc<mint>(K, mint(0)); }\r\n  static constexpr\
    \ bool commute = 1;\r\n};\r\n"
  code: "#pragma once\r\n\r\n// 0 \u4E57\u548C\u304B\u3089 K-1 \u4E57\u548C\u307E\u3067\
    \r\ntemplate <typename mint, int K>\r\nstruct Group_power_sums {\r\n  using value_type\
    \ = vc<mint>;\r\n  using X = value_type;\r\n  static X op(X x, X y) {\r\n    vc<mint>\
    \ z(K);\r\n    FOR(i, K) z[i] = x[i] + y[i];\r\n    return z;\r\n  }\r\n  static\
    \ X from_element(mint x) {\r\n    vc<mint> a(K);\r\n    a[0] = 1;\r\n    FOR(i,\
    \ K - 1) a[i + 1] = a[i] * x;\r\n  }\r\n  static X unit() { return vc<mint>(K,\
    \ mint(0)); }\r\n  static constexpr bool commute = 1;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid/power_sums.hpp
  requiredBy: []
  timestamp: '2022-11-27 13:06:40+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: alg/monoid/power_sums.hpp
layout: document
redirect_from:
- /library/alg/monoid/power_sums.hpp
- /library/alg/monoid/power_sums.hpp.html
title: alg/monoid/power_sums.hpp
---
