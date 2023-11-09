---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: mod/floor_sum_of_linear.hpp
    title: mod/floor_sum_of_linear.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest/mod_sum_of_linear.test.cpp
    title: test/mytest/mod_sum_of_linear.test.cpp
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
    \   tie(a, mod) = mp(mod, a);\n  }\n  return res;\n}\n#line 2 \"mod/mod_sum_of_linear.hpp\"\
    \n\ni128 mod_sum_of_linear(ll L, ll R, ll a, ll b, ll mod) {\n  /*\n  sum_{x in\
    \ [L,R)} (ax + b mod mod)\n  */\n  i128 s = a * L + b;\n  i128 t = a * (R - 1)\
    \ + b;\n  i128 sum = (s + t) * (R - L) / 2;\n  i128 fsum = floor_sum_of_linear(L,\
    \ R, a, b, mod);\n  return sum - fsum * mod;\n}\n"
  code: "#include \"mod/floor_sum_of_linear.hpp\"\n\ni128 mod_sum_of_linear(ll L,\
    \ ll R, ll a, ll b, ll mod) {\n  /*\n  sum_{x in [L,R)} (ax + b mod mod)\n  */\n\
    \  i128 s = a * L + b;\n  i128 t = a * (R - 1) + b;\n  i128 sum = (s + t) * (R\
    \ - L) / 2;\n  i128 fsum = floor_sum_of_linear(L, R, a, b, mod);\n  return sum\
    \ - fsum * mod;\n}\n"
  dependsOn:
  - mod/floor_sum_of_linear.hpp
  isVerificationFile: false
  path: mod/mod_sum_of_linear.hpp
  requiredBy: []
  timestamp: '2022-09-19 03:25:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/mod_sum_of_linear.test.cpp
documentation_of: mod/mod_sum_of_linear.hpp
layout: document
redirect_from:
- /library/mod/mod_sum_of_linear.hpp
- /library/mod/mod_sum_of_linear.hpp.html
title: mod/mod_sum_of_linear.hpp
---
