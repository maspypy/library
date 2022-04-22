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
  bundledCode: "#line 1 \"graph/count_tree.hpp\"\n/*\r\n\u30E9\u30D9\u30EB\u4ED8\u304D\
    \u6728\u306E\u6570\u3048\u4E0A\u3052\u3002\u9802\u70B9\u6570\u3068\u6839\u306E\
    \u6B21\u6570\u3054\u3068\u306B\u6570\u3048\u4E0A\u3052\u308B\u3002\r\n*/\r\ntemplate\
    \ <typename T>\r\nT count_tree(int n, int root_degree) {\r\n  int d = root_degree;\r\
    \n  if (d <= 0 || d >= n) return T(0);\r\n  d -= 1;\r\n  return fact<T>(n - 2)\
    \ * fact_inv<T>(d) * fact_inv<T>(n - 2 - d)\r\n         * T(n - 1).pow(n - 2 -\
    \ d);\r\n}\r\n"
  code: "/*\r\n\u30E9\u30D9\u30EB\u4ED8\u304D\u6728\u306E\u6570\u3048\u4E0A\u3052\u3002\
    \u9802\u70B9\u6570\u3068\u6839\u306E\u6B21\u6570\u3054\u3068\u306B\u6570\u3048\
    \u4E0A\u3052\u308B\u3002\r\n*/\r\ntemplate <typename T>\r\nT count_tree(int n,\
    \ int root_degree) {\r\n  int d = root_degree;\r\n  if (d <= 0 || d >= n) return\
    \ T(0);\r\n  d -= 1;\r\n  return fact<T>(n - 2) * fact_inv<T>(d) * fact_inv<T>(n\
    \ - 2 - d)\r\n         * T(n - 1).pow(n - 2 - d);\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/count_tree.hpp
  requiredBy: []
  timestamp: '2022-04-22 16:52:47+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/count_tree.hpp
layout: document
redirect_from:
- /library/graph/count_tree.hpp
- /library/graph/count_tree.hpp.html
title: graph/count_tree.hpp
---
