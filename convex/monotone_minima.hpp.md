---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':question:'
    path: convex/minplus_convolution_convex.hpp
    title: convex/minplus_convolution_convex.hpp
  - icon: ':x:'
    path: convex/minplus_convolution_of_triples.hpp
    title: convex/minplus_convolution_of_triples.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/convolution/minplus_convolution_conv_arb.test.cpp
    title: test/library_checker/convolution/minplus_convolution_conv_arb.test.cpp
  - icon: ':x:'
    path: test/library_checker/convolution/minplus_convolution_conv_conv.test.cpp
    title: test/library_checker/convolution/minplus_convolution_conv_conv.test.cpp
  - icon: ':x:'
    path: test/mytest/minplus_conv_triple.test.cpp
    title: test/mytest/minplus_conv_triple.test.cpp
  - icon: ':x:'
    path: test/mytest/minplus_convex.test.cpp
    title: test/mytest/minplus_convex.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"convex/monotone_minima.hpp\"\n\n// select(i,j,k) : (i,j)\
    \ -> (i,k) \u3092\u884C\u3046\u304B\u3069\u3046\u304B\ntemplate <typename F>\n\
    vc<int> monotone_minima(int H, int W, F select) {\n  vc<int> min_col(H);\n  auto\
    \ dfs = [&](auto& dfs, int x1, int x2, int y1, int y2) -> void {\n    if (x1 ==\
    \ x2) return;\n    int x = (x1 + x2) / 2;\n    int best_y = y1;\n    for (int\
    \ y = y1 + 1; y < y2; ++y) {\n      if (select(x, best_y, y)) best_y = y;\n  \
    \  }\n    min_col[x] = best_y;\n    dfs(dfs, x1, x, y1, best_y + 1);\n    dfs(dfs,\
    \ x + 1, x2, best_y, y2);\n  };\n  dfs(dfs, 0, H, 0, W);\n  return min_col;\n\
    }\n"
  code: "\n// select(i,j,k) : (i,j) -> (i,k) \u3092\u884C\u3046\u304B\u3069\u3046\u304B\
    \ntemplate <typename F>\nvc<int> monotone_minima(int H, int W, F select) {\n \
    \ vc<int> min_col(H);\n  auto dfs = [&](auto& dfs, int x1, int x2, int y1, int\
    \ y2) -> void {\n    if (x1 == x2) return;\n    int x = (x1 + x2) / 2;\n    int\
    \ best_y = y1;\n    for (int y = y1 + 1; y < y2; ++y) {\n      if (select(x, best_y,\
    \ y)) best_y = y;\n    }\n    min_col[x] = best_y;\n    dfs(dfs, x1, x, y1, best_y\
    \ + 1);\n    dfs(dfs, x + 1, x2, best_y, y2);\n  };\n  dfs(dfs, 0, H, 0, W);\n\
    \  return min_col;\n}"
  dependsOn: []
  isVerificationFile: false
  path: convex/monotone_minima.hpp
  requiredBy:
  - convex/minplus_convolution_of_triples.hpp
  - convex/minplus_convolution_convex.hpp
  timestamp: '2023-07-06 21:02:18+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/mytest/minplus_conv_triple.test.cpp
  - test/mytest/minplus_convex.test.cpp
  - test/library_checker/convolution/minplus_convolution_conv_arb.test.cpp
  - test/library_checker/convolution/minplus_convolution_conv_conv.test.cpp
documentation_of: convex/monotone_minima.hpp
layout: document
redirect_from:
- /library/convex/monotone_minima.hpp
- /library/convex/monotone_minima.hpp.html
title: convex/monotone_minima.hpp
---
