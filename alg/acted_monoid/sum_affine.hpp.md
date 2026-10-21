---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':heavy_check_mark:'
    path: alg/monoid/affine.hpp
    title: alg/monoid/affine.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/data_structure/dynamic_sequence_range_affine_range_sum_rbst.test.cpp
    title: test/2_library_checker/data_structure/dynamic_sequence_range_affine_range_sum_rbst.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/data_structure/dynamic_sequence_range_affine_range_sum_splay.test.cpp
    title: test/2_library_checker/data_structure/dynamic_sequence_range_affine_range_sum_splay.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/data_structure/persistent_range_affine_range_sum.test.cpp
    title: test/2_library_checker/data_structure/persistent_range_affine_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/data_structure/range_affine_range_sum.test.cpp
    title: test/2_library_checker/data_structure/range_affine_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/2342.test.cpp
    title: test/3_yukicoder/2342.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://github.com/maspypy/library/blob/main/alg/acted_monoid/sum_affine.hpp
  bundledCode: "#line 1 \"alg/acted_monoid/sum_affine.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/alg/acted_monoid/sum_affine.hpp\n\
    #line 1 \"alg/monoid/add.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/alg/monoid/add.hpp\n\
    \ntemplate <typename E>\nstruct Monoid_Add {\n  using X = E;\n  using value_type\
    \ = X;\n  static constexpr X op(const X &x, const X &y) noexcept { return x +\
    \ y; }\n  static constexpr X inverse(const X &x) noexcept { return -x; }\n  static\
    \ constexpr X power(const X &x, ll n) noexcept { return X(n) * x; }\n  static\
    \ constexpr X id() { return X(0); }\n  static constexpr bool commute = true;\n\
    };\n#line 1 \"alg/monoid/affine.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/alg/monoid/affine.hpp\n\
    \n// op(F, G) = comp(G,F), F \u306E\u3042\u3068\u3067 G\ntemplate <typename K>\n\
    struct Monoid_Affine {\n  using F = pair<K, K>;\n  using value_type = F;\n  using\
    \ X = value_type;\n  static constexpr F op(const F &x, const F &y) noexcept {\n\
    \    return F({x.first * y.first, x.second * y.first + y.second});\n  }\n  static\
    \ constexpr F inverse(const F &x) {\n    auto [a, b] = x;\n    a = K(1) / a;\n\
    \    return {a, a * (-b)};\n  }\n  static constexpr K eval(const F &f, K x) noexcept\
    \ {\n    return f.first * x + f.second;\n  }\n  static constexpr F id() { return\
    \ {K(1), K(0)}; }\n  static constexpr bool commute = false;\n};\n#line 4 \"alg/acted_monoid/sum_affine.hpp\"\
    \n\ntemplate <typename E>\nstruct ActedMonoid_Sum_Affine {\n  using Monoid_X =\
    \ Monoid_Add<E>;\n  using Monoid_A = Monoid_Affine<E>;\n  using X = typename Monoid_X::value_type;\n\
    \  using A = typename Monoid_A::value_type;\n  static constexpr X act(const X\
    \ &x, const A &a, const ll &size) {\n    return x * a.fi + E(size) * a.se;\n \
    \ }\n};\n"
  code: "// Source: https://github.com/maspypy/library/blob/main/alg/acted_monoid/sum_affine.hpp\n\
    #include \"alg/monoid/add.hpp\"\n#include \"alg/monoid/affine.hpp\"\n\ntemplate\
    \ <typename E>\nstruct ActedMonoid_Sum_Affine {\n  using Monoid_X = Monoid_Add<E>;\n\
    \  using Monoid_A = Monoid_Affine<E>;\n  using X = typename Monoid_X::value_type;\n\
    \  using A = typename Monoid_A::value_type;\n  static constexpr X act(const X\
    \ &x, const A &a, const ll &size) {\n    return x * a.fi + E(size) * a.se;\n \
    \ }\n};\n"
  dependsOn:
  - alg/monoid/add.hpp
  - alg/monoid/affine.hpp
  isVerificationFile: false
  path: alg/acted_monoid/sum_affine.hpp
  requiredBy: []
  timestamp: '2026-10-15 19:54:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/3_yukicoder/2342.test.cpp
  - test/2_library_checker/data_structure/dynamic_sequence_range_affine_range_sum_rbst.test.cpp
  - test/2_library_checker/data_structure/persistent_range_affine_range_sum.test.cpp
  - test/2_library_checker/data_structure/range_affine_range_sum.test.cpp
  - test/2_library_checker/data_structure/dynamic_sequence_range_affine_range_sum_splay.test.cpp
documentation_of: alg/acted_monoid/sum_affine.hpp
layout: document
redirect_from:
- /library/alg/acted_monoid/sum_affine.hpp
- /library/alg/acted_monoid/sum_affine.hpp.html
title: alg/acted_monoid/sum_affine.hpp
---
