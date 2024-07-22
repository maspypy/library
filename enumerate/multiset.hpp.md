---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest/enumerate_multisets.test.cpp
    title: test/mytest/enumerate_multisets.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"enumerate/multiset.hpp\"\n// N \u5143 K \u7A2E\u985E\u306E\
    \u591A\u91CD\u96C6\u5408\u306E\u983B\u5EA6\u5217\u3064\u307E\u308A\r\n// a[0]+...+a[K-1]==N\r\
    \ntemplate <typename F>\r\nvoid enumerate_multiset(int N, int K, F query) {\r\n\
    \  vc<int> A(K);\r\n  auto dfs = [&](auto& dfs, int p, int s) -> void {\r\n  \
    \  if (p == K) {\r\n      if (s == 0) query(A);\r\n      return;\r\n    }\r\n\
    \    FOR(x, s + 1) {\r\n      A[p] = x;\r\n      dfs(dfs, p + 1, s - x);\r\n \
    \   }\r\n  };\r\n  dfs(dfs, 0, N);\r\n}\r\n"
  code: "// N \u5143 K \u7A2E\u985E\u306E\u591A\u91CD\u96C6\u5408\u306E\u983B\u5EA6\
    \u5217\u3064\u307E\u308A\r\n// a[0]+...+a[K-1]==N\r\ntemplate <typename F>\r\n\
    void enumerate_multiset(int N, int K, F query) {\r\n  vc<int> A(K);\r\n  auto\
    \ dfs = [&](auto& dfs, int p, int s) -> void {\r\n    if (p == K) {\r\n      if\
    \ (s == 0) query(A);\r\n      return;\r\n    }\r\n    FOR(x, s + 1) {\r\n    \
    \  A[p] = x;\r\n      dfs(dfs, p + 1, s - x);\r\n    }\r\n  };\r\n  dfs(dfs, 0,\
    \ N);\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: enumerate/multiset.hpp
  requiredBy: []
  timestamp: '2024-03-10 03:27:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/enumerate_multisets.test.cpp
documentation_of: enumerate/multiset.hpp
layout: document
redirect_from:
- /library/enumerate/multiset.hpp
- /library/enumerate/multiset.hpp.html
title: enumerate/multiset.hpp
---
