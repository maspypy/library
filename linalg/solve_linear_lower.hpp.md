---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test_atcoder/abc249_ex.test.cpp
    title: test_atcoder/abc249_ex.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"linalg/solve_linear_lower.hpp\"\n// \u4E0B\u4E09\u89D2\u884C\
    \u5217\u3092\u4EEE\u5B9A\u3002\u3068\u308A\u3042\u3048\u305A\u6B63\u5247\u3082\
    \u4EEE\u5B9A\u3002\ntemplate <typename T>\nvc<T> solve_linear_lower(vc<vc<T>>\
    \ a, vc<T> b) {\n  auto n = len(a);\n  FOR(i, n) assert(a[i][i] != T(0));\n  FOR(i,\
    \ n) FOR(j, i + 1, n) assert(a[i][j] == T(0));\n  FOR(i, n) {\n    {\n      T\
    \ c = T(1) / a[i][i];\n      a[i][i] *= c;\n      b[i] *= c;\n    }\n    FOR(j,\
    \ i + 1, n) {\n      b[j] -= b[i] * a[j][i];\n      a[j][i] = T(0);\n    }\n \
    \ }\n  return b;\n}\n"
  code: "// \u4E0B\u4E09\u89D2\u884C\u5217\u3092\u4EEE\u5B9A\u3002\u3068\u308A\u3042\
    \u3048\u305A\u6B63\u5247\u3082\u4EEE\u5B9A\u3002\ntemplate <typename T>\nvc<T>\
    \ solve_linear_lower(vc<vc<T>> a, vc<T> b) {\n  auto n = len(a);\n  FOR(i, n)\
    \ assert(a[i][i] != T(0));\n  FOR(i, n) FOR(j, i + 1, n) assert(a[i][j] == T(0));\n\
    \  FOR(i, n) {\n    {\n      T c = T(1) / a[i][i];\n      a[i][i] *= c;\n    \
    \  b[i] *= c;\n    }\n    FOR(j, i + 1, n) {\n      b[j] -= b[i] * a[j][i];\n\
    \      a[j][i] = T(0);\n    }\n  }\n  return b;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: linalg/solve_linear_lower.hpp
  requiredBy: []
  timestamp: '2022-10-25 17:22:46+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test_atcoder/abc249_ex.test.cpp
documentation_of: linalg/solve_linear_lower.hpp
layout: document
redirect_from:
- /library/linalg/solve_linear_lower.hpp
- /library/linalg/solve_linear_lower.hpp.html
title: linalg/solve_linear_lower.hpp
---
