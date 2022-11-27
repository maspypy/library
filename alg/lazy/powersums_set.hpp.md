---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: alg/monoid/add_array.hpp
    title: alg/monoid/add_array.hpp
  - icon: ':heavy_check_mark:'
    path: alg/monoid/set.hpp
    title: alg/monoid/set.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1548.test.cpp
    title: test/yukicoder/1548.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/lazy/powersums_set.hpp\"\n\r\n#line 1 \"alg/monoid/set.hpp\"\
    \ntemplate <typename E, E none_val>\r\nstruct Monoid_Set {\r\n  using value_type\
    \ = E;\r\n  using X = value_type;\r\n  static X op(X x, X y) { return (y == none_val\
    \ ? x : y); }\r\n  static constexpr X unit() { return none_val; }\r\n  static\
    \ constexpr bool commute = false;\r\n};\n#line 2 \"alg/monoid/add_array.hpp\"\n\
    \r\ntemplate <typename E, int K>\r\nstruct Monoid_Add_Array {\r\n  using value_type\
    \ = array<E, K>;\r\n  using X = value_type;\r\n  static X op(X x, X y) {\r\n \
    \   X z;\r\n    FOR(i, K) z[i] = x[i] + y[i];\r\n    return z;\r\n  }\r\n  static\
    \ X unit() { return X{}; }\r\n  static constexpr bool commute = 1;\r\n};\r\n#line\
    \ 5 \"alg/lazy/powersums_set.hpp\"\n\r\ntemplate <typename mint, int K>\r\nstruct\
    \ Lazy_Power_Sums_Set {\r\n  using MX = Monoid_Add_Array<mint, K>;\r\n  using\
    \ MA = Monoid_Set<int, -1>;\r\n  using X_structure = MX;\r\n  using A_structure\
    \ = MA;\r\n  using X = typename MX::value_type;\r\n  using A = typename MA::value_type;\r\
    \n  static X act(const X &x, const A &b) {\r\n    if (b == -1) return x;\r\n \
    \   mint a = b;\r\n    X y;\r\n    X pow;\r\n    pow[0] = mint(1);\r\n    FOR(k,\
    \ K - 1) pow[k + 1] = pow[k] * a;\r\n    FOR(i, K) y[i] = x[0] * pow[i];\r\n \
    \   return y;\r\n  }\r\n};\r\n"
  code: "#pragma once\r\n\r\n#include \"alg/monoid/set.hpp\"\r\n#include \"alg/monoid/add_array.hpp\"\
    \r\n\r\ntemplate <typename mint, int K>\r\nstruct Lazy_Power_Sums_Set {\r\n  using\
    \ MX = Monoid_Add_Array<mint, K>;\r\n  using MA = Monoid_Set<int, -1>;\r\n  using\
    \ X_structure = MX;\r\n  using A_structure = MA;\r\n  using X = typename MX::value_type;\r\
    \n  using A = typename MA::value_type;\r\n  static X act(const X &x, const A &b)\
    \ {\r\n    if (b == -1) return x;\r\n    mint a = b;\r\n    X y;\r\n    X pow;\r\
    \n    pow[0] = mint(1);\r\n    FOR(k, K - 1) pow[k + 1] = pow[k] * a;\r\n    FOR(i,\
    \ K) y[i] = x[0] * pow[i];\r\n    return y;\r\n  }\r\n};\r\n"
  dependsOn:
  - alg/monoid/set.hpp
  - alg/monoid/add_array.hpp
  isVerificationFile: false
  path: alg/lazy/powersums_set.hpp
  requiredBy: []
  timestamp: '2022-11-27 20:55:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1548.test.cpp
documentation_of: alg/lazy/powersums_set.hpp
layout: document
redirect_from:
- /library/alg/lazy/powersums_set.hpp
- /library/alg/lazy/powersums_set.hpp.html
title: alg/lazy/powersums_set.hpp
---
