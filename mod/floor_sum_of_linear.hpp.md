---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: mod/mod_sum_of_linear.hpp
    title: mod/mod_sum_of_linear.hpp
  - icon: ':heavy_check_mark:'
    path: mod/range_freq_of_linear.hpp
    title: mod/range_freq_of_linear.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/sum_of_floor_of_linear.test.cpp
    title: test/library_checker/math/sum_of_floor_of_linear.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/mod_sum_of_linear.test.cpp
    title: test/mytest/mod_sum_of_linear.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/range_freq_of_linear.test.cpp
    title: test/mytest/range_freq_of_linear.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"mod/floor_sum_of_linear.hpp\"\n\n// sum_{x in [L,R)} floor(ax\
    \ + b, mod)\ni128 floor_sum_of_linear(ll L, ll R, ll a, ll b, ll mod) {\n  assert(L\
    \ <= R);\n  i128 res = 0;\n  b += L * a;\n  ll N = R - L;\n  while (N) {\n   \
    \ ll q;\n    tie(q, a) = divmod(a, mod);\n    res += i128(N) * (N - 1) / 2 * q;\n\
    \    tie(q, b) = divmod(b, mod);\n    res += i128(N) * q;\n    tie(N, b) = divmod(a\
    \ * N + b, mod);\n    tie(a, mod) = mp(mod, a);\n  }\n  return res;\n}\n"
  code: "#pragma once\n\n// sum_{x in [L,R)} floor(ax + b, mod)\ni128 floor_sum_of_linear(ll\
    \ L, ll R, ll a, ll b, ll mod) {\n  assert(L <= R);\n  i128 res = 0;\n  b += L\
    \ * a;\n  ll N = R - L;\n  while (N) {\n    ll q;\n    tie(q, a) = divmod(a, mod);\n\
    \    res += i128(N) * (N - 1) / 2 * q;\n    tie(q, b) = divmod(b, mod);\n    res\
    \ += i128(N) * q;\n    tie(N, b) = divmod(a * N + b, mod);\n    tie(a, mod) =\
    \ mp(mod, a);\n  }\n  return res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: mod/floor_sum_of_linear.hpp
  requiredBy:
  - mod/range_freq_of_linear.hpp
  - mod/mod_sum_of_linear.hpp
  timestamp: '2022-07-22 22:14:52+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/math/sum_of_floor_of_linear.test.cpp
  - test/mytest/mod_sum_of_linear.test.cpp
  - test/mytest/range_freq_of_linear.test.cpp
documentation_of: mod/floor_sum_of_linear.hpp
layout: document
redirect_from:
- /library/mod/floor_sum_of_linear.hpp
- /library/mod/floor_sum_of_linear.hpp.html
title: mod/floor_sum_of_linear.hpp
---
