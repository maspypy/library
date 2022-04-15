---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"mod/floor_sum.hpp\"\ni128 floor_sum(ll L, ll R, ll a, ll\
    \ b, ll mod) {\r\n  /*\r\n  sum_{x in [L,R)} floor(ax + b, mod)\r\n  */\r\n  assert(L\
    \ <= R);\r\n  i128 res = 0;\r\n  b += L * a;\r\n  ll N = R - L;\r\n  while (N)\
    \ {\r\n    ll q;\r\n    tie(q, a) = divmod(a, mod);\r\n    res += i128(N) * (N\
    \ - 1) / 2 * q;\r\n    tie(q, b) = divmod(b, mod);\r\n    res += i128(N) * q;\r\
    \n    tie(N, b) = divmod(a * N + b, mod);\r\n    tie(a, mod) = mp(mod, a);\r\n\
    \  }\r\n  return res;\r\n}\r\n\r\ni128 mod_sum(ll L, ll R, ll a, ll b, ll mod){\r\
    \n  /*\r\n  sum_{x in [L,R)} (ax + b mod mod)\r\n  */\r\n  i128 s = a * L + b;\r\
    \n  i128 t = a * (R-1) + b;\r\n  i128 sum = (s+t) * (R-L) / 2;\r\n  i128 fsum\
    \ = floor_sum(L, R, a, b, mod);\r\n  return sum - fsum * mod;\r\n}\n"
  code: "i128 floor_sum(ll L, ll R, ll a, ll b, ll mod) {\r\n  /*\r\n  sum_{x in [L,R)}\
    \ floor(ax + b, mod)\r\n  */\r\n  assert(L <= R);\r\n  i128 res = 0;\r\n  b +=\
    \ L * a;\r\n  ll N = R - L;\r\n  while (N) {\r\n    ll q;\r\n    tie(q, a) = divmod(a,\
    \ mod);\r\n    res += i128(N) * (N - 1) / 2 * q;\r\n    tie(q, b) = divmod(b,\
    \ mod);\r\n    res += i128(N) * q;\r\n    tie(N, b) = divmod(a * N + b, mod);\r\
    \n    tie(a, mod) = mp(mod, a);\r\n  }\r\n  return res;\r\n}\r\n\r\ni128 mod_sum(ll\
    \ L, ll R, ll a, ll b, ll mod){\r\n  /*\r\n  sum_{x in [L,R)} (ax + b mod mod)\r\
    \n  */\r\n  i128 s = a * L + b;\r\n  i128 t = a * (R-1) + b;\r\n  i128 sum = (s+t)\
    \ * (R-L) / 2;\r\n  i128 fsum = floor_sum(L, R, a, b, mod);\r\n  return sum -\
    \ fsum * mod;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: mod/floor_sum.hpp
  requiredBy: []
  timestamp: '2022-04-16 04:26:49+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: mod/floor_sum.hpp
layout: document
redirect_from:
- /library/mod/floor_sum.hpp
- /library/mod/floor_sum.hpp.html
title: mod/floor_sum.hpp
---
