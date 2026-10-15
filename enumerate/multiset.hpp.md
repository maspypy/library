---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/enumerate_multisets.test.cpp
    title: test/1_mytest/enumerate_multisets.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://github.com/maspypy/library/blob/main/enumerate/multiset.hpp
  bundledCode: "#line 1 \"enumerate/multiset.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/enumerate/multiset.hpp\n\
    // N \u5143 K \u7A2E\u985E\u306E\u591A\u91CD\u96C6\u5408\u306E\u983B\u5EA6\u5217\
    \u3064\u307E\u308A\n// a[0]+...+a[K-1]==N\ntemplate <typename F>\nvoid enumerate_multiset(int\
    \ N, int K, F query) {\n  vc<int> A(K);\n  auto dfs = [&](auto& dfs, int p, int\
    \ s) -> void {\n    if (p == K) {\n      if (s == 0) query(A);\n      return;\n\
    \    }\n    FOR(x, s + 1) {\n      A[p] = x;\n      dfs(dfs, p + 1, s - x);\n\
    \    }\n  };\n  dfs(dfs, 0, N);\n}\n"
  code: "// Source: https://github.com/maspypy/library/blob/main/enumerate/multiset.hpp\n\
    // N \u5143 K \u7A2E\u985E\u306E\u591A\u91CD\u96C6\u5408\u306E\u983B\u5EA6\u5217\
    \u3064\u307E\u308A\n// a[0]+...+a[K-1]==N\ntemplate <typename F>\nvoid enumerate_multiset(int\
    \ N, int K, F query) {\n  vc<int> A(K);\n  auto dfs = [&](auto& dfs, int p, int\
    \ s) -> void {\n    if (p == K) {\n      if (s == 0) query(A);\n      return;\n\
    \    }\n    FOR(x, s + 1) {\n      A[p] = x;\n      dfs(dfs, p + 1, s - x);\n\
    \    }\n  };\n  dfs(dfs, 0, N);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: enumerate/multiset.hpp
  requiredBy: []
  timestamp: '2026-10-15 19:54:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/1_mytest/enumerate_multisets.test.cpp
documentation_of: enumerate/multiset.hpp
layout: document
redirect_from:
- /library/enumerate/multiset.hpp
- /library/enumerate/multiset.hpp.html
title: enumerate/multiset.hpp
---
