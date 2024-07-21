---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest/O1_inv.test.cpp
    title: test/mytest/O1_inv.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://qoj.ac/problem/5
  bundledCode: "#line 1 \"mod/O1_inverse.hpp\"\n\n// https://qoj.ac/problem/5\n//\
    \ precompute O(p^{2/3}), query O(1)\n// 10^8 query: 3sec\ntemplate <typename mint>\n\
    mint O1_inverse(int a) {\n  /*\n  n^3>=p \u3068\u306A\u308B\u3088\u3046\u306B\
    \ n \u3092\u3068\u308A, n^2\u307E\u3067\u306F\u524D\u8A08\u7B97.\n  a/p \u3092\
    \u6709\u7406\u6570\u8FD1\u4F3C\u3059\u308B x/y. |a/p-x/y|<=|1/ny \u3068\u306A\u308B\
    \u3068\n  |ay-px|<=p/n<=n^2 \u3088\u308A(ay)^{-1}\u304C\u524D\u8A08\u7B97\u3055\
    \u308C\u3066\u3044\u308B\u306E\u3067\u3067\u304D\u308B.\n\n  x/y \u306F\u5206\u6BCD\
    \ n \u672A\u6E80\u306E Farey \u6570\u5217\u306E\u524D\u5F8C\u3069\u3061\u3089\u304B\
    \u304C\u6E80\u305F\u3059.\n  n^2 bucket \u306B\u5206\u5272\u3057\u3066\u304A\u304F\
    \u3068 bucket \u3054\u3068\u306E\u6709\u7406\u6570\u306F distinct.\n  \u524D\u5F8C\
    \u306E\u3046\u3061\u826F\u3044\u65B9\u3092\u9078\u3079\u3070\u3088\u3044.\n  */\n\
    \  static int p = 0;\n  static double cp = 0.0;\n  static vc<int> FRAC;\n  static\
    \ vc<mint> invs;\n  if (p != mint::get_mod()) {\n    p = mint::get_mod();\n  \
    \  int k = min(2 << 20, p);\n    invs.resize(k);\n    invs[1] = 1;\n    FOR(i,\
    \ 2, k) {\n      int q = (p + i - 1) / i;\n      invs[i] = invs[i * q - p] * mint::raw(q);\n\
    \    }\n    assert(p <= (1 << 30));\n    FRAC.assign(1 << 20, -1);\n    cp = 1.0\
    \ * (1 << 20) / p;\n    for (int y = 1023; y >= 1; --y) {\n      for (int x =\
    \ 0; x < y; ++x) { FRAC[(x << 20) / y] = {x << 10 | y}; }\n    }\n    FOR(i, 1,\
    \ len(FRAC)) if (FRAC[i] == -1) FRAC[i] = FRAC[i - 1];\n    int nxt = 1025;\n\
    \    FOR_R(i, 1, len(FRAC)) {\n      if (FRAC[i] != FRAC[i - 1]) {\n        nxt\
    \ = FRAC[i];\n        continue;\n      }\n      int x1 = FRAC[i] >> 10, y1 = FRAC[i]\
    \ & 1023;\n      int x2 = nxt >> 10, y2 = nxt & 1023;\n      int c1 = i * y1 -\
    \ (x1 << 20);\n      int c2 = i * y2 - (x2 << 20);\n      if (abs(c2) < abs(c1))\
    \ FRAC[i] = nxt;\n    }\n  }\n  assert(0 <= a && a < p);\n  if (a < len(invs))\
    \ return invs[a];\n\n  int k = a * cp;\n  ll x = FRAC[k] >> 10, y = FRAC[k] &\
    \ 1023;\n  int c = ll(a) * y - ll(p) * x;\n  if (c < 0) c = -c, y = -y;\n  return\
    \ invs[c] * mint(y);\n}\n"
  code: "\n// https://qoj.ac/problem/5\n// precompute O(p^{2/3}), query O(1)\n// 10^8\
    \ query: 3sec\ntemplate <typename mint>\nmint O1_inverse(int a) {\n  /*\n  n^3>=p\
    \ \u3068\u306A\u308B\u3088\u3046\u306B n \u3092\u3068\u308A, n^2\u307E\u3067\u306F\
    \u524D\u8A08\u7B97.\n  a/p \u3092\u6709\u7406\u6570\u8FD1\u4F3C\u3059\u308B x/y.\
    \ |a/p-x/y|<=|1/ny \u3068\u306A\u308B\u3068\n  |ay-px|<=p/n<=n^2 \u3088\u308A\
    (ay)^{-1}\u304C\u524D\u8A08\u7B97\u3055\u308C\u3066\u3044\u308B\u306E\u3067\u3067\
    \u304D\u308B.\n\n  x/y \u306F\u5206\u6BCD n \u672A\u6E80\u306E Farey \u6570\u5217\
    \u306E\u524D\u5F8C\u3069\u3061\u3089\u304B\u304C\u6E80\u305F\u3059.\n  n^2 bucket\
    \ \u306B\u5206\u5272\u3057\u3066\u304A\u304F\u3068 bucket \u3054\u3068\u306E\u6709\
    \u7406\u6570\u306F distinct.\n  \u524D\u5F8C\u306E\u3046\u3061\u826F\u3044\u65B9\
    \u3092\u9078\u3079\u3070\u3088\u3044.\n  */\n  static int p = 0;\n  static double\
    \ cp = 0.0;\n  static vc<int> FRAC;\n  static vc<mint> invs;\n  if (p != mint::get_mod())\
    \ {\n    p = mint::get_mod();\n    int k = min(2 << 20, p);\n    invs.resize(k);\n\
    \    invs[1] = 1;\n    FOR(i, 2, k) {\n      int q = (p + i - 1) / i;\n      invs[i]\
    \ = invs[i * q - p] * mint::raw(q);\n    }\n    assert(p <= (1 << 30));\n    FRAC.assign(1\
    \ << 20, -1);\n    cp = 1.0 * (1 << 20) / p;\n    for (int y = 1023; y >= 1; --y)\
    \ {\n      for (int x = 0; x < y; ++x) { FRAC[(x << 20) / y] = {x << 10 | y};\
    \ }\n    }\n    FOR(i, 1, len(FRAC)) if (FRAC[i] == -1) FRAC[i] = FRAC[i - 1];\n\
    \    int nxt = 1025;\n    FOR_R(i, 1, len(FRAC)) {\n      if (FRAC[i] != FRAC[i\
    \ - 1]) {\n        nxt = FRAC[i];\n        continue;\n      }\n      int x1 =\
    \ FRAC[i] >> 10, y1 = FRAC[i] & 1023;\n      int x2 = nxt >> 10, y2 = nxt & 1023;\n\
    \      int c1 = i * y1 - (x1 << 20);\n      int c2 = i * y2 - (x2 << 20);\n  \
    \    if (abs(c2) < abs(c1)) FRAC[i] = nxt;\n    }\n  }\n  assert(0 <= a && a <\
    \ p);\n  if (a < len(invs)) return invs[a];\n\n  int k = a * cp;\n  ll x = FRAC[k]\
    \ >> 10, y = FRAC[k] & 1023;\n  int c = ll(a) * y - ll(p) * x;\n  if (c < 0) c\
    \ = -c, y = -y;\n  return invs[c] * mint(y);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: mod/O1_inverse.hpp
  requiredBy: []
  timestamp: '2024-04-04 04:49:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/O1_inv.test.cpp
documentation_of: mod/O1_inverse.hpp
layout: document
redirect_from:
- /library/mod/O1_inverse.hpp
- /library/mod/O1_inverse.hpp.html
title: mod/O1_inverse.hpp
---
