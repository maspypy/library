---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"enumerate/multiset.hpp\"\ntemplate <typename F>\r\nvoid\
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
  path: enumerate/multiset.hpp
  requiredBy: []
  timestamp: '2023-01-23 21:04:48+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: enumerate/multiset.hpp
layout: document
redirect_from:
- /library/enumerate/multiset.hpp
- /library/enumerate/multiset.hpp.html
title: enumerate/multiset.hpp
---
