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
  bundledCode: "#line 1 \"graph/count/count_tree_by_root_degree.hpp\"\n/*\n\u30E9\u30D9\
    \u30EB\u4ED8\u304D\u6728\u306E\u6570\u3048\u4E0A\u3052\u3002\u9802\u70B9\u6570\
    \u3068\u6839\u306E\u6B21\u6570\u3054\u3068\u306B\u6570\u3048\u4E0A\u3052\u308B\
    \u3002\n*/\ntemplate <typename T>\nT count_tree_by_root_degree(int n, int root_degree)\
    \ {\n  int d = root_degree;\n  if (d <= 0 || d >= n) return T(0);\n  d -= 1;\n\
    \  return fact<T>(n - 2) * fact_inv<T>(d) * fact_inv<T>(n - 2 - d)\n         *\
    \ T(n - 1).pow(n - 2 - d);\n}\n"
  code: "/*\n\u30E9\u30D9\u30EB\u4ED8\u304D\u6728\u306E\u6570\u3048\u4E0A\u3052\u3002\
    \u9802\u70B9\u6570\u3068\u6839\u306E\u6B21\u6570\u3054\u3068\u306B\u6570\u3048\
    \u4E0A\u3052\u308B\u3002\n*/\ntemplate <typename T>\nT count_tree_by_root_degree(int\
    \ n, int root_degree) {\n  int d = root_degree;\n  if (d <= 0 || d >= n) return\
    \ T(0);\n  d -= 1;\n  return fact<T>(n - 2) * fact_inv<T>(d) * fact_inv<T>(n -\
    \ 2 - d)\n         * T(n - 1).pow(n - 2 - d);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/count/count_tree_by_root_degree.hpp
  requiredBy: []
  timestamp: '2023-05-21 00:13:10+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/count/count_tree_by_root_degree.hpp
layout: document
redirect_from:
- /library/graph/count/count_tree_by_root_degree.hpp
- /library/graph/count/count_tree_by_root_degree.hpp.html
title: graph/count/count_tree_by_root_degree.hpp
---
