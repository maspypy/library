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
  bundledCode: "#line 1 \"ds/range_min_change.hpp\"\n\n// array B[l] := min of B[l,r),\
    \ or default\n// dat[k]: change of B, when r=k -> r=k+1\ntemplate <typename T>\n\
    vvc<tuple<int, int, T, T>> range_min_change(vc<T> A, T default_val = infty<T>)\
    \ {\n  int N = len(A);\n  vvc<tuple<int, int, T, T>> res(N);\n  vc<tuple<int,\
    \ int, T>> stack;\n  FOR(i, N) {\n    T a = A[i];\n    res[i].eb(i, i + 1, default_val,\
    \ a);\n    int p = i;\n    while (len(stack)) {\n      auto [l, r, x] = stack.back();\n\
    \      if (x <= a)\n        break;\n      res[i].eb(l, r, x, a);\n      p = l;\n\
    \      POP(stack);\n    }\n    stack.eb(p, i + 1, a);\n    reverse(all(res[i]));\n\
    \  }\n  return res;\n}\n"
  code: "\n// array B[l] := min of B[l,r), or default\n// dat[k]: change of B, when\
    \ r=k -> r=k+1\ntemplate <typename T>\nvvc<tuple<int, int, T, T>> range_min_change(vc<T>\
    \ A, T default_val = infty<T>) {\n  int N = len(A);\n  vvc<tuple<int, int, T,\
    \ T>> res(N);\n  vc<tuple<int, int, T>> stack;\n  FOR(i, N) {\n    T a = A[i];\n\
    \    res[i].eb(i, i + 1, default_val, a);\n    int p = i;\n    while (len(stack))\
    \ {\n      auto [l, r, x] = stack.back();\n      if (x <= a)\n        break;\n\
    \      res[i].eb(l, r, x, a);\n      p = l;\n      POP(stack);\n    }\n    stack.eb(p,\
    \ i + 1, a);\n    reverse(all(res[i]));\n  }\n  return res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/range_min_change.hpp
  requiredBy: []
  timestamp: '2025-06-24 13:25:23+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/range_min_change.hpp
layout: document
redirect_from:
- /library/ds/range_min_change.hpp
- /library/ds/range_min_change.hpp.html
title: ds/range_min_change.hpp
---
