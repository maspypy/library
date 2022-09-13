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
  bundledCode: "#line 1 \"seq/enumerate_products.hpp\"\n// [0, N) ^ K\ntemplate <typename\
    \ F>\nvoid enumerate_products(int N, int K, F query, int LIM_len = -1, int LIM_val\
    \ = -1) {\n  assert(N >= 0);\n  auto dfs = [&](auto& dfs, vc<int>& p) -> void\
    \ {\n    if (len(p) == K) {\n      query(p);\n      return;\n    }\n    FOR(x,\
    \ N){\n      p.eb(x);\n      dfs(dfs, p);\n      p.pop_back();\n    }\n  };\n\
    \  vc<int> p;\n  dfs(dfs, p);\n}\n"
  code: "// [0, N) ^ K\ntemplate <typename F>\nvoid enumerate_products(int N, int\
    \ K, F query, int LIM_len = -1, int LIM_val = -1) {\n  assert(N >= 0);\n  auto\
    \ dfs = [&](auto& dfs, vc<int>& p) -> void {\n    if (len(p) == K) {\n      query(p);\n\
    \      return;\n    }\n    FOR(x, N){\n      p.eb(x);\n      dfs(dfs, p);\n  \
    \    p.pop_back();\n    }\n  };\n  vc<int> p;\n  dfs(dfs, p);\n}"
  dependsOn: []
  isVerificationFile: false
  path: seq/enumerate_products.hpp
  requiredBy: []
  timestamp: '2022-09-14 04:28:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: seq/enumerate_products.hpp
layout: document
redirect_from:
- /library/seq/enumerate_products.hpp
- /library/seq/enumerate_products.hpp.html
title: seq/enumerate_products.hpp
---
