---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: poly/fps_exp.hpp
    title: poly/fps_exp.hpp
  - icon: ':x:'
    path: poly/fps_pow.hpp
    title: poly/fps_pow.hpp
  - icon: ':x:'
    path: poly/sharp_p_subset_sum.hpp
    title: poly/sharp_p_subset_sum.hpp
  - icon: ':x:'
    path: seq/stirling_number_1.hpp
    title: seq/stirling_number_1.hpp
  - icon: ':x:'
    path: seq/stirling_number_2.hpp
    title: seq/stirling_number_2.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/math/sharp_p_subset_sum.test.cpp
    title: test/library_checker/math/sharp_p_subset_sum.test.cpp
  - icon: ':x:'
    path: test/library_checker/math/stirling_number_of_the_first_kind.test.cpp
    title: test/library_checker/math/stirling_number_of_the_first_kind.test.cpp
  - icon: ':x:'
    path: test/library_checker/math/stirling_number_of_the_second_kind.test.cpp
    title: test/library_checker/math/stirling_number_of_the_second_kind.test.cpp
  - icon: ':x:'
    path: test/library_checker/polynomial/exp_of_fps.test.cpp
    title: test/library_checker/polynomial/exp_of_fps.test.cpp
  - icon: ':x:'
    path: test/library_checker/polynomial/exp_of_fps_amint.test.cpp
    title: test/library_checker/polynomial/exp_of_fps_amint.test.cpp
  - icon: ':x:'
    path: test/library_checker/polynomial/pow_of_fps.test.cpp
    title: test/library_checker/polynomial/pow_of_fps.test.cpp
  - icon: ':x:'
    path: test/library_checker/polynomial/pow_of_fps_mint.test.cpp
    title: test/library_checker/polynomial/pow_of_fps_mint.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"poly/integrate.hpp\"\n\ntemplate <typename mint>\nvc<mint>\
    \ integrate(const vc<mint>& f) {\n  vc<mint> g(len(f) + 1);\n  FOR3(i, 1, len(g))\
    \ g[i] = f[i - 1] * inv<mint>(i);\n  return g;\n}\n"
  code: "#pragma once\n\ntemplate <typename mint>\nvc<mint> integrate(const vc<mint>&\
    \ f) {\n  vc<mint> g(len(f) + 1);\n  FOR3(i, 1, len(g)) g[i] = f[i - 1] * inv<mint>(i);\n\
    \  return g;\n}"
  dependsOn: []
  isVerificationFile: false
  path: poly/integrate.hpp
  requiredBy:
  - seq/stirling_number_2.hpp
  - seq/stirling_number_1.hpp
  - poly/fps_exp.hpp
  - poly/sharp_p_subset_sum.hpp
  - poly/fps_pow.hpp
  timestamp: '2022-05-02 13:06:43+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library_checker/math/stirling_number_of_the_second_kind.test.cpp
  - test/library_checker/math/stirling_number_of_the_first_kind.test.cpp
  - test/library_checker/math/sharp_p_subset_sum.test.cpp
  - test/library_checker/polynomial/pow_of_fps.test.cpp
  - test/library_checker/polynomial/exp_of_fps.test.cpp
  - test/library_checker/polynomial/pow_of_fps_mint.test.cpp
  - test/library_checker/polynomial/exp_of_fps_amint.test.cpp
documentation_of: poly/integrate.hpp
layout: document
redirect_from:
- /library/poly/integrate.hpp
- /library/poly/integrate.hpp.html
title: poly/integrate.hpp
---
