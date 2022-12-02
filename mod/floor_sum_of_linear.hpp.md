---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: mod/mod_sum_of_linear.hpp
    title: mod/mod_sum_of_linear.hpp
  - icon: ':question:'
    path: mod/range_freq_of_linear.hpp
    title: mod/range_freq_of_linear.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/min_of_mod_of_linear_2.test.cpp
    title: test/library_checker/math/min_of_mod_of_linear_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/sum_of_floor_of_linear.test.cpp
    title: test/library_checker/math/sum_of_floor_of_linear.test.cpp
  - icon: ':x:'
    path: test/mytest/mod_sum_of_linear.test.cpp
    title: test/mytest/mod_sum_of_linear.test.cpp
  - icon: ':x:'
    path: test/mytest/range_freq_of_linear.test.cpp
    title: test/mytest/range_freq_of_linear.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1201.test.cpp
    title: test/yukicoder/1201.test.cpp
  - icon: ':x:'
    path: test/yukicoder/2066.test.cpp
    title: test/yukicoder/2066.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"mod/floor_sum_of_linear.hpp\"\n\n// sum_{x in [L,R)} floor(ax\
    \ + b, mod)\ni128 floor_sum_of_linear(ll L, ll R, ll a, ll b, ll mod) {\n  assert(L\
    \ <= R);\n  i128 res = 0;\n  b += L * a;\n  ll N = R - L;\n\n  if (b < 0) {\n\
    \    ll k = ceil(-b, mod);\n    b += k * mod;\n    res -= i128(N) * k;\n  }\n\n\
    \  while (N) {\n    ll q;\n    tie(q, a) = divmod(a, mod);\n    res += i128(N)\
    \ * (N - 1) / 2 * q;\n    if (b >= mod) {\n      tie(q, b) = divmod(b, mod);\n\
    \      res += i128(N) * q;\n    }\n    tie(N, b) = divmod(a * N + b, mod);\n \
    \   tie(a, mod) = mp(mod, a);\n  }\n  return res;\n}\n"
  code: "#pragma once\n\n// sum_{x in [L,R)} floor(ax + b, mod)\ni128 floor_sum_of_linear(ll\
    \ L, ll R, ll a, ll b, ll mod) {\n  assert(L <= R);\n  i128 res = 0;\n  b += L\
    \ * a;\n  ll N = R - L;\n\n  if (b < 0) {\n    ll k = ceil(-b, mod);\n    b +=\
    \ k * mod;\n    res -= i128(N) * k;\n  }\n\n  while (N) {\n    ll q;\n    tie(q,\
    \ a) = divmod(a, mod);\n    res += i128(N) * (N - 1) / 2 * q;\n    if (b >= mod)\
    \ {\n      tie(q, b) = divmod(b, mod);\n      res += i128(N) * q;\n    }\n   \
    \ tie(N, b) = divmod(a * N + b, mod);\n    tie(a, mod) = mp(mod, a);\n  }\n  return\
    \ res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: mod/floor_sum_of_linear.hpp
  requiredBy:
  - mod/mod_sum_of_linear.hpp
  - mod/range_freq_of_linear.hpp
  timestamp: '2022-09-19 03:25:55+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/2066.test.cpp
  - test/yukicoder/1201.test.cpp
  - test/mytest/mod_sum_of_linear.test.cpp
  - test/mytest/range_freq_of_linear.test.cpp
  - test/library_checker/math/sum_of_floor_of_linear.test.cpp
  - test/library_checker/math/min_of_mod_of_linear_2.test.cpp
documentation_of: mod/floor_sum_of_linear.hpp
layout: document
redirect_from:
- /library/mod/floor_sum_of_linear.hpp
- /library/mod/floor_sum_of_linear.hpp.html
title: mod/floor_sum_of_linear.hpp
---
