---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/1_mytest/non_adj.test.cpp
    title: test/1_mytest/non_adj.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links:
    - https://atcoder.jp/contests/abc464/tasks/abc464_g
    - https://atcoder.jp/contests/joisc2018/tasks/joisc2018_j
    - https://github.com/maspypy/library/blob/main/convex/path_independent_set.hpp
  bundledCode: "#line 1 \"convex/path_independent_set.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/convex/path_independent_set.hpp\n\
    \n// https://atcoder.jp/contests/joisc2018/tasks/joisc2018_j\n// https://atcoder.jp/contests/abc464/tasks/abc464_g\n\
    // return: (val,i,j), \u9802\u70B9\u91CD\u307F\u306E\u548C\u3068 2 \u70B9\ntemplate\
    \ <typename T, bool MINIMIZE>\nvc<tuple<T, int, int>>(vc<T> A) {\n  vc<tuple<T,\
    \ int, int>> dat;\n  if constexpr (!MINIMIZE) {\n    for (auto& x : A) x = -x;\n\
    \  }\n  dat.clear();\n  N = len(A);\n  vc<int> st;\n  FOR(i, N) {\n    st.eb(i);\n\
    \    while (len(st) >= 3) {\n      int a = st[len(st) - 3], b = st[len(st) - 2],\
    \ c = st[len(st) - 1];\n      if (A[a] > A[c]) break;\n      if (len(st) >= 4\
    \ && A[st[len(st) - 4]] < A[b]) break;\n      dat.eb(A[a] + A[b], a, b);\n   \
    \   st[len(st) - 3] = c;\n      st.pop_back(), st.pop_back();\n    }\n  }\n  while\
    \ (len(st) >= 2) {\n    int b = POP(st);\n    int a = POP(st);\n    dat.eb(A[a]\
    \ + A[b], a, b);\n  }\n  sort(all(dat));\n  if (!MINIMIZE) {\n    for (auto& [x,\
    \ a, b] : dat) x = -x;\n  }\n  return dat;\n}\n"
  code: "// Source: https://github.com/maspypy/library/blob/main/convex/path_independent_set.hpp\n\
    \n// https://atcoder.jp/contests/joisc2018/tasks/joisc2018_j\n// https://atcoder.jp/contests/abc464/tasks/abc464_g\n\
    // return: (val,i,j), \u9802\u70B9\u91CD\u307F\u306E\u548C\u3068 2 \u70B9\ntemplate\
    \ <typename T, bool MINIMIZE>\nvc<tuple<T, int, int>>(vc<T> A) {\n  vc<tuple<T,\
    \ int, int>> dat;\n  if constexpr (!MINIMIZE) {\n    for (auto& x : A) x = -x;\n\
    \  }\n  dat.clear();\n  N = len(A);\n  vc<int> st;\n  FOR(i, N) {\n    st.eb(i);\n\
    \    while (len(st) >= 3) {\n      int a = st[len(st) - 3], b = st[len(st) - 2],\
    \ c = st[len(st) - 1];\n      if (A[a] > A[c]) break;\n      if (len(st) >= 4\
    \ && A[st[len(st) - 4]] < A[b]) break;\n      dat.eb(A[a] + A[b], a, b);\n   \
    \   st[len(st) - 3] = c;\n      st.pop_back(), st.pop_back();\n    }\n  }\n  while\
    \ (len(st) >= 2) {\n    int b = POP(st);\n    int a = POP(st);\n    dat.eb(A[a]\
    \ + A[b], a, b);\n  }\n  sort(all(dat));\n  if (!MINIMIZE) {\n    for (auto& [x,\
    \ a, b] : dat) x = -x;\n  }\n  return dat;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: convex/path_independent_set.hpp
  requiredBy: []
  timestamp: '2026-11-06 22:43:05+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/1_mytest/non_adj.test.cpp
documentation_of: convex/path_independent_set.hpp
layout: document
redirect_from:
- /library/convex/path_independent_set.hpp
- /library/convex/path_independent_set.hpp.html
title: convex/path_independent_set.hpp
---
