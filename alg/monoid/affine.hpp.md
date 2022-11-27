---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':question:'
    path: alg/lazy/cntsum_affine.hpp
    title: alg/lazy/cntsum_affine.hpp
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
  - icon: ':x:'
    path: test/yukicoder/255.test.cpp
    title: test/yukicoder/255.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"alg/monoid/affine.hpp\"\ntemplate <typename K>\nstruct Group_Affine\
    \ {\n  using F = pair<K, K>;\n  using value_type = F;\n  static constexpr F op(const\
    \ F &x, const F &y) noexcept {\n    return F({x.first * y.first, x.second * y.first\
    \ + y.second});\n  }\n  static constexpr F inverse(const F &x) {\n    auto [a,\
    \ b] = x;\n    a = K(1) / a;\n    return {a, a * (-b)};\n  }\n  static constexpr\
    \ K eval(const F &f, K x) noexcept {\n    return f.first * x + f.second;\n  }\n\
    \  static constexpr F unit() { return {K(1), K(0)}; }\n  static constexpr bool\
    \ commute = false;\n};\n"
  code: "template <typename K>\nstruct Group_Affine {\n  using F = pair<K, K>;\n \
    \ using value_type = F;\n  static constexpr F op(const F &x, const F &y) noexcept\
    \ {\n    return F({x.first * y.first, x.second * y.first + y.second});\n  }\n\
    \  static constexpr F inverse(const F &x) {\n    auto [a, b] = x;\n    a = K(1)\
    \ / a;\n    return {a, a * (-b)};\n  }\n  static constexpr K eval(const F &f,\
    \ K x) noexcept {\n    return f.first * x + f.second;\n  }\n  static constexpr\
    \ F unit() { return {K(1), K(0)}; }\n  static constexpr bool commute = false;\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid/affine.hpp
  requiredBy:
  - alg/lazy/cntsum_affine.hpp
  timestamp: '2022-11-27 13:06:40+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/255.test.cpp
  - test/library_checker/datastructure/dynamic_sequence_range_affine_range_sum_rbst.test.cpp
  - test/library_checker/datastructure/dynamic_sequence_range_affine_range_sum_splay.test.cpp
  - test/library_checker/datastructure/range_affine_range_sum.test.cpp
documentation_of: alg/monoid/affine.hpp
layout: document
redirect_from:
- /library/alg/monoid/affine.hpp
- /library/alg/monoid/affine.hpp.html
title: alg/monoid/affine.hpp
---
