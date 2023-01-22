---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest/enumerate_products.test.cpp
    title: test/mytest/enumerate_products.test.cpp
  - icon: ':x:'
    path: test_atcoder/arc153f.test.cpp
    title: test_atcoder/arc153f.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"enumerate/products.hpp\"\n// [0, K) ^ N\ntemplate <typename\
    \ F>\nvoid enumerate_products(int K, int N, F query) {\n  assert(N >= 0);\n  auto\
    \ dfs = [&](auto& dfs, vc<int>& p) -> void {\n    if (len(p) == N) {\n      query(p);\n\
    \      return;\n    }\n    FOR(x, K) {\n      p.eb(x);\n      dfs(dfs, p);\n \
    \     p.pop_back();\n    }\n  };\n  vc<int> p;\n  dfs(dfs, p);\n}\n"
  code: "// [0, K) ^ N\ntemplate <typename F>\nvoid enumerate_products(int K, int\
    \ N, F query) {\n  assert(N >= 0);\n  auto dfs = [&](auto& dfs, vc<int>& p) ->\
    \ void {\n    if (len(p) == N) {\n      query(p);\n      return;\n    }\n    FOR(x,\
    \ K) {\n      p.eb(x);\n      dfs(dfs, p);\n      p.pop_back();\n    }\n  };\n\
    \  vc<int> p;\n  dfs(dfs, p);\n}"
  dependsOn: []
  isVerificationFile: false
  path: enumerate/products.hpp
  requiredBy: []
  timestamp: '2022-10-21 20:59:38+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/mytest/enumerate_products.test.cpp
  - test_atcoder/arc153f.test.cpp
documentation_of: enumerate/products.hpp
layout: document
redirect_from:
- /library/enumerate/products.hpp
- /library/enumerate/products.hpp.html
title: enumerate/products.hpp
---
