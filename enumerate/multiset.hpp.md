---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/mytest/enumerate_multisets.test.cpp
    title: test/mytest/enumerate_multisets.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"enumerate/multiset.hpp\"\n// [0, K) \u5185\u306E\u5E83\u7FA9\
    \u5358\u8ABF\u5897\u52A0\u5217\r\ntemplate <typename F>\r\nvoid enumerate_multiset(int\
    \ K, int N, F query) {\r\n  vc<int> A(N);\r\n  auto dfs = [&](auto& dfs, int p,\
    \ int s) -> void {\r\n    if (p == N) {\r\n      query(A);\r\n      return;\r\n\
    \    }\r\n    FOR(x, s, K) {\r\n      A[p] = x;\r\n      dfs(dfs, p + 1, x);\r\
    \n    }\r\n  };\r\n  dfs(dfs, 0, 0);\r\n}\r\n"
  code: "// [0, K) \u5185\u306E\u5E83\u7FA9\u5358\u8ABF\u5897\u52A0\u5217\r\ntemplate\
    \ <typename F>\r\nvoid enumerate_multiset(int K, int N, F query) {\r\n  vc<int>\
    \ A(N);\r\n  auto dfs = [&](auto& dfs, int p, int s) -> void {\r\n    if (p ==\
    \ N) {\r\n      query(A);\r\n      return;\r\n    }\r\n    FOR(x, s, K) {\r\n\
    \      A[p] = x;\r\n      dfs(dfs, p + 1, x);\r\n    }\r\n  };\r\n  dfs(dfs, 0,\
    \ 0);\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: enumerate/multiset.hpp
  requiredBy: []
  timestamp: '2023-01-23 21:38:01+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/mytest/enumerate_multisets.test.cpp
documentation_of: enumerate/multiset.hpp
layout: document
redirect_from:
- /library/enumerate/multiset.hpp
- /library/enumerate/multiset.hpp.html
title: enumerate/multiset.hpp
---
