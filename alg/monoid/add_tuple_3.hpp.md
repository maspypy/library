---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: alg/acted_monoid/powersums_add_3.hpp
    title: alg/acted_monoid/powersums_add_3.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"alg/monoid/add_tuple_3.hpp\"\ntemplate <typename E1, typename\
    \ E2, typename E3>\nstruct Monoid_Add_Tuple_3 {\n  using value_type = tuple<E1,\
    \ E2, E3>;\n  using X = value_type;\n  static X op(X x, X y) {\n    auto [x0,\
    \ x1, x2] = x;\n    auto [y0, y1, y2] = y;\n    return {x0 + y0, x1 + y1, x2 +\
    \ y2};\n  }\n  static X inverse(X x) {\n    auto [x0, x1, x2] = x;\n    return\
    \ {-x0, -x1, -x2};\n  }\n  static constexpr X unit() { return {E1(0), E2(0), E3(0)};\
    \ }\n  static constexpr bool commute = 1;\n};\n"
  code: "template <typename E1, typename E2, typename E3>\nstruct Monoid_Add_Tuple_3\
    \ {\n  using value_type = tuple<E1, E2, E3>;\n  using X = value_type;\n  static\
    \ X op(X x, X y) {\n    auto [x0, x1, x2] = x;\n    auto [y0, y1, y2] = y;\n \
    \   return {x0 + y0, x1 + y1, x2 + y2};\n  }\n  static X inverse(X x) {\n    auto\
    \ [x0, x1, x2] = x;\n    return {-x0, -x1, -x2};\n  }\n  static constexpr X unit()\
    \ { return {E1(0), E2(0), E3(0)}; }\n  static constexpr bool commute = 1;\n};"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid/add_tuple_3.hpp
  requiredBy:
  - alg/acted_monoid/powersums_add_3.hpp
  timestamp: '2022-12-15 05:38:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: alg/monoid/add_tuple_3.hpp
layout: document
redirect_from:
- /library/alg/monoid/add_tuple_3.hpp
- /library/alg/monoid/add_tuple_3.hpp.html
title: alg/monoid/add_tuple_3.hpp
---
