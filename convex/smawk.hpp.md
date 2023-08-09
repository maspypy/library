---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: convex/maxplus_convolution_concave.hpp
    title: convex/maxplus_convolution_concave.hpp
  - icon: ':question:'
    path: convex/minplus_convolution_convex.hpp
    title: convex/minplus_convolution_convex.hpp
  - icon: ':x:'
    path: convex/minplus_convolution_of_triples.hpp
    title: convex/minplus_convolution_of_triples.hpp
  - icon: ':heavy_check_mark:'
    path: convex/monge.hpp
    title: convex/monge.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/convolution/minplus_convolution_conv_arb.test.cpp
    title: test/library_checker/convolution/minplus_convolution_conv_arb.test.cpp
  - icon: ':x:'
    path: test/library_checker/convolution/minplus_convolution_conv_conv.test.cpp
    title: test/library_checker/convolution/minplus_convolution_conv_conv.test.cpp
  - icon: ':x:'
    path: test/mytest/maxplus_concave.test.cpp
    title: test/mytest/maxplus_concave.test.cpp
  - icon: ':x:'
    path: test/mytest/minplus_conv_triple.test.cpp
    title: test/mytest/minplus_conv_triple.test.cpp
  - icon: ':x:'
    path: test/mytest/minplus_convex.test.cpp
    title: test/mytest/minplus_convex.test.cpp
  - icon: ':x:'
    path: test/mytest/smawk.test.cpp
    title: test/mytest/smawk.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/705.test.cpp
    title: test/yukicoder/705.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"convex/smawk.hpp\"\n\n// select(i,j,k) \u306F (i,j) -> (i,k)\
    \ \u3092\u884C\u3046\u304B\u3069\u3046\u304B\n// \u6B8B\u5FF5\u306A\u304C\u3089\
    \ monotone minima \u3088\u308A\u9AD8\u901F\u306A\u5834\u5408\u304C\u5B58\u5728\
    \u3057\u306A\u3044\u8AAC\u304C\u3042\u308B\ntemplate <typename F>\nvc<int> smawk(int\
    \ H, int W, F select) {\n  auto dfs = [&](auto& dfs, vc<int> X, vc<int> Y) ->\
    \ vc<int> {\n    int N = len(X);\n    if (N == 0) return {};\n    vc<int> YY;\n\
    \    for (auto&& y: Y) {\n      while (len(YY)) {\n        int py = YY.back(),\
    \ x = X[len(YY) - 1];\n        if (!select(x, py, y)) break;\n        YY.pop_back();\n\
    \      }\n      if (len(YY) < len(X)) YY.eb(y);\n    }\n    vc<int> XX;\n    FOR(i,\
    \ 1, len(X), 2) XX.eb(X[i]);\n    vc<int> II = dfs(dfs, XX, YY);\n    vc<int>\
    \ I(N);\n    FOR(i, len(II)) I[i + i + 1] = II[i];\n    int p = 0;\n    FOR(i,\
    \ 0, N, 2) {\n      int LIM = (i + 1 == N ? Y.back() : I[i + 1]);\n      int best\
    \ = Y[p];\n      while (Y[p] < LIM) {\n        ++p;\n        if (select(X[i],\
    \ best, Y[p])) best = Y[p];\n      }\n      I[i] = best;\n    }\n    return I;\n\
    \  };\n  vc<int> X(H), Y(W);\n  iota(all(X), 0), iota(all(Y), 0);\n  return dfs(dfs,\
    \ X, Y);\n}\n"
  code: "#pragma once\n\n// select(i,j,k) \u306F (i,j) -> (i,k) \u3092\u884C\u3046\
    \u304B\u3069\u3046\u304B\n// \u6B8B\u5FF5\u306A\u304C\u3089 monotone minima \u3088\
    \u308A\u9AD8\u901F\u306A\u5834\u5408\u304C\u5B58\u5728\u3057\u306A\u3044\u8AAC\
    \u304C\u3042\u308B\ntemplate <typename F>\nvc<int> smawk(int H, int W, F select)\
    \ {\n  auto dfs = [&](auto& dfs, vc<int> X, vc<int> Y) -> vc<int> {\n    int N\
    \ = len(X);\n    if (N == 0) return {};\n    vc<int> YY;\n    for (auto&& y: Y)\
    \ {\n      while (len(YY)) {\n        int py = YY.back(), x = X[len(YY) - 1];\n\
    \        if (!select(x, py, y)) break;\n        YY.pop_back();\n      }\n    \
    \  if (len(YY) < len(X)) YY.eb(y);\n    }\n    vc<int> XX;\n    FOR(i, 1, len(X),\
    \ 2) XX.eb(X[i]);\n    vc<int> II = dfs(dfs, XX, YY);\n    vc<int> I(N);\n   \
    \ FOR(i, len(II)) I[i + i + 1] = II[i];\n    int p = 0;\n    FOR(i, 0, N, 2) {\n\
    \      int LIM = (i + 1 == N ? Y.back() : I[i + 1]);\n      int best = Y[p];\n\
    \      while (Y[p] < LIM) {\n        ++p;\n        if (select(X[i], best, Y[p]))\
    \ best = Y[p];\n      }\n      I[i] = best;\n    }\n    return I;\n  };\n  vc<int>\
    \ X(H), Y(W);\n  iota(all(X), 0), iota(all(Y), 0);\n  return dfs(dfs, X, Y);\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: convex/smawk.hpp
  requiredBy:
  - convex/minplus_convolution_of_triples.hpp
  - convex/minplus_convolution_convex.hpp
  - convex/maxplus_convolution_concave.hpp
  - convex/monge.hpp
  timestamp: '2023-08-10 00:32:23+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/mytest/minplus_conv_triple.test.cpp
  - test/mytest/maxplus_concave.test.cpp
  - test/mytest/minplus_convex.test.cpp
  - test/mytest/smawk.test.cpp
  - test/yukicoder/705.test.cpp
  - test/library_checker/convolution/minplus_convolution_conv_arb.test.cpp
  - test/library_checker/convolution/minplus_convolution_conv_conv.test.cpp
documentation_of: convex/smawk.hpp
layout: document
redirect_from:
- /library/convex/smawk.hpp
- /library/convex/smawk.hpp.html
title: convex/smawk.hpp
---
