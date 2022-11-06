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
  bundledCode: "#line 1 \"enumerate/multisets.hpp\"\ntemplate <typename F>\r\nvoid\
    \ enumerate_multisets(int K, int N, F query) {\r\n  vc<int> A(N);\r\n  auto dfs\
    \ = [&](auto& dfs, int p, int s) -> void {\r\n    if (p == N) {\r\n      query(A);\r\
    \n      return;\r\n    }\r\n    FOR(x, s, K) {\r\n      A[p] = x;\r\n      dfs(dfs,\
    \ p + 1, x);\r\n    }\r\n  };\r\n  dfs(dfs, 0, 0);\r\n}\r\n"
  code: "template <typename F>\r\nvoid enumerate_multisets(int K, int N, F query)\
    \ {\r\n  vc<int> A(N);\r\n  auto dfs = [&](auto& dfs, int p, int s) -> void {\r\
    \n    if (p == N) {\r\n      query(A);\r\n      return;\r\n    }\r\n    FOR(x,\
    \ s, K) {\r\n      A[p] = x;\r\n      dfs(dfs, p + 1, x);\r\n    }\r\n  };\r\n\
    \  dfs(dfs, 0, 0);\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: enumerate/multisets.hpp
  requiredBy: []
  timestamp: '2022-10-21 20:37:52+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/enumerate_multisets.test.cpp
documentation_of: enumerate/multisets.hpp
layout: document
redirect_from:
- /library/enumerate/multisets.hpp
- /library/enumerate/multisets.hpp.html
title: enumerate/multisets.hpp
---
