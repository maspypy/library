---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://github.com/maspypy/library/blob/main/convex/path_independent_set.hpp
    - https://info.atcoder.jp/entry/algorithm_lectures/matching_on_path
  bundledCode: "#line 1 \"flow/path_matching.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/convex/path_independent_set.hpp\n\
    \n// https://info.atcoder.jp/entry/algorithm_lectures/matching_on_path\n// return:\
    \ (val,i,j), \u9802\u70B9\u91CD\u307F\u306E\u548C\u3068 2 \u70B9\ntemplate <typename\
    \ T, bool MINIMIZE>\nvc<tuple<T, int, int>> path_matching(vc<T> A) {\n  vc<tuple<T,\
    \ int, int>> dat;\n  if constexpr (!MINIMIZE) {\n    for (auto& x : A) x = -x;\n\
    \  }\n  dat.clear();\n  vc<int> st;\n  FOR(i, len(A)) {\n    st.eb(i);\n    while\
    \ (len(st) >= 3) {\n      int a = st[len(st) - 3], b = st[len(st) - 2], c = st[len(st)\
    \ - 1];\n      if (A[a] > A[c]) break;\n      if (len(st) >= 4 && A[st[len(st)\
    \ - 4]] < A[b]) break;\n      dat.eb(A[a] + A[b], a, b);\n      st[len(st) - 3]\
    \ = c;\n      st.pop_back(), st.pop_back();\n    }\n  }\n  while (len(st) >= 2)\
    \ {\n    int b = POP(st);\n    int a = POP(st);\n    dat.eb(A[a] + A[b], a, b);\n\
    \  }\n  sort(all(dat));\n  if (!MINIMIZE) {\n    for (auto& [x, a, b] : dat) x\
    \ = -x;\n  }\n  return dat;\n}\n"
  code: "// Source: https://github.com/maspypy/library/blob/main/convex/path_independent_set.hpp\n\
    \n// https://info.atcoder.jp/entry/algorithm_lectures/matching_on_path\n// return:\
    \ (val,i,j), \u9802\u70B9\u91CD\u307F\u306E\u548C\u3068 2 \u70B9\ntemplate <typename\
    \ T, bool MINIMIZE>\nvc<tuple<T, int, int>> path_matching(vc<T> A) {\n  vc<tuple<T,\
    \ int, int>> dat;\n  if constexpr (!MINIMIZE) {\n    for (auto& x : A) x = -x;\n\
    \  }\n  dat.clear();\n  vc<int> st;\n  FOR(i, len(A)) {\n    st.eb(i);\n    while\
    \ (len(st) >= 3) {\n      int a = st[len(st) - 3], b = st[len(st) - 2], c = st[len(st)\
    \ - 1];\n      if (A[a] > A[c]) break;\n      if (len(st) >= 4 && A[st[len(st)\
    \ - 4]] < A[b]) break;\n      dat.eb(A[a] + A[b], a, b);\n      st[len(st) - 3]\
    \ = c;\n      st.pop_back(), st.pop_back();\n    }\n  }\n  while (len(st) >= 2)\
    \ {\n    int b = POP(st);\n    int a = POP(st);\n    dat.eb(A[a] + A[b], a, b);\n\
    \  }\n  sort(all(dat));\n  if (!MINIMIZE) {\n    for (auto& [x, a, b] : dat) x\
    \ = -x;\n  }\n  return dat;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: flow/path_matching.hpp
  requiredBy: []
  timestamp: '2026-11-06 23:04:21+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: flow/path_matching.hpp
layout: document
redirect_from:
- /library/flow/path_matching.hpp
- /library/flow/path_matching.hpp.html
title: flow/path_matching.hpp
---
