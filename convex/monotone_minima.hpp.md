---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: convex/monge/monge_dp_update.hpp
    title: convex/monge/monge_dp_update.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/monotone_minima.test.cpp
    title: test/1_mytest/monotone_minima.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/952.test.cpp
    title: test/3_yukicoder/952.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"convex/monotone_minima.hpp\"\n\n// \u5404\u884C\u306E\u6700\
    \u9069\u5217\u3092\u6C42\u3081\u308B\n// better(i,j,k): \u884C i \u306B\u304A\u3044\
    \u3066\u5217 k \u304C\u5217 j \u3088\u308A\u826F\u3044\u3068\u304D true\n// \u9069\
    \u7528\u6761\u4EF6\uFF1Abetter \u306B\u3088\u3063\u3066\u9078\u3070\u308C\u308B\
    \u6700\u9069\u5217 opt[i] \u304C i \u306B\u3064\u3044\u3066\u5E83\u7FA9\u5358\u8ABF\
    \u5897\u52A0\ntemplate <typename F>\nvc<int> monotone_minima(int H, int W, F better)\
    \ {\n  if (H == 0) return {};\n  assert(H > 0 && W > 0);\n\n  vc<int> idx(H +\
    \ 1);\n  idx[0] = 0;\n  FOR(y, 1, W) {\n    if (better(0, idx[0], y)) idx[0] =\
    \ y;\n  }\n  idx[H] = W - 1;\n\n  int d = 1;\n  while (d < H) d <<= 1;\n  for\
    \ (int q = d >> 1; q > 0; q >>= 1) {\n    for (int h = q; h < H; h += q << 1)\
    \ {\n      int l = h - q;\n      int r = min(h + q, H);\n      int best = idx[l];\n\
    \      for (int y = idx[l] + 1; y <= idx[r]; ++y) {\n        if (better(h, best,\
    \ y)) best = y;\n      }\n      idx[h] = best;\n    }\n  }\n  idx.pop_back();\n\
    \  return idx;\n}\n"
  code: "#pragma once\n\n// \u5404\u884C\u306E\u6700\u9069\u5217\u3092\u6C42\u3081\
    \u308B\n// better(i,j,k): \u884C i \u306B\u304A\u3044\u3066\u5217 k \u304C\u5217\
    \ j \u3088\u308A\u826F\u3044\u3068\u304D true\n// \u9069\u7528\u6761\u4EF6\uFF1A\
    better \u306B\u3088\u3063\u3066\u9078\u3070\u308C\u308B\u6700\u9069\u5217 opt[i]\
    \ \u304C i \u306B\u3064\u3044\u3066\u5E83\u7FA9\u5358\u8ABF\u5897\u52A0\ntemplate\
    \ <typename F>\nvc<int> monotone_minima(int H, int W, F better) {\n  if (H ==\
    \ 0) return {};\n  assert(H > 0 && W > 0);\n\n  vc<int> idx(H + 1);\n  idx[0]\
    \ = 0;\n  FOR(y, 1, W) {\n    if (better(0, idx[0], y)) idx[0] = y;\n  }\n  idx[H]\
    \ = W - 1;\n\n  int d = 1;\n  while (d < H) d <<= 1;\n  for (int q = d >> 1; q\
    \ > 0; q >>= 1) {\n    for (int h = q; h < H; h += q << 1) {\n      int l = h\
    \ - q;\n      int r = min(h + q, H);\n      int best = idx[l];\n      for (int\
    \ y = idx[l] + 1; y <= idx[r]; ++y) {\n        if (better(h, best, y)) best =\
    \ y;\n      }\n      idx[h] = best;\n    }\n  }\n  idx.pop_back();\n  return idx;\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: convex/monotone_minima.hpp
  requiredBy:
  - convex/monge/monge_dp_update.hpp
  timestamp: '2026-05-31 17:32:53+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/3_yukicoder/952.test.cpp
  - test/1_mytest/monotone_minima.test.cpp
documentation_of: convex/monotone_minima.hpp
layout: document
redirect_from:
- /library/convex/monotone_minima.hpp
- /library/convex/monotone_minima.hpp.html
title: convex/monotone_minima.hpp
---
