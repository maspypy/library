---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: mod/floor_sum_of_linear.hpp
    title: mod/floor_sum_of_linear.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/min_of_mod_of_linear_2.test.cpp
    title: test/library_checker/math/min_of_mod_of_linear_2.test.cpp
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
    \ <= R);\n  i128 res = 0;\n  b += L * a;\n  ll N = R - L;\n\n  if (b < 0) {\n\
    \    ll k = ceil(-b, mod);\n    b += k * mod;\n    res -= i128(N) * k;\n  }\n\n\
    \  while (N) {\n    ll q;\n    tie(q, a) = divmod(a, mod);\n    res += i128(N)\
    \ * (N - 1) / 2 * q;\n    if (b >= mod) {\n      tie(q, b) = divmod(b, mod);\n\
    \      res += i128(N) * q;\n    }\n    tie(N, b) = divmod(a * N + b, mod);\n \
    \   tie(a, mod) = mp(mod, a);\n  }\n  return res;\n}\n#line 2 \"mod/range_freq_of_linear.hpp\"\
    \n\n// L <= x < R \u306E\u3046\u3061\u3067\u3001(ax+b mod) in [lo, hi) \u3068\u306A\
    \u308B\u3082\u306E\u306E\u500B\u6570\nll range_freq_of_linear(ll L, ll R, ll a,\
    \ ll b, ll mod, ll lo, ll hi) {\n  if (lo >= hi) return 0;\n  assert(0 <= lo &&\
    \ lo < hi && hi <= mod);\n\n  i128 x1 = floor_sum_of_linear(L, R, a, b - lo, mod);\n\
    \  i128 x2 = floor_sum_of_linear(L, R, a, b - hi, mod);\n  return x1 - x2;\n}\n"
  code: "#include \"mod/floor_sum_of_linear.hpp\"\n\n// L <= x < R \u306E\u3046\u3061\
    \u3067\u3001(ax+b mod) in [lo, hi) \u3068\u306A\u308B\u3082\u306E\u306E\u500B\u6570\
    \nll range_freq_of_linear(ll L, ll R, ll a, ll b, ll mod, ll lo, ll hi) {\n  if\
    \ (lo >= hi) return 0;\n  assert(0 <= lo && lo < hi && hi <= mod);\n\n  i128 x1\
    \ = floor_sum_of_linear(L, R, a, b - lo, mod);\n  i128 x2 = floor_sum_of_linear(L,\
    \ R, a, b - hi, mod);\n  return x1 - x2;\n}\n"
  dependsOn:
  - mod/floor_sum_of_linear.hpp
  isVerificationFile: false
  path: mod/range_freq_of_linear.hpp
  requiredBy: []
  timestamp: '2022-09-19 03:25:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/math/min_of_mod_of_linear_2.test.cpp
  - test/mytest/range_freq_of_linear.test.cpp
documentation_of: mod/range_freq_of_linear.hpp
layout: document
redirect_from:
- /library/mod/range_freq_of_linear.hpp
- /library/mod/range_freq_of_linear.hpp.html
title: mod/range_freq_of_linear.hpp
---
