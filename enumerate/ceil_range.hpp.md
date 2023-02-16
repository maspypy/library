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
    \u306F r == infty<T>\ntemplate <typename T, typename F>\nvoid ceil_range(T N,\
    \ F f) {\n  T q = 1, l = N, r = infty<T>;\n  while (1) {\n    f(q, l, r);\n  \
    \  if (q == N) break;\n    r = l, q = ceil(N, l - 1), l = ceil(N, q);\n  }\n}\n"
  code: "// f(q, l, r)\uFF1Aceil \u304C q \u306B\u306A\u308B\u7BC4\u56F2\u304C [l,\
    \ r)\n// q == 1 \u306E\u3068\u304D\u306B\u306F r == infty<T>\ntemplate <typename\
    \ T, typename F>\nvoid ceil_range(T N, F f) {\n  T q = 1, l = N, r = infty<T>;\n\
    \  while (1) {\n    f(q, l, r);\n    if (q == N) break;\n    r = l, q = ceil(N,\
    \ l - 1), l = ceil(N, q);\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: enumerate/ceil_range.hpp
  requiredBy: []
  timestamp: '2023-02-02 01:33:15+09:00'
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
