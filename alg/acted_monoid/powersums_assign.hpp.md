---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: alg/monoid/add_array.hpp
    title: alg/monoid/add_array.hpp
  - icon: ':x:'
    path: alg/monoid/assign.hpp
    title: alg/monoid/assign.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/acted_monoid/powersums_assign.hpp\"\n\r\n#line 2 \"\
    alg/monoid/assign.hpp\"\n\r\ntemplate <typename X, X none_val>\r\nstruct Monoid_Assign\
    \ {\r\n  using value_type = X;\r\n  static X op(X x, X y) { return (y == none_val\
    \ ? x : y); }\r\n  static constexpr X unit() { return none_val; }\r\n  static\
    \ constexpr bool commute = false;\r\n};\r\n#line 2 \"alg/monoid/add_array.hpp\"\
    \n\r\ntemplate <typename E, int K>\r\nstruct Monoid_Add_Array {\r\n  using value_type\
    \ = array<E, K>;\r\n  using X = value_type;\r\n  static X op(X x, X y) {\r\n \
    \   X z;\r\n    FOR(i, K) z[i] = x[i] + y[i];\r\n    return z;\r\n  }\r\n  static\
    \ X unit() { return X{}; }\r\n  static constexpr bool commute = 1;\r\n};\r\n#line\
    \ 5 \"alg/acted_monoid/powersums_assign.hpp\"\n\r\ntemplate <typename mint, int\
    \ K>\r\nstruct ActedMonoid_Power_Sums_Assign {\r\n  using Monoid_X = Monoid_Add_Array<mint,\
    \ K>;\r\n  using Monoid_A = Monoid_Assign<int, -1>;\r\n  using X = typename Monoid_X::value_type;\r\
    \n  using A = typename Monoid_A::value_type;\r\n  static constexpr X act(const\
    \ X &x, const A &a, const ll &size) {\r\n    if (b == -1) return x;\r\n    X y;\r\
    \n    mint pow = 1;\r\n    FOR(i, K) { y[i] = x[0] * pow, pow *= mint(b); }\r\n\
    \    return y;\r\n  }\r\n};\r\n"
  code: "#pragma once\r\n\r\n#include \"alg/monoid/assign.hpp\"\r\n#include \"alg/monoid/add_array.hpp\"\
    \r\n\r\ntemplate <typename mint, int K>\r\nstruct ActedMonoid_Power_Sums_Assign\
    \ {\r\n  using Monoid_X = Monoid_Add_Array<mint, K>;\r\n  using Monoid_A = Monoid_Assign<int,\
    \ -1>;\r\n  using X = typename Monoid_X::value_type;\r\n  using A = typename Monoid_A::value_type;\r\
    \n  static constexpr X act(const X &x, const A &a, const ll &size) {\r\n    if\
    \ (b == -1) return x;\r\n    X y;\r\n    mint pow = 1;\r\n    FOR(i, K) { y[i]\
    \ = x[0] * pow, pow *= mint(b); }\r\n    return y;\r\n  }\r\n};\r\n"
  dependsOn:
  - alg/monoid/assign.hpp
  - alg/monoid/add_array.hpp
  isVerificationFile: false
  path: alg/acted_monoid/powersums_assign.hpp
  requiredBy: []
  timestamp: '2022-12-03 08:35:02+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: alg/acted_monoid/powersums_assign.hpp
layout: document
redirect_from:
- /library/alg/acted_monoid/powersums_assign.hpp
- /library/alg/acted_monoid/powersums_assign.hpp.html
title: alg/acted_monoid/powersums_assign.hpp
---
