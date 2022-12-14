---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':warning:'
    path: alg/monoid/add_tuple_3.hpp
    title: alg/monoid/add_tuple_3.hpp
  _extendedRequiredBy: []
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
    \ }\n  static constexpr bool commute = 1;\n};\n#line 2 \"alg/monoid/add.hpp\"\n\
    \r\ntemplate <typename X>\r\nstruct Monoid_Add {\r\n  using value_type = X;\r\n\
    \  static constexpr X op(const X &x, const X &y) noexcept { return x + y; }\r\n\
    \  static constexpr X inverse(const X &x) noexcept { return -x; }\r\n  static\
    \ constexpr X power(const X &x, ll n) noexcept { return X(n) * x; }\r\n  static\
    \ constexpr X unit() { return X(0); }\r\n  static constexpr bool commute = true;\r\
    \n};\r\n#line 3 \"alg/acted_monoid/powersums_add_3.hpp\"\n\n// \u91CD\u307F\u4ED8\
    \u304D\u591A\u91CD\u96C6\u5408 S \u306E\u8981\u7D20\u306B\u5BFE\u3059\u308B\u3001\
    0,1,2 \u4E57\u548C\u3092\u7BA1\u7406\u3002\ntemplate <typename T>\nstruct ActedMonoid_PowerSum_Add_3\
    \ {\n  using Monoid_X = Monoid_Add_Tuple_3<T, T, T>;\n  using Monoid_A = Monoid_Add<T>;\n\
    \  using X = typename Monoid_X::value_type;\n  using A = typename Monoid_A::value_type;\n\
    \  static X act(const X &x, const A &a, const ll &size) {\n    auto [x0, x1, x2]\
    \ = x;\n    return {x0, x1 + x0 * a, x2 + (a + a) * x1 + a * a * x0};\n  }\n};\n"
  code: "#include \"alg/monoid/add_tuple_3.hpp\"\n#include \"alg/monoid/add.hpp\"\n\
    \n// \u91CD\u307F\u4ED8\u304D\u591A\u91CD\u96C6\u5408 S \u306E\u8981\u7D20\u306B\
    \u5BFE\u3059\u308B\u30010,1,2 \u4E57\u548C\u3092\u7BA1\u7406\u3002\ntemplate <typename\
    \ T>\nstruct ActedMonoid_PowerSum_Add_3 {\n  using Monoid_X = Monoid_Add_Tuple_3<T,\
    \ T, T>;\n  using Monoid_A = Monoid_Add<T>;\n  using X = typename Monoid_X::value_type;\n\
    \  using A = typename Monoid_A::value_type;\n  static X act(const X &x, const\
    \ A &a, const ll &size) {\n    auto [x0, x1, x2] = x;\n    return {x0, x1 + x0\
    \ * a, x2 + (a + a) * x1 + a * a * x0};\n  }\n};\n"
  dependsOn:
  - alg/monoid/add_tuple_3.hpp
  - alg/monoid/add.hpp
  isVerificationFile: false
  path: alg/acted_monoid/powersums_add_3.hpp
  requiredBy: []
  timestamp: '2022-12-15 05:38:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: alg/acted_monoid/powersums_add_3.hpp
layout: document
redirect_from:
- /library/alg/acted_monoid/powersums_add_3.hpp
- /library/alg/acted_monoid/powersums_add_3.hpp.html
title: alg/acted_monoid/powersums_add_3.hpp
---
