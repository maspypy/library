---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: seq/monge.hpp
    title: seq/monge.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/705.test.cpp
    title: test/yukicoder/705.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"seq/monotone_minima.hpp\"\n/*\nT \u5024\u306E 2 \u5909\u6570\
    \u95A2\u6570 f(i,j) \u304C monotone \u3060\u3068\u3059\u308B\u3002\n\u5404 i \u306B\
    \u5BFE\u3057\u3066\u3001f \u304C min \u306B\u306A\u308B j \u304A\u3088\u3073\u3001\
    f(i,j) \u306E\u7D44\u3092\u8FD4\u3059\u3002\nf \u3092 O((H+W) logH) \u56DE\u8A08\
    \u7B97\u3059\u308B\u3002\n*/\ntemplate <typename T, typename F>\nvc<pair<int,\
    \ T>> monotone_minima(int H, int W, F f) {\n  using P = pair<int, T>;\n  vc<P>\
    \ dp(H);\n  // closed\n  auto dfs = [&](auto self, int x1, int x2, int y1, int\
    \ y2) -> void {\n    if (x1 > x2) return;\n    int x = (x1 + x2) / 2;\n    P best\
    \ = {-1, 0};\n    FOR3(y, y1, y2 + 1) {\n      T cost = f(x, y);\n      if (best.fi\
    \ == -1 || cost < best.se) best = {y, cost};\n    }\n    dp[x] = best;\n    int\
    \ y = best.fi;\n    if (x1 <= x - 1) self(self, x1, x - 1, y1, y);\n    if (x\
    \ + 1 <= x2) self(self, x + 1, x2, y, y2);\n  };\n  dfs(dfs, 0, H - 1, 0, W -\
    \ 1);\n  return dp;\n}\n"
  code: "/*\nT \u5024\u306E 2 \u5909\u6570\u95A2\u6570 f(i,j) \u304C monotone \u3060\
    \u3068\u3059\u308B\u3002\n\u5404 i \u306B\u5BFE\u3057\u3066\u3001f \u304C min\
    \ \u306B\u306A\u308B j \u304A\u3088\u3073\u3001f(i,j) \u306E\u7D44\u3092\u8FD4\
    \u3059\u3002\nf \u3092 O((H+W) logH) \u56DE\u8A08\u7B97\u3059\u308B\u3002\n*/\n\
    template <typename T, typename F>\nvc<pair<int, T>> monotone_minima(int H, int\
    \ W, F f) {\n  using P = pair<int, T>;\n  vc<P> dp(H);\n  // closed\n  auto dfs\
    \ = [&](auto self, int x1, int x2, int y1, int y2) -> void {\n    if (x1 > x2)\
    \ return;\n    int x = (x1 + x2) / 2;\n    P best = {-1, 0};\n    FOR3(y, y1,\
    \ y2 + 1) {\n      T cost = f(x, y);\n      if (best.fi == -1 || cost < best.se)\
    \ best = {y, cost};\n    }\n    dp[x] = best;\n    int y = best.fi;\n    if (x1\
    \ <= x - 1) self(self, x1, x - 1, y1, y);\n    if (x + 1 <= x2) self(self, x +\
    \ 1, x2, y, y2);\n  };\n  dfs(dfs, 0, H - 1, 0, W - 1);\n  return dp;\n}"
  dependsOn: []
  isVerificationFile: false
  path: seq/monotone_minima.hpp
  requiredBy:
  - seq/monge.hpp
  timestamp: '2022-10-21 16:42:45+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/705.test.cpp
documentation_of: seq/monotone_minima.hpp
layout: document
redirect_from:
- /library/seq/monotone_minima.hpp
- /library/seq/monotone_minima.hpp.html
title: seq/monotone_minima.hpp
---
