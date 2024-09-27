---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':question:'
    path: ds/segtree/range_assignment_segtree.hpp
    title: ds/segtree/range_assignment_segtree.hpp
  - icon: ':question:'
    path: mod/floor_monoid_product.hpp
    title: mod/floor_monoid_product.hpp
  - icon: ':question:'
    path: mod/floor_sum_of_linear_polynomial.hpp
    title: mod/floor_sum_of_linear_polynomial.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/floor_sum_of_polynomial.test.cpp
    title: test/1_mytest/floor_sum_of_polynomial.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/range_assign.test.cpp
    title: test/1_mytest/range_assign.test.cpp
  - icon: ':x:'
    path: test/2_library_checker/data_structure/range_set_range_composite.test.cpp
    title: test/2_library_checker/data_structure/range_set_range_composite.test.cpp
  - icon: ':x:'
    path: test/2_library_checker/number_theory/sum_of_floor_of_linear_2.test.cpp
    title: test/2_library_checker/number_theory/sum_of_floor_of_linear_2.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/2362.test.cpp
    title: test/3_yukicoder/2362.test.cpp
  - icon: ':x:'
    path: test/5_atcoder/abc200f.test.cpp
    title: test/5_atcoder/abc200f.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid_pow.hpp\"\n\n// chat gpt\ntemplate <typename\
    \ U, typename Arg1, typename Arg2>\nstruct has_power_method {\nprivate:\n  //\
    \ \u30D8\u30EB\u30D1\u30FC\u95A2\u6570\u306E\u5B9F\u88C5\n  template <typename\
    \ V, typename A1, typename A2>\n  static auto check(int)\n      -> decltype(std::declval<V>().power(std::declval<A1>(),\n\
    \                                          std::declval<A2>()),\n            \
    \      std::true_type{});\n  template <typename, typename, typename>\n  static\
    \ auto check(...) -> std::false_type;\n\npublic:\n  // \u30E1\u30BD\u30C3\u30C9\
    \u306E\u6709\u7121\u3092\u8868\u3059\u578B\n  static constexpr bool value = decltype(check<U,\
    \ Arg1, Arg2>(0))::value;\n};\n\ntemplate <typename Monoid>\ntypename Monoid::X\
    \ monoid_pow(typename Monoid::X x, ll exp) {\n  using X = typename Monoid::X;\n\
    \  if constexpr (has_power_method<Monoid, X, ll>::value) {\n    return Monoid::power(x,\
    \ exp);\n  } else {\n    assert(exp >= 0);\n    X res = Monoid::unit();\n    while\
    \ (exp) {\n      if (exp & 1) res = Monoid::op(res, x);\n      x = Monoid::op(x,\
    \ x);\n      exp >>= 1;\n    }\n    return res;\n  }\n}\n"
  code: "#pragma once\n\n// chat gpt\ntemplate <typename U, typename Arg1, typename\
    \ Arg2>\nstruct has_power_method {\nprivate:\n  // \u30D8\u30EB\u30D1\u30FC\u95A2\
    \u6570\u306E\u5B9F\u88C5\n  template <typename V, typename A1, typename A2>\n\
    \  static auto check(int)\n      -> decltype(std::declval<V>().power(std::declval<A1>(),\n\
    \                                          std::declval<A2>()),\n            \
    \      std::true_type{});\n  template <typename, typename, typename>\n  static\
    \ auto check(...) -> std::false_type;\n\npublic:\n  // \u30E1\u30BD\u30C3\u30C9\
    \u306E\u6709\u7121\u3092\u8868\u3059\u578B\n  static constexpr bool value = decltype(check<U,\
    \ Arg1, Arg2>(0))::value;\n};\n\ntemplate <typename Monoid>\ntypename Monoid::X\
    \ monoid_pow(typename Monoid::X x, ll exp) {\n  using X = typename Monoid::X;\n\
    \  if constexpr (has_power_method<Monoid, X, ll>::value) {\n    return Monoid::power(x,\
    \ exp);\n  } else {\n    assert(exp >= 0);\n    X res = Monoid::unit();\n    while\
    \ (exp) {\n      if (exp & 1) res = Monoid::op(res, x);\n      x = Monoid::op(x,\
    \ x);\n      exp >>= 1;\n    }\n    return res;\n  }\n}"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid_pow.hpp
  requiredBy:
  - mod/floor_sum_of_linear_polynomial.hpp
  - mod/floor_monoid_product.hpp
  - ds/segtree/range_assignment_segtree.hpp
  timestamp: '2024-01-23 03:59:43+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/1_mytest/floor_sum_of_polynomial.test.cpp
  - test/1_mytest/range_assign.test.cpp
  - test/2_library_checker/data_structure/range_set_range_composite.test.cpp
  - test/2_library_checker/number_theory/sum_of_floor_of_linear_2.test.cpp
  - test/3_yukicoder/2362.test.cpp
  - test/5_atcoder/abc200f.test.cpp
documentation_of: alg/monoid_pow.hpp
layout: document
redirect_from:
- /library/alg/monoid_pow.hpp
- /library/alg/monoid_pow.hpp.html
title: alg/monoid_pow.hpp
---
