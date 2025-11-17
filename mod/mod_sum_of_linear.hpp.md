---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: mod/floor_sum_of_linear.hpp
    title: mod/floor_sum_of_linear.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/1_mytest/mod_sum_of_linear.test.cpp
    title: test/1_mytest/mod_sum_of_linear.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"mod/floor_sum_of_linear.hpp\"\n\n// sum_{x in [L,R)} floor(ax\
    \ + b, mod)\n// I \u306F\u7BC4\u56F2\u5185\u3067 ax+b \u304C\u30AA\u30FC\u30D0\
    \u30FC\u30D5\u30ED\u30FC\u3057\u306A\u3044\u7A0B\u5EA6\ntemplate <typename O =\
    \ i128, typename I = long long>\nO floor_sum_of_linear(I L, I R, I a, I b, I mod)\
    \ {\n  assert(L <= R);\n  O res = 0;\n  b += L * a;\n  I N = R - L;\n\n  if (b\
    \ < 0) {\n    I k = ceil(-b, mod);\n    b += k * mod;\n    res -= O(N) * O(k);\n\
    \  }\n\n  while (N) {\n    I q;\n    tie(q, a) = divmod(a, mod);\n    res += (N\
    \ & 1 ? O(N) * O((N - 1) / 2) * O(q) : O(N / 2) * O(N - 1) * O(q));\n    if (b\
    \ >= mod) {\n      tie(q, b) = divmod(b, mod);\n      res += O(N) * q;\n    }\n\
    \    tie(N, b) = divmod(a * N + b, mod);\n    tie(a, mod) = mp(mod, a);\n  }\n\
    \  return res;\n}\n#line 2 \"mod/mod_sum_of_linear.hpp\"\n\ni128 mod_sum_of_linear(ll\
    \ L, ll R, ll a, ll b, ll mod) {\n  /*\n  sum_{x in [L,R)} (ax + b mod mod)\n\
    \  */\n  i128 s = a * L + b;\n  i128 t = a * (R - 1) + b;\n  i128 sum = (s + t)\
    \ * (R - L) / 2;\n  i128 fsum = floor_sum_of_linear(L, R, a, b, mod);\n  return\
    \ sum - fsum * mod;\n}\n"
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
  timestamp: '2023-11-10 22:48:13+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/1_mytest/mod_sum_of_linear.test.cpp
documentation_of: mod/mod_sum_of_linear.hpp
layout: document
redirect_from:
- /library/mod/mod_sum_of_linear.hpp
- /library/mod/mod_sum_of_linear.hpp.html
title: mod/mod_sum_of_linear.hpp
---
