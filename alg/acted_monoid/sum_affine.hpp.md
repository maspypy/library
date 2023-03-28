---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':heavy_check_mark:'
    path: alg/monoid/affine.hpp
    title: alg/monoid/affine.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/dynamic_sequence_range_affine_range_sum_rbst.test.cpp
    title: test/library_checker/datastructure/dynamic_sequence_range_affine_range_sum_rbst.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/dynamic_sequence_range_affine_range_sum_splay.test.cpp
    title: test/library_checker/datastructure/dynamic_sequence_range_affine_range_sum_splay.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/range_affine_range_sum.test.cpp
    title: test/library_checker/datastructure/range_affine_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/add.hpp\"\n\r\ntemplate <typename X>\r\nstruct\
    \ Monoid_Add {\r\n  using value_type = X;\r\n  static constexpr X op(const X &x,\
    \ const X &y) noexcept { return x + y; }\r\n  static constexpr X inverse(const\
    \ X &x) noexcept { return -x; }\r\n  static constexpr X power(const X &x, ll n)\
    \ noexcept { return X(n) * x; }\r\n  static constexpr X unit() { return X(0);\
    \ }\r\n  static constexpr bool commute = true;\r\n};\r\n#line 2 \"alg/monoid/affine.hpp\"\
    \n\ntemplate <typename K>\nstruct Monoid_Affine {\n  using F = pair<K, K>;\n \
    \ using value_type = F;\n  static constexpr F op(const F &x, const F &y) noexcept\
    \ {\n    return F({x.first * y.first, x.second * y.first + y.second});\n  }\n\
    \  static constexpr F inverse(const F &x) {\n    auto [a, b] = x;\n    a = K(1)\
    \ / a;\n    return {a, a * (-b)};\n  }\n  static constexpr K eval(const F &f,\
    \ K x) noexcept {\n    return f.first * x + f.second;\n  }\n  static constexpr\
    \ F unit() { return {K(1), K(0)}; }\n  static constexpr bool commute = false;\n\
    };\n#line 3 \"alg/acted_monoid/sum_affine.hpp\"\n\r\ntemplate <typename E>\r\n\
    struct ActedMonoid_Sum_Affine {\r\n  using Monoid_X = Monoid_Add<E>;\r\n  using\
    \ Monoid_A = Monoid_Affine<E>;\r\n  using X = typename Monoid_X::value_type;\r\
    \n  using A = typename Monoid_A::value_type;\r\n  static constexpr X act(const\
    \ X &x, const A &a, const ll &size) {\r\n    return x * a.fi + E(size) * a.se;\r\
    \n  }\r\n};\r\n"
  code: "#include \"alg/monoid/add.hpp\"\r\n#include \"alg/monoid/affine.hpp\"\r\n\
    \r\ntemplate <typename E>\r\nstruct ActedMonoid_Sum_Affine {\r\n  using Monoid_X\
    \ = Monoid_Add<E>;\r\n  using Monoid_A = Monoid_Affine<E>;\r\n  using X = typename\
    \ Monoid_X::value_type;\r\n  using A = typename Monoid_A::value_type;\r\n  static\
    \ constexpr X act(const X &x, const A &a, const ll &size) {\r\n    return x *\
    \ a.fi + E(size) * a.se;\r\n  }\r\n};\r\n"
  dependsOn:
  - alg/monoid/add.hpp
  - alg/monoid/affine.hpp
  isVerificationFile: false
  path: alg/acted_monoid/sum_affine.hpp
  requiredBy: []
  timestamp: '2022-12-03 07:16:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/datastructure/dynamic_sequence_range_affine_range_sum_rbst.test.cpp
  - test/library_checker/datastructure/range_affine_range_sum.test.cpp
  - test/library_checker/datastructure/dynamic_sequence_range_affine_range_sum_splay.test.cpp
documentation_of: alg/acted_monoid/sum_affine.hpp
layout: document
redirect_from:
- /library/alg/acted_monoid/sum_affine.hpp
- /library/alg/acted_monoid/sum_affine.hpp.html
title: alg/acted_monoid/sum_affine.hpp
---
