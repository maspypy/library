---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest/floor_ceil_ranges.test.cpp
    title: test/mytest/floor_ceil_ranges.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"enumerate/ceil_range.hpp\"\n// f(q, l, r)\uFF1Aceil \u304C\
    \ q \u306B\u306A\u308B\u7BC4\u56F2\u304C [l, r)\n// q == 1 \u306E\u3068\u304D\u306B\
    \u306F r == INF \u304C\u5165\u308B\u3053\u3068\u306B\u6CE8\u610F\ntemplate <typename\
    \ INT_TYPE, typename F>\nvoid ceil_range(INT_TYPE N, F f, INT_TYPE INF) {\n  INT_TYPE\
    \ q = 1, l = N, r = INF;\n  while (1) {\n    f(q, l, r);\n    if (q == N) break;\n\
    \    r = l, q = ceil(N, l - 1), l = ceil(N, q);\n  }\n}\n"
  code: "// f(q, l, r)\uFF1Aceil \u304C q \u306B\u306A\u308B\u7BC4\u56F2\u304C [l,\
    \ r)\n// q == 1 \u306E\u3068\u304D\u306B\u306F r == INF \u304C\u5165\u308B\u3053\
    \u3068\u306B\u6CE8\u610F\ntemplate <typename INT_TYPE, typename F>\nvoid ceil_range(INT_TYPE\
    \ N, F f, INT_TYPE INF) {\n  INT_TYPE q = 1, l = N, r = INF;\n  while (1) {\n\
    \    f(q, l, r);\n    if (q == N) break;\n    r = l, q = ceil(N, l - 1), l = ceil(N,\
    \ q);\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: enumerate/ceil_range.hpp
  requiredBy: []
  timestamp: '2023-01-31 20:39:54+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/floor_ceil_ranges.test.cpp
documentation_of: enumerate/ceil_range.hpp
layout: document
redirect_from:
- /library/enumerate/ceil_range.hpp
- /library/enumerate/ceil_range.hpp.html
title: enumerate/ceil_range.hpp
---
