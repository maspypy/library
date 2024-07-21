---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest/non_adj.test.cpp
    title: test/mytest/non_adj.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://atcoder.jp/contests/joisc2018/tasks/joisc2018_j
  bundledCode: "#line 1 \"convex/non_adjecent_selection.hpp\"\n\n// https://atcoder.jp/contests/joisc2018/tasks/joisc2018_j\n\
    template <typename T, bool MINIMIZE>\nstruct Non_Adjacent_Selection {\n  int N;\n\
    \  vc<T> ANS;\n  vc<pair<int, int>> history;\n\n  Non_Adjacent_Selection(vc<T>&\
    \ A) { calc(A); }\n\n  void calc(vc<T> A) {\n    if (MINIMIZE) {\n      for (auto&\
    \ x: A) x = -x;\n    }\n    N = len(A);\n    vc<bool> rest(N + 2, 1);\n    rest[0]\
    \ = rest[N + 1] = 0;\n    vc<pair<int, int>> range(N + 2);\n    vc<int> left(N\
    \ + 2), right(N + 2);\n    vc<T> val(N + 2);\n    pq<pair<T, int>> que;\n    FOR(i,\
    \ N + 2) { left[i] = i - 1, right[i] = i + 1; }\n    FOR(i, N) {\n      val[i\
    \ + 1] = A[i], range[i + 1] = {i, i + 1};\n      que.emplace(val[i + 1], i + 1);\n\
    \    }\n\n    ANS = {0};\n    while (len(que)) {\n      auto [add, i] = POP(que);\n\
    \      if (!rest[i]) continue;\n      ANS.eb(ANS.back() + add);\n      int L =\
    \ left[i], R = right[i];\n      history.eb(range[i]);\n      if (1 <= L) { right[left[L]]\
    \ = i, left[i] = left[L]; }\n      if (R <= N) { left[right[R]] = i, right[i]\
    \ = right[R]; }\n      if (rest[L] && rest[R]) {\n        val[i] = val[L] + val[R]\
    \ - val[i];\n        que.emplace(val[i], i);\n        range[i] = {range[L].fi,\
    \ range[R].se};\n      } else {\n        rest[i] = 0;\n      }\n      rest[L]\
    \ = rest[R] = 0;\n    }\n\n    if (MINIMIZE) {\n      for (auto& x: ANS) x = -x;\n\
    \    }\n  }\n\n  vc<int> restore(int n) {\n    vc<int> F(N + 1);\n    FOR(i, n)\
    \ {\n      auto [a, b] = history[i];\n      F[a]++, F[b]--;\n    }\n    F = cumsum<int>(F,\
    \ 0);\n    vc<int> I;\n    FOR(i, N) if (F[i] & 1) I.eb(i);\n    return I;\n \
    \ }\n};\n"
  code: "\n// https://atcoder.jp/contests/joisc2018/tasks/joisc2018_j\ntemplate <typename\
    \ T, bool MINIMIZE>\nstruct Non_Adjacent_Selection {\n  int N;\n  vc<T> ANS;\n\
    \  vc<pair<int, int>> history;\n\n  Non_Adjacent_Selection(vc<T>& A) { calc(A);\
    \ }\n\n  void calc(vc<T> A) {\n    if (MINIMIZE) {\n      for (auto& x: A) x =\
    \ -x;\n    }\n    N = len(A);\n    vc<bool> rest(N + 2, 1);\n    rest[0] = rest[N\
    \ + 1] = 0;\n    vc<pair<int, int>> range(N + 2);\n    vc<int> left(N + 2), right(N\
    \ + 2);\n    vc<T> val(N + 2);\n    pq<pair<T, int>> que;\n    FOR(i, N + 2) {\
    \ left[i] = i - 1, right[i] = i + 1; }\n    FOR(i, N) {\n      val[i + 1] = A[i],\
    \ range[i + 1] = {i, i + 1};\n      que.emplace(val[i + 1], i + 1);\n    }\n\n\
    \    ANS = {0};\n    while (len(que)) {\n      auto [add, i] = POP(que);\n   \
    \   if (!rest[i]) continue;\n      ANS.eb(ANS.back() + add);\n      int L = left[i],\
    \ R = right[i];\n      history.eb(range[i]);\n      if (1 <= L) { right[left[L]]\
    \ = i, left[i] = left[L]; }\n      if (R <= N) { left[right[R]] = i, right[i]\
    \ = right[R]; }\n      if (rest[L] && rest[R]) {\n        val[i] = val[L] + val[R]\
    \ - val[i];\n        que.emplace(val[i], i);\n        range[i] = {range[L].fi,\
    \ range[R].se};\n      } else {\n        rest[i] = 0;\n      }\n      rest[L]\
    \ = rest[R] = 0;\n    }\n\n    if (MINIMIZE) {\n      for (auto& x: ANS) x = -x;\n\
    \    }\n  }\n\n  vc<int> restore(int n) {\n    vc<int> F(N + 1);\n    FOR(i, n)\
    \ {\n      auto [a, b] = history[i];\n      F[a]++, F[b]--;\n    }\n    F = cumsum<int>(F,\
    \ 0);\n    vc<int> I;\n    FOR(i, N) if (F[i] & 1) I.eb(i);\n    return I;\n \
    \ }\n};"
  dependsOn: []
  isVerificationFile: false
  path: convex/non_adjecent_selection.hpp
  requiredBy: []
  timestamp: '2023-10-14 01:49:54+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/non_adj.test.cpp
documentation_of: convex/non_adjecent_selection.hpp
layout: document
redirect_from:
- /library/convex/non_adjecent_selection.hpp
- /library/convex/non_adjecent_selection.hpp.html
title: convex/non_adjecent_selection.hpp
---
