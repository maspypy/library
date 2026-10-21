---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':question:'
    path: alg/monoid/minmincnt.hpp
    title: alg/monoid/minmincnt.hpp
  _extendedRequiredBy:
  - icon: ':question:'
    path: ds/rectangle_union.hpp
    title: ds/rectangle_union.hpp
  - icon: ':warning:'
    path: graph/count/count_connected_intervals.hpp
    title: graph/count/count_connected_intervals.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/data_structure/area_of_union_of_rectangles.test.cpp
    title: test/2_library_checker/data_structure/area_of_union_of_rectangles.test.cpp
  - icon: ':x:'
    path: test/4_aoj/DSL_4_A.test.cpp
    title: test/4_aoj/DSL_4_A.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links:
    - https://github.com/maspypy/library/blob/main/alg/acted_monoid/minmincnt_add.hpp
  bundledCode: "#line 1 \"alg/acted_monoid/minmincnt_add.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/alg/acted_monoid/minmincnt_add.hpp\n\
    #line 1 \"alg/monoid/minmincnt.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/alg/monoid/minmincnt.hpp\n\
    \n// \u6700\u5C0F\u5024\u3001\u6700\u5C0F\u5024\u306E\u500B\u6570\ntemplate <typename\
    \ E>\nstruct Monoid_MinMincnt {\n  using value_type = pair<E, E>;\n  using X =\
    \ value_type;\n  static X op(X x, X y) {\n    auto [xmin, xmincnt] = x;\n    auto\
    \ [ymin, ymincnt] = y;\n    if (xmin > ymin) return y;\n    if (xmin < ymin) return\
    \ x;\n    return {xmin, xmincnt + ymincnt};\n  }\n  static constexpr X id() {\
    \ return {infty<E>, 0}; }\n  static constexpr bool commute = true;\n};\n#line\
    \ 1 \"alg/monoid/add.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/alg/monoid/add.hpp\n\
    \ntemplate <typename E>\nstruct Monoid_Add {\n  using X = E;\n  using value_type\
    \ = X;\n  static constexpr X op(const X &x, const X &y) noexcept { return x +\
    \ y; }\n  static constexpr X inverse(const X &x) noexcept { return -x; }\n  static\
    \ constexpr X power(const X &x, ll n) noexcept { return X(n) * x; }\n  static\
    \ constexpr X id() { return X(0); }\n  static constexpr bool commute = true;\n\
    };\n#line 4 \"alg/acted_monoid/minmincnt_add.hpp\"\n\ntemplate <typename E>\n\
    struct ActedMonoid_MinMincnt_Add {\n  using Monoid_X = Monoid_MinMincnt<E>;\n\
    \  using Monoid_A = Monoid_Add<E>;\n  using X = typename Monoid_X::value_type;\n\
    \  using A = typename Monoid_A::value_type;\n  static constexpr X act(const X\
    \ &x, const A &a, const ll &size) {\n    auto [xmin, xmincnt] = x;\n    if (xmin\
    \ == infty<E>) return x;\n    return {xmin + a, xmincnt};\n  }\n};\n"
  code: "// Source: https://github.com/maspypy/library/blob/main/alg/acted_monoid/minmincnt_add.hpp\n\
    #include \"alg/monoid/minmincnt.hpp\"\n#include \"alg/monoid/add.hpp\"\n\ntemplate\
    \ <typename E>\nstruct ActedMonoid_MinMincnt_Add {\n  using Monoid_X = Monoid_MinMincnt<E>;\n\
    \  using Monoid_A = Monoid_Add<E>;\n  using X = typename Monoid_X::value_type;\n\
    \  using A = typename Monoid_A::value_type;\n  static constexpr X act(const X\
    \ &x, const A &a, const ll &size) {\n    auto [xmin, xmincnt] = x;\n    if (xmin\
    \ == infty<E>) return x;\n    return {xmin + a, xmincnt};\n  }\n};\n"
  dependsOn:
  - alg/monoid/minmincnt.hpp
  - alg/monoid/add.hpp
  isVerificationFile: false
  path: alg/acted_monoid/minmincnt_add.hpp
  requiredBy:
  - graph/count/count_connected_intervals.hpp
  - ds/rectangle_union.hpp
  timestamp: '2026-10-15 19:54:56+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/4_aoj/DSL_4_A.test.cpp
  - test/2_library_checker/data_structure/area_of_union_of_rectangles.test.cpp
documentation_of: alg/acted_monoid/minmincnt_add.hpp
layout: document
redirect_from:
- /library/alg/acted_monoid/minmincnt_add.hpp
- /library/alg/acted_monoid/minmincnt_add.hpp.html
title: alg/acted_monoid/minmincnt_add.hpp
---
