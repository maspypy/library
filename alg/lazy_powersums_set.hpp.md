---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: alg/group_power_sums.hpp
    title: alg/group_power_sums.hpp
  - icon: ':question:'
    path: alg/monoid_set.hpp
    title: alg/monoid_set.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/1548_power_sums.test.cpp
    title: test/yukicoder/1548_power_sums.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/lazy_powersums_set.hpp\"\n\r\n#line 1 \"alg/monoid_set.hpp\"\
    \ntemplate <typename E, E none_val>\r\nstruct Monoid_Set {\r\n  using value_type\
    \ = E;\r\n  using X = value_type;\r\n  static X op(X x, X y) { return (y == none_val\
    \ ? x : y); }\r\n  static constexpr X unit() { return none_val; }\r\n  static\
    \ constexpr bool commute = false;\r\n};\n#line 2 \"alg/group_power_sums.hpp\"\n\
    \r\n// 0 \u4E57\u548C\u304B\u3089 K-1 \u4E57\u548C\u307E\u3067\r\ntemplate <typename\
    \ mint, int K>\r\nstruct Group_power_sums {\r\n  using value_type = vc<mint>;\r\
    \n  using X = value_type;\r\n  static X op(X x, X y) {\r\n    vc<mint> z(K);\r\
    \n    FOR(i, K) z[i] = x[i] + y[i];\r\n    return z;\r\n  }\r\n  static X from_element(mint\
    \ x) {\r\n    vc<mint> a(K);\r\n    a[0] = 1;\r\n    FOR(i, K - 1) a[i + 1] =\
    \ a[i] * K;\r\n  }\r\n  static X unit() { return vc<mint>(K, mint(0)); }\r\n \
    \ static constexpr bool commute = 1;\r\n};\r\n#line 5 \"alg/lazy_powersums_set.hpp\"\
    \ntemplate <typename mint, int K>\r\nstruct Lazy_Power_Sums_Set {\r\n  using MX\
    \ = Group_power_sums<mint, K>;\r\n  using MA = Monoid_Set<int, -1>;\r\n  using\
    \ X_structure = MX;\r\n  using A_structure = MA;\r\n  using X = typename MX::value_type;\r\
    \n  using A = typename MA::value_type;\r\n  static X act(const X &x, const A &b)\
    \ {\r\n    if (b == -1) return x;\r\n    mint a = b;\r\n    vc<mint> y(K);\r\n\
    \    vc<mint> pow(K);\r\n    pow[0] = mint(1);\r\n    FOR(k, K - 1) pow[k + 1]\
    \ = pow[k] * a;\r\n    FOR(i, 5) y[i] = x[0] * pow[i];\r\n    return y;\r\n  }\r\
    \n};\r\n"
  code: "#pragma once\r\n\r\n#include \"alg/monoid_set.hpp\"\r\n#include \"alg/group_power_sums.hpp\"\
    \r\ntemplate <typename mint, int K>\r\nstruct Lazy_Power_Sums_Set {\r\n  using\
    \ MX = Group_power_sums<mint, K>;\r\n  using MA = Monoid_Set<int, -1>;\r\n  using\
    \ X_structure = MX;\r\n  using A_structure = MA;\r\n  using X = typename MX::value_type;\r\
    \n  using A = typename MA::value_type;\r\n  static X act(const X &x, const A &b)\
    \ {\r\n    if (b == -1) return x;\r\n    mint a = b;\r\n    vc<mint> y(K);\r\n\
    \    vc<mint> pow(K);\r\n    pow[0] = mint(1);\r\n    FOR(k, K - 1) pow[k + 1]\
    \ = pow[k] * a;\r\n    FOR(i, 5) y[i] = x[0] * pow[i];\r\n    return y;\r\n  }\r\
    \n};\r\n"
  dependsOn:
  - alg/monoid_set.hpp
  - alg/group_power_sums.hpp
  isVerificationFile: false
  path: alg/lazy_powersums_set.hpp
  requiredBy: []
  timestamp: '2022-05-26 00:08:45+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/1548_power_sums.test.cpp
documentation_of: alg/lazy_powersums_set.hpp
layout: document
redirect_from:
- /library/alg/lazy_powersums_set.hpp
- /library/alg/lazy_powersums_set.hpp.html
title: alg/lazy_powersums_set.hpp
---
